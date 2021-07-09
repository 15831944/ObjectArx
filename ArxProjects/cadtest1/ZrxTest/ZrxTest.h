// ZrxTest.h : main header file for the ZrxTest DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CZrxTestApp
// See ZrxTest.cpp for the implementation of this class
//

class CZrxTestApp : public CWinApp
{
public:
	CZrxTestApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
