//
#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _ZCDBCUSTOMNURBSCURVE_H_
#define _ZCDBCUSTOMNURBSCURVE_H_

#include "dbents.h"

//demo, ignore validation check
class ZcDbCustomNurbsCurve : public AcDbEntity
{
public:
	ACRX_DECLARE_MEMBERS(ZcDbCustomNurbsCurve);

	ZcDbCustomNurbsCurve();
	ZcDbCustomNurbsCurve(int iDeg, const AcArray<double>& arrKnotVec, const AcArray<AcGePoint3d>& arrCtrlPt, const AcArray<double>& arrWei);
	~ZcDbCustomNurbsCurve();

	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;

	virtual Acad::ErrorStatus copyFrom(const AcRxObject* pSrc);

protected:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset);

private:
	void getPointAtParam(double dU, AcGePoint3d& pt) const;
	void sampling(AcArray<AcGePoint3d>& arrSampPt);

	int m_iP;  // degree
	AcArray<double> m_arrKnotVec;  // knot vector
	int m_iM;  // max index of m_arrKnotVec, i.e. length - 1
	AcArray<AcGePoint3d> m_arrCtrlPt;  // control points
	AcArray<double> m_arrWei;  // weights

	AcArray<AcGePoint3d> m_arrKnotPt;  // knot points;
};

#endif
