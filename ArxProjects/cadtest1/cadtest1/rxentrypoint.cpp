#include "stdafx.h"
#include "adsmigr.h"
#include "adsdef.h"
#include "adscodes.h"
#include "acestext.h"
#include "acedads.h"
#include "CustEntities.h"

void initapp()
{
	OCmdData** ppArxCmdMapEntryFirst = &__pArxCmdMapEntryFirst + 1;
	OCmdData** ppArxCmdMapEntryLast = &__pArxCmdMapEntryLast;
	for (OCmdData** ppEntry = ppArxCmdMapEntryFirst; ppEntry < ppArxCmdMapEntryLast; ppEntry++)
	{
		if (ppEntry) {
			acedRegCmds->addCommand(cmd_group_name
				, (*ppEntry)->gname
				, (*ppEntry)->lname
				, (*ppEntry)->flags
				, (*ppEntry)->func);
		}
	}
}

#if ARX == 2020 || ZRX ==2021
extern void removeHighlightStateOverrule();
extern void removeHighlightOverrule();
extern void removeVisibilityOverrule();
extern void removeGeometryOverrule();
#include "DrawingRefDlg.h"
extern DrawingRefDlg* pDrawingRefDlg;
#endif
void unloadapp()
{
#if ARX == 2020 || ZRX ==2021
	removeHighlightStateOverrule();
	removeHighlightOverrule();
	removeVisibilityOverrule();
	removeGeometryOverrule();

	if (pDrawingRefDlg)
	{
		delete pDrawingRefDlg;
		pDrawingRefDlg = nullptr;
	}

#endif

    acedRegCmds->removeGroup(cmd_group_name);
}

static int funcload()
{
	OFuncData** ppAdsCmdMapEntryFirst = &__pAdsCmdMapEntryFirst + 1;
	OFuncData** ppAdsCmdMapEntryLast = &__pAdsCmdMapEntryLast;
	short i = 0;
	for (OFuncData** ppEntry = ppAdsCmdMapEntryFirst; ppEntry < ppAdsCmdMapEntryLast; ppEntry++)
	{
		if (ppEntry) {
			if (!acedDefun((*ppEntry)->szFuncName, i++))
				return RTERROR;
		}
	}
    return RTNORM;
}

static int dofunc()
{
    struct resbuf* rb = NULL;
    int val = 0;

    if ((val = acedGetFunCode()) < 0)
    {
        acdbFail(_T("Received nonexistent function code."));
        return RTERROR;
    }
	AdsFunctionPtr pFunc = NULL;
	OFuncData** ppAdsCmdMapEntryFirst = &__pAdsCmdMapEntryFirst + 1;
	OFuncData** ppAdsCmdMapEntryLast = &__pAdsCmdMapEntryLast;
	short i = 0;
	for (OFuncData** ppEntry = ppAdsCmdMapEntryFirst; ppEntry < ppAdsCmdMapEntryLast; ppEntry++)
	{
		if (ppEntry) {
			if (val == i)
			{
				pFunc = (*ppEntry)->pFunc;
				break;
			}
			i++;
		}
	}
	if (pFunc)
	{
		rb = acedGetArgs();
		val = pFunc(rb);
		acutRelRb(rb);
		return val;
	}
	else
	{ // val > cmd-count
		acdbFail(_T("Received nonexistent function code."));
		return RTERROR;
	}
}


void registerRxClasses()
{
	int nDbCustObjCount = 0;
	OCustomObjData **ppDbCustObjMapEntryFirst = &__pDbCustObjMapEntryFirst + 1;
	OCustomObjData **ppDbCustObjMapEntryLast = &__pDbCustObjMapEntryLast;
	for (OCustomObjData **ppEntry = ppDbCustObjMapEntryFirst; ppEntry < ppDbCustObjMapEntryLast; ppEntry++) {
		if (*ppEntry != NULL) {
			nDbCustObjCount++;
			(*ppEntry)->rxInit();
			(*ppEntry)->bRegistered = true;
		}
	}
	if (nDbCustObjCount > 0)
		acrxBuildClassHierarchy();
}

void DeleteClassAndAllChild(OCustomObjData **ppEntry) {
	OCustomObjData **ppDbCustObjMapEntryFirst = &__pDbCustObjMapEntryFirst + 1;
	OCustomObjData **ppDbCustObjMapEntryLast = &__pDbCustObjMapEntryLast;
	for (OCustomObjData **ppEntry2 = ppDbCustObjMapEntryFirst; ppEntry2 < ppDbCustObjMapEntryLast; ppEntry2++) {
		if (*ppEntry2 != NULL && *ppEntry2 != *ppEntry && (*ppEntry2)->bRegistered == true) {
			if ((*ppEntry2)->desc()->myParent() == (*ppEntry)->desc())
				DeleteClassAndAllChild(ppEntry2);
		}
	}
	deleteAcRxClass((*ppEntry)->desc());
	(*ppEntry)->bRegistered = false;
}
void unregisterRxClasses()
{
	OCustomObjData **ppDbCustObjMapEntryFirst = &__pDbCustObjMapEntryFirst + 1;
	OCustomObjData **ppDbCustObjMapEntryLast = &__pDbCustObjMapEntryLast;
	for (OCustomObjData **ppEntry = ppDbCustObjMapEntryFirst; ppEntry < ppDbCustObjMapEntryLast; ppEntry++) {
		if (*ppEntry != NULL && (*ppEntry)->bRegistered == true)
			DeleteClassAndAllChild(ppEntry);
	}
}

#define AppMsgSwitchBegin(x) AA(); switch(x){
#define AppMsgCaseBegin(x) case AcRx::##x: { AAINFO(_T("AcRx::") _T(_STR(x)));
#define AppMsgCaseEnd() } break;
#define AppMsgCaseDefaultBegin(x) default: { AAINFO(_T("AcRx::AppMsgCode: %d"), x);
#define AppMsgCaseDefaultEnd() } break;
#define AppMsgSwitchEnd() }


#if 0
#ifdef _USRDLL
#undef _USRDLL
#endif

#include "AcExtensionModule.h"
// Define the sole extension module object.
AC_IMPLEMENT_EXTENSION_MODULE(theArxDLL);
HINSTANCE _hdllInstance = NULL;

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		// Extension DLL one time initialization
		//theArxDLL.AttachInstance(hInstance);
		_hdllInstance = hInstance;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		// Terminate the library before destructors are called
		//theArxDLL.DetachInstance();
	}
	return 1;   // ok
}
#endif



AcRx::AppRetCode cadtest_rxEntryPoint(AcRx::AppMsgCode msg, void* appId);

#ifdef ARX
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
#else
extern "C" AcRx::AppRetCode zcrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
#endif
{
	return cadtest_rxEntryPoint(msg, appId);
}

AcRx::AppRetCode cadtest_rxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
	AppMsgSwitchBegin(msg)
		AppMsgCaseBegin(kNullMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kInitAppMsg)
		AFX_MODULE_STATE* pState = AfxGetStaticModuleState();
	AfxSetResourceHandle(pState->m_hCurrentInstanceHandle);

	acrxDynamicLinker->unlockApplication(appId);
	acrxDynamicLinker->registerAppMDIAware(appId);
	initapp();
	registerRxClasses();
	CString strFile = _T("D:\\test.zrx");
	bool bRet = acrxDynamicLinker->loadModule(strFile, 0);
	AppMsgCaseEnd()

		AppMsgCaseBegin(kUnloadAppMsg)
		unregisterRxClasses();
	unloadapp();
	AppMsgCaseEnd()

		AppMsgCaseBegin(kLoadDwgMsg)
		funcload();
	AppMsgCaseEnd()

		AppMsgCaseBegin(kUnloadDwgMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kInvkSubrMsg)
		dofunc();
	AppMsgCaseEnd()

		AppMsgCaseBegin(kCfgMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kEndMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kQuitMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kSaveMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kDependencyMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kNoDependencyMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kOleUnloadAppMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kPreQuitMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kInitDialogMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kEndDialogMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kSuspendMsg)
		AppMsgCaseEnd()

#ifdef ARX
		AppMsgCaseBegin(kInitTabGroupMsg)
		AppMsgCaseEnd()

		AppMsgCaseBegin(kEndTabGroupMsg)
		AppMsgCaseEnd()
#endif
		AppMsgCaseDefaultBegin(msg)
		AppMsgCaseDefaultEnd()
		AppMsgSwitchEnd();

	return AcRx::kRetOK;
}


#ifdef ARX
#ifdef _WIN64
#pragma comment(linker, "/export:acrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:acrxGetApiVersion,PRIVATE")
#else // WIN32
#pragma comment(linker, "/export:_acrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:_acrxGetApiVersion,PRIVATE")
#endif
#else // ZRX
#ifdef _WIN64
#pragma comment(linker, "/export:zcrxEntryPoint,PRIVATE") 
#pragma comment(linker, "/export:zcrxGetApiVersion,PRIVATE")
#else // WIN32
#pragma comment(linker, "/export:_zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:_zcrxGetApiVersion,PRIVATE")
#endif
#endif

