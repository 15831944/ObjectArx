#pragma once
#include "pch.h"
#include "framework.h"
#include "gs.h"
#include "acgs.h"

// Simple lighweight drawable to do orbit glyph
//
class OrbitGadget : public AcGiDrawable
{
	AcGsNode* m_pNode;
	AcGsView* m_pAcGsView;
public:

	OrbitGadget() :m_pNode(NULL) {}
	void setGsView(AcGsView* pView) { m_pAcGsView = pView; }

	virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits * traits)
	{
		traits->setTrueColor(AcCmEntityColor(0, 200, 0));
		return kDrawableNone;
	}

	virtual Adesk::Boolean  subWorldDraw(AcGiWorldDraw * wd)
	{
		return Adesk::kFalse;
	}

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
	}
	virtual Adesk::Boolean  isPersistent(void) const
	{
		return Adesk::kFalse;
	};
	virtual AcDbObjectId    id(void) const
	{
		return AcDbObjectId::kNull;
	}
	virtual void            setGsNode(AcGsNode * gsnode)
	{
		m_pNode = gsnode;
	}
	virtual AcGsNode*       gsNode(void) const
	{
		return m_pNode;
	}
};


/////////////////////////////////////////////////////////////////////////////
// CGsPreviewCtrl window

class CGsPreviewCtrl : public CStatic
{

public:

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGsPreviewCtrl)
	//}}AFX_VIRTUAL


public:
	CGsPreviewCtrl() : CStatic(),
		mpManager(NULL), mpDevice(NULL), mpView(NULL),
		mpModel(NULL), mbModelCreated(false), mbPanning(false), mbOrbiting(false)
	{
		// zooming functionality
		mZooming = false;
		mMouseDown = false;
		mMouseMoving = false;
		mpFactory = NULL;
	}

	virtual ~CGsPreviewCtrl() { clearAll(); }
	void init(HMODULE hRes, bool bCreateModel = true);
	void erasePreview();
	void clearAll();

	AcGsView*   view() { return mpView; }
	AcGsDevice* device() { return mpDevice; }
	AcGsModel*  model() { return mpModel; }
	void setModel(AcGsModel* pModel);
	// draws XOR ink Rectangle, for zooming
	void RubberRectangle(CPoint startPt, CPoint endPt);
	// Generated message map functions
protected:
	//{{AFX_MSG(CGsPreviewCtrl)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
#if _MSC_VER < 1400
	afx_msg UINT OnNcHitTest(CPoint point);
#else
	afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public:
	HCURSOR mhSavedCursor;
	HCURSOR mhPanCursor;
	HCURSOR mhCrossCursor;
	HCURSOR mhOrbitCursor;
	AcGsManager         *mpManager;

	AcGsGraphicsKernel *mpFactory;
	AcGsDevice          *mpDevice;
	AcGsView            *mpView;
	AcGsModel           *mpModel;
	AcGsModel           *mpGhostModel;
	OrbitGadget         mOrbitGadget;
	bool mbModelCreated;
	bool mbPanning;
	bool mbOrbiting;
	CPoint mStartPt;

	// zooming functionality
	bool mZooming;
	bool mMouseDown;
	bool mMouseMoving;
	CPoint mEndPt;

public:
	// functions for adding and freeing temporary entities, these are entities that exist in the AcGsView but 
	// don't exist in the AcDbDatabase
	// records a temp entity and returns the total number recorded internally
	int addTempEntity(AcDbEntity *ent);
	// frees the temporary memory, returns the total number freed
	int freeTempEntities();

public:
	AcArray<AcDbEntity *> mTempEnts;
};