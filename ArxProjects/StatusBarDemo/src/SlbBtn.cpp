// SlbBtn.cpp : 实现文件
//

#include "StdAfx.h"
#include "SlbBtn.h"
#include "CSlb.h"
#include "ZwUiPushButton.h"
#include <QPainter>
#include <QPixmap>
#include <qwidget.h>

// CSlbBtn

//IMPLEMENT_DYNAMIC(CSlbBtn, CButtonST)
CSlbBtn::CSlbBtn()
{
	m_pSldData = NULL;
	m_dSldSize = 0;
}

CSlbBtn::~CSlbBtn()
{
	if(m_pSldData != NULL)
		delete m_pSldData;
}


/*BEGIN_MESSAGE_MAP(CSlbBtn, CButtonST)
END_MESSAGE_MAP()*/

//要合理显示出幻灯片按钮的CHECKED状态
void CSlbBtn::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
#ifdef _ZW_WINDOWS
	//CButtonST::DrawItem(lpDIS) ;
	//----------------------------------//
 	CDC*	pDC = CDC::FromHandle(lpDIS->hDC);
	CPen*	pOldPen = NULL;
 	CRect itemRect = lpDIS->rcItem;

	// draw the checked or pressed status
//	if ((m_bIsCheckBox && m_bIsPressed) || (!m_bIsCheckBox && (m_bIsPressed || m_bMouseOnButton)))
	if ((m_bIsCheckBox && m_bIsPressed))
	{
/*       
        PULLED BY MRY 20111012
		CRect rtButtons (itemRect.left+itemRect.Width()*0.1,
						itemRect.bottom - itemRect.Height()*0.3,
						itemRect.left + itemRect.Width() * 0.3,
						itemRect.bottom - itemRect.Height() * 0.1);


		CBrush brSelect;
		CPen penBtnHiLight(PS_SOLID, 0, GetSysColor(COLOR_BTNHILIGHT)); // White
		brSelect.CreateSolidBrush(GetSysColor(COLOR_HIGHLIGHT));
		pOldPen = pDC->SelectObject (&penBtnHiLight);
		
	
		pDC->FillRect (rtButtons,&brSelect);
		//
		pDC->SelectObject(pOldPen);
*/

		//NEW ADD BY MRY 20111012

		//资源切换
		CTemporaryResourceOverride myResources(_hdllInstance);

		CRect rtButtons (itemRect.right - 11,
						itemRect.bottom - 11,
						itemRect.right - 1,
						itemRect.bottom - 1);

		CBitmap* pBitmap = new CBitmap;
		CBitmap* pOldBitmap;
		CDC* pDisplayMemDC=new CDC;
		pDisplayMemDC->CreateCompatibleDC(pDC);
		//绘制图片
		pBitmap->LoadBitmap(IDB_BITMAP_SLBBTN_FOCUS);
		pOldBitmap=(CBitmap*)pDisplayMemDC->SelectObject(pBitmap);
		pDC->BitBlt(rtButtons.left, rtButtons.top, rtButtons.Width(), rtButtons.Height(), pDisplayMemDC, 0, 0, SRCCOPY);
		pDisplayMemDC->SelectObject(pOldBitmap);
		pBitmap->DeleteObject();

		ReleaseDC(pDisplayMemDC);
		delete pDisplayMemDC;
		delete pBitmap;
		//END OF ADD 
	}
#endif 
}

// CSlbBtn 消息处理程序

void CSlbBtn::SetSld()
{
	CRect rect;
	this->GetClientRect(rect);
	int nWidth = rect.Width() - 4;
	int nHeight = rect.Height() - 4;

	/*CDC* pDC = GetDC();

	m_bmp.CreateCompatibleBitmap(pDC, nWidth, nHeight);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap* hObj = memDC.SelectObject(&m_bmp);*/
	
	QPixmap qmap(nWidth, nHeight);
	QRect size = qmap.rect();
	m_bmp = qmap;
	QPainter painter(&m_bmp);
	painter.fillRect(size, QColor(0, 0, 0));
	CGraph graph;
	graph.pDC = &painter;

	if(m_pSldData!=NULL && m_dSldSize!=0)
	{
  		graph.Draw((char*)m_pSldData, m_dSldSize, nWidth, nHeight, 2, 2);
		//memDC.SelectObject(hObj);

		//HICON hIcon = ZwmUiBase::GetIconByBitmap(&m_bmp, RGB(0,0,0));
		//SetIcon(hIcon);
		if(!m_pWidget)
		{
			return;
		}
	
		QPushButton* pPushButton = static_cast<QPushButton*>(m_pWidget);
		if (!pPushButton)
		{
			return;
		}
		
		QIcon icon(m_bmp);
		pPushButton->setIcon(icon);
		pPushButton->setIconSize(QSize(nWidth, nHeight));
	}
}

//重载这个函数，设置背景色为黑色，这样SLD好看点
DWORD CSlbBtn::OnDrawBackground(CDC *pDC, CRect* pRect)
{
#ifdef _ZW_WINDOWS
	COLORREF	crColor = RGB(0,0,0);
	CBrush		brBackground(crColor);

	pDC->FillRect(pRect, &brBackground);
#endif 
	return 0;
} // End of OnDrawBackground

DWORD CSlbBtn::OnDrawBorder(CDC* pDC, CRect* pRect)
{
	//CButtonST::OnDrawBorder(pDC, pRect);

	return 0;
} // End of OnDrawBorder

