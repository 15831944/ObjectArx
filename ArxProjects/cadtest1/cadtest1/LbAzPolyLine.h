//////////////////////////////////////////////////////////////////////////////
// LbAzPolyLine custom object, created by  [2005-10-14], , 

#if !defined(ARX__LBAZPOLYLINE_H__20051014_160535)
#define ARX__LBAZPOLYLINE_H__20051014_160535

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "dbpl.h"
//#include "LbAzCurveEntity.h"
#include "dbents.h"

#pragma warning(push)
#pragma warning(disable:4275)

#pragma warning(disable: 4275 4251)

#ifndef LBAZOBJECT_DBXSERVICE
#define LBAZOBJECT_DBXSERVICE _T( "LBAZOBJECT_DBXSERVICE" )
#endif

class
//#ifdef _LBAZOBJECT_
//	__declspec(dllexport)
//#else
//	__declspec(dllimport)
//#endif 
LbAzPolyLine2:  public AcDbCurve
{
public:
	// Constructor / Destructor
	ACRX_DECLARE_MEMBERS(LbAzPolyLine2);
	//LB_DYNAMIC_CAST(LbAzPolyLine2);

	LbAzPolyLine2();
	virtual ~LbAzPolyLine2();

	//{{AFX_ARX_METHODS(LbAzPolyLine)
 	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
 
 	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
 
 	virtual Acad::ErrorStatus getStartPoint(AcGePoint3d& x0) const;
 
 	virtual Acad::ErrorStatus getStartParam(double& x0) const;
 
 	virtual Acad::ErrorStatus getEndPoint(AcGePoint3d& x0) const;
 
 	virtual Acad::ErrorStatus getEndParam(double& x0) const;
 
 	virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity* pEnt,
 		AcDb::Intersect intType,
 		const AcGePlane& projPlane,
 		AcGePoint3dArray& points,
 		Adesk::GsMarker thisGsMarker = 0,
 		Adesk::GsMarker otherGsMarker = 0) const;
 
 	virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity* pEnt,
 		AcDb::Intersect intType,
 		AcGePoint3dArray& points,
 		Adesk::GsMarker thisGsMarker = 0,
 		Adesk::GsMarker otherGsMarker = 0) const;
 
 	virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray& stretchPoints) const;
 
 	virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray& points,
 		AcDbVoidPtrArray& curveSegments) const;
 
 	virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray& params,
 		AcDbVoidPtrArray& curveSegments) const;
 
 	virtual Acad::ErrorStatus getSecondDeriv(double param,
 		AcGeVector3d& secDeriv) const;
 
 	virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d& x0,
 		AcGeVector3d& secDeriv) const;
 
 	virtual Acad::ErrorStatus getPointAtParam(double x0,
 		AcGePoint3d& x1) const;
 
 	virtual Acad::ErrorStatus getPointAtDist(double x0,
 		AcGePoint3d& x1) const;
 
 	virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d& x0,
 		double& x1)const;
 
 	virtual Acad::ErrorStatus getParamAtDist(double dist,
 		double& param) const;
 
 	virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
 		Adesk::GsMarker gsSelectionMark,
 		const AcGePoint3d& pickPoint,
 		const AcGePoint3d& lastPoint,
 		const AcGeMatrix3d& viewXform,
 		AcGePoint3dArray& snapPoints,
 		AcDbIntArray& geomIds) const;
 
 	virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal,
 		double offsetDist,
 		AcDbVoidPtrArray& offsetCurves) const;
 
 	virtual Acad::ErrorStatus getOffsetCurves(double offsetDist,
 		AcDbVoidPtrArray& offsetCurves) const;
 
 	virtual Acad::ErrorStatus   subGetGripPoints(AcDbGripDataPtrArray& grips,
 		const double curViewUnitSize, const int gripSize,
 		const AcGeVector3d& curViewDir, const int bitflags) const
 	{
 		assertReadEnabled();
 		return Acad::eNotImplemented;
 	}
 
 	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints,
 		AcDbIntArray& osnapModes,
 		AcDbIntArray& geomIds) const;
 
 	virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const;
 
 	virtual Acad::ErrorStatus getFirstDeriv(double param,
 		AcGeVector3d& firstDeriv) const;
 
 	virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d& x0,
 		AcGeVector3d& firstDeriv) const;
 
 	virtual Acad::ErrorStatus getDistAtParam(double param,
 		double& dist) const;
 
 	virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d& x0,
 		double& x1)const;
 
 	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt,
 		const AcGeVector3d& direction,
 		AcGePoint3d& pointOnCurve,
 		Adesk::Boolean extend = Adesk::kFalse) const;
 
 	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt,
 		AcGePoint3d& pointOnCurve,
 		Adesk::Boolean extend = Adesk::kFalse) const;
 	virtual Acad::ErrorStatus extend(double newParam);
 
 	virtual Acad::ErrorStatus extend(Adesk::Boolean extendStart,
 		const AcGePoint3d& toPoint);
 
 	virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;
 
 	virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices,
 		const AcGeVector3d& offset);
 
 	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices,
 		const AcGeVector3d& offset);
 
 	virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane&    plane,
 		const AcGeVector3d& projDir,
 		AcDbCurve*&       projectedCurve) const;
 
 	//virtual Acad::ErrorStatus subHighlight(const AcDbFullSubentPath& subId = kNullSubent,
 	//	const Adesk::Boolean highlightAll = false) const;
 
 	//virtual Acad::ErrorStatus subUnhighlight(const AcDbFullSubentPath& subId = kNullSubent,
 	//	const Adesk::Boolean highlightAll = false) const;
 
 	virtual void subList() const;
 
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
 	//}}AFX_ARX_METHODS
 
 
 public:
 	virtual AcGePoint3d         startPoint() const;
 	virtual Acad::ErrorStatus	setStartPoint(const AcGePoint3d&);
 	virtual AcGePoint3d         endPoint() const;
 	virtual Acad::ErrorStatus	setEndPoint(const AcGePoint3d&);
 	virtual AcGeVector3d GetNormal() const;
 	virtual void SetNormal(AcGeVector3d vecNormal);
 	virtual double GetBulge() const;
 	virtual void    SetBulge(double dBulge);

	const AcDbPolyline& GetPoly() const;

protected:
	AcDbPolyline m_pPolyline;
	Acad::ErrorStatus getAzPolyGripPoints_2d(AcGePoint3dArray&  gripPoints)const;
	Acad::ErrorStatus moveGripPointsAt_2d(const AcDbIntArray& indices, const AcGeVector3d& offset);

private:
	void *operator new[](size_t nSize) { return 0; }
	void operator delete[](void *p) {};
	void *operator new[](size_t nSize, const TCHAR *file, int line) { return 0; }

};


#pragma warning(pop)

#endif // !defined(ARX__LBAZPOLYLINE_H__20051014_160535)
