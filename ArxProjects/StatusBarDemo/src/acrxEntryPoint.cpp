#include "StdAfx.h"
#include "ZwmTrayItem.h"
#include "rxmfcapi.h"
#include <QString>
#include <QIcon>

//using boost::lexical_cast;
using namespace std;

class CHelloWorldApp : public ZcRxZrxApp {

public:
	CHelloWorldApp () {}

	virtual ZcRx::AppRetCode On_kInitAppMsg (void *pkt) {
		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kInitAppMsg (pkt) ;
		//ZsdkSign::rxInit();
		acrxBuildClassHierarchy();
		//ZsdkSign::initCLSID();
		
		acedRegCmds->addCommand(_T("HelloWorld"), _T("_ZwStatusbarTest"), _T("ZwStatusbarTest"), ZCRX_CMD_TRANSPARENT, statusbarTest);
		return (retCode) ;
	}

	virtual ZcRx::AppRetCode On_kLoadDwgMsg (void *pkt) {
		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kLoadDwgMsg (pkt) ;
		
		return (retCode) ;
	}

	virtual ZcRx::AppRetCode On_kInvkSubrMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kInvkSubrMsg (pkt) ;

		// TODO: Unload dependencies here

		return (retCode) ;
	}

	virtual ZcRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		ZcRx::AppRetCode retCode =ZcRxZrxApp::On_kUnloadAppMsg (pkt) ;
		//deleteAcRxClass(ZsdkSign::desc());

		acedRegCmds->removeCmd(_T("HelloWorld"), _T("_ZwStatusbarTest"));
		return (retCode) ;
	}

	virtual void RegisterServerComponents () {
	}
	
	static void statusbarTest()
	{
		ZwmTrayItem* g_pTrayItem = new ZwmTrayItem;

		QString str(":/ZWCADRes/ZWCAD/IDI_ICON_STATUSBAR_SNAPMODE");
		QIcon* hIcon = new QIcon(str);
		int result = g_pTrayItem->SetIcon((HICON)hIcon);
		result = g_pTrayItem->SetToolTipText(ZW_T("statusbar"));
		g_pTrayItem->Enable(TRUE);
		g_pTrayItem->SetVisible(TRUE);
		result = acedGetApplicationStatusBar()->Add(g_pTrayItem);
	}
	

} ;

IMPLEMENT_ARX_ENTRYPOINT(CHelloWorldApp)