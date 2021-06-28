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
	AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_highlightOverrule);
	AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_highlightOverrule);
	AcRxOverrule::setIsOverruling(false);

	if (s_g_highlightOverrule)
	{
		delete s_g_highlightOverrule;
		s_g_highlightOverrule = nullptr;
	}

	acutPrintf(_T("\nHighlightOverrule is OFF..."));
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
	AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_highlightStateOverrule);
	AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_highlightStateOverrule);
	AcRxOverrule::setIsOverruling(false);

	if (s_g_highlightStateOverrule)
	{
		delete s_g_highlightStateOverrule;
		s_g_highlightStateOverrule = nullptr;
	}

	acutPrintf(_T("\nHighlightStateOverrule is OFF..."));
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

// 如果未覆盖subCloneMeForDragging接口，将从dwginFileds取克隆数据
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
	CustomLine *pCusLine = new CustomLine(AcGePoint3d(100, 100, 0), AcGePoint3d(600, 100, 0));
	AcDbObjectId id;
	CADUtils::AppendToModalSpace(pCusLine, id);
	pCusLine->close();
}
#pragma endregion