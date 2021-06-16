//
// (C) Copyright 1998-1999 by Autodesk, Inc. 
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
#if !defined(AFX_WHIP_H__12A96FD6_36AA_11D2_B730_444553540001__INCLUDED_)
#define AFX_WHIP_H__12A96FD6_36AA_11D2_B730_444553540001__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CWhip wrapper class

class CWhip : public CWnd
{
protected:
	DECLARE_DYNCREATE(CWhip)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xb2be75f3, 0x9197, 0x11cf, { 0xab, 0xf4, 0x8, 0x0, 0x9, 0x96, 0xe9, 0x31 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	void SetBackColor(unsigned long newValue);
	unsigned long GetBackColor();
	void SetBorderStyle(short nNewValue);
	short GetBorderStyle();
	void SetAppearance(short nNewValue);
	short GetAppearance();
	void SetUserInterfaceEnabled(BOOL bNewValue);
	BOOL GetUserInterfaceEnabled();
	void Set_BrowserID(long nNewValue);
	long Get_BrowserID();
	void Set_DisplayMode(long nNewValue);
	long Get_DisplayMode();
	void SetStreamName(LPCTSTR lpszNewValue);
	CString GetStreamName();
	void SetHighlightUrls(BOOL bNewValue);
	BOOL GetHighlightUrls();
	void SetGreekImages(BOOL bNewValue);
	BOOL GetGreekImages();
	void SetLoadStreamAutomatically(BOOL bNewValue);
	BOOL GetLoadStreamAutomatically();
	void SetDropFile(LPCTSTR lpszNewValue);
	CString GetDropFile();
	void SetCursorMode(long nNewValue);
	long GetCursorMode();
	void SetProxyAccessType(long nNewValue);
	long GetProxyAccessType();
	void SetProxyBypassServerList(LPCTSTR lpszNewValue);
	CString GetProxyBypassServerList();
	void SetProxyServerList(LPCTSTR lpszNewValue);
	CString GetProxyServerList();
	void SetMergeDwf(BOOL bNewValue);
	BOOL GetMergeDwf();
	void SetForceArrowKeys(BOOL bNewValue);
	BOOL GetForceArrowKeys();
	void AboutBox();
	CString _ExtractAndSetInitialViewFromURL(LPCTSTR url);
	BOOL SetAndDrawView(BOOL adjust_aspect_ratio, double left, double right, double bottom, double top);
	BOOL GetWindowExtents(long* left, long* right, long* bottom, long* top);
	BOOL GetDrawingExtents(double* left, double* right, double* bottom, double* top);
	BOOL GetInitialView(BOOL* stream_fully_loaded, double* left, double* right, double* bottom, double* top);
	BOOL GetCurrentView(double* left, double* right, double* bottom, double* top);
	BOOL SetAndDrawViewByName(BOOL adjust_aspect_ratio, LPCTSTR view_name);
	BOOL DrawCurrentViewToDC(BOOL adjust_aspect_ratio, long dc_handle, long subwindow_left, long subwindow_right, long subwindow_bottom, long subwindow_top, long full_width, long full_height, BOOL force_background_white, 
		BOOL force_geometry_black, BOOL use_mapped_colors, BOOL palette_in_background);
	CString GetNamedViewName();
	BOOL GetNamedViewView(double* left, double* right, double* bottom, double* top);
	long GetWindowExtentsLeft();
	long GetWindowExtentsRight();
	long GetWindowExtentsBottom();
	long GetWindowExtentsTop();
	double GetDrawingExtentsLeft();
	double GetDrawingExtentsRight();
	double GetDrawingExtentsBottom();
	double GetDrawingExtentsTop();
	double GetCurrentViewLeft();
	double GetCurrentViewRight();
	double GetCurrentViewBottom();
	double GetCurrentViewTop();
	double GetNamedViewLeft();
	double GetNamedViewRight();
	double GetNamedViewBottom();
	double GetNamedViewTop();
	void SetUserInterface(BOOL mode);
	BOOL GetUserInterface();
	void SetHighlightURLs(BOOL highlight_urls);
	BOOL GetHighlightURLs();
	void DrawView(double left, double right, double bottom, double top);
	void DrawNamedView(LPCTSTR name);
	BOOL BeginNamedViewSearch(LPCTSTR name);
	BOOL FindNextNamedView();
	VARIANT NamedViews(const VARIANT& item);
	VARIANT Layers(const VARIANT& item);
	void _StoreLayerInfo(BOOL vis_state, LPCTSTR layernames);
	VARIANT FindText(LPCTSTR item);
	void Clear();
	void AddByRef(long length, const VARIANT& buffer);
	void Add(const VARIANT& item);
	VARIANT Links(const VARIANT& item);
	BOOL BeginLayerSearch(LPCTSTR name);
	BOOL FindNextLayer();
	CString GetLayerName();
	BOOL GetLayerVisibility();
	void SetLayerVisibility(BOOL vis_state);
	BOOL BeginTextSearch(LPCTSTR name);
	BOOL FindNextText();
	CString GetTextString();
	double GetTextLeft();
	double GetTextRight();
	double GetTextBottom();
	double GetTextTop();
	void GotoText(LPCTSTR name);
	BOOL BeginLinksSearch(LPCTSTR name);
	BOOL FindNextLink();
	CString GetLinkURL();
	double GetLinkLeft();
	double GetLinkRight();
	double GetLinkBottom();
	double GetLinkTop();
	BOOL PrintCurrentView();
	BOOL DeleteLayer(LPCTSTR name);
	VARIANT ComputeCoordinate(long from_space, long to_space, double x, double y);
	void DoDragAndDrop(LPCTSTR drop_file);
	BOOL SetInsertionTranslation(double x, double y);
	BOOL SetInsertionScale(double x_scale, double y_scale);
	void ForceBackPalette(BOOL state);
	CString GetFileVersion();
	CString GetUnits();
	BOOL PrintSetup(BOOL white_background, BOOL black_geometry, BOOL show_dialog, const VARIANT& printer);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHIP_H__12A96FD6_36AA_11D2_B730_444553540001__INCLUDED_)
