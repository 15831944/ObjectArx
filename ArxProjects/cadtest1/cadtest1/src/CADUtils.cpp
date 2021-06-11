#include "StdAfx.h"
#include "CADUtils.h"
#include "dbapserv.h"
#include "migrtion.h"
#include "aced.h"
#include "adscodes.h"
#include "dbpl.h"

CADUtils::CADUtils()
{
}


CADUtils::~CADUtils()
{
}

AcDbDatabase* CADUtils::curDwg()
{
    return acdbCurDwg();
}

Acad::ErrorStatus CADUtils::AppendToModalSpace(AcDbEntity* ent, AcDbObjectId& oid)
{
    return AppendToModalSpace(curDwg(), ent, oid);
}

Acad::ErrorStatus CADUtils::AppendToModalSpace(AcDbDatabase* db, AcDbEntity* ent, AcDbObjectId& oid)
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

Acad::ErrorStatus CADUtils::AppendToPaperSpace(AcDbEntity * ent, AcDbObjectId & oid)
{
	return AppendToPaperSpace(curDwg(), ent, oid);
}

Acad::ErrorStatus CADUtils::AppendToPaperSpace(AcDbDatabase * db, AcDbEntity * ent, AcDbObjectId & oid)
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
		stats = pBlockTable->getAt(ACDB_PAPER_SPACE, pBTR, AcDb::kForWrite);
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

Acad::ErrorStatus CADUtils::AppendToCurrentSpace(AcDbEntity * ent, AcDbObjectId & oid)
{
	if (curDwg() && curDwg()->tilemode())
	{
		return AppendToModalSpace(ent, oid);
	}
	else
	{
		return AppendToPaperSpace(ent, oid);
	}
}

Acad::ErrorStatus CADUtils::AppendToBTR(AcDbBlockTableRecord * btr, AcDbEntity * ent, AcDbObjectId & oid)
{
	Acad::ErrorStatus stats = Acad::eOk;
	if (btr)
	{
		stats = btr->appendAcDbEntity(oid, ent);
	}
	return stats;
}

Acad::ErrorStatus CADUtils::AppendToBTR(AcDbObjectId btrId, AcDbEntity * ent, AcDbObjectId & oid)
{
	Acad::ErrorStatus stats = Acad::eOk;
	AcDbBlockTableRecord* btr = NULL;
	stats = acdbOpenObject(btr, btrId, AcDb::kForWrite);
	if (btr)
	{
		stats = btr->appendAcDbEntity(oid, ent);
		btr->close();
	}
	return stats;
}



int CADUtils::SelectEntity(LPCTSTR text, AcDbObjectId & entId)
{
	AcGePoint3d pt;
	return SelectEntity(text, entId, pt);
}

int CADUtils::SelectEntity(LPCTSTR text, AcDbObjectId & entId, AcGePoint3d & pt)
{
	ads_name ent;
	ads_point ptres;
	int ret = acedEntSel(text, ent, ptres);
	if (ret == RTNORM)
	{
		acdbGetObjectId(entId, ent);
		pt = asPnt3d(ptres);
	}
	return ret;
}

int CADUtils::SelectEntities(LPCTSTR text, AcDbObjectIdArray & entIdArray)
{
	ads_name ss;
	int ret = acedSSGet(NULL, NULL, NULL, NULL, ss);
	if (ret == RTNORM)
	{
#if ARX>2013 || ZRX > 2020
		Adesk::Int32 len = 0;
#else
		long len = 0;
#endif
		acedSSLength(ss, &len);
		for (int i = 0; i < len; i++)
		{
			ads_name ent;
			AcDbObjectId entId;
			acedSSName(ss, i, ent);
			acdbGetObjectId(entId, ent);
			if (entId.isValid())
			{
				entIdArray.append(entId);
			}
		}
		acedSSFree(ss);
	}
	return ret;
}

int CADUtils::GetPoint(LPCTSTR text, AcGePoint3d & pt)
{
	return acedGetPoint(NULL, text, asDblArray(pt));
}

int CADUtils::GetPoint(LPCTSTR text, const AcGePoint3d & ptbase, AcGePoint3d & pt)
{
	return acedGetPoint(asDblArray(ptbase), text, asDblArray(pt));
}

AcDbLine * CADUtils::NewDbLine(const AcGePoint3d & s, const AcGePoint3d & e)
{
	AcDbLine* line = new AcDbLine(s, e);
	return line;
}

AcDbCircle * CADUtils::NewDbCircle(const AcGePoint3d & cen, double rad)
{
	AcDbCircle* circle = new AcDbCircle(cen, AcGeVector3d::kZAxis, rad);
	return circle;
}

AcDbPolyline * CADUtils::NewDbPolyline(const AcGePoint2dArray & pts, bool closed)
{
	AcDbPolyline* polyline = new AcDbPolyline();
	for (int i = 0; i < pts.length(); i++)
	{
		polyline->addVertexAt(i, pts[i]);
	}
	if (closed)
		polyline->setClosed(closed);
	return polyline;
}

AcDbPolyline * CADUtils::NewDbPolyline(const AcGePoint3dArray & pts, bool closed)
{
	AcDbPolyline* polyline = new AcDbPolyline();
	for (int i = 0; i < pts.length(); i++)
	{
		AcGePoint2d pt = AcGePoint2d(pts[i].x, pts[i].y);
		polyline->addVertexAt(i, pt);
	}
	if (closed)
		polyline->setClosed(closed);
	return polyline;
}

AcDbPolyline * CADUtils::NewDbRectangle(const AcGePoint3d & ll, const AcGePoint3d & ur)
{
	AcGePoint2d pt1, pt2, pt3, pt4;
	if (ll.x < ur.x)
	{
		pt1.x = ll.x;
		pt2.x = ur.x;
		pt3.x = ur.x;
		pt4.x = ll.x;
	}
	else
	{
		pt1.x = ur.x;
		pt2.x = ll.x;
		pt3.x = ll.x;
		pt4.x = ur.x;
	}
	if (ll.y < ur.y)
	{
		pt1.y = ll.y;
		pt2.y = ll.y;
		pt3.y = ur.y;
		pt4.y = ur.y;
	}
	else
	{
		pt1.y = ur.y;
		pt2.y = ur.y;
		pt3.y = ll.y;
		pt4.y = ll.y;
	}

	AcDbPolyline* polyline = new AcDbPolyline();
	polyline->addVertexAt(0, pt1);
	polyline->addVertexAt(1, pt2);
	polyline->addVertexAt(2, pt3);
	polyline->addVertexAt(3, pt4);
	polyline->setClosed(true);

	return polyline;
}


//////////////////////////////////////////////////////////////////////////

AcDbExtents CADUtils::GetExtentsInModalSpace()
{
	AcDbExtents extRet;
	Acad::ErrorStatus es;
	AcDbBlockTable *pBlkTbl = nullptr;
	es = acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlkTbl, AcDb::kForRead);
	if (es != Acad::eOk)
		return extRet;

	AcDbBlockTableRecord *pBlkTblRcd = nullptr;
	pBlkTbl->getAt(ACDB_MODEL_SPACE, pBlkTblRcd, AcDb::kForRead);
	if (es != Acad::eOk || pBlkTblRcd == nullptr)
		return extRet;

	AcDbBlockTableRecordIterator *iter = nullptr;
	es = pBlkTblRcd->newIterator(iter);
	for (iter->start(); !iter->done(); iter->step())
	{
		AcDbExtents ext;
		AcDbEntity *pEntity = NULL;
		if (iter->getEntity(pEntity, AcDb::kForRead) != Acad::eOk)
			continue;
		pEntity->close();

		if (pEntity->getGeomExtents(ext) != Acad::eOk)
			continue;

		extRet.addExt(ext);
	}
	delete iter;
	iter = nullptr;

	pBlkTbl->close();
	pBlkTblRcd->close();

	return extRet;
}

 Acad::ErrorStatus CADUtils::GetBlockRecordId(AcDbDatabase *pDb, TCHAR *szBlkName, AcDbObjectId &blkRecId)
{
	Acad::ErrorStatus es;
	AcDbBlockTable *pBlkTbl = nullptr;

	es = pDb->getBlockTable(pBlkTbl, AcDb::kForRead);
	pBlkTbl->close();
	if (es != Acad::eOk)
		return es;

	return pBlkTbl->getAt(szBlkName, blkRecId);
}


