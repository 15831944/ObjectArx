//
#if _MSC_VER > 1000 
#pragma once
#endif

#ifndef _OVERRULETEST_H_	
#define _OVERRULETEST_H_	

#include "dbents.h"

#if ARX == 2020 || ZRX == 2021
#include "dbentityoverrule.h"

class HighlightOverrule : public AcDbHighlightOverrule
{
public:
	virtual Acad::ErrorStatus highlight(
		const AcDbEntity*      pSubject,
		const AcDbFullSubentPath& subId = kNullSubent,
		const Adesk::Boolean highlightAll = false) ADESK_OVERRIDE; 

	virtual Acad::ErrorStatus unhighlight(
		const AcDbEntity*      pSubject,
		const AcDbFullSubentPath& subId = kNullSubent,
		const Adesk::Boolean highlightAll = false) ADESK_OVERRIDE;

	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const ADESK_OVERRIDE;
};

class HighlightStateOverrule : public AcDbHighlightStateOverrule
{
public:
	virtual Acad::ErrorStatus pushHighlight(AcDbEntity* pSubject, const AcDbFullSubentPath& subId, AcGiHighlightStyle highlightStyle) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus popHighlight(AcDbEntity* pSubject, const AcDbFullSubentPath& subId) ADESK_OVERRIDE;
	virtual AcGiHighlightStyle highlightState(AcDbEntity* pSubject, const AcDbFullSubentPath& subId) ADESK_OVERRIDE;
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const ADESK_OVERRIDE;
};

class VisibilityOverrule : public AcDbVisibilityOverrule
{
public:
	virtual AcDb::Visibility visibility(const AcDbEntity* pSubject) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus setVisibility(AcDbEntity* pSubject, AcDb::Visibility newVal, Adesk::Boolean doSubents = true) ADESK_OVERRIDE;
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const ADESK_OVERRIDE;
};

class GeometryOverrule : public AcDbGeometryOverrule
{
public:
	virtual  Acad::ErrorStatus intersectWith(
		const AcDbEntity* pSubject,
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) ADESK_OVERRIDE;
	virtual  Acad::ErrorStatus intersectWith(
		const AcDbEntity* pSubject,
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		const AcGePlane& projPlane,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0) ADESK_OVERRIDE;
	virtual  Acad::ErrorStatus getGeomExtents(const AcDbEntity* pSubject, AcDbExtents& extents) ADESK_OVERRIDE;
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const ADESK_OVERRIDE;
};

class SubentityOverrule : public AcDbSubentityOverrule
{
public:
	virtual Acad::ErrorStatus addSubentPaths(AcDbEntity* pSubject, const AcDbFullSubentPathArray& newPaths) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus deleteSubentPaths(AcDbEntity* pSubject, const AcDbFullSubentPathArray& paths) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus transformSubentPathsBy(AcDbEntity* pSubject, const AcDbFullSubentPathArray& paths, const AcGeMatrix3d& xform) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus getGripPointsAtSubentPath(
		const AcDbEntity* pSubject,
		const AcDbFullSubentPath& path,
		AcDbGripDataPtrArray& grips,
		const double curViewUnitSize,
		const int gripSize,
		const AcGeVector3d& curViewDir,
		const int bitflags) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus moveGripPointsAtSubentPaths(
		AcDbEntity* pSubject,
		const AcDbFullSubentPathArray& paths,
		const AcDbVoidPtrArray& gripAppData,
		const AcGeVector3d& offset,
		const int bitflags) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus getSubentPathsAtGsMarker(
		const AcDbEntity* pSubject,
		AcDb::SubentType type,
		Adesk::GsMarker gsMark,
		const AcGePoint3d& pickPoint,
		const AcGeMatrix3d& viewXform,
		int& numPaths, AcDbFullSubentPath*& subentPaths,
		int numInserts = 0,
		AcDbObjectId* entAndInsertStack = NULL) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus getGsMarkersAtSubentPath(
		const AcDbEntity* pSubject,
		const AcDbFullSubentPath& subPath,
		AcArray<Adesk::GsMarker>& gsMarkers) ADESK_OVERRIDE;
	virtual AcDbEntity* subentPtr(const AcDbEntity* pSubject, const AcDbFullSubentPath& id) ADESK_OVERRIDE;
	virtual void subentGripStatus(AcDbEntity* pSubject, const AcDb::GripStat status, const AcDbFullSubentPath& subentity) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus getCompoundObjectTransform(const AcDbEntity* pSubject, AcGeMatrix3d & xMat) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus getSubentPathGeomExtents(const AcDbEntity* pSubject, const AcDbFullSubentPath& path, AcDbExtents& extents) ADESK_OVERRIDE;
	virtual Acad::ErrorStatus getSubentClassId(const AcDbEntity* pSubject, const AcDbFullSubentPath& path, CLSID* clsId) ADESK_OVERRIDE;
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const ADESK_OVERRIDE;
};

#endif


#if ZRX == 2020 || ARX == 2013
#define subWorldDraw worldDraw
#define subViewportDraw viewportDraw
#define subGetGripPoints getGripPoints
#define subMoveGripPointsAt moveGripPointsAt
#define subGetOsnapPoints getOsnapPoints
#define subTransformBy transformBy
#endif

class CustomLine : public AcDbEntity
{
public:
	ACRX_DECLARE_MEMBERS(CustomLine);
	CustomLine() {}
	CustomLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);
	virtual ~CustomLine();

	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const; 
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset);
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d& pickPoint,
		const AcGePoint3d& lastPoint,
		const AcGeMatrix3d& viewXform,
		AcGePoint3dArray& snapPoints,
		AcDbIntArray & geomIds) const;
	virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform);

public:
    inline double length() const { return m_ptStart.distanceTo(m_ptEnd); }
private:
	AcGePoint3d m_ptStart;
	AcGePoint3d m_ptEnd;
};


#endif  /* _OVERRULETEST_H_ */
