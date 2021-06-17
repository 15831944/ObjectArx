// CusEntities.h

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _CUSENTITIES_H_
#define _CUSENTITIES_H_

#include "dbents.h"
#include "gepent3d.h"
#include <vector>

#if ZRX == 2020 || ARX == 2013
#define subWorldDraw worldDraw
#define subViewportDraw viewportDraw
#define subList list
#define subGetSubentPathsAtGsMarker getSubentPathsAtGsMarker
#define subGetGripPoints getGripPoints
#define subMoveGripPointsAt moveGripPointsAt
#define subGetOsnapPoints getOsnapPoints
#define subIntersectWith intersectWith
#define subExplode explode
#define subGetStretchPoints getStretchPoints
#define subMoveStretchPointsAt moveStretchPointsAt
#define subGetGeomExtents getGeomExtents
#define subTransformBy transformBy
#endif

class CusEntity :public AcDbEntity
{
public:
	CusEntity();
	CusEntity(const AcGePoint3d&, const AcGePoint3d&);
	~CusEntity();
public:
	ACRX_DECLARE_MEMBERS(CusEntity);       //declare desc(),cast(),isA()
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const;
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode       osnapMode,
		Adesk::GsMarker       gsSelectionMark,
		const AcGePoint3d&    pickPoint,
		const AcGePoint3d&    lastPoint,
		const AcGeMatrix3d&   viewXform,
		AcGePoint3dArray&     snapPoints,
		AcDbIntArray&         geomIds) const;

	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* filer);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* filer) const;

public:
	inline void set(AcGePoint3d& pnt1, AcGePoint3d& pnt2) { m_point1 = pnt1; m_point2 = pnt2; };
private:
	AcGePoint3d m_point1;
	AcGePoint3d m_point2;
	AcDbPolyline* m_pPolyline;
	std::vector<AcDbPolyline*> m_plVec;
};


class CusEntityByBlkRef :public AcDbEntity
{
public:
	CusEntityByBlkRef();
	CusEntityByBlkRef(AcDbObjectId id);
	ACRX_DECLARE_MEMBERS(CusEntityByBlkRef);       //declare desc(),cast(),isA()
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
private:
	AcDbObjectId m_blockId;
};

class CusEntity01 :public AcDbEntity
{
public:
	CusEntity01();
	ACRX_DECLARE_MEMBERS(CusEntity01);       //declare desc(),cast(),isA()
#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
public:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
	virtual void subViewportDraw(AcGiViewportDraw* pVd);
#else
protected:
	virtual Adesk::Boolean      subWorldDraw(AcGiWorldDraw* pWd);
	virtual void subViewportDraw(AcGiViewportDraw* pVd);
#endif
};

class PMACLINAGA_SIMULATION :public AcDbEntity
{
public:
	ACRX_DECLARE_MEMBERS(PMACLINAGA_SIMULATION);       //declare desc(),cast(),isA()
public:
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const;
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode       osnapMode,
		Adesk::GsMarker       gsSelectionMark,
		const AcGePoint3d&    pickPoint,
		const AcGePoint3d&    lastPoint,
		const AcGeMatrix3d&   viewXform,
		AcGePoint3dArray&     snapPoints,
		AcDbIntArray&         geomIds) const;
	virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity* ent,
		AcDb::Intersect intType,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;

#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
public:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
	//virtual void subViewportDraw(AcGiViewportDraw* pVd);
#else
protected:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	//virtual void subViewportDraw(AcGiViewportDraw* pVd);
#endif
private:
	std::vector<AcDbPolyline*> m_plVec;
};

class PMACPOLE_SIMULATION :public AcDbEntity
{
public:
	ACRX_DECLARE_MEMBERS(PMACPOLE_SIMULATION);       //declare desc(),cast(),isA()
public:
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const;
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode       osnapMode,
		Adesk::GsMarker       gsSelectionMark,
		const AcGePoint3d&    pickPoint,
		const AcGePoint3d&    lastPoint,
		const AcGeMatrix3d&   viewXform,
		AcGePoint3dArray&     snapPoints,
		AcDbIntArray&         geomIds) const;
	virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity* ent,
		AcDb::Intersect intType,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;

#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
public:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
	//virtual void subViewportDraw(AcGiViewportDraw* pVd);
#else
protected:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	//virtual void subViewportDraw(AcGiViewportDraw* pVd);
#endif
private:
	std::vector<AcDbPolyline*> m_plVec;
};

class CusEntity02 :public AcDbCurve
{
public:
	CusEntity02();
	~CusEntity02();
	ACRX_DECLARE_MEMBERS(CusEntity02);       //declare desc(),cast(),isA()
public:
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset);
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode       osnapMode,
		Adesk::GsMarker       gsSelectionMark,
		const AcGePoint3d&    pickPoint,
		const AcGePoint3d&    lastPoint,
		const AcGeMatrix3d&   viewXform,
		AcGePoint3dArray&     snapPoints,
		AcDbIntArray&         geomIds) const;
	virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity* ent,
		AcDb::Intersect intType,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	virtual  Acad::ErrorStatus subIntersectWith(const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		const AcGePlane& projPlane,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	//virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;
	virtual Acad::ErrorStatus extend(double newParam);
	virtual Acad::ErrorStatus extend(Adesk::Boolean extendStart,const AcGePoint3d& toPoint);
	virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray& stretchPoints) const;
	virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset);
	virtual  Acad::ErrorStatus subGetSubentPathsAtGsMarker(
		AcDb::SubentType       type,
		Adesk::GsMarker        gsMark,
		const AcGePoint3d&     pickPoint,
		const AcGeMatrix3d&    viewXform,
		int&                   numPaths,
		AcDbFullSubentPath*&   subentPaths,
		int                    numInserts = 0,
		AcDbObjectId*          entAndInsertStack
		= nullptr) const;

#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
public:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
	//virtual void subViewportDraw(AcGiViewportDraw* pVd);
#else
protected:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	//virtual void subViewportDraw(AcGiViewportDraw* pVd);
#endif
private:
	//AcDbCurve *m_pCurve;
	AcDbPolyline *m_pPolyline;
};

/**
 * @brief CusEntity03
 * Show block-reference in subWorldDraw
 */
class CusEntity03 : public AcDbPolyline
{
public:
	ACRX_DECLARE_MEMBERS(CusEntity03);

	CusEntity03();
	CusEntity03(AcGePoint3d ptPos ,AcDbObjectId blkRecId);
	~CusEntity03();

#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
public:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* wd);
#else
protected:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
#endif
private:
	AcGePoint3d m_ptPos;
	AcDbObjectId m_blkRecId;
};
#if 0
class
	//#ifdef _LBAZOBJECT_
	//	__declspec(dllexport)
	//#else
	//	__declspec(dllimport)
	//#endif 
LbCusPolyline : public AcDbCurve
{
public:
	// Constructor / Destructor
	ACRX_DECLARE_MEMBERS(LbCusPolyline);
	//LB_DYNAMIC_CAST(LbCusPolyline);

	LbCusPolyline();
	virtual ~LbCusPolyline();

	virtual Acad::ErrorStatus	setStartPoint(const AcGePoint3d&);
	virtual Acad::ErrorStatus	setEndPoint(const AcGePoint3d&);
	virtual AcGePoint3d         startPoint() const;
	virtual AcGePoint3d         endPoint() const;
	virtual AcGeVector3d GetNormal() const;
	virtual void SetNormal(AcGeVector3d vecNormal);
	virtual double GetBulge() const;
	virtual void    SetBulge(double dBulge);
	const AcDbPolyline& GetPoly() const;
public:
	virtual Adesk::Boolean isClosed() const;  // Added for test

	// Get planar and start/end geometric properties.
	virtual Acad::ErrorStatus getStartPoint(AcGePoint3d&) const;
	virtual Acad::ErrorStatus getEndPoint(AcGePoint3d&) const;
	virtual Acad::ErrorStatus getStartParam(double& x0) const;
	virtual Acad::ErrorStatus getEndParam(double& x0) const;

	// Derivative information.
	virtual Acad::ErrorStatus getFirstDeriv(double param, AcGeVector3d& firstDeriv) const;
	virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d& x0, AcGeVector3d& firstDeriv) const;
	virtual Acad::ErrorStatus getSecondDeriv(double param, AcGeVector3d& secDeriv) const;
	virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d& x0, AcGeVector3d& secDeriv) const;

	// Conversions to/from parametric/world/distance.
	virtual Acad::ErrorStatus getPointAtParam(double x0, AcGePoint3d& x1) const;
	virtual Acad::ErrorStatus getPointAtDist(double x0, AcGePoint3d& x1) const;
	virtual Acad::ErrorStatus getParamAtDist(double dist, double& param) const;
	virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d& x0, double& x1)const;
	virtual Acad::ErrorStatus getDistAtParam(double param, double& dist) const;
	virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d& x0, double& x1)const;

	// Closest point on curve.
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, AcGePoint3d& pointOnCurve, Adesk::Boolean extend = Adesk::kFalse) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt, AcGePoint3d& pointOnCurve, Adesk::Boolean extend = Adesk::kFalse) const;

	// Get offset, spline and split copies of the curve.
	virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist, AcDbVoidPtrArray& offsetCurves) const;
	virtual Acad::ErrorStatus getOffsetCurves(double offsetDist, AcDbVoidPtrArray& offsetCurves) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray& points, AcDbVoidPtrArray& curveSegments) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray& params, AcDbVoidPtrArray& curveSegments) const;

	// Get a projected copy of the curve.
	virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane& plane, const AcGeVector3d& projDir, AcDbCurve*& projectedCurve) const;

	virtual Acad::ErrorStatus extend(double newParam);
	virtual Acad::ErrorStatus extend(Adesk::Boolean extendStart, const AcGePoint3d& toPoint);
public:
	// filing
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
#if (defined(ARX) && ARX < 2010) || (defined(ZRX) && ZRX < 2021)
public:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	virtual Acad::ErrorStatus subIntersectWith(
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		const AcGePlane& projPlane,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	virtual Acad::ErrorStatus subIntersectWith(
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const;
	virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray& stretchPoints) const;
	virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;
	virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices, const AcGeVector3d& offset);
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices, const AcGeVector3d& offset);
	virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d& pickPoint,
		const AcGePoint3d& lastPoint,
		const AcGeMatrix3d& viewXform,
		AcGePoint3dArray& snapPoints,
		AcDbIntArray& geomIds) const;
	virtual void subList() const;
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const;
#else
protected:
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	virtual Acad::ErrorStatus subIntersectWith(
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		const AcGePlane& projPlane,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	virtual Acad::ErrorStatus subIntersectWith(
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) const;
	virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const;
	virtual Acad::ErrorStatus subGetStretchPoints(AcGePoint3dArray& stretchPoints) const;
	virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;
	virtual Acad::ErrorStatus subMoveStretchPointsAt(const AcDbIntArray& indices, const AcGeVector3d& offset);
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices, const AcGeVector3d& offset);
	virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d& pickPoint,
		const AcGePoint3d& lastPoint,
		const AcGeMatrix3d& viewXform,
		AcGePoint3dArray& snapPoints,
		AcDbIntArray& geomIds) const;
	virtual void subList() const;
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const;
#endif
protected:
	AcDbPolyline m_pPolyline;
	Acad::ErrorStatus getAzPolyGripPoints_2d(AcGePoint3dArray&  gripPoints)const;
	Acad::ErrorStatus moveGripPointsAt_2d(const AcDbIntArray& indices, const AcGeVector3d& offset);
private:
	void *operator new[](size_t nSize) { return 0; }
	void operator delete[](void *p) {};
	void *operator new[](size_t nSize, const TCHAR *file, int line) { return 0; }

};
#endif




#endif /*_CUSENTITIES_H_*/