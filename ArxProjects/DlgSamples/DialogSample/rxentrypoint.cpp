#include "pch.h"
#include "adsmigr.h"
#include "adsdef.h"
#include "adscodes.h"
#include "acestext.h"
#include "acedads.h"
#include "AcExtensionModule.h"
#include "SampleDlg.h"
#include "rxmfcapi.h"

extern HWND adsw_acadMainWnd();

AC_IMPLEMENT_EXTENSION_MODULE(theArxDLL);

void dialogCreate();

void initapp()
{
	acedRegCmds->addCommand(cmd_group_name, _T("DlgSample"), _T("DlgSample"), ACRX_CMD_MODAL, dialogCreate);
}

void unloadapp()
{
	acedRegCmds->removeGroup(cmd_group_name);
}

void dialogCreate()
{
	// Modal
	SampleDlg dlg(CWnd::FromHandle(adsw_acadMainWnd()));
	int nReturnValue = dlg.DoModal();

	//SampleDlg *pDialog = NULL;
	//if (pDialog == NULL)
	//{
	//	pDialog = new SampleDlg(acedGetAcadFrame());
	//	pDialog->Create(IDD_DIALOG1);
	//	pDialog->ShowWindow(SW_SHOW);
	//}
	//else
	//{
	//	pDialog->ShowWindow(SW_SHOW);
	//}
}

/*****************************************************************************************************************/
/* 创建了一个支持MFC的DLL项目, 创建MFC dll项目时如何使用自己的DllMain？(链接器在obj文件中找到多个dllmain的符号)
 * 当使用MFC库时，肯定会直接或间接地包含afx.h，然后MFC(afx.h)告诉链接器找到__afxForceUSRDLL的符号并将包含__afxForceUSRDLL的对象放入程序中，
 * 因此链接器搜索并将dllmodule.obj放入我们的程序中，因为__afxForceUSRDLL是在 dllmodule.cpp中定义。这是常见的场景。
 * 当我们想在mfc dll项目中使用我们自己的DllMain时，链接器会找到有两个DllMain，一个在我们的代码中，一个在Dllmodule.obj中。
 * 所以需要告诉链接器为__afxForceUSRDLL添加我们的dllmain.obj，
 * 需要在自己的cpp文件中定义__afxForceUSRDLL，其中定义了我们自己的DllMain，然后链接器会忽略mfc的dllmodule.obj，找到自定义的DllMain
 * 在定义自定义DllMain的文件中添加 extern “C” { int _afxForceUSRDLL; }                                                                    */
/*****************************************************************************************************************/

// 强制执行自定义的dllmain函数(也可去除_USRDLL预定义)
#ifdef _X86_
extern "C" { int _afxForceUSRDLL; }
#else
extern "C" { int __afxForceUSRDLL; }
#endif


extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		theArxDLL.AttachInstance(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		theArxDLL.DetachInstance();
	}
	return 1;   // ok
}

extern "C" AcRx::AppRetCode zcrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
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
			// Add your code here.
		}
		break;
		case AcRx::kUnloadDwgMsg:
		{
			// Add your code here.
		}
		break;
		case AcRx::kInvkSubrMsg:
		{
			// Add your code here.
		}
		break;
		default:
			break;
	}
	return AcRx::kRetOK;
}



#ifdef _WIN64
#pragma comment(linker, "/export:zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:zcrxGetApiVersion,PRIVATE")
#else // WIN32
#pragma comment(linker, "/export:_zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:_zcrxGetApiVersion,PRIVATE")
#endif

