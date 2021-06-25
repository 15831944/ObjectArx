//
#if _MSC_VER > 1000 
#pragma once
#endif

#ifndef _OVERRULETEST_H_	
#define _OVERRULETEST_H_	

#include "dbents.h"
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

class CustomLine : public AcDbEntity
{
public:
	ACRX_DECLARE_MEMBERS(CustomLine);
	CustomLine() {}
	CustomLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);
	virtual ~CustomLine();

	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* pWd);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset);
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d& pickPoint,
		const AcGePoint3d& lastPoint,
		const AcGeMatrix3d& viewXform,
		AcGePoint3dArray& snapPoints,
		AcDbIntArray & geomIds) const;

    inline double length() const { return m_ptStart.distanceTo(m_ptEnd); }

	Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform);
	Acad::ErrorStatus subGetTransformedCopy(const AcGeMatrix3d& xform, AcDbEntity*& pEnt) const;

	virtual Adesk::Boolean subCloneMeForDragging() override;
	virtual bool subHideMeForDragging() const override;

	AcGePoint3d m_ptStart;
	AcGePoint3d m_ptEnd;
};



#endif  /* _OVERRULETEST_H_ */
