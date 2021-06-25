#pragma once
#include <qstring.h>
#include <qpixmap.h>
#include "ZwAfxWinCustomCtrl.h"

// CSlbBtn
/*

	һ��������ʾSLD�İ�ť�࣬������ʾѡ��״̬

*/

class CSlbBtn : public CButton
{
	//DECLARE_DYNAMIC(CSlbBtn)

public:
	CSlbBtn();
	virtual ~CSlbBtn();

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonST)
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
//protected:
	//}}AFX_VIRTUAL

//protected:
//	DECLARE_MESSAGE_MAP()

public:
	BYTE* m_pSldData;
	DWORD m_dSldSize;
	QPixmap m_bmp;
	void SetSld();
	
protected:
	virtual DWORD OnDrawBorder(CDC* pDC, CRect* pRect);
	virtual DWORD OnDrawBackground(CDC* pDC, CRect* pRect);
};