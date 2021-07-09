#include "pch.h"

#include "adsmigr.h"
#include "adsdef.h"
#include "adscodes.h"
#include "acestext.h"
#include "acedads.h"

#include "helloworld.h"
#include "CustomLine.h"


void initapp()
{
	CustomLine::rxInit();
	SubCustomLine::rxInit();
	acrxBuildClassHierarchy();

	acedRegCmds->addCommand(cmd_group_name, _T("loadtest"), _T("loadtest"), ACRX_CMD_MODAL, loadtest);
	acedRegCmds->addCommand(cmd_group_name, _T("CreateCusLineZrxTest"), _T("CreateCusLineZrxTest"), ACRX_CMD_MODAL, CreateCustomLineInZrxTest);
	acedRegCmds->addCommand(cmd_group_name, _T("BrepCrashTest"), _T("BrepCrashTest"), ACRX_CMD_MODAL, BrepCrashTest);
	acutPrintf(L"\nZrxTest.zrx is loaded!\n");
}

void unloadapp()
{
	acedRegCmds->removeGroup(cmd_group_name);

	deleteAcRxClass(SubCustomLine::desc());
	deleteAcRxClass(CustomLine::desc());
	//deleteAcRxClass(SubCustomLine::desc());  // 子类不从运行时类树移除和销毁，delete父类时会抛出异常<Delete rx class in wrong order!!!> (z20似乎顺序不对也可以)

	// 正确为：注册时先初始化父类，再初始化之类，反注册时先del子类再del父类
	acutPrintf(L"\nZrxTest.zrx is unload!\n");
}


#define ELEMENTS(array) (sizeof(array)/sizeof((array)[0]))

struct func_entry { TCHAR *func_name; int(*func) (struct resbuf *); };

struct func_entry func_table[] = {
	{_T("showhello"), showhello},
	{_T("c:showhello"), showhellocmd},
};

int funcload()
{
	for (int i = 0; i < ELEMENTS(func_table); i++)
	{
		if (!acedDefun(func_table[i].func_name, i))
			return RTERROR;
	}

	return RTNORM;
}

int dofunc()
{
	struct resbuf* rb = NULL;
	int val = 0;

	if ((val = acedGetFunCode()) < 0 || val >= ELEMENTS(func_table))
	{
		acdbFail(_T("Received nonexistent function code."));
		return RTERROR;
	}
	rb = acedGetArgs();
	val = (*func_table[val].func)(rb);
	acutRelRb(rb);
	return val;
}


#ifdef ARX
extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
#else
extern "C" AcRx::AppRetCode zcrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
#endif
{
	switch (msg)
	{
		case AcRx::kInitAppMsg:
		{
			acrxDynamicLinker->unlockApplication(appId);
			acrxDynamicLinker->registerAppMDIAware(appId);
			initapp();
		}
		break;
		case AcRx::kUnloadAppMsg:
		{
			unloadapp();
		}
		break;
		
		case AcRx::kLoadDwgMsg:
		{
			funcload();
		}
		break;
		case AcRx::kUnloadDwgMsg:
		{
			// Add your code here.
		}
		break;
		case AcRx::kInvkSubrMsg:
		{
			dofunc();
		}
		break;
		
		default:
			break;
	}
	return AcRx::kRetOK;
}



#ifdef _WIN64
#ifdef ARX
#pragma comment(linker, "/export:acrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:acrxGetApiVersion,PRIVATE")
#else
#pragma comment(linker, "/export:zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:zcrxGetApiVersion,PRIVATE")
#endif
#else // WIN32
#pragma comment(linker, "/export:_zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:_zcrxGetApiVersion,PRIVATE")
#endif

