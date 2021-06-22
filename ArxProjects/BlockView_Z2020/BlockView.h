// BlockView.h : main header file for the BlockView DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CBlockViewApp
// See BlockView.cpp for the implementation of this class
//

class CBlockViewApp : public CWinApp
{
public:
	CBlockViewApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
