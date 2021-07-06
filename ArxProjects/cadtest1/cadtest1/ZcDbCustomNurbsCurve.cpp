//
#include "stdafx.h"
#include "ZcDbCustomNurbsCurve.h"

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

ACRX_DEFINE_MEMBERS(ZcDbCustomNurbsCurve, AcDbEntity, AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, AcDbProxyEntity::kAllAllowedBits, ZcDbCustomNurbsCurve, ZWCAD);

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
	return Acad::eNotImplementedYet;
}

Acad::ErrorStatus ZcDbCustomNurbsCurve::dwgOutFields(AcDbDwgFiler* pFiler) const
{
	return Acad::eNotImplementedYet;
}

Acad::ErrorStatus ZcDbCustomNurbsCurve::copyFrom(const AcRxObject* pSrc)
{
	return Acad::eNotImplementedYet;
}

Adesk::Boolean ZcDbCustomNurbsCurve::subWorldDraw(AcGiWorldDraw* pWd)
{
	return Adesk::kFalse;
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