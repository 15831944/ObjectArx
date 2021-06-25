// (C) Copyright 2002-2005 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//- ZwmNote.cpp : Initialization functions
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "ZwPlatform.h"
#include "ZwDebug.h"
#include "ZwTracer.h"
//#include "SignEntity.h"
//#include "ZcadMsXml.h"

//extern void ZwRegOPMPropertyMap(CLSID clsId, ZCAD_OPMPROPMAP_ENTRY*	property, PER_PROP_DISP_ENTRY*	display);
//CComModule _DemoModule;

static AFX_EXTENSION_MODULE ZcadOPMDLL = { NULL, NULL };

HMODULE g_hInstZrxOPMResDll = NULL;

bool InitLocalResource()
{
	/*if (g_hInstZrxOPMResDll != NULL)
		return true;

	ZTCHAR szResDllName[ZWCF_PATH_SIZE] = { 0 };
	ZTCHAR szPrdPreName[ZWCF_PATH_SIZE] = { 0 };
	ZUINT32 nRetGot = GetZcadProductPreName(szPrdPreName);
	if (nRetGot > 0)
	{
		zw_strcpy(szResDllName, szPrdPreName);
		zw_strcat(szResDllName, ZW_T("OPMRes.dll"));
	}
	else
	{
		zw_strcpy(szResDllName, ZW_T("ZwOPMRes.dll"));
	}

	g_hInstZrxOPMResDll = LoadResourceDll(szResDllName);
	if (g_hInstZrxOPMResDll == NULL)
		return false;*/

	return true;
}

void UninitLocaldResource()
{
	if (g_hInstZrxOPMResDll)
		::FreeLibrary(g_hInstZrxOPMResDll);
}

extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		InitLocalResource();
		// 扩展 DLL 一次性初始化
		if(!AfxInitExtensionModule(ZcadOPMDLL, hInstance))
			return 0;

		/*BEGIN_OBJECT_MAP(ObjectMap)
			OBJECT_ENTRY(CLSID_SignEntity, CSignEntity)
			OBJECT_ENTRY(CLSID_DOMDocument, CZcadXMLDOMDocument)
		END_OBJECT_MAP()

		_DemoModule.Init(ObjectMap, hInstance);
		new CDynLinkLibrary(ZcadOPMDLL);
		ZwRegOPMPropertyMap(CLSID_SignEntity, CSignEntity::GetOPMPropertyMap(), CSignEntity::GetPerPropDisplayArray());*/
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		UninitLocaldResource();
		//_DemoModule.Term();

		AfxTermExtensionModule(ZcadOPMDLL);
	}
	return (TRUE) ;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	//return _DemoModule.GetClassObject(rclsid, riid, ppv);
	return 0;
}