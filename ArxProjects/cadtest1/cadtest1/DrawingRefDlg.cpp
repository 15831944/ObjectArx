// 
#include "stdafx.h"
#include "DrawingRefDlg.h"

#include "AcGsManager.h"
#include "AcExtensionModule.h"

#pragma region DrawingRefDlg

extern CAcExtensionModule theArxDLL;

BEGIN_MESSAGE_MAP(DrawingRefDlg, CAcUiDialog)
	//ON_BN_CLICKED(IDC_BUTTON1, &DrawingRefDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

DrawingRefDlg::DrawingRefDlg(CWnd* pParent /*=NULL*/)
	: CAcUiDialog(DrawingRefDlg::IDD, pParent)
{
}

DrawingRefDlg::~DrawingRefDlg()
{
}

void DrawingRefDlg::DoDataExchange(CDataExchange* pDX)
{
	CAcUiDialog::DoDataExchange(pDX);
}

BOOL DrawingRefDlg::OnInitDialog()
{
	CAcUiDialog::OnInitDialog();

	if (!m_PreviewCtrl.SubclassDlgItem(IDC_VIEW, this))
		return FALSE;

	// now initialise the drawing control with the current working database
	InitDrawingControl(acdbHostApplicationServices()->workingDatabase());

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

// takes a drawing and updates the GsView with it
Acad::ErrorStatus DrawingRefDlg::InitDrawingControl(AcDbDatabase *pDb, const TCHAR *space)
{
	// have we got a valid drawing
	if (pDb == NULL)
		return Acad::eNullBlockName;

	// save the passed drawing so that we can use it later in various controls such as zoom extents
	m_CurrentDwg = pDb;

	AcDbBlockTableRecordPointer spaceRec(space, pDb, AcDb::kForRead);
	// if ok
	if (spaceRec.openStatus() == Acad::eOk)
	{
		// initialize the preview control
		m_PreviewCtrl.init(theArxDLL.ModuleResourceInstance(), true);

		m_PreviewCtrl.SetFocus();
		AcDbObjectId currentVsId;

		// set the view to the *Active* AutoCAD view
		currentVsId = SetViewTo(m_PreviewCtrl.view(), pDb, m_viewMatrix);

		// tell the view to display this space
		m_PreviewCtrl.view()->add(spaceRec, m_PreviewCtrl.model());

		// finally, tell the AcGsView what style to display in
		m_PreviewCtrl.view()->setVisualStyle(currentVsId);
#ifndef ARX
		m_PreviewCtrl.view()->setMode(AcGsView::kGouraudShaded);
#else
		m_PreviewCtrl.view()->setVisualStyle(AcGiVisualStyle::k3DWireframe);
#endif
	}
	return spaceRec.openStatus();
}


//void DrawingRefDlg::OnBnClickedButton1()
//{
//	// TODO...
//}

#pragma endregion

#pragma region DrawingRefDlg

BEGIN_MESSAGE_MAP(GsPreViewCtrl, CStatic)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

GsPreViewCtrl::GsPreViewCtrl()
: CStatic(), m_pManager(nullptr), m_pFactory(nullptr), m_pDevice(nullptr), m_pModel(nullptr), m_pView(nullptr), m_bModelCreated(false)
{

}

GsPreViewCtrl::~GsPreViewCtrl() 
{ 
	releaseAll(); 
}

void GsPreViewCtrl::init(HMODULE hRes, bool bCreateModel/* = true*/)
{
	// Load custom special cursors
	//m_hPanCursor = LoadCursor(hRes, MAKEINTRESOURCE(IDI_PAN));
	//m_hCrossCursor = LoadCursor(hRes, MAKEINTRESOURCE(IDI_CROSS));
	//m_hOrbitCursor = LoadCursor(hRes, MAKEINTRESOURCE(IDI_ORBIT));

	SetClassLongPtr(m_hWnd, GCLP_HCURSOR, (LONG_PTR)NULL);

	// Instantiate view, a device and a model object
	CRect rect;
	if (!m_pManager)
	{
		// get the AcGsManager object for a specified AutoCAD MDI Client CView
		m_pManager = acgsGetGsManager();

		// get the GS class factory
#if ZRX == 2021
		m_pFactory = m_pManager->getGSClassFactory();
#endif
#if ARX == 2020
		AcGsKernelDescriptor keyDescriptor;
		keyDescriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
		m_pFactory = AcGsManager::acquireGraphicsKernel(keyDescriptor);
#endif
		// create an AcGsDevice object. The window handle passed in to this 
		// function is the display surface onto which the graphics system draws
		//a device with standard autocad color palette

		m_pDevice = m_pManager->createAutoCADDevice(*m_pFactory, m_hWnd);
		//RXASSERT(mpDevice);

		// get the size of the window that we are going to draw in
		GetClientRect(&rect);

		// make sure the gs device knows how big the window is
		m_pDevice->onSize(rect.Width(), rect.Height());

		// construct a simple view
		m_pView = m_pFactory->createView();

		if (bCreateModel)
		{
			// create an AcGsModel object with the AcGsModel::kMain RenderType 
			// (which is a hint to the graphics system that the geometry in this 
			// model should be rasterized into its main frame buffer). This 
			// AcGsModel is created with get and release functions that will open and close AcDb objects.
			m_pModel = m_pManager->createAutoCADModel(*m_pFactory);
			m_bModelCreated = true;
		}

		// another model without open/close for the orbit gadget
		m_pGhostModel = m_pFactory->createModel(AcGsModel::kDirect, 0, 0, 0);
		m_pView->add(&m_OrbitGadget, m_pGhostModel);
		m_OrbitGadget.setGsView(m_pView);
		m_pDevice->add(m_pView);
	}
}

void GsPreViewCtrl::OnPaint()
{
	CPaintDC dc(this);

	// update the gs view
	m_pView->invalidate();
	m_pView->update();
}

void GsPreViewCtrl::OnSize(UINT nType, int cx, int cy)
{
	CRect rect;
	if (m_pDevice) 
	{
		GetClientRect(&rect);
		m_pDevice->onSize(rect.Width(), rect.Height());
	}
}

void GsPreViewCtrl::releaseAll()
{
	if (m_pView)
	{
		m_pView->eraseAll();
	}
	if (m_pDevice)
	{
		bool b = m_pDevice->erase(m_pView);
		//RXASSERT(b);
	}
	if (m_pFactory)
	{
		if (m_pView)
		{
			// free all of our temporary entities
			//freeTempEntities();

			m_pFactory->deleteView(m_pView);
			m_pView = nullptr;
		}
		if (m_pGhostModel)
		{
			m_pFactory->deleteModel(m_pGhostModel);
			m_pGhostModel = nullptr;
		}
		m_pFactory = nullptr;
	}
	if (m_pManager)
	{
		if (m_pModel)
		{
			if (m_bModelCreated)
				m_pManager->destroyAutoCADModel(m_pModel);
			m_pModel = nullptr;
		}

		if (m_pDevice)
		{
			m_pManager->destroyAutoCADDevice(m_pDevice);
			m_pDevice = nullptr;
		}
		m_pManager = nullptr;
	}
}

#pragma endregion

DrawingRefDlg* pDrawingRefDlg = nullptr;
ARXCMD3(DrawingRefDlgCreate)
{
	// ÇÐ»»×ÊÔ´
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// Modal
	//SampleDlg dlg(CWnd::FromHandle(adsw_acadMainWnd()));
	//int nReturnValue = dlg.DoModal();

	// Modeless
	if (!pDrawingRefDlg)
	{
		pDrawingRefDlg = new DrawingRefDlg();
		pDrawingRefDlg->Create(DrawingRefDlg::IDD, CWnd::FromHandle(adsw_acadMainWnd()));
	}
	pDrawingRefDlg->ShowWindow(SW_SHOW);
}

// get the view port information - see parameter list
bool GetActiveViewPortInfo(AcDbDatabase *pDb, ads_real &height, ads_real &width,
	AcGePoint3d &target, AcGeVector3d &viewDir,
	ads_real &viewTwist,
	AcDbObjectId &currentVsId,
	bool getViewCenter)
{
	// if not ok
	if (pDb == NULL)
		return false;

	// get the current working database as a backup
	AcDbDatabase *workingDataBase = acdbHostApplicationServices()->workingDatabase();
	// now set the working database
	acdbHostApplicationServices()->setWorkingDatabase(pDb);

	// make sure the active view port is uptodate
	acedVports2VportTableRecords();

	// open the view port records
	AcDbViewportTablePointer pVTable(pDb->viewportTableId(), AcDb::kForRead);
	// if we opened them ok
	if (pVTable.openStatus() == Acad::eOk)
	{
		AcDbViewportTableRecord *pViewPortRec = NULL;
		Acad::ErrorStatus es = pVTable->getAt(_T("*Active"), pViewPortRec, AcDb::kForRead);
		if (es == Acad::eOk)
		{
			// get the height of the view
			height = pViewPortRec->height();
			// get the width
			width = pViewPortRec->width();
			// if the user wants the center of the viewport used
			if (getViewCenter == true)
			{
				struct resbuf rb;
				memset(&rb, 0, sizeof(struct resbuf));
				// get the system var VIEWCTR
				acedGetVar(_T("VIEWCTR"), &rb);
				// set that as the target
				target = AcGePoint3d(rb.resval.rpoint[X], rb.resval.rpoint[Y], rb.resval.rpoint[Z]);
			}
			// we want the viewport's camera target setting
			else
			{
				// get the target of the view
				target = pViewPortRec->target();
			}

			// get the view direction
			viewDir = pViewPortRec->viewDirection();
			// get the view twist of the viewport
			viewTwist = pViewPortRec->viewTwist();
			// return the current Visual Style
			currentVsId = pViewPortRec->visualStyle();
		}
		// close after use
		pViewPortRec->close();
	}

	// now restore the original working database
	acdbHostApplicationServices()->setWorkingDatabase(workingDataBase);

	return (true);
}
// set the passed AcGsView to the *Active* AutoCAD AcDbDatabase view
AcDbObjectId SetViewTo(AcGsView *pView, AcDbDatabase *pDb, AcGeMatrix3d& viewMat)
{
	// we are going to set the view to the current view of the drawing
	// The overall approach is to calculate the extents of the database in the coordinate system of the view
	// Calculate the extents in WCS
	AcGePoint3d extMax = pDb->extmax();
	AcGePoint3d extMin = pDb->extmin();

	// initialize it with sensible numbers - even if there is no entity
	if (extMin.distanceTo(extMax) > 1e20)
	{
		extMin.set(0, 0, 0);
		extMax.set(100, 100, 100);
	}

	// get the view port information - see parameter list
	ads_real height = 0.0, width = 0.0, viewTwist = 0.0;
	AcGePoint3d targetView;
	AcGeVector3d viewDir;
	AcDbObjectId currentVsId;
	GetActiveViewPortInfo(pDb, height, width, targetView, viewDir, viewTwist, currentVsId, true);

	// we are only interested in the directions of the view, not the sizes, so we normalise. 
	viewDir = viewDir.normal();

	//**********************************************
	// Our view coordinate space consists of z direction 
	// get a perp vector off the z direction
	// Make sure its normalised
	AcGeVector3d viewXDir = viewDir.perpVector().normal();
	// correct the x angle by applying the twist
	viewXDir = viewXDir.rotateBy(viewTwist, -viewDir);
	// now we can work out y, this is of course perp to the x and z directions. No need to normalise this, 
	// as we know that x and z are of unit length, and perpendicular, so their cross product must be on unit length
	AcGeVector3d viewYDir = viewDir.crossProduct(viewXDir);

	// find a nice point around which to transform the view. We'll use the same point as the center of the view.
	AcGePoint3d boxCenter = extMin + 0.5 * (extMax - extMin);

	//**********************************************
	// create a transform from WCS to View space
	// this represents the transformation from WCS to the view space. (Actually not quite since 
	// we are keeping the fixed point as the center of the box for convenience )
	viewMat = AcGeMatrix3d::alignCoordSys(boxCenter, AcGeVector3d::kXAxis, AcGeVector3d::kYAxis, AcGeVector3d::kZAxis,
		boxCenter, viewXDir, viewYDir, viewDir).inverse();

	AcDbExtents wcsExtents(extMin, extMax);
	// now we have the view Extents
	AcDbExtents viewExtents = wcsExtents;
	// transforms the extents in WCS->view space
	viewExtents.transformBy(viewMat);

	//**********************************************
	// get the extents of the AutoCAD view
	double xMax = fabs(viewExtents.maxPoint().x - viewExtents.minPoint().x);
	double yMax = fabs(viewExtents.maxPoint().y - viewExtents.minPoint().y);

	//**********************************************
	// setup the view
	AcGePoint3d eye = boxCenter + viewDir;

	// upvector				
	pView->setView(eye, boxCenter, viewYDir, xMax, yMax);
	// update the gsView
	refreshView(pView);

	return currentVsId;
}