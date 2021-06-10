//
#pragma once

#ifdef SAMPLE_MODULE
#define DLLIMPEXP __declspec(dllexport)
#else
#define DLLIMPEXP
#endif

#include "dbmain.h"

class DLLIMPEXP Ccross : public AcDbEntity 
{

public:
	ACRX_DECLARE_MEMBERS(Ccross) ;

protected:
	static Adesk::UInt32 kCurrentVersionNumber ;

public:
	Ccross () ;
	Ccross (const AcGePoint3d& pt);
	virtual ~Ccross () ;

	//----- AcDbObject protocols
	//- Dwg Filing protocol
	virtual Acad::ErrorStatus dwgOutFields (AcDbDwgFiler *pFiler) const ;
	virtual Acad::ErrorStatus dwgInFields (AcDbDwgFiler *pFiler) ;

	virtual Acad::ErrorStatus getOsnapPoints(
		AcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray& snapPoints,
		AcDbIntArray& geomIds) const;

	//----- AcDbEntity protocols
	virtual Acad::ErrorStatus intersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType, AcGePoint3dArray& points, int thisGsMarker, int otherGsMarker) const;

	//- Graphics protocol
	virtual Adesk::Boolean worldDraw (AcGiWorldDraw *mode) ;
protected:
	Adesk::Int16 m_len;
	AcGeVector3d m_firstVec;
	AcGePoint3d m_basePoint;
	double m_rotateAngle;
} ;

#ifdef SAMPLE_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO(Ccross)
#endif
