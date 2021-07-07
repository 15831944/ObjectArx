#pragma once
#include "pch.h"
#include "framework.h"
#include <dbsymtb.h>
#include <dbapserv.h>
#include <adslib.h>
#include <adui.h>
#include <acui.h>

// SampleDlg 对话框

class SampleDlg : public CAcUiDialog
{
	DECLARE_DYNAMIC(SampleDlg)

public:
	SampleDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SampleDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void AddToList(CString field, CString value);
	void AddSeperatorLine(CString field);
	void Display(AcDbObject* pObj);
	void Display(AcDbEntity* pObj);
	void Display(AcDbCurve* pObj);
	void Display(AcDbCircle* pObj);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CListCtrl m_listctl;
};
