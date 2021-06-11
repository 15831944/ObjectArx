//
#include "stdafx.h"
#include "CADUtils.h"
#include "CustEntities.h"

#include "rxboiler.h"
#include "dbproxy.h"
#include "dbapserv.h"
#include "acestext.h"
#include "tchar.h"

#pragma region CusEntity
ACRX_DXF_DEFINE_MEMBERS(CusEntity, AcDbEntity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kTransformAllowed |
	AcDbProxyEntity::kColorChangeAllowed |
	AcDbProxyEntity::kLayerChangeAllowed,
	CusEntity, ZrxTemplate | Product: ZRX Enabler for CustEntity | Company : ZWSOFT | Website : www.zwcad.com
);
const double kCurrentVersionNumber = 1.0;

CusEntity::CusEntity() {}
CusEntity::~CusEntity() 
{
	for (int i = 0; i < m_plVec.size(); i++)
	{
		if (m_plVec.at(i))
		{
			delete m_plVec.at(i);
			m_plVec.at(i) = nullptr;
		}
	}
	//m_plVec.clear();
	m_plVec.swap(std::vector<AcDbPolyline*>());
}
CusEntity::CusEntity(const AcGePoint3d& point1, const AcGePoint3d&point2)
	:m_point1(point1),
	m_point2(point2)
{

}
Adesk::Boolean CusEntity::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.

	//AcGePoint3dArray pointsArray;
	//pointsArray.append(m_point1);
	//pointsArray.append(m_point2);
	//pointsArray.append(m_point2+ AcGeVector3d::kXAxis *500);
	//wd->geometry().polyline(3,pointsArray.asArrayPtr());

	//AcDbPolyline* pPolyline1 = new AcDbPolyline()

	AcDbPolyline* pPolyline1 = new AcDbPolyline(2);
	pPolyline1->addVertexAt(0, AcGePoint2d(0, 0));
	pPolyline1->addVertexAt(1, AcGePoint2d(100, 0));
	m_plVec.push_back(pPolyline1);
	
	AcDbPolyline* pPolyline2 = new AcDbPolyline(2);
	pPolyline2->addVertexAt(0, AcGePoint2d(100, 0));
	pPolyline2->addVertexAt(1, AcGePoint2d(100, 100));
	m_plVec.push_back(pPolyline2);
	
	AcDbPolyline* pPolyline3 = new AcDbPolyline(2);
	pPolyline3->addVertexAt(0, AcGePoint2d(100, 100));
	pPolyline3->addVertexAt(1, AcGePoint2d(0, 100));
	m_plVec.push_back(pPolyline3); 
	
	AcDbPolyline* pPolyline4 = new AcDbPolyline(2);
	pPolyline4->addVertexAt(0, AcGePoint2d(0, 100));
	pPolyline4->addVertexAt(1, AcGePoint2d(0, 0));
	m_plVec.push_back(pPolyline4);

	AcDbPolyline* pPolyline5 = new AcDbPolyline(2);
	pPolyline5->addVertexAt(0, AcGePoint2d(0, 50));
	pPolyline5->addVertexAt(1, AcGePoint2d(100, 50));
	m_plVec.push_back(pPolyline5);

	pPolyline1->worldDraw(wd);
	pPolyline2->worldDraw(wd);
	pPolyline3->worldDraw(wd);
	pPolyline4->worldDraw(wd);
	pPolyline5->worldDraw(wd);

	//m_pPolyline = pPolyline;
	return Adesk::kTrue;
}

Acad::ErrorStatus CusEntity::subGetOsnapPoints(
	AcDb::OsnapMode       osnapMode,
	Adesk::GsMarker       gsSelectionMark,
	const AcGePoint3d&    pickPoint,
	const AcGePoint3d&    lastPoint,
	const AcGeMatrix3d&   viewXform,
	AcGePoint3dArray&     snapPoints,
	AcDbIntArray&         geomIds) const
{
	assertReadEnabled();
	for (int i = 0; i < m_plVec.size(); i++)
	{
		m_plVec.at(i)->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
	}
	//AcDbFullSubentPath subentPath(AcDb::kEdgeSubentType, 0);
	//m_plVec.at(0)->subentPtr(subentPath)->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
	//m_pPolyline->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
#if 0
	Acad::ErrorStatus es = Acad::eOk;
	AcGePoint3d pt;
	AcGeLineSeg3d lnsg;
	AcGeVector3d viewDir(viewXform(Z, 0), viewXform(Z, 1), viewXform(Z, 2));
	lnsg.set(AcGePoint3d(0, 0, 0), AcGePoint3d(100, 100, 0));
	switch (osnapMode)
	{
	case AcDb::kOsModeEnd:
		snapPoints.append(AcGePoint3d(0, 0, 0));
		snapPoints.append(AcGePoint3d(100, 100, 0));
		break;
	case AcDb::kOsModeCen:
		snapPoints.append(AcGePoint3d(50, 50, 0));
		break;
	case AcDb::kOsModeNear:
		pt = lnsg.projClosestPointTo(pickPoint, viewDir);
		snapPoints.append(pt);
		break;
	}
#endif
	return Acad::eOk;
}

Acad::ErrorStatus CusEntity::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const
{
	assertReadEnabled();
	//gripPoints.append(AcGePoint3d(0, 0, 0));
	//gripPoints.append(AcGePoint3d(100, 100, 0));

	return Acad::eOk;
}

Acad::ErrorStatus CusEntity::dwgInFields(AcDbDwgFiler *filer)
{
	assertWriteEnabled();
	AcDbEntity::dwgInFields(filer);
	// Read version number
	double version;
	filer->readItem(&version);
	if (version > kCurrentVersionNumber)
	{
		return Acad::eMakeMeProxy;
	}
	//read data
	filer->readItem(&m_point1);
	filer->readItem(&m_point2);
	// finished
	return (filer->filerStatus());
}
Acad::ErrorStatus CusEntity::dwgOutFields(AcDbDwgFiler* filer) const
{
	assertReadEnabled();
	//----- Save parent class information first. 
	Acad::ErrorStatus es = AcDbEntity::dwgOutFields(filer);
	if (es != Acad::eOk)
		return (es);
	filer->writeItem(kCurrentVersionNumber);
	filer->writeItem(m_point1);
	filer->writeItem(m_point2);

	return filer->filerStatus();
}

#pragma endregion 

#pragma region CusEntityByBlkRef
ACRX_DXF_DEFINE_MEMBERS(CusEntityByBlkRef, AcDbEntity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kTransformAllowed |
	AcDbProxyEntity::kColorChangeAllowed |
	AcDbProxyEntity::kLayerChangeAllowed,
	CusEntityByBlkRef, CUSTENT
);
CusEntityByBlkRef::CusEntityByBlkRef() {}
CusEntityByBlkRef::CusEntityByBlkRef(AcDbObjectId id)
	:m_blockId(id)
{
	//AcDbDatabase *pDb = new AcDbDatabase(/*false, true*/);
	//AcDbBlockTable* pBT = NULL;
	////acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBT, AcDb::kForWrite);
	//Acad::ErrorStatus es;
	//TCHAR* szBlockPath = _T("D:\\DDDD\\SysComponentLib_9.dwg");
	//es = pDb->readDwgFile(szBlockPath);
	//acutPrintf(_T("\nes = %s"), acadErrorStatusText(es));
	//pDb->getBlockTable(pBT, AcDb::kForWrite);

	//pBT->getAt(_T("3$3$1$3@0"), m_blockId);
	//pBT->close();
}
Adesk::Boolean CusEntityByBlkRef::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.

	AcDbLine* pLine = new AcDbLine(AcGePoint3d(0, 0, 0), AcGePoint3d(1000, 1000, 0));
	pLine->worldDraw(wd);

	AcDbBlockReference* pBlkRef = new AcDbBlockReference;
	pBlkRef->setBlockTableRecord(m_blockId);
	pBlkRef->setLayer(this->layer());
	pBlkRef->worldDraw(wd);

	//pBlkRef->close();

	return Adesk::kTrue;
}

#pragma endregion

#pragma region CusEntity01
ACRX_DXF_DEFINE_MEMBERS(CusEntity01,
	AcDbEntity,
	AcDb::kDHL_CURRENT,
	AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits,
	CusEntity01,
	TdmHoldEntity);
CusEntity01::CusEntity01() {}

Adesk::Boolean CusEntity01::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.

	AcDbLine* pLine = new AcDbLine(AcGePoint3d(0, 0, 0), AcGePoint3d(1000, 1000, 0));
	pLine->worldDraw(wd);

	wd->subEntityTraits().setColor(1);
	wd->geometry().circle(AcGePoint3d(0, 0, 0), 500.0, AcGeVector3d::kZAxis);

	return Adesk::kTrue;
}

void CusEntity01::subViewportDraw(AcGiViewportDraw *pVd)
{
	assertReadEnabled();

	if (!this->isReadEnabled())
		acutPrintf(_T("\nIsReadEnable = false\n"));

	pVd->subEntityTraits().setColor(1);
	pVd->geometry().circle(AcGePoint3d(0, 0, 0), 500.0, AcGeVector3d::kZAxis);

	return;
}

bool AppendEntityToModelSpace(AcDbEntity* pEntity)
{
	Acad::ErrorStatus es;
	bool bRet = true;

	AcDbDatabase* pDb = acdbCurDwg();
	if (pDb != NULL)
	{
		AcDbBlockTableRecordPointer pModelSpace(ACDB_MODEL_SPACE, pDb, AcDb::kForWrite);
		es = pModelSpace.openStatus();
		if (Acad::eOk == es)
		{
			AcDbObjectId idEntity;
			es = pModelSpace->appendAcDbEntity(idEntity, pEntity);
			if (Acad::eOk == es)
			{
				//关闭对象
				es = pEntity->close();
			}
			else
			{
				bRet = false;
			}
		}
	}

	return bRet;
}

AcDbObjectId PostToModelSpace(AcDbEntity *pEnt)
{
	//打开块表记录
	//得到块表对象
	AcDbBlockTable *pBlockTable = NULL;
	Acad::ErrorStatus es;
	es = acdbHostApplicationServices()->workingDatabase()
		->getSymbolTable(pBlockTable, AcDb::kForRead);
	if (es != Acad::eOk)
	{
		acutPrintf(_T("\n块表获取失败，错误代码:%s"), acadErrorStatusText(es));
		return AcDbObjectId::kNull;
	}
	//得到模型空间
	AcDbBlockTableRecord *pBlockTableRecord = NULL;
	es = pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord,
		AcDb::kForWrite);
	if (es != Acad::eOk)
	{
		acutPrintf(_T("\n模型空间块表记录打开失败，错误代码:%s"), acadErrorStatusText(es));
		pBlockTable->close();
		return AcDbObjectId::kNull;
	}
	pBlockTable->close();
	//添加实体对象到块表记录：
	AcDbObjectId outId;
	es = pBlockTableRecord->appendAcDbEntity(outId, pEnt);
	if (es != Acad::eOk)
	{
		acutPrintf(_T("\n无法添加实体到模型空间，错误代码:%s"), acadErrorStatusText(es));
		pBlockTableRecord->close();
		return AcDbObjectId::kNull;
	}
	//关闭块表记录和实体：
	pBlockTableRecord->close();
	pEnt->close();
	return outId; 
}

REGISTER_OBJECT(CusEntity01);

ARXCMD3(CusEntity01Test)
{
	//CusEntity01 *CEnt01 = new CusEntity01();
	CusEntity01 *p = new CusEntity01();
	acutPrintf(_T("\nname :%s"), p->isA()->name());
	PostToModelSpace(p);
	//AppendEntityToModelSpace(CEnt01);
}

#pragma endregion 

#pragma region 
ACRX_DXF_DEFINE_MEMBERS(PMACLINAGA_SIMULATION,
	AcDbEntity,
	AcDb::kDHL_CURRENT,
	AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits,
	PMACLINAGA_SIMULATION,
	TdmHoldEntity);

Adesk::Boolean PMACLINAGA_SIMULATION::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.

	AcDbPolyline* polyline1 = new AcDbPolyline(2);
	polyline1->addVertexAt(0, AcGePoint2d(0, 0));
	polyline1->addVertexAt(1, AcGePoint2d(1000, 0));

	AcDbPolyline* polyline2 = new AcDbPolyline(2);
	polyline2->addVertexAt(0, AcGePoint2d(1000, 0));
	polyline2->addVertexAt(1, AcGePoint2d(1000, 120));

	AcDbPolyline* polyline3 = new AcDbPolyline(2);
	polyline3->addVertexAt(0, AcGePoint2d(1000, 120));
	polyline3->addVertexAt(1, AcGePoint2d(0, 120));

	AcDbPolyline* polyline4 = new AcDbPolyline(2);
	polyline4->addVertexAt(0, AcGePoint2d(0, 120));
	polyline4->addVertexAt(1, AcGePoint2d(0, 0));

	AcDbPolyline* polyline5 = new AcDbPolyline(2);
	polyline5->addVertexAt(0, AcGePoint2d(0, 60));
	polyline5->addVertexAt(1, AcGePoint2d(1000, 60));

	if (m_plVec.size() == 0)
	{
		m_plVec.push_back(polyline1);
		m_plVec.push_back(polyline2);
		m_plVec.push_back(polyline3);
		m_plVec.push_back(polyline4);
		m_plVec.push_back(polyline5);
	}

	polyline1->worldDraw(wd);
	polyline2->worldDraw(wd);
	polyline3->worldDraw(wd);
	polyline4->worldDraw(wd);
	polyline5->worldDraw(wd);

	return Adesk::kTrue;
}

Acad::ErrorStatus PMACLINAGA_SIMULATION::subGetOsnapPoints(
	AcDb::OsnapMode       osnapMode,
	Adesk::GsMarker       gsSelectionMark,
	const AcGePoint3d&    pickPoint,
	const AcGePoint3d&    lastPoint,
	const AcGeMatrix3d&   viewXform,
	AcGePoint3dArray&     snapPoints,
	AcDbIntArray&         geomIds) const
{
	assertReadEnabled();
	for (int i = 0; i < m_plVec.size(); i++)
	{
		m_plVec.at(i)->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
	}
	//AcDbFullSubentPath subentPath(AcDb::kEdgeSubentType, 0);
	//m_plVec.at(0)->subentPtr(subentPath)->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
	//m_pPolyline->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
#if 0
	Acad::ErrorStatus es = Acad::eOk;
	AcGePoint3d pt;
	AcGeLineSeg3d lnsg;
	AcGeVector3d viewDir(viewXform(Z, 0), viewXform(Z, 1), viewXform(Z, 2));
	lnsg.set(AcGePoint3d(0, 0, 0), AcGePoint3d(100, 100, 0));
	switch (osnapMode)
	{
	case AcDb::kOsModeEnd:
		snapPoints.append(AcGePoint3d(0, 0, 0));
		snapPoints.append(AcGePoint3d(100, 100, 0));
		break;
	case AcDb::kOsModeCen:
		snapPoints.append(AcGePoint3d(50, 50, 0));
		break;
	case AcDb::kOsModeNear:
		pt = lnsg.projClosestPointTo(pickPoint, viewDir);
		snapPoints.append(pt);
		break;
	}
#endif
	return Acad::eOk;
}

Acad::ErrorStatus PMACLINAGA_SIMULATION::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const
{
	assertReadEnabled();

	gripPoints.removeAll();
	gripPoints.append(AcGePoint3d(0, 60, 0));
	gripPoints.append(AcGePoint3d(500, 60, 0));
	gripPoints.append(AcGePoint3d(1000, 60, 0));

	return Acad::eOk;
}
Acad::ErrorStatus PMACLINAGA_SIMULATION::subIntersectWith(const AcDbEntity* ent,
	AcDb::Intersect intType,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker,
	Adesk::GsMarker otherGsMarker) const
{
	Acad::ErrorStatus es;
	CString szEntClassName = ent->isA()->name();
	AcDbVoidPtrArray vptrArr;
	es = ent->explode(vptrArr);
	assertReadEnabled();
	for (int i = 0; i < m_plVec.size(); i++)
	{
		for (int j = 0; j < vptrArr.length(); j++)
		{
			AcDbEntity *pSubEnt = (AcDbEntity*)vptrArr[j];
			es = m_plVec.at(i)->intersectWith(pSubEnt, intType, points, thisGsMarker, otherGsMarker);
		}
	}
	return Acad::eOk;
}

Acad::ErrorStatus PMACLINAGA_SIMULATION::subExplode(AcDbVoidPtrArray& entitySet) const
{
	assertReadEnabled();

	for (int i = 0; i < m_plVec.size(); i++)
		entitySet.append((void*)m_plVec[i]);

	return Acad::eOk;
}


ACRX_DXF_DEFINE_MEMBERS(PMACPOLE_SIMULATION,
	AcDbEntity,
	AcDb::kDHL_CURRENT,
	AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits,
	PMACPOLE_SIMULATION,
	TdmHoldEntity);

Adesk::Boolean PMACPOLE_SIMULATION::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.

	//AcDbPolyline *polyline = new AcDbPolyline();
	//polyline->addVertexAt(0, AcGePoint2d(200, -40));
	//polyline->addVertexAt(1, AcGePoint2d(400, -40));
	//polyline->addVertexAt(2, AcGePoint2d(400, 160));
	//polyline->addVertexAt(3, AcGePoint2d(200, 160));
	//polyline->addVertexAt(4, AcGePoint2d(200, -40));
	//m_plVec.push_back(polyline);
	//wd->geometry().pline(*polyline);

	AcDbPolyline* polyline1 = new AcDbPolyline(2);
	polyline1->addVertexAt(0, AcGePoint2d(200, -40));
	polyline1->addVertexAt(1, AcGePoint2d(400, -40));

	AcDbPolyline* polyline2 = new AcDbPolyline(2);
	polyline2->addVertexAt(0, AcGePoint2d(400, -40));
	polyline2->addVertexAt(1, AcGePoint2d(400, 160));

	AcDbPolyline* polyline3 = new AcDbPolyline(2);
	polyline3->addVertexAt(0, AcGePoint2d(400, 160));
	polyline3->addVertexAt(1, AcGePoint2d(200, 160));

	AcDbPolyline* polyline4 = new AcDbPolyline(2);
	polyline4->addVertexAt(0, AcGePoint2d(200, 160));
	polyline4->addVertexAt(1, AcGePoint2d(200, -40));

	if (m_plVec.size() == 0)
	{
		m_plVec.push_back(polyline1);
		m_plVec.push_back(polyline2);
		m_plVec.push_back(polyline3);
		m_plVec.push_back(polyline4);
	}

	polyline1->worldDraw(wd);
	polyline2->worldDraw(wd);
	polyline3->worldDraw(wd);
	polyline4->worldDraw(wd);

	return Adesk::kTrue;
}

Acad::ErrorStatus PMACPOLE_SIMULATION::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const
{
	assertReadEnabled();

	gripPoints.removeAll();
	gripPoints.append(AcGePoint3d(300, 60, 0));

	return Acad::eOk;
}

Acad::ErrorStatus PMACPOLE_SIMULATION::subGetOsnapPoints(
	AcDb::OsnapMode       osnapMode,
	Adesk::GsMarker       gsSelectionMark,
	const AcGePoint3d&    pickPoint,
	const AcGePoint3d&    lastPoint,
	const AcGeMatrix3d&   viewXform,
	AcGePoint3dArray&     snapPoints,
	AcDbIntArray&         geomIds) const
{
	assertReadEnabled();
	for (int i = 0; i < m_plVec.size(); i++)
	{
		m_plVec.at(i)->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
	}
	return Acad::eOk;
}

Acad::ErrorStatus PMACPOLE_SIMULATION::subIntersectWith(const AcDbEntity* ent,
	AcDb::Intersect intType,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker,
	Adesk::GsMarker otherGsMarker) const
{
	Acad::ErrorStatus es;
	CString szEntClassName = ent->isA()->name();
	AcDbVoidPtrArray vptrArr;
	es = ent->explode(vptrArr);
	assertReadEnabled();
	for (int i = 0; i < m_plVec.size(); i++)
	{
		for (int j = 0; j < vptrArr.length(); j++)
		{
			AcDbEntity *pSubEnt = (AcDbEntity*)vptrArr[j];
			es = m_plVec.at(i)->intersectWith(pSubEnt, intType, points, thisGsMarker, otherGsMarker);
		}
	}
	return Acad::eOk;
}

Acad::ErrorStatus PMACPOLE_SIMULATION::subExplode(AcDbVoidPtrArray& entitySet) const
{
	assertReadEnabled();

	for (int i = 0; i < m_plVec.size(); i++)
		entitySet.append((void*)m_plVec[i]);

	return Acad::eOk;
}

REGISTER_OBJECT(PMACLINAGA_SIMULATION);
REGISTER_OBJECT(PMACPOLE_SIMULATION);
ARXCMD3(testDimaligned)
{
	PMACLINAGA_SIMULATION *pCusEnt1 = new PMACLINAGA_SIMULATION();
	PMACPOLE_SIMULATION *pCusEnt2 = new PMACPOLE_SIMULATION();
	AcDbObjectId id1,id2;
	CADUtils::AppendToModalSpace(pCusEnt1, id1);
	CADUtils::AppendToModalSpace(pCusEnt2, id2);
	pCusEnt1->close();
	pCusEnt2->close();
}

#pragma endregion Test PM dim err

#pragma region CusEntity02
ACRX_DXF_DEFINE_MEMBERS(CusEntity02,
	AcDbEntity,
	AcDb::kDHL_CURRENT,
	AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits,
	CusEntity02,
	TdmHoldEntity);

CusEntity02::CusEntity02()
	//:m_pCurve(new AcDbLine(AcGePoint3d(200, 40, 0), AcGePoint3d(400, 40, 0)))
	:m_pPolyline(new AcDbPolyline(2))
{
	m_pPolyline->addVertexAt(0, AcGePoint2d(200, 40));
	m_pPolyline->addVertexAt(1, AcGePoint2d(400, 40));
}

CusEntity02::~CusEntity02()
{
	if (m_pPolyline)
	{
		delete m_pPolyline;
		m_pPolyline = nullptr;
	}
}

Acad::ErrorStatus CusEntity02::subGetGripPoints(AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const
{
	assertReadEnabled();
	return m_pPolyline->getGripPoints(gripPoints, osnapModes, geomIds);
}
Acad::ErrorStatus CusEntity02::subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset)
{
	assertReadEnabled();
	return m_pPolyline->moveGripPointsAt(indices, offset);
}

Acad::ErrorStatus CusEntity02::subGetOsnapPoints(
	AcDb::OsnapMode       osnapMode,
	Adesk::GsMarker       gsSelectionMark,
	const AcGePoint3d&    pickPoint,
	const AcGePoint3d&    lastPoint,
	const AcGeMatrix3d&   viewXform,
	AcGePoint3dArray&     snapPoints,
	AcDbIntArray&         geomIds) const
{
	assertReadEnabled();
	return m_pPolyline->getOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
}

Adesk::Boolean CusEntity02::subWorldDraw(AcGiWorldDraw* wd)
{
	assertReadEnabled();    // Its purpose is to make sure that the object is open AcDb::kForRead.
	m_pPolyline->worldDraw(wd);

	return Adesk::kTrue;
}

Acad::ErrorStatus CusEntity02::subIntersectWith(const AcDbEntity* ent,
	AcDb::Intersect intType,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker,
	Adesk::GsMarker otherGsMarker) const
{
	assertReadEnabled();

	return m_pPolyline->intersectWith(ent, intType, points, thisGsMarker, otherGsMarker);
}
Acad::ErrorStatus CusEntity02::subIntersectWith(const AcDbEntity* pEnt,
	AcDb::Intersect intType,
	const AcGePlane& projPlane,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker,
	Adesk::GsMarker otherGsMarker) const
{
	assertReadEnabled();
	return m_pPolyline->intersectWith(pEnt, intType, projPlane, points, thisGsMarker, otherGsMarker);
}

Acad::ErrorStatus CusEntity02::extend(double newParam)
{
	assertWriteEnabled();
	return m_pPolyline->extend(newParam);
}
Acad::ErrorStatus CusEntity02::extend(Adesk::Boolean extendStart,
	const AcGePoint3d& toPoint)
{
	assertWriteEnabled();
	return m_pPolyline->extend(extendStart, toPoint);
}

Acad::ErrorStatus CusEntity02::subGetStretchPoints(AcGePoint3dArray& stretchPoints) const
{
	assertReadEnabled();;
	return m_pPolyline->getStretchPoints(stretchPoints);
}
Acad::ErrorStatus CusEntity02::subMoveStretchPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset)
{
	assertReadEnabled();;
	return m_pPolyline->moveStretchPointsAt(indices, offset);
}

Acad::ErrorStatus CusEntity02::subGetSubentPathsAtGsMarker(
	AcDb::SubentType       type,
	Adesk::GsMarker        gsMark,
	const AcGePoint3d&     pickPoint,
	const AcGeMatrix3d&    viewXform,
	int&                   numPaths,
	AcDbFullSubentPath*&   subentPaths,
	int                    numInserts,
	AcDbObjectId*          entAndInsertStack
	) const
{
	assertReadEnabled();;
	return m_pPolyline->getSubentPathsAtGsMarker(type, gsMark, pickPoint, viewXform, numPaths, subentPaths, numInserts, entAndInsertStack);
}

//Acad::ErrorStatus CusEntity02::subExplode(AcDbVoidPtrArray& entitySet) const
//{
//	assertReadEnabled();
//		
//    entitySet.append((void*)m_plVec[0]);
//
//	return Acad::eOk;
//}

REGISTER_OBJECT(CusEntity02);
ARXCMD3(CusEntity02Test)
{
	CusEntity02 *pCusEnt = new CusEntity02();
	AcDbObjectId id;
	CADUtils::AppendToModalSpace(pCusEnt, id);

	if (pCusEnt->isKindOf(AcDbCurve::desc()))
	{
		acutPrintf(_T("\nAcDbCurve"));
	}
	else if (pCusEnt->isKindOf(AcDbEntity::desc()))
	{
		acutPrintf(_T("\nAcDbEntity"));
	}
	else if (pCusEnt->isKindOf(AcDbObject::desc()))
	{
		acutPrintf(_T("\nAcDbObject"));
	}

	pCusEnt->close();
#ifndef ARX
	acedCommand(RTSTR, _T("zoom e"), RTNONE);
#else
	acedCommandS(RTSTR, _T("zoom e"), RTNONE);
#endif
}
#pragma endregion Test Extend custom entity

#pragma region CusEntity03

ACRX_DXF_DEFINE_MEMBERS(CusEntity03, AcDbEntity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kAllAllowedBits,
	CusEntity03Test, "CusEntity03-Test");

CusEntity03::CusEntity03() {}

CusEntity03::CusEntity03(AcGePoint3d ptPos ,AcDbObjectId blkRecId) 
	:m_ptPos(ptPos), m_blkRecId(blkRecId)
{}

CusEntity03::~CusEntity03() {}

Adesk::Boolean CusEntity03::subWorldDraw(AcGiWorldDraw* pWd)
{
	assertReadEnabled();   

	AcDbBlockReference *pBlockRef = new AcDbBlockReference(m_ptPos, m_blkRecId);
	pBlockRef->worldDraw(pWd);

	delete pBlockRef;
	pBlockRef = nullptr;

	return Adesk::kTrue;
}

REGISTER_OBJECT(CusEntity03)
ARXCMD3(CusEntity03Test)
{
	AcDbObjectId cusEntId, blkRecId;

#if 0
	if (Acad::eOk != CADUtils::GetBlockRecordId(curDoc()->database(), _T("aaa"), blkRecId))
		return;
#endif

	AcDbDatabase *extDb = new AcDbDatabase(false);
	Acad::ErrorStatus es = Acad::eOk;
	TCHAR  blkName[256] = { 0 };
	if (Acad::eOk != extDb->readDwgFile(_T("D:\\dwgfiles\\1137.dwg")))
	{
		acedAlert(_T("读取dwg文件失败！"));
		return;
	}
	es = acdbCurDwg()->insert(blkRecId, blkName, extDb, false);
	if (Acad::eOk != es)
		acedAlert(_T("插入块操作失败"));

	delete extDb;
	extDb = NULL;

	CusEntity03 *pCusEnt03 = new CusEntity03(AcGePoint3d(0, 0, 0) ,blkRecId);
	CADUtils::AppendToModalSpace(pCusEnt03, cusEntId);
	pCusEnt03->close();
}

#pragma endregion Test blockreference in subWorldDraw

