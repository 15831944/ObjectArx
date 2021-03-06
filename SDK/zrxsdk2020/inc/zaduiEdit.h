

#ifndef _zduiEdit_h
#define _zduiEdit_h
#pragma pack (push, 8)

#pragma once

#include "zadesk.h"

#ifdef _ZSOFT_WINDOWS_
#pragma warning(push)
#pragma warning(disable : 4275)

class ZDUI_PORT CZdUiEdit : public CEdit {
    DECLARE_DYNAMIC(CZdUiEdit)

public:
                CZdUiEdit ();
virtual         ~CZdUiEdit ();

protected:
        CPoint  m_lastMousePoint;
        CRect   m_tipRect;

public:
virtual void    GetContentExtent (LPCTSTR text, int& width, int& height);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);

public:
        DWORD   m_styleMask;            

virtual void    SetStyleMask (DWORD);   
        DWORD   GetStyleMask ();        
        BOOL    IsStyleMaskSet (DWORD); 

protected:
        CWnd    *m_zduiParent;

virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual void    OnDrawTip (CDC& dc);
virtual BOOL    OnDrawTipText (CZdUiDrawTipText& dtt);
virtual ZDUI_REPLY OnGetTipSupport (CPoint& p);
virtual BOOL    OnGetTipRect (CRect& r);
virtual BOOL    OnGetTipText (CString& text);
virtual BOOL    OnHitTipRect (CPoint& p);
public:
        CWnd    *GetZdUiParent ();
        void    SetZdUiParent (CWnd *w);

public:

protected:
	
    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
#ifndef _UNICODE
	afx_msg LRESULT OnEditPaste(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEditCopy(WPARAM wParam, LPARAM lParam);
#endif 
	DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
#endif

#pragma pack (pop)
#endif


