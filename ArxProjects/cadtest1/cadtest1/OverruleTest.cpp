//
#include "stdafx.h"
#include "OverruleTest.h"

#include "dbproxy.h"

#if ARX == 2020 || ZRX == 2021

#pragma region  HighlightOverrule
Acad::ErrorStatus HighlightOverrule::highlight(
	const AcDbEntity*      pSubject,
	const AcDbFullSubentPath& subId/* = kNullSubent*/,
	const Adesk::Boolean highlightAll/* = false*/)
{
	if (isApplicable(pSubject))
	{
		if (pSubject->isKindOf(AcDbLine::desc()))
		{
			acutPrintf(_T("\nAcDbLine highlight invalid..."));
			return Acad::eInvalidInput;
		}
		else if (pSubject->isKindOf(AcDbCircle::desc()))
		{
			acutPrintf(_T("\nAcDbCircle highlight..."));
		}
	}

	return AcDbHighlightOverrule::highlight(pSubject, subId, highlightAll);
}

Acad::ErrorStatus HighlightOverrule::unhighlight(
	const AcDbEntity*      pSubject,
	const AcDbFullSubentPath& subId /*= kNullSubent*/,
	const Adesk::Boolean highlightAll /*= false*/)
{
	if (isApplicable(pSubject))
	{
		if (pSubject->isKindOf(AcDbLine::desc()))
		{
			acutPrintf(_T("\nAcDbLine unhighlight..."));
		}
		else if (pSubject->isKindOf(AcDbCircle::desc()))
		{
			acutPrintf(_T("\nAcDbCircle unhighlight invalid..."));
			return Acad::eInvalidInput;
		}
	}

	return AcDbHighlightOverrule::unhighlight(pSubject, subId, highlightAll);
}

bool HighlightOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbLine::desc()) || pOverruledSubject->isKindOf(AcDbCircle::desc());
}

static HighlightOverrule* s_g_highlightOverrule = nullptr;
ARXCMD3(HighlightOverruleTest)
{
	if (!s_g_highlightOverrule)
	{
		acutPrintf(_T("\nHighlightOverrule is ON..."));
		s_g_highlightOverrule = new HighlightOverrule;
		AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_highlightOverrule);
		AcRxOverrule::addOverrule(AcDbCircle::desc(), s_g_highlightOverrule);
		AcRxOverrule::setIsOverruling(true);
	}
	else
	{
		acutPrintf(_T("\nHighlightOverrule is OFF..."));
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_highlightOverrule);
		AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_highlightOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_highlightOverrule;
		s_g_highlightOverrule = nullptr;
	}
}

ARXCMD3(removeHighlightOverrule)
{
	if (s_g_highlightOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_highlightOverrule);
		AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_highlightOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_highlightOverrule;
		s_g_highlightOverrule = nullptr;

		acutPrintf(_T("\nHighlightOverrule is OFF..."));
	}
}
ARXCMD3(addHighlightOverrule)
{
	removeHighlightOverrule();

	s_g_highlightOverrule = new HighlightOverrule;
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_highlightOverrule);
	AcRxOverrule::addOverrule(AcDbCircle::desc(), s_g_highlightOverrule);
	AcRxOverrule::setIsOverruling(true);

	acutPrintf(_T("\nHighlightOverrule is ON..."));
}

#pragma endregion 

#pragma region HighlightStateOverrule

Acad::ErrorStatus HighlightStateOverrule::pushHighlight(AcDbEntity* pSubject, const AcDbFullSubentPath& subId, AcGiHighlightStyle highlightStyle)
{
	acutPrintf(_T("\nHighlightStateOverrule::pushHighlight"));
	return AcDbHighlightStateOverrule::pushHighlight(pSubject, subId, highlightStyle);
}

Acad::ErrorStatus HighlightStateOverrule::popHighlight(AcDbEntity* pSubject, const AcDbFullSubentPath& subId)
{
	acutPrintf(_T("\nHighlightStateOverrule::popHighlight"));
	return AcDbHighlightStateOverrule::popHighlight(pSubject, subId);
}

AcGiHighlightStyle HighlightStateOverrule::highlightState(AcDbEntity* pSubject, const AcDbFullSubentPath& subId)
{
	acutPrintf(_T("\nHighlightStateOverrule::highlightState"));
	return AcDbHighlightStateOverrule::highlightState(pSubject, subId);
}

bool HighlightStateOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbLine::desc()) || pOverruledSubject->isKindOf(AcDbCircle::desc());
}

static HighlightStateOverrule* s_g_highlightStateOverrule = nullptr;
ARXCMD3(removeHighlightStateOverrule)
{
	if (s_g_highlightStateOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_highlightStateOverrule);
		AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_highlightStateOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_highlightStateOverrule;
		s_g_highlightStateOverrule = nullptr;

		acutPrintf(_T("\nHighlightStateOverrule is OFF..."));
	}
}
ARXCMD3(addHighlightStateOverrule)
{
	removeHighlightStateOverrule();

	s_g_highlightStateOverrule = new HighlightStateOverrule;
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_highlightStateOverrule);
	AcRxOverrule::addOverrule(AcDbCircle::desc(), s_g_highlightStateOverrule);
	AcRxOverrule::setIsOverruling(true);

	acutPrintf(_T("\nHighlightStateOverrule is ON..."));
}

#pragma endregion

#pragma region VisibilityOverrule

AcDb::Visibility VisibilityOverrule::visibility(const AcDbEntity* pSubject)
{
	acutPrintf(_T("\nVisibilityOverrule::visibility<pSubject: %s>..."), pSubject->isA()->name());
	return AcDbVisibilityOverrule::visibility(pSubject);
}

Acad::ErrorStatus VisibilityOverrule::setVisibility(AcDbEntity* pSubject, AcDb::Visibility newVal, Adesk::Boolean doSubents/* = true*/)
{
	acutPrintf(_T("\nVisibilityOverrule::setVisibility<pSubject: %s>..."), pSubject->isA()->name());

	// ??????????kInvisible
	if (pSubject->isKindOf(AcDbCircle::desc()) || pSubject->isKindOf(CustomLine::desc()))
		return AcDbVisibilityOverrule::setVisibility(pSubject, AcDb::kInvisible, doSubents);

	return AcDbVisibilityOverrule::setVisibility(pSubject, newVal, doSubents);
}

bool VisibilityOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return true;
}

static VisibilityOverrule* s_g_visibilityOverrule = nullptr;
ARXCMD3(removeVisibilityOverrule)
{
	if (s_g_visibilityOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_visibilityOverrule);
		AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_visibilityOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_visibilityOverrule;
		s_g_visibilityOverrule = nullptr;

		acutPrintf(_T("\nVisibilityOverrule is OFF..."));
	}
}

ARXCMD3(addVisibilityOverrule)
{
	removeVisibilityOverrule();

	s_g_visibilityOverrule = new VisibilityOverrule;
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_visibilityOverrule);
	AcRxOverrule::addOverrule(AcDbCircle::desc(), s_g_visibilityOverrule);
	AcRxOverrule::setIsOverruling(true);

	acutPrintf(_T("\nVisibilityOverrule is ON..."));
}

#pragma endregion

#pragma region GeometryOverrule

Acad::ErrorStatus GeometryOverrule::intersectWith(
	const AcDbEntity* pSubject,
	const AcDbEntity* pEnt,
	AcDb::Intersect intType,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker/* = 0*/,
	Adesk::GsMarker otherGsMarker/* = 0*/)
{
	acutPrintf(_T("\nGeometryOverrule::intersectWith()<pSubject: %s>..."), pSubject->isA()->name());
	AcGePoint3dArray tmpPoints;
	Acad::ErrorStatus es/* = AcDbGeometryOverrule::intersectWith(pSubject, pEnt, intType, tmpPoints, thisGsMarker, otherGsMarker)*/;
	if (pSubject->isKindOf(AcDbLine::desc()))
	{
		AcGePoint3d pt1(50, 50, 0), pt2(100, 100, 0);
		points.append(pt1);
		points.append(pt2);
		acutPrintf(_T("\n<AcDbLine> Find %d Points"), points.length());
	}
	else if (pSubject->isKindOf(AcDbCircle::desc()))
	{
		AcGePoint3d pt(1, 1, 0);
		points.append(pt);
		acutPrintf(_T("\n<AcDbCircle> Find %d Points"), points.length());
	}
	else
	{
		AcGePoint3d pt(2, 2, 0);
		points.append(pt);
		acutPrintf(_T("\n<OtherType> Find %d Points"), points.length());
	}

	//return AcDbGeometryOverrule::intersectWith(pSubject, pEnt, intType, points, thisGsMarker, otherGsMarker);  // include real intersection and all intersection of the two entities
	return AcDbGeometryOverrule::intersectWith(pSubject, pEnt, intType, tmpPoints, thisGsMarker, otherGsMarker); 
}
Acad::ErrorStatus GeometryOverrule::intersectWith(
	const AcDbEntity* pSubject,
	const AcDbEntity* pEnt,
	AcDb::Intersect intType,
	const AcGePlane& projPlane,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker/* = 0*/,
	Adesk::GsMarker otherGsMarker/* = 0*/)
{
	acutPrintf(_T("\nGeometryOverrule::intersectWith(AcGePlane)<pSubject: %s>..."), pSubject->isA()->name());
	AcGePoint3dArray tmpPoints;

	if (pSubject->isKindOf(AcDbLine::desc()))
	{
		AcGePoint3d pt1(50, 50, 0), pt2(100, 100, 0);
		points.append(pt1);
		points.append(pt2);
		acutPrintf(_T("\n<AcDbLine> Find %d Points"), points.length());
	}
	else if (pSubject->isKindOf(AcDbCircle::desc()))
	{
		AcGePoint3d pt(1, 1, 0);
		points.append(pt);
		acutPrintf(_T("\n<AcDbCircle> Find %d Points"), points.length());
	}
	else
	{
		AcGePoint3d pt(2, 2, 0);
		points.append(pt);
		acutPrintf(_T("\n<OtherType> Find %d Points"), points.length());
	}

	return AcDbGeometryOverrule::intersectWith(pSubject, pEnt, intType, projPlane, tmpPoints, thisGsMarker, otherGsMarker);
}
Acad::ErrorStatus GeometryOverrule::getGeomExtents(const AcDbEntity* pSubject, AcDbExtents& extents)
{
	acutPrintf(_T("\nGeometryOverrule::getGeomExtents()<pSubject: %s>..."), pSubject->isA()->name());
	AcDbExtents extTemp; 

	if (pSubject->isKindOf(AcDbLine::desc()))
	{
		AcGePoint3d ptMax(100, 100, 0), ptMin(5, 5, 0);
		extents.addPoint(ptMax);
		extents.addPoint(ptMin);
		acutPrintf(_T("\nAcDbLine extents: (%g, %g)-->(%g, %g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
	}
	else if (pSubject->isKindOf(AcDbCircle::desc()))
	{
		AcGePoint3d ptMax(50, 50, 0), ptMin(0, 0, 0);
		extents.addPoint(ptMax);
		extents.addPoint(ptMin);
		acutPrintf(_T("\nAcDbCircle extents: (%g, %g)-->(%g, %g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
	}
	else
	{
		AcGePoint3d ptMax(20, 20, 0), ptMin(0, 0, 0);
		extents.addPoint(ptMax);
		extents.addPoint(ptMin);
		acutPrintf(_T("\nOtherType extents: (%g, %g)-->(%g, %g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
	}

	return AcDbGeometryOverrule::getGeomExtents(pSubject, extTemp);
}
bool GeometryOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return true;
}

static GeometryOverrule* s_g_geometryOverrule = nullptr;
ARXCMD3(removeGeometryOverrule)
{
	if (s_g_geometryOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_geometryOverrule);
		AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_geometryOverrule);
		AcRxOverrule::removeOverrule(AcDbPolyline::desc(), s_g_geometryOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_geometryOverrule;
		s_g_geometryOverrule = nullptr;

		acutPrintf(_T("\nGeometryOverrule is OFF..."));
	}
}
ARXCMD3(addGeometryOverrule)
{
	removeGeometryOverrule();

	s_g_geometryOverrule = new GeometryOverrule;
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_geometryOverrule);
	AcRxOverrule::addOverrule(AcDbCircle::desc(), s_g_geometryOverrule);
	AcRxOverrule::addOverrule(AcDbPolyline::desc(), s_g_geometryOverrule);
	AcRxOverrule::setIsOverruling(true);

	acutPrintf(_T("\nGeometryOverrule is ON..."));
}

#pragma endregion

#pragma region SubentityOverrule

Acad::ErrorStatus SubentityOverrule::addSubentPaths(AcDbEntity* pSubject, const AcDbFullSubentPathArray& newPaths)
{
	return AcDbSubentityOverrule::addSubentPaths(pSubject, newPaths);
}

Acad::ErrorStatus SubentityOverrule::deleteSubentPaths(AcDbEntity* pSubject, const AcDbFullSubentPathArray& paths)
{
	return AcDbSubentityOverrule::deleteSubentPaths(pSubject, paths);
}

Acad::ErrorStatus SubentityOverrule::transformSubentPathsBy(AcDbEntity* pSubject, const AcDbFullSubentPathArray& paths, const AcGeMatrix3d& xform)
{
	return AcDbSubentityOverrule::transformSubentPathsBy(pSubject, paths, xform);
}

Acad::ErrorStatus SubentityOverrule::getGripPointsAtSubentPath(
	const AcDbEntity* pSubject,
	const AcDbFullSubentPath& path,
	AcDbGripDataPtrArray& grips,
	const double curViewUnitSize,
	const int gripSize,
	const AcGeVector3d& curViewDir,
	const int bitflags)
{
	return AcDbSubentityOverrule::getGripPointsAtSubentPath(pSubject, path, grips, curViewUnitSize, gripSize, curViewDir, bitflags);
}

Acad::ErrorStatus SubentityOverrule::moveGripPointsAtSubentPaths(
	AcDbEntity* pSubject,
	const AcDbFullSubentPathArray& paths,
	const AcDbVoidPtrArray& gripAppData,
	const AcGeVector3d& offset,
	const int bitflags)
{
	return AcDbSubentityOverrule::moveGripPointsAtSubentPaths(pSubject, paths, gripAppData, offset, bitflags);
}

Acad::ErrorStatus SubentityOverrule::getSubentPathsAtGsMarker(
	const AcDbEntity* pSubject,
	AcDb::SubentType type,
	Adesk::GsMarker gsMark,
	const AcGePoint3d& pickPoint,
	const AcGeMatrix3d& viewXform,
	int& numPaths, 
	AcDbFullSubentPath*& subentPaths,
	int numInserts/* = 0*/,
	AcDbObjectId* entAndInsertStack/* = NULL*/)
{
	return AcDbSubentityOverrule::getSubentPathsAtGsMarker(pSubject, type, gsMark, pickPoint, viewXform, numPaths, subentPaths, numInserts, entAndInsertStack);
}

Acad::ErrorStatus SubentityOverrule::getGsMarkersAtSubentPath(
	const AcDbEntity* pSubject,
	const AcDbFullSubentPath& subPath,
	AcArray<Adesk::GsMarker>& gsMarkers)
{
	return AcDbSubentityOverrule::getGsMarkersAtSubentPath(pSubject, subPath, gsMarkers);
}

AcDbEntity* SubentityOverrule::subentPtr(const AcDbEntity* pSubject, const AcDbFullSubentPath& id)
{
	return AcDbSubentityOverrule::subentPtr(pSubject, id);
}

void SubentityOverrule::subentGripStatus(AcDbEntity* pSubject, const AcDb::GripStat status, const AcDbFullSubentPath& subentity)
{
	return AcDbSubentityOverrule::subentGripStatus(pSubject, status, subentity);
}

Acad::ErrorStatus SubentityOverrule::getCompoundObjectTransform(const AcDbEntity* pSubject, AcGeMatrix3d & xMat)
{
	return AcDbSubentityOverrule::getCompoundObjectTransform(pSubject, xMat);
}

Acad::ErrorStatus SubentityOverrule::getSubentPathGeomExtents(const AcDbEntity* pSubject, const AcDbFullSubentPath& path, AcDbExtents& extents)
{
	return AcDbSubentityOverrule::getSubentPathGeomExtents(pSubject, path, extents);
}

Acad::ErrorStatus SubentityOverrule::getSubentClassId(const AcDbEntity* pSubject, const AcDbFullSubentPath& path, CLSID* clsId)
{
	return AcDbSubentityOverrule::getSubentClassId(pSubject, path, clsId);
}

bool SubentityOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return true;
}

#pragma endregion

#endif

#pragma region CustomLine

ACRX_DXF_DEFINE_MEMBERS(CustomLine, AcDbEntity, AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, AcDbProxyEntity::kAllAllowedBits, CustomLine, "CustomLine")

CustomLine::CustomLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint)
	:m_ptStart(startPoint), m_ptEnd(endPoint)
{

}

CustomLine:: ~CustomLine()
{

}

Adesk::Boolean CustomLine::subWorldDraw(AcGiWorldDraw* pWd)
{
	assertReadEnabled();

	pWd->subEntityTraits().setColor(1);

	AcGePoint3d verts[2];
	verts[0] = m_ptStart;
	verts[1] = m_ptEnd;

	pWd->geometry().polyline(2, verts);

	return true;
}

Acad::ErrorStatus CustomLine::dwgInFields(AcDbDwgFiler* pFiler)
{
	assertWriteEnabled();

	Acad::ErrorStatus es = AcDbEntity::dwgInFields(pFiler);
	if (es != Acad::eOk)
		return es;

	pFiler->readPoint3d(&m_ptStart);
	pFiler->readPoint3d(&m_ptEnd);

	return pFiler->filerStatus();
}

Acad::ErrorStatus CustomLine::dwgOutFields(AcDbDwgFiler* pFiler) const
{
	assertReadEnabled();

	Acad::ErrorStatus es = AcDbEntity::dwgOutFields(pFiler);
	if (es != Acad::eOk)
		return es;

	pFiler->writePoint3d(m_ptStart);
	pFiler->writePoint3d(m_ptEnd);

	return pFiler->filerStatus();
}

Acad::ErrorStatus CustomLine::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const
{
	assertReadEnabled();

	gripPoints.removeAll();
	gripPoints.append(m_ptStart);
	gripPoints.append((m_ptStart / 2) + (m_ptEnd / 2).asVector());
	gripPoints.append(m_ptEnd);

	return Acad::eOk;
}

// ??????????subCloneMeForDragging??????????dwginFileds??????????
Acad::ErrorStatus CustomLine::subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset)
{
	assertWriteEnabled();

	if (indices.isEmpty())
		return Acad::eInvalidInput;

	if (offset.isZeroLength())
		return Acad::eOk;

	for (int i = 0; i < indices.length(); i++)
	{
		switch (indices[i])
		{
		case 0:
			m_ptStart += offset;
			break;
		case 1:
			m_ptStart += offset;
			m_ptEnd += offset;
			break;
		case 2:
			m_ptEnd += offset;
			break;
		default:
			break;
		}
	}

	return Acad::eOk;
}
Acad::ErrorStatus CustomLine::subGetOsnapPoints(
	AcDb::OsnapMode osnapMode,
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d& pickPoint,
	const AcGePoint3d& lastPoint,
	const AcGeMatrix3d& viewXform,
	AcGePoint3dArray& snapPoints,
	AcDbIntArray & geomIds) const
{
	assertReadEnabled();

	AcGeLine3d line(m_ptStart, m_ptEnd);
	AcGeLineSeg3d lnsg;
	lnsg.set(m_ptStart, m_ptEnd);

	switch (osnapMode)
	{
	case AcDb::kOsModeEnd:
		snapPoints.append(m_ptStart);
		snapPoints.append(m_ptEnd);
		break;
	case AcDb::kOsModeMid:
		snapPoints.append(m_ptStart + (m_ptEnd - m_ptStart) / 2);
		break;
	case AcDb::kOsModePerp:
		snapPoints.append(line.evalPoint(line.paramOf(lastPoint)));
		break;
	case AcDb::kOsModeNear:
		if (!m_ptStart.isEqualTo(m_ptEnd))
		{
			//getClosestPointTo()
			snapPoints.append(lnsg.projClosestPointTo(pickPoint, AcGeVector3d::kZAxis));
		}
		else
		{
			snapPoints.append(m_ptStart);
		}
		break;
	default:
		break;
	}

	return Acad::eOk;
}
Acad::ErrorStatus CustomLine::subTransformBy(const AcGeMatrix3d& xform)
{
	assertWriteEnabled();

	m_ptStart.transformBy(xform);
	m_ptEnd.transformBy(xform);

	return Acad::eOk;
}

REGISTER_OBJECT(CustomLine);
ARXCMD3(CustomLineCreate)
{
	ads_point pt1, pt2;
	if (RTNORM == acedGetPoint(NULL, L"Start Point:", pt1))
	{
		if (RTNORM == acedGetPoint(pt1, L"End Point:", pt2))
		{
			//CustomLine *pCusLine = new CustomLine(AcGePoint3d(100, 100, 0), AcGePoint3d(600, 100, 0));
			CustomLine *pCusLine = new CustomLine(AcGePoint3d(pt1[X], pt1[Y], 0), AcGePoint3d(pt2[X], pt2[Y], 0));
			AcDbObjectId id;
			CADUtils::AppendToModalSpace(pCusLine, id);
			pCusLine->close();
		}
	}
}
#pragma endregion