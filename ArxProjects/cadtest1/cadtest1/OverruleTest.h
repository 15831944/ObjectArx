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
