#pragma once
#include "framework.h"
#include "stdafx.h"
#include "ZGsPreviewCtrl.h"

///////////////////////////////////////////////////////////////////////////////
//ZBlockViewDlg.h : 对话框的头文件

///////////////////////////////////////////////////////////////////////////////
// CBlockViewDlg dialog
class CBlockViewDlg : public CAcUiDialog
{
public:
	// Construction
	CBlockViewDlg(CWnd* pParent = NULL); // standard constructor

	// Dialog Data
	//{{AFX_DATA(CBlockViewDlg)
	enum { IDD = IDD_BLOCKVIEW };
	//}}AFX_DATA

	CGsPreviewCtrl mPreviewCtrl;
	AcDbDatabase *mCurrentDwg;

	//////////////////////////////////////////////////////////////////////////////
	// takes a drawing and updates the GsView with it
	Acad::ErrorStatus InitDrawingControl(AcDbDatabase *pDb, const TCHAR *space = ACDB_MODEL_SPACE);
	// resets the view to the passed AcDbDatabase
	// util function to toggle the tick for a specific menu item
	bool toggleCheckMenuItem(UINT resId);
	// util functions for setting the tick for a specific menu item
	void setMenuCheck(UINT resId, UINT nCheck = MF_CHECKED);
	void setMenuUnCheck(UINT resId);
	AcDbObjectId CBlockViewDlg::setVisualStyleCurrent(ACHAR *name);
	const ACHAR* getVisualStyleLocalName(AcDbObjectId vsId);

	// view mode of the AcGsView
	CComboBox m_viewMode;
	void InitVisualStyleCombo();

	afx_msg void OnCbnSelchangeViewmode();
	afx_msg void OnFileOutput();
	afx_msg void OnFileAcGsConfig();
	afx_msg void OnFileOpen();
	afx_msg void OnShowlinetypes();
	afx_msg void OnShowSectioning();
	afx_msg void OnRenderertypeKdefault();
	afx_msg void OnRenderertypeKsoftware();
	afx_msg void OnRenderertypeKsoftwareNewViewsOnly();
	afx_msg void OnRenderertypeKfullRender();
	afx_msg void OnRenderertypeKselectionRender();
	afx_msg void OnZoomWindow();
	afx_msg void OnZoomExtents();
	afx_msg void OnZScaleDiv10();
	afx_msg void OnZScaleDiv5();
	afx_msg void OnZScaleDiv2();
	afx_msg void OnZScaleOrigin();
	afx_msg void OnZScaleMul2();
	afx_msg void OnZScaleMul5();
	afx_msg void OnZScaleMul10();
	afx_msg void OnSettingsVisualstyle();
	AcGeMatrix3d m_viewMatrix;

	// - take into account previous temporary entities
	AcDbExtents m_tempExt;

protected:
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBlockViewDlg)
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	// Implementation
	// Generated message map functions
	//{{AFX_MSG(CBlockViewDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddentity();
	afx_msg void OnAddtempentity();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedRemapcolors();
	afx_msg void OnBnClickedStandardcolors();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void OnZScale(const double newScale);
	double m_zScale;
};