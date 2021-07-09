//
#include "pch.h"
#include "CustomLine.h"
#include "rxboiler.h"
#include "dbproxy.h"

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

Acad::ErrorStatus AppendToModalSpace(AcDbDatabase* db, AcDbEntity* ent, AcDbObjectId& oid)
{
	if (!db)
		return Acad::eNoDatabase;
	if (!ent)
		return Acad::eNullObjectPointer;

	Acad::ErrorStatus stats = Acad::eOk;
	AcDbBlockTable* pBlockTable = NULL;
	stats = db->getBlockTable(pBlockTable, AcDb::kForRead);
	if (pBlockTable)
	{
		AcDbBlockTableRecord* pBTR = NULL;
		stats = pBlockTable->getAt(ACDB_MODEL_SPACE, pBTR, AcDb::kForWrite);
		pBlockTable->close();
		pBlockTable = NULL;
		if (pBTR)
		{
			stats = pBTR->appendAcDbEntity(oid, ent);
			pBTR->close();
		}
	}
	return stats;
}


ACRX_DXF_DEFINE_MEMBERS(SubCustomLine, CustomLine, AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, AcDbProxyEntity::kAllAllowedBits, SubCustomLine, "CustomLine")

SubCustomLine:: ~SubCustomLine()
{

}


void CreateCustomLineInZrxTest()
{
	ads_point pt1, pt2;
	if (RTNORM == acedGetPoint(NULL, L"Start Point:", pt1))
	{
		if (RTNORM == acedGetPoint(pt1, L"End Point:", pt2))
		{
			//CustomLine *pCusLine = new CustomLine(AcGePoint3d(100, 100, 0), AcGePoint3d(600, 100, 0));
			CustomLine *pCusLine = new CustomLine(AcGePoint3d(pt1[X], pt1[Y], 0), AcGePoint3d(pt2[X], pt2[Y], 0));
			AcDbObjectId id;
			AppendToModalSpace(curDoc()->database(), pCusLine, id);
			pCusLine->close();
		}
	}
}