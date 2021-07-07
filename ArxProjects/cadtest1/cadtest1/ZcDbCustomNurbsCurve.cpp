//
#include "stdafx.h"
#include "ZcDbCustomNurbsCurve.h"

#include "rxboiler.h"
#include "dbproxy.h"

#define GRIP_PTS_ARE_CTRL_PTS 0

class ZcGeCustomPoint4d
{
public:
	ZcGeCustomPoint4d() : m_dX(0.0), m_dY(0.0), m_dZ(0.0), m_dW(0.0) {};
	ZcGeCustomPoint4d(const AcGePoint3d& pt, double dWei) : m_dX(pt.x * dWei), m_dY(pt.y * dWei), m_dZ(pt.z * dWei), m_dW(dWei) {};
	~ZcGeCustomPoint4d() {};

	void operator*=(double dN)
	{
		m_dX *= dN;
		m_dY *= dN;
		m_dZ *= dN;
		m_dW *= dN;
	};

	void operator+=(const ZcGeCustomPoint4d& pt)
	{
		m_dX += pt.m_dX;
		m_dY += pt.m_dY;
		m_dZ += pt.m_dZ;
		m_dW += pt.m_dW;
	};

	double x() const { return m_dX; };
	double y() const { return m_dY; };
	double z() const { return m_dZ; };
	double w() const { return m_dW; };

private:
	double m_dX;
	double m_dY;
	double m_dZ;
	double m_dW;
};

double _safeDivide(double dDivisor, double dDividend)
{
	if (dDividend == 0.0)
		return 0.0;
	else
		return dDivisor / dDividend;
}

bool _appendEntToDb(AcDbEntity* pEnt)
{
	AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
	if (!pDb)
		return false;

	AcDbBlockTable* pBlkTbl = nullptr;
	pDb->getBlockTable(pBlkTbl, AcDb::kForRead);
	if (!pBlkTbl)
		return false;

	AcDbBlockTableRecord* pBlkTblRec = nullptr;
	pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRec, AcDb::kForWrite);
	pBlkTbl->close();
	if (!pBlkTblRec)
		return false;

	Acad::ErrorStatus es = pBlkTblRec->appendAcDbEntity(pEnt);
	pBlkTblRec->close();

	return (Acad::eOk == es);
}

ACRX_DXF_DEFINE_MEMBERS(ZcDbCustomNurbsCurve, AcDbEntity, AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, AcDbProxyEntity::kAllAllowedBits, ZcDbCustomNurbsCurve, ZWCAD);

ZcDbCustomNurbsCurve::ZcDbCustomNurbsCurve() 
	: m_iP(0), m_iM(0)
{
}

ZcDbCustomNurbsCurve::ZcDbCustomNurbsCurve(int iP, const AcArray<double>& arrKnotVec, const AcArray<AcGePoint3d>& arrCtrlPt, const AcArray<double>& arrWei)
	:AcDbEntity(), m_iP(iP), m_arrKnotVec(arrKnotVec), m_iM(m_arrKnotVec.length() - 1), m_arrCtrlPt(arrCtrlPt), m_arrWei(arrWei)
{
}

ZcDbCustomNurbsCurve::~ZcDbCustomNurbsCurve()
{
}

Acad::ErrorStatus ZcDbCustomNurbsCurve::dwgInFields(AcDbDwgFiler* pFiler)
{
	assertWriteEnabled();

	if (AcDbEntity::dwgInFields(pFiler) != Acad::eOk)
		return pFiler->filerStatus();

#if ZRX != 2020
	pFiler->readInt32(&m_iP);
	pFiler->readInt32(&m_iM);
#endif
	m_arrKnotVec.setLogicalLength(m_iM + 1);
	double dKnot = 0.0;
	for (int i = 0; i < m_iM + 1; i++)
	{
		pFiler->readDouble(&dKnot);
		m_arrKnotVec[i] = dKnot;
	}

	int iCtrlPtCnt = m_iM - m_iP;
	m_arrCtrlPt.setLogicalLength(iCtrlPtCnt);
	m_arrWei.setLogicalLength(iCtrlPtCnt);
	AcGePoint3d ctrlPt;
	double dWei = 0.0;
	for (int i = 0; i < iCtrlPtCnt; i++)
	{
		pFiler->readPoint3d(&ctrlPt);
		m_arrCtrlPt[i] = ctrlPt;
		pFiler->readDouble(&dWei);
		m_arrWei[i] = dWei;
	}

	return pFiler->filerStatus();
}

Acad::ErrorStatus ZcDbCustomNurbsCurve::dwgOutFields(AcDbDwgFiler* pFiler) const
{
	assertReadEnabled();

	if (AcDbEntity::dwgOutFields(pFiler) != Acad::eOk)
		return pFiler->filerStatus();

	pFiler->writeInt32(m_iP);
	pFiler->writeInt32(m_iM);
	for (int i = 0; i < m_iM + 1; i++)
	{
		pFiler->writeDouble(m_arrKnotVec[i]);
	}
	for (int i = 0; i < m_iM - m_iP; i++)
	{
		pFiler->writePoint3d(m_arrCtrlPt[i]);
		pFiler->writeDouble(m_arrWei[i]);
	}

	return pFiler->filerStatus();
}

Acad::ErrorStatus ZcDbCustomNurbsCurve::copyFrom(const AcRxObject* pSrc)
{
	Acad::ErrorStatus es = AcDbEntity::copyFrom(pSrc);
	if (Acad::eOk == es)
	{
		es = Acad::eWrongObjectType;
		ZcDbCustomNurbsCurve* pCrv = ZcDbCustomNurbsCurve::cast(pSrc);
		if (!pCrv)
		{
			es = Acad::eOk;
			if (!pCrv->m_arrKnotPt.isEmpty())
				m_arrKnotPt = pCrv->m_arrKnotPt;
		}
	}

	return es;
}

Adesk::Boolean ZcDbCustomNurbsCurve::subWorldDraw(AcGiWorldDraw* pWd)
{
	assertReadEnabled();

	AcArray<AcGePoint3d> arrSampPt;
	sampling(arrSampPt);
	pWd->geometry().polyline(arrSampPt.length(), arrSampPt.asArrayPtr());

	pWd->subEntityTraits().setColor(1);
	pWd->geometry().polyline(m_iM - m_iP, m_arrCtrlPt.asArrayPtr());

	return Adesk::kTrue;
}

Acad::ErrorStatus ZcDbCustomNurbsCurve::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const
{
	return Acad::eNotImplementedYet;
}

Acad::ErrorStatus ZcDbCustomNurbsCurve::subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset)
{
	return Acad::eNotImplementedYet;
}

void ZcDbCustomNurbsCurve::getPointAtParam(double dU, AcGePoint3d& pt) const
{

}

void ZcDbCustomNurbsCurve::sampling(AcArray<AcGePoint3d>& arrSampPt)
{

}

REGISTER_OBJECT(ZcDbCustomNurbsCurve)
ARXCMD3(CreateCustomNurbsCurve)
{
	int iP = 3;
	AcArray<double> arrKnotVec;
	AcArray<AcGePoint3d> arrCtrlPt;
	AcArray<double> arrWei;

	arrKnotVec.append(0.0);
	arrKnotVec.append(0.0);
	arrKnotVec.append(0.0);
	arrKnotVec.append(0.0);    // iP + 1¸ö0.0
	arrKnotVec.append(0.25);
	arrKnotVec.append(0.5);
	arrKnotVec.append(0.75);
	arrKnotVec.append(1.0);    // iP + 1¸ö1.0
	arrKnotVec.append(1.0);
	arrKnotVec.append(1.0);
	arrKnotVec.append(1.0);  

	// n = m - p - 1
	arrCtrlPt.append(AcGePoint3d(0.0, 0.0, 0.0));
	arrCtrlPt.append(AcGePoint3d(10.0, 10.0, 0.0));
	arrCtrlPt.append(AcGePoint3d(20.0, -10.0, 0.0));
	arrCtrlPt.append(AcGePoint3d(30.0, 10.0, 0.0));
	arrCtrlPt.append(AcGePoint3d(40.0, -10.0, 0.0));
	arrCtrlPt.append(AcGePoint3d(50.0, 10.0, 0.0));
	arrCtrlPt.append(AcGePoint3d(60.0, 0.0, 0.0));

	arrWei.append(1.0);
	arrWei.append(1.0);
	arrWei.append(1.0);
	arrWei.append(1.0);
	arrWei.append(1.0);
	arrWei.append(1.0);
	arrWei.append(1.0);

	ZcDbCustomNurbsCurve* pCrv = new ZcDbCustomNurbsCurve(iP, arrKnotVec, arrCtrlPt, arrWei);
	if (_appendEntToDb(pCrv))
		pCrv->close();
	else
	{
		delete pCrv;
		pCrv = nullptr;
	}
}