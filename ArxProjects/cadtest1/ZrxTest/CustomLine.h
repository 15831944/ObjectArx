#pragma once

#include "dbents.h"

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

class SubCustomLine : public CustomLine
{
public:
	ACRX_DECLARE_MEMBERS(SubCustomLine);
	SubCustomLine() {}
	virtual ~SubCustomLine();
};


void CreateCustomLineInZrxTest(); 
