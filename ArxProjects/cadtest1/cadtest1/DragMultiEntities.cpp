// 
#include "stdafx.h"
#include "DragMultiEntities.h"
#include "dbtrans.h"
#include "actrans.h"

//////////////////////////////////////////////////////////////////////////
Adesk::Boolean CDatabaseJigEntity::subWorldDraw(AcGiWorldDraw *mode)
{
	// Push a new transform onto the transform stack. 
	// When you have finished with the transform, you must call popModelTransform() to leave the pipe in the same state as before.
	mode->geometry().pushModelTransform(m_Xform);
	AcDbEntity* pEnt;
	for (int i = 0; i < m_Ids.length(); i++)
	{
		// 绘制实体无需写打开
		if (Acad::eOk == acdbOpenObject(pEnt, m_Ids[i], AcDb::kForRead))
		{
			mode->geometry().draw(pEnt);
			Acad::ErrorStatus es = pEnt->close();
		}
	}
	// The method must be called to restore the model transform after a call to PushModelTransform(). 
	mode->geometry().popModelTransform();	

	return (AcDbEntity::subWorldDraw(mode));
}
// 拖动结束后，将实体变换到新位置
BOOL CDatabaseJigEntity::transform()
{
	AcTransaction * pTrans = acTransactionManagerPtr()->startTransaction();
	if (NULL == pTrans)
		return FALSE;
	AcDbEntity *pEnt;
	AcDbObject *pObj;
	for (int i = 0; i < m_Ids.length(); i++)
	{
		if (Acad::eOk != pTrans->getObject(pObj, m_Ids[i], AcDb::kForWrite))
		{
			acTransactionManagerPtr()->abortTransaction();
			return FALSE;
		}
		pEnt = AcDbEntity::cast(pObj);
		pEnt->transformBy(m_Xform);
	}
	acTransactionManagerPtr()->endTransaction();

	return TRUE;
}
// 拖动结束后，将实体复制到新位置
BOOL CDatabaseJigEntity::transformedCopy()
{
	AcTransaction *pTrans = acTransactionManagerPtr()->startTransaction();
	if (NULL == pTrans)
		return FALSE;
	AcDbEntity *pEnt;
	AcDbEntity *pNewEnt;
	AcDbObject *pObj;
	AcDbBlockTableRecord *pBlkRec = nullptr;
	AcDbObjectId blkRecId;
	for (int i = 0; i < m_Ids.length(); i++)
	{
		if (Acad::eOk != pTrans->getObject(pObj, m_Ids[i], AcDb::kForRead))
		{
			acTransactionManagerPtr()->abortTransaction();
			return FALSE;
		}
		pEnt = AcDbEntity::cast(pObj);
		if (0 == i)
		{
			blkRecId = pEnt->blockId();
			if (Acad::eOk != pTrans->getObject(pObj, blkRecId, AcDb::kForWrite))
			{
				acTransactionManagerPtr()->abortTransaction();
				return FALSE;
			}
			pBlkRec = AcDbBlockTableRecord::cast(pObj);
		}
		pEnt->getTransformedCopy(m_Xform, pNewEnt);
		pBlkRec->appendAcDbEntity(pNewEnt);
		acTransactionManagerPtr()->addNewlyCreatedDBRObject(pNewEnt);
	}
	acTransactionManagerPtr()->endTransaction();

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
CMoveJig::~CMoveJig()
{
	if (NULL != m_pEnt)
	{
		delete m_pEnt;
		m_pEnt = NULL;
	}
}
AcEdJig::DragStatus CMoveJig::sampler()
{
	DragStatus stat;
	setUserInputControls((UserInputControls)
		(AcEdJig::kAccept3dCoordinates
			| AcEdJig::kNoNegativeResponseAccepted
			| AcEdJig::kNoZeroResponseAccepted
			| AcEdJig::kNullResponseAccepted));
	static AcGePoint3d pointTemp;
	stat = acquirePoint(m_ToPoint, m_FromPoint);
	if (pointTemp != m_ToPoint)
		pointTemp = m_ToPoint;
	else if (stat == AcEdJig::kNormal)
		stat = AcEdJig::kNoChange;
	return stat;
}
Adesk::Boolean CMoveJig::update()
{
	m_Xform.setToTranslation(m_ToPoint - m_FromPoint);
	m_pEnt->setXform(m_Xform);
	return Adesk::kTrue;
}
AcDbEntity * CMoveJig::entity() const
{
	return m_pEnt;
}
void CMoveJig::doIt(const AcDbObjectIdArray &ids, bool bCopy /*= false*/)
{
	if (0 == ids.length())
	{
		return;
	}
	if (NULL != m_pEnt)
	{
		delete m_pEnt;
		m_pEnt = NULL;
	}

	m_pEnt = new CDatabaseJigEntity(ids);
	setDispPrompt(_T("\n移动到: "));
	AcEdJig::DragStatus ds = drag();
	if (AcEdJig::kNormal == ds)
	{
		if (bCopy)
		{
			m_pEnt->transformedCopy();
		}
		else
		{
			m_pEnt->transform();
		}
	}
	delete m_pEnt;
	m_pEnt = NULL;
}

ARXCMD3(MoveMultiEntsByJig)
{
	ads_name ename;
	ads_point pt;
	ads_name ss;
	int rt;

	if (rt = acedSSGet(NULL, NULL, NULL, NULL, ss) == RTCAN)
		return;
#if ZRX==2020
	long len;
#else
	int32_t len;
#endif
	acedSSLength(ss, &len);
	if (0 == len) return;

	AcDbObjectId id;
	//acdbGetObjectId(id,ename);
	AcDbObjectIdArray ids;
	for (int i = 0; i < len; i++)
	{
		acedSSName(ss, i, ename);
		acdbGetObjectId(id, ename);
		ids.append(id);
	}
	acedSSFree(ss);
	acedGetPoint(NULL, L"\n起点：", pt);

	CMoveJig * pJig = new CMoveJig(asPnt3d(pt));
	pJig->doIt(ids);
}