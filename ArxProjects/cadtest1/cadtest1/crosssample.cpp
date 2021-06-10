// (C) Copyright 2002-2005 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
#include "stdafx.h"
#include "crosssample.h"
#include "rxboiler.h"
#include "dbproxy.h"

Adesk::UInt32 Ccross::kCurrentVersionNumber =1 ;

ACRX_DXF_DEFINE_MEMBERS (
	Ccross, AcDbEntity,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent, 
	AcDbProxyEntity::kNoOperation, CROSS,
	"HYSAMPLEAPP"
	"|Product Desc:     A description for your object"
	"|Company:          Your company name"
	"|WEB Address:      Your company WEB site address"
)

//-----------------------------------------------------------------------------
Ccross::Ccross () : AcDbEntity ()
{
	m_len = 10;
	m_firstVec = AcGeVector3d::kYAxis;
	m_rotateAngle = 0.5 * 3.1415926;
}

Ccross::Ccross (const AcGePoint3d& pt) : AcDbEntity ()
{
	m_len = 10;
	m_firstVec = AcGeVector3d::kYAxis;
	m_rotateAngle = 0.5 * 3.1415926;
	m_basePoint = pt;
}

Ccross::~Ccross () {
}

//-----------------------------------------------------------------------------
//----- AcDbObject protocols
//- Dwg Filing protocol
Acad::ErrorStatus Ccross::dwgOutFields (AcDbDwgFiler *pFiler) const {
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es =AcDbEntity::dwgOutFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be saved first
	if ( (es =pFiler->writeUInt32 (Ccross::kCurrentVersionNumber)) != Acad::eOk )
		return (es) ;
	//----- Output params
	//.....
	pFiler->writeInt16(m_len);
	pFiler->writeVector3d(m_firstVec);
	pFiler->writePoint3d(m_basePoint);
	pFiler->writeDouble(m_rotateAngle);

	return (pFiler->filerStatus ()) ;
}

Acad::ErrorStatus Ccross::dwgInFields (AcDbDwgFiler *pFiler) {
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es =AcDbEntity::dwgInFields (pFiler) ;
	if ( es != Acad::eOk )
		return (es) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version =0 ;
	if ( (es =pFiler->readUInt32 (&version)) != Acad::eOk )
		return (es) ;
	if ( version > Ccross::kCurrentVersionNumber )
		return (Acad::eMakeMeProxy) ;
	//- Uncomment the 2 following lines if your current object implementation cannot
	//- support previous version of that object.
	//if ( version < Ccross::kCurrentVersionNumber )
	//	return (Acad::eMakeMeProxy) ;
	//----- Read params
	//.....

	pFiler->readInt16(&m_len);
	pFiler->readVector3d(&m_firstVec);
	pFiler->readPoint3d(&m_basePoint);
	pFiler->readDouble(&m_rotateAngle);
	return (pFiler->filerStatus ()) ;
}

//-----------------------------------------------------------------------------
//----- AcDbEntity protocols
Adesk::Boolean Ccross::worldDraw (AcGiWorldDraw *mode) 
{
	assertReadEnabled() ;

	AcGePoint3d pnts[2];
	pnts[0] = m_basePoint;
	pnts[1] = m_basePoint + m_firstVec.normal() * m_len;
	mode->geometry().polyline(2,pnts);

	pnts[0] = m_basePoint;
	pnts[1] = m_basePoint + m_firstVec.rotateBy(m_rotateAngle, AcGeVector3d::kZAxis).normal() * m_len;
	mode->geometry().polyline(2,pnts);
	
	return (Adesk::kTrue);
}

Acad::ErrorStatus Ccross::intersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType, AcGePoint3dArray& points, int thisGsMarker, int otherGsMarker) const
{
	assertReadEnabled();

	CString msg;
	msg.Format(_T("\n****pEnt Type is %s"),pEnt->isA()->name());
	acutPrintf(msg);
//	AfxMessageBox(msg);
	if (pEnt!= this && pEnt->isKindOf(AcDbLine::desc()) == Adesk::kTrue)
	{
		AcDbLine* pLine = (AcDbLine*)pEnt;
		AcGePoint3d p1 = pLine->startPoint();
		AcGePoint3d p2 = pLine->endPoint();
		msg.Format(_T("\nstartPt:%.3f,%.3f,%.3f  endPt:%.3f,%.3f,%.3f"),p1.x,p1.y,p1.z,p2.x,p2.y,p2.z);
		acutPrintf(msg);
	//	AfxMessageBox(msg);
	}

	if (pEnt == this)
	{
		// get the intersect points of custom entity itself 
		points.append(m_basePoint);
	}
	else 
	{
		// get the intersect points of custom entity and other type entity 
	}
	return Acad::eOk;
}

Acad::ErrorStatus Ccross::getOsnapPoints(
	AcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray& snapPoints,
	AcDbIntArray& geomIds) const
{
	assertReadEnabled();
	return (AcDbEntity::getOsnapPoints (osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds));
}

REGISTER_OBJECT(Ccross);
ARXCMD3(crosssample)
{
	// Add your code for command hySample.HydrawEnt here
	ads_point pt;

	if (acedGetPoint(NULL, _T("\n请点取绘制基点:"), pt) == RTNORM)
	{
		Ccross* pEnt = new Ccross(AcGePoint3d(pt[0], pt[1], pt[2]));

		AcDbBlockTable *pBlockTable;
		AcDbBlockTableRecord *pBlockRecord;
		AcDbObjectId objId;
		acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead);
		pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockRecord, AcDb::kForWrite);
		pBlockTable->close();
		pBlockRecord->appendAcDbEntity(objId, (AcDbEntity*)pEnt);
		pBlockRecord->close();
		pEnt->close();
	}

}
