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
/* ������һ��֧��MFC��DLL��Ŀ, ����MFC dll��Ŀʱ���ʹ���Լ���DllMain��(��������obj�ļ����ҵ����dllmain�ķ���)
 * ��ʹ��MFC��ʱ���϶���ֱ�ӻ��ӵذ���afx.h��Ȼ��MFC(afx.h)�����������ҵ�__afxForceUSRDLL�ķ��Ų�������__afxForceUSRDLL�Ķ����������У�
 * �����������������dllmodule.obj�������ǵĳ����У���Ϊ__afxForceUSRDLL���� dllmodule.cpp�ж��塣���ǳ����ĳ�����
 * ����������mfc dll��Ŀ��ʹ�������Լ���DllMainʱ�����������ҵ�������DllMain��һ�������ǵĴ����У�һ����Dllmodule.obj�С�
 * ������Ҫ����������Ϊ__afxForceUSRDLL������ǵ�dllmain.obj��
 * ��Ҫ���Լ���cpp�ļ��ж���__afxForceUSRDLL�����ж����������Լ���DllMain��Ȼ�������������mfc��dllmodule.obj���ҵ��Զ����DllMain
 * �ڶ����Զ���DllMain���ļ������ extern ��C�� { int _afxForceUSRDLL; }                                                                    */
/*****************************************************************************************************************/

// ǿ��ִ���Զ����dllmain����(Ҳ��ȥ��_USRDLLԤ����)
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

