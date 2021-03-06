//////////////////////////////////////////////////////////////////////////////
//
//                     (C) Copyright 1994-2002 by Autodesk, Inc.
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
//////////////////////////////////////////////////////////////////////////////

#ifndef _aduiTextTip_h
#define _aduiTextTip_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CAdUiTipWindow
#pragma warning(push)
#pragma warning(disable : 4275)
class ADUI_PORT CAdUiTipWindow : public CWnd {
	DECLARE_DYNAMIC(CAdUiTipWindow)

public:
                CAdUiTipWindow ();
virtual         ~CAdUiTipWindow ();

// Tip Window
private:
        void    ForwardClickMessage (UINT msg, UINT nFlags, CPoint& point, BOOL focus);
protected:
static  LPCTSTR m_className;                // Registered class name
static const UINT m_timerEvent;

        BOOL    m_bUseText;                 // Draw as text vs. owner-draw.
        CWnd    *m_control;                 // Related control
        CWnd    *m_owner;                   // Owner (dialog, etc.)
        UINT    m_timerId;

virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior);
virtual void    DrawContent (CDC& dc, CRect& rInterior);
        void    StartTimer (DWORD ms=50);
        void    StopTimer ();
public:
virtual BOOL    Create (CWnd *owner);
        CWnd    *GetControl ();
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    GetUseText ();
virtual void    Hide ();
        CWnd    *Owner ();
        void    SetControl (CWnd *control);
        void    SetUseText (BOOL useText);
virtual void    Show ();

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CAdUiTipWindow)
    //}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CAdUiTipWindow)
	afx_msg void OnActivateApp(BOOL bActive, DWORD hTask);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNcDestroy();
	afx_msg void OnPaint();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
// CAdUiBalloonTip window - INTERNAL USE ONLY

class ADUI_PORT CAdUiBalloonTip : public CAdUiTipWindow {
	DECLARE_DYNAMIC(CAdUiBalloonTip)

public:
                CAdUiBalloonTip ();
virtual         ~CAdUiBalloonTip ();

// Text Tip
protected:
        CPoint  m_initialCursorPos;

virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior);
virtual void    DrawContent (CDC& dc, CRect& rInterior);
public:
virtual void    Hide ();
virtual void    Show ();

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CAdUiBalloonTip)
    //}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CAdUiBalloonTip)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CAdUiTextTip window

class ADUI_PORT CAdUiTextTip : public CAdUiTipWindow {
	DECLARE_DYNAMIC(CAdUiTextTip)

public:
                CAdUiTextTip ();
virtual         ~CAdUiTextTip ();

// Text Tip
protected:
virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior);
virtual void    DrawContent (CDC& dc, CRect& rInterior);
public:
virtual void    Hide ();
        void    Update (CWnd *control, BOOL useText);
        void    UpdateIfNecessary (CWnd *control, BOOL useText);

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CAdUiTextTip)
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    //}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CAdUiTextTip)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// These functions are all for INTERNAL USE ONLY.

void ADUI_PORT AdUiHideBalloonTip (CWnd *control);
BOOL ADUI_PORT AdUiShowBalloonTip (
    CWnd *owner, CWnd *control, LPCTSTR text, BOOL beep
);
BOOL ADUI_PORT AdUiShowBalloonTip (
    CWnd *owner, CWnd *control, CRect& rect, LPCTSTR text, BOOL beep
);

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
