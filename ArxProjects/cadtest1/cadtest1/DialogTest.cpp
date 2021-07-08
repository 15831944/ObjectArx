//

#include "stdafx.h"
#include "DialogTest.h"

BEGIN_MESSAGE_MAP(MyTestDlg, CAcUiDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MyTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

MyTestDlg::MyTestDlg(CWnd* pParent /*=NULL*/)
	: CAcUiDialog(MyTestDlg::IDD, pParent)
{
}

MyTestDlg::~MyTestDlg()
{
}

void MyTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CAcUiDialog::DoDataExchange(pDX);
}

#include "acedads.h"
void MyTestDlg::OnBnClickedButton1()
{
	this->ShowWindow(SW_HIDE);
	//TCHAR keyWord[10] = { 0 };
	//acedInitGet(0, _T("A B C D"));
	//int retVal = acedGetKword(_T("Input KeyWord [Branch A(A)/Branch B(B)/Branch C(C)/Branch D(D)] <D>: "), keyWord);
	//acutPrintf(_T("\n RetVal = %d\n"), retVal);
	//if (retVal == RTNORM)
	//{
	//	if (_tcscmp(keyWord, _T("A")) == 0)
	//		AfxMessageBox(_T("\nThis is Branch A"));
	//	else if (_tcscmp(keyWord, _T("B")) == 0)
	//		AfxMessageBox(_T("\nThis is Branch B"));
	//	else if (_tcscmp(keyWord, _T("C")) == 0)
	//		AfxMessageBox(_T("\nThis is Branch C"));
	//	else if (_tcscmp(keyWord, _T("D")) == 0)
	//		AfxMessageBox(_T("\nThis is Branch D"));
	//	else
	//		AfxMessageBox(_T("\nDo not Match"));
	//}
	//else if (retVal == RTCAN)
	//	AfxMessageBox(_T("\nYou have cancelled!"));
	//else if (retVal == RTNONE)
	//	AfxMessageBox(_T("\nYou Have not input, and the default is Branch D"));

	//TCHAR ret[10] = { 0 };
	//int nRet = acedGetString(1, L"input:", ret);

	//if (_tcscmp(ret, L"y"))
	{
		CString strCmd = L"_3dorbit\n";

		COPYDATASTRUCT cmdMsg;
		cmdMsg.dwData = (DWORD)1;
		cmdMsg.cbData = (DWORD)(_tcslen(strCmd) + 1) * sizeof(TCHAR);
		cmdMsg.lpData = (void*)(LPCTSTR)strCmd;

		::SendMessage(adsw_acadMainWnd(), WM_COPYDATA, (WPARAM)adsw_acadMainWnd(), (LPARAM)&cmdMsg);
	}
}

MyTestDlg* pDlg = nullptr;
ARXCMD3(MyDlgCreate)
{
	// ÇÐ»»×ÊÔ´
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// Modal
	//SampleDlg dlg(CWnd::FromHandle(adsw_acadMainWnd()));
	//int nReturnValue = dlg.DoModal();

	// Modeless
	if (!pDlg)
	{
		pDlg = new MyTestDlg();
		pDlg->Create(MyTestDlg::IDD, CWnd::FromHandle(adsw_acadMainWnd()));
	}
	pDlg->ShowWindow(SW_SHOW);
}
#include "rxmfcapi.h"
void TESTCHANGEICON()
{
	CView* pView = acedGetAcadDwgView();
	CFrameWnd* pWnd = pView->GetParentFrame();
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_TRAYITEM);
	pWnd->SetIcon(hIcon, FALSE);
	if (hIcon)
		::DeleteObject(hIcon);
}
