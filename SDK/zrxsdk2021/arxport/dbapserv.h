
#ifndef __DBAPSERV_H__
#define __DBAPSERV_H__

#include "adesk.h"
#include "acdb.h"
#include "acarray.h"
#include "AcString.h"
#include "PAL/api/codepgid.h"
#include "acdlflagbits.h"

#include "inetstrc.h"
#include "rxdlinkr.h"
#include "PAL/api/product_flavors.h"
#include "PAL/api/aclocale.h"

#include "../inc/zdbapserv.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#ifndef ACUTIL_API
#define ACUTIL_API		ZCUTIL_API
#endif //#ifndef ACUTIL_API

#ifndef ACUTIL_INTERNAL
#define ACUTIL_INTERNAL		ZCUTIL_INTERNAL
#endif //#ifndef ACUTIL_INTERNAL

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef kARXApplication
#define kARXApplication		kZRXApplication
#endif //#ifndef kARXApplication

#ifndef reportUnhandledArxException
#define reportUnhandledArxException		reportUnhandledZrxException
#endif //#ifndef reportUnhandledArxException

#ifndef AcDbAbstractClipBoundaryDefinition
#define AcDbAbstractClipBoundaryDefinition		ZcDbAbstractClipBoundaryDefinition
#endif //#ifndef AcDbAbstractClipBoundaryDefinition

#ifndef AcDbAppSystemVariables
#define AcDbAppSystemVariables		ZcDbAppSystemVariables
#endif //#ifndef AcDbAppSystemVariables

#ifndef AcDbAuditInfo
#define AcDbAuditInfo		ZcDbAuditInfo
#endif //#ifndef AcDbAuditInfo

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbGlobals
#define AcDbGlobals		ZcDbGlobals
#endif //#ifndef AcDbGlobals

#ifndef AcDbHostApplicationProgressMeter
#define AcDbHostApplicationProgressMeter		ZcDbHostApplicationProgressMeter
#endif //#ifndef AcDbHostApplicationProgressMeter

#ifndef AcDbHostApplicationServices
#define AcDbHostApplicationServices		ZcDbHostApplicationServices
#endif //#ifndef AcDbHostApplicationServices

#ifndef AcDbHostApplicationServices_INC
#define AcDbHostApplicationServices_INC		ZcDbHostApplicationServices_INC
#endif //#ifndef AcDbHostApplicationServices_INC

#ifndef AcDbLayoutManager
#define AcDbLayoutManager		ZcDbLayoutManager
#endif //#ifndef AcDbLayoutManager

#ifndef AcDbPasswordedFile
#define AcDbPasswordedFile		ZcDbPasswordedFile
#endif //#ifndef AcDbPasswordedFile

#ifndef AcDbPlotSettingsValidator
#define AcDbPlotSettingsValidator		ZcDbPlotSettingsValidator
#endif //#ifndef AcDbPlotSettingsValidator

#ifndef AcDbTransactionManager
#define AcDbTransactionManager		ZcDbTransactionManager
#endif //#ifndef AcDbTransactionManager

#ifndef AcDbUndoController
#define AcDbUndoController		ZcDbUndoController
#endif //#ifndef AcDbUndoController

#ifndef AcPwdCache
#define AcPwdCache		ZcPwdCache
#endif //#ifndef AcPwdCache

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AcSDIValues
#define AcSDIValues		ZcSDIValues
#endif //#ifndef AcSDIValues

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef AcadApp
#define AcadApp		ZcadApp
#endif //#ifndef AcadApp

#ifndef AcadInet
#define AcadInet		ZcadInet
#endif //#ifndef AcadInet

#ifndef AcadInternalServices
#define AcadInternalServices		ZcadInternalServices
#endif //#ifndef AcadInternalServices

#ifndef AcadInternalServices2
#define AcadInternalServices2		ZcadInternalServices2
#endif //#ifndef AcadInternalServices2

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acadInternalGetvar
#define acadInternalGetvar		zcadInternalGetvar
#endif //#ifndef acadInternalGetvar

#ifndef acadInternalServices
#define acadInternalServices		zcadInternalServices
#endif //#ifndef acadInternalServices

#ifndef acadInternalSetvar
#define acadInternalSetvar		zcadInternalSetvar
#endif //#ifndef acadInternalSetvar

#ifndef acdbHostApplicationServices
#define acdbHostApplicationServices		zcdbHostApplicationServices
#endif //#ifndef acdbHostApplicationServices

#ifndef acdbSendInitialDwgFileOpenComplete
#define acdbSendInitialDwgFileOpenComplete		zcdbSendInitialDwgFileOpenComplete
#endif //#ifndef acdbSendInitialDwgFileOpenComplete

#ifndef acdbSetBreak3dQueueForRegen
#define acdbSetBreak3dQueueForRegen		zcdbSetBreak3dQueueForRegen
#endif //#ifndef acdbSetBreak3dQueueForRegen

#ifndef acdbSetHostApplicationServices
#define acdbSetHostApplicationServices		zcdbSetHostApplicationServices
#endif //#ifndef acdbSetHostApplicationServices

#ifndef acdbTriggerAcadOctTreeReclassification
#define acdbTriggerAcadOctTreeReclassification		zcdbTriggerZcadOctTreeReclassification
#endif //#ifndef acdbTriggerAcadOctTreeReclassification

#ifndef acadInternalServices2
#define acadInternalServices2		zcadInternalServices2
#endif //#ifndef acadInternalServices2

#ifndef mapInetStatusToAcadStatus
#define mapInetStatusToAcadStatus		mapInetStatusToZcadStatus
#endif //#ifndef mapInetStatusToAcadStatus

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcStringArray
#define AcStringArray		ZcStringArray
#endif //#ifndef AcStringArray

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef AcLocale
#define AcLocale		ZcLocale
#endif //#ifndef AcLocale

//TODODELETE //TODOREMAIN
#ifndef acdbHostAppMinorVersion
#define acdbHostAppMinorVersion		zcdbHostAppMinorVersion
#endif //#ifndef acdbHostAppMinorVersion

#endif //#ifndef __DBAPSERV_H__
