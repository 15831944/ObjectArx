#pragma once

#include "resource.h"

#include <adui.h>
#include <acui.h>

class MyTestDlg : public CAcUiDialog
{
public:
	MyTestDlg(CWnd* pParent = NULL);
	~MyTestDlg();

	enum { IDD = IDD_DIALOG2 };

public:
	afx_msg void OnBnClickedButton1();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV
	//virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
};
