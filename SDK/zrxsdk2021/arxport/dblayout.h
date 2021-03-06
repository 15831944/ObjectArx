
#ifndef __DBLAYOUT_H__
#define __DBLAYOUT_H__

#include "dbmain.h"
#include "dbdict.h"
#include "AdAChar.h"
#include "dbPlotSettings.h"

#include "../inc/zdblayout.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbLayout
#define AcDbLayout		ZcDbLayout
#endif //#ifndef AcDbLayout

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcDbPlotSettings
#define AcDbPlotSettings		ZcDbPlotSettings
#endif //#ifndef AcDbPlotSettings

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcDbExtents2d
#define AcDbExtents2d		ZcDbExtents2d
#endif //#ifndef AcDbExtents2d

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef Atil
#define Atil		Ztil
#endif //#ifndef Atil

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef acutGetAcStringConvertToAChar
#define acutGetAcStringConvertToAChar		zcutGetZcStringConvertToZTChar
#endif //#ifndef acutGetAcStringConvertToAChar

#endif //#ifndef __DBLAYOUT_H__
