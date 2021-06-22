// stdafx.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef __STDAFX_H__
#define __STDAFX_H__

// add headers that you want to pre-compile here
#include "framework.h"

#include "resource.h"

#include "accmd.h"
#include "AcString.h"
#include "gepnt3d.h"
#include "geassign.h"
#include "dbents.h"
#include "dbmain.h"
#include "acdocman.h"
#include "acarray.h"
#include "adscodes.h"

//ZWCAD MFC Extensions:
#include "adui.h"
#include "acui.h"
#include "acuiComboBox.h"
#include "acuiDialog.h"
//
//#include "imgdef.h"
//#include "imgent.h"
//
#include "axlock.h"
//#include "dbxutil.h"

#define cmd_group_name _T("BlockView")

#include "arxHeaders.h"
#include <math.h>
#include "AcExtensionModule.h"

////***************************************************************************************
//// get the view port information - see parameter list
bool GetActiveViewPortInfo(AcDbDatabase *pDb, ads_real &height, ads_real &width, AcGePoint3d &target, AcGeVector3d &viewDir, ads_real &viewTwist, bool getViewCenter);
void refreshView(AcGsView *pView);
AcDbObjectId SetViewTo(AcGsView *pView, AcDbDatabase *pDb, AcGeMatrix3d& viewMat);

#endif //__STDAFX_H__
