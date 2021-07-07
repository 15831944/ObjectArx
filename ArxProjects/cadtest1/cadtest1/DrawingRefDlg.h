//
#if !defined(_DRAWINGREFDLG_H_)
#define _DRAWINGREFDLG_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "resource.h"

#include <adui.h>
#include <acui.h>

bool GetActiveViewPortInfo(AcDbDatabase *pDb, ads_real &height, ads_real &width, AcGePoint3d &target, AcGeVector3d &viewDir, ads_real &viewTwist, bool getViewCenter);
extern void refreshView(AcGsView *pView);
AcDbObjectId SetViewTo(AcGsView *pView, AcDbDatabase *pDb, AcGeMatrix3d& viewMat);

// Simple lighweight drawable to do orbit glyph
class OrbitGadget : public AcGiDrawable
{
	AcGsNode* m_pNode;
	AcGsView* m_pAcGsView;
public:

	OrbitGadget() :m_pNode(NULL) {};
	void setGsView(AcGsView* pView) { m_pAcGsView = pView; };

	virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits * traits)
	{
		traits->setTrueColor(AcCmEntityColor(0, 200, 0));
		return kDrawableNone;
	};

	virtual Adesk::Boolean  subWorldDraw(AcGiWorldDraw * wd)
	{
		return Adesk::kFalse;
	};

	virtual void subViewportDraw(AcGiViewportDraw * pViewportDraw)
	{
		AcGsDCRect view_rect;
		m_pAcGsView->getViewport(view_rect);

		int nViewportX = (view_rect.m_max.x - view_rect.m_min.x) + 1;
		int nViewportY = (view_rect.m_max.y - view_rect.m_min.y) + 1;
		AcGeMatrix3d scale = m_pAcGsView->viewingMatrix() * m_pAcGsView->worldToDeviceMatrix().inverse();
		AcGeVector3d viewDir = m_pAcGsView->target() - m_pAcGsView->position();
		const double radius = min(nViewportX, nViewportY) * 0.4f*scale.scale();

		pViewportDraw->geometry().circle(m_pAcGsView->target(), radius, viewDir);
		return;
	};

	virtual Adesk::Boolean  isPersistent(void) const
	{
		return Adesk::kFalse;
	};

	virtual AcDbObjectId    id(void) const
	{
		return AcDbObjectId::kNull;
	};

	virtual void setGsNode(AcGsNode * gsnode)
	{
		m_pNode = gsnode;
	};

	virtual AcGsNode* gsNode(void) const
	{
		return m_pNode;
	};
};


#if ARX == 2020 || ZRX == 2021

class GsPreViewCtrl : public CStatic
{
public:
	GsPreViewCtrl();
	~GsPreViewCtrl();

	void init(HMODULE hRes, bool bCreateModel = true);
	void releaseAll();
	inline AcGsView*   view() { return m_pView; };
	inline AcGsDevice* device() { return m_pDevice; };
	inline AcGsModel*  model() { return m_pModel; };

protected:
	//{{AFX_MSG(CGsPreviewCtrl)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()

private:
	AcGsManager         *m_pManager;
	AcGsGraphicsKernel  *m_pFactory;
	AcGsDevice          *m_pDevice;
	AcGsView            *m_pView;
	AcGsModel           *m_pModel;
	AcGsModel           *m_pGhostModel;
	OrbitGadget          m_OrbitGadget;
	bool m_bModelCreated;
};

class DrawingRefDlg : public CAcUiDialog
{
public:
	DrawingRefDlg(CWnd* pParent = NULL);
	~DrawingRefDlg();

	enum { IDD = IDD_DIALOG1 };

	// takes a drawing and updates the GsView with it
	Acad::ErrorStatus InitDrawingControl(AcDbDatabase *pDb, const TCHAR *space = ACDB_MODEL_SPACE);

public:
	//afx_msg void OnBnClickedButton1();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
private:
	GsPreViewCtrl m_PreviewCtrl;
	AcDbDatabase *m_CurrentDwg;
	AcGeMatrix3d m_viewMatrix;
};

#endif

#endif	// _DRAWINGREFDLG_H_