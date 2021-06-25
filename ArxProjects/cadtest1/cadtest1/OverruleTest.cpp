//
#include "stdafx.h"
#include "OverruleTest.h"

#pragma region  HighlightOverrule

Acad::ErrorStatus HighlightOverrule::highlight(
	const AcDbEntity*      pSubject,
	const AcDbFullSubentPath& subId/* = kNullSubent*/,
	const Adesk::Boolean highlightAll/* = false*/)
{
	acutPrintf(_T("\nHighlightOverrule::highlight"));

	if (isApplicable(pSubject))
	{
		if (pSubject->isKindOf(CustomLine::desc()))
		{
			acutPrintf(_T("\nCustomLine"));
		}
		else if (pSubject->isKindOf(AcDbCircle::desc()))
		{
			acutPrintf(_T("\nAcDbCircle"));
		}
	}

	acutPrintf(_T("\n"));

	return AcDbHighlightOverrule::highlight(pSubject, subId, highlightAll);
}

Acad::ErrorStatus HighlightOverrule::unhighlight(
	const AcDbEntity*      pSubject,
	const AcDbFullSubentPath& subId /*= kNullSubent*/,
	const Adesk::Boolean highlightAll /*= false*/)
{
	acutPrintf(_T("\nHighlightOverrule::unhighlight"));

	if (isApplicable(pSubject))
	{
		if (pSubject->isKindOf(CustomLine::desc()))
		{
			acutPrintf(_T("\nCustomLine"));
		}
		else if (pSubject->isKindOf(AcDbCircle::desc()))
		{
			acutPrintf(_T("\nAcDbCircle"));
		}
	}

	acutPrintf(_T("\n"));

	return AcDbHighlightOverrule::unhighlight(pSubject, subId, highlightAll);
}

bool HighlightOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbLine::desc());
}

static HighlightOverrule* m_HighlightOverrule;
ARXCMD3(removeHighlightOverrule)
{
	AcRxOverrule::removeOverrule(CustomLine::desc(), m_HighlightOverrule);
	AcRxOverrule::setIsOverruling(false);

	if (m_HighlightOverrule)
	{
		delete m_HighlightOverrule;
		m_HighlightOverrule = nullptr;
	}
}
ARXCMD3(addHighlightOverrule)
{
	removeHighlightOverrule();

	m_HighlightOverrule = new HighlightOverrule;
	AcRxOverrule::addOverrule(CustomLine::desc(), m_HighlightOverrule);
	AcRxOverrule::setIsOverruling(true);
}

ARXCMD3(CustomLine1)
{
	CustomLine *pCusLine = new CustomLine(AcGePoint3d(100, 100, 0), AcGePoint3d(600, 100, 0));
	AcDbObjectId id;
	CADUtils::AppendToModalSpace(pCusLine, id);
	pCusLine->close();
}

#pragma endregion 

#pragma region CustomLine

ACRX_DXF_DEFINE_MEMBERS(CustomLine, AcDbEntity, AcDb::kDHL_1012, AcDb::kMRelease0, 0, CustomLine, "CustomLine")

CustomLine::CustomLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint)
{
	m_ptStart = startPoint;
	m_ptEnd = endPoint;
}

CustomLine:: ~CustomLine()
{

}

Adesk::Boolean CustomLine::subWorldDraw(AcGiWorldDraw* pWd)
{
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

	if (pFiler->filerType() == AcDb::kWblockCloneFiler)
	{
		AcDbHardPointerId id;
		pFiler->readItem(&id);
	}

	pFiler->readPoint3d(&m_ptStart);
	pFiler->readPoint3d(&m_ptEnd);

	return pFiler->filerStatus();
}

Acad::ErrorStatus CustomLine::dwgOutFields(AcDbDwgFiler* pFiler)
{
	assertReadEnabled();

	Acad::ErrorStatus es = AcDbEntity::dwgOutFields(pFiler);
	if (es != Acad::eOk)
		return es;

	if (pFiler->filerType() == AcDb::kWblockCloneFiler)
	{
		pFiler->writeHardPointerId((AcDbHardPointerId)ownerId());
	}

	pFiler->writePoint3d(m_ptStart);
	pFiler->writePoint3d(m_ptEnd);

	return pFiler->filerStatus();
}
Acad::ErrorStatus CustomLine::subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds) const
{
	assertReadEnabled();

	gripPoints.append(m_ptStart);
	gripPoints.append(m_ptEnd);

	return Acad::eOk;
}
Acad::ErrorStatus CustomLine::subMoveGripPointsAt(const AcDbIntArray & indices, const AcGeVector3d& offset)
{
	assertReadEnabled();

	for (int i = 0; i < indices.length(); i++)
	{
		if (indices[i] == 0)
			m_ptStart += offset;
		else
			m_ptEnd += offset;
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

	return Acad::eOk;
}
Acad::ErrorStatus CustomLine::subTransformBy(const AcGeMatrix3d& xform)
{
	assertReadEnabled();
	assertWriteEnabled();

	m_ptStart.transformBy(xform);
	m_ptEnd.transformBy(xform);

	return Acad::eOk;
}
Acad::ErrorStatus CustomLine::subGetTransformedCopy(const AcGeMatrix3d& xform, AcDbEntity*& pEnt) const
{
	acutPrintf(_T("\nCustomLine::subGetTransformedCopy"));
	return Acad::eOk;
}
Adesk::Boolean CustomLine::subCloneMeForDragging() 
{
	acutPrintf(_T("\nCustomLine::subCloneMeForDragging"));
	return true;
}
bool CustomLine::subHideMeForDragging() const
{
	acutPrintf(_T("\nCustomLine::subHideMeForDragging"));
	return true;
}

REGISTER_OBJECT(CustomLine);
#pragma endregion