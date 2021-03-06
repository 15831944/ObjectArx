
#ifndef __DBPLOTSETTINGS_H__
#define __DBPLOTSETTINGS_H__

#include "dbmain.h"
#include "dbdict.h"
#include "AcDbCore2dDefs.h"//TODONewHeadFile

#include "../inc/zdbPlotSettings.h"

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbPlotSettings
#define AcDbPlotSettings		ZcDbPlotSettings
#endif //#ifndef AcDbPlotSettings

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef IAcReadStream
#define IAcReadStream		IZcReadStream
#endif //#ifndef IAcReadStream

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#endif //#ifndef __DBPLOTSETTINGS_H__
