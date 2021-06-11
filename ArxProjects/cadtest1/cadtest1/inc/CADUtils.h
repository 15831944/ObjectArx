#pragma once
class CADUtils
{
public:
    CADUtils();
    virtual ~CADUtils();

public:
    static AcDbDatabase* curDwg();
    static Acad::ErrorStatus AppendToModalSpace(AcDbEntity* ent, AcDbObjectId& oid);
	static Acad::ErrorStatus AppendToModalSpace(AcDbDatabase* db, AcDbEntity* ent, AcDbObjectId& oid);
	static Acad::ErrorStatus AppendToPaperSpace(AcDbEntity* ent, AcDbObjectId& oid);
	static Acad::ErrorStatus AppendToPaperSpace(AcDbDatabase* db, AcDbEntity* ent, AcDbObjectId& oid);
	static Acad::ErrorStatus AppendToCurrentSpace(AcDbEntity* ent, AcDbObjectId& oid);

	static Acad::ErrorStatus AppendToBTR(AcDbBlockTableRecord* btr, AcDbEntity* ent, AcDbObjectId& oid);
	static Acad::ErrorStatus AppendToBTR(AcDbObjectId btrId, AcDbEntity* ent, AcDbObjectId& oid);

public:
	static int SelectEntity(LPCTSTR text, AcDbObjectId& entId);
	static int SelectEntity(LPCTSTR text, AcDbObjectId& entId, AcGePoint3d& pt);
	static int SelectEntities(LPCTSTR text, AcDbObjectIdArray& entIdArray);
	static int GetPoint(LPCTSTR text, AcGePoint3d& pt);
	static int GetPoint(LPCTSTR text, const AcGePoint3d& ptbase, AcGePoint3d& pt);

public:
	static AcDbLine* NewDbLine(const AcGePoint3d& s, const AcGePoint3d& e);
	static AcDbCircle* NewDbCircle(const AcGePoint3d& cen, double rad);
	static AcDbPolyline* NewDbPolyline(const AcGePoint2dArray& pts, bool closed);
	static AcDbPolyline* NewDbPolyline(const AcGePoint3dArray& pts, bool closed);
	static AcDbPolyline* NewDbRectangle(const AcGePoint3d& ll, const AcGePoint3d& ur);

//////////////////////////////////////////////////////////////////////////
public:
	static AcDbExtents GetExtentsInModalSpace();
	static  Acad::ErrorStatus GetBlockRecordId(AcDbDatabase *pDb, TCHAR *szBlkName, AcDbObjectId &blkRecId);
};

