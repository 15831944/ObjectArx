#include "stdafx.h"
#include "adsmigr.h"
#include "adsdef.h"
#include "adscodes.h"
#include "acestext.h"
#include "acedads.h"
#include "ZBlockViewDlg.h"

//{{AFX_ZRX_FUNC
void Zsdk_BlockView();
void Zsdk_RenderOffScreen();
void Zsdk_ConfigGS();
//}}AFX_ZRX_FUNC

void initapp()
{
	//acedRegCmds->addCommand(cmd_group_name, _T("helloworld"), _T("helloworld"), ACRX_CMD_MODAL, helloworld);
	acedRegCmds->addCommand(cmd_group_name, _T("BLOCKVIEW"), _T("BVIEW"), ACRX_CMD_MODAL, Zsdk_BlockView);
	acedRegCmds->addCommand(cmd_group_name, _T("RenderOffScreen"), _T("ROS"), ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, Zsdk_RenderOffScreen);
	acedRegCmds->addCommand(cmd_group_name, _T("ConfigGS"), _T("CONFIGGS"), ACRX_CMD_TRANSPARENT | ACRX_CMD_USEPICKSET, Zsdk_ConfigGS);

	acutPrintf(_T("\nBlockView Sample Loaded"));
	acutPrintf(_T("\n\nCommands are:"));
	acutPrintf(_T("\n  Bview - display the BlockView dialog"));
	acutPrintf(_T("\n  ROS - Render off screen image"));
	acutPrintf(_T("\n  Configgs - Programatically display the Graphics settings\n"));
}

void unloadapp()
{
	acedRegCmds->removeGroup(cmd_group_name);
}

///////////////////////////////////////////////////////////////////////////////
//以下放置命令的实现

///////////////////////////////////////////////////////////////////////////////
//BLOCKVIEW或者BVIEW命令
void Zsdk_BlockView()
{
	//switch our resources to the foreground
	CAcModuleResourceOverride overr;
	////construct and display the preview dialog
	CBlockViewDlg dlg;
	dlg.DoModal();
}

///////////////////////////////////////////////////////////////////////////////
//RenderOffScreen或者ROS命令
void Zsdk_RenderOffScreen()
{
	// Obtain the current viewport's screen size.  This will be the rendered image size.
	//AcDbObjectId curVportId = acedActiveViewportId();
	//AcDbObjectPointer<AcDbViewportTableRecord> curVport(curVportId, AcDb::kForRead);
	//int l, r, b, t;
	//acgsGetViewportInfo(curVport->number(), l, b, r, t);
	//int height = t - b - 1;
	//int width = r - l - 1;

	//// get the acgsManager
	//AcGsManager *gsManager = acgsGetGsManager();
	//// if ok
	//if (gsManager)
	//{
	//	AcGsClassFactory *factory = gsManager->getGSClassFactory();
	//	// if ok
	//	if (factory)
	//	{
	//		// create a new off screen device
	//		AcGsDevice *offDevice = factory->createOffScreenDevice();
	//		// if ok
	//		if (offDevice)
	//		{
	//			// size it to what the user requires
	//			offDevice->onSize(width, height);

	//			// construct a simple view
	//			AcGsView *pView = factory->createView();

	//			// if ok
	//			if (pView)
	//			{
	//				// set the gsview mode to kGouraudShaded
	//				pView->setMode(AcGsView::kGouraudShaded);

	//				// set the device rendered to software
	//				offDevice->setDeviceRenderer(AcGsDevice::kFullRender);
	//				// add the gs view to the device
	//				offDevice->add(pView);
	//				// force update calls to all gsviews
	//				offDevice->update();

	//				AcGsModel *pModel = gsManager->createAutoCADModel();
	//				// if ok
	//				if (pModel)
	//				{
	//					AcDbBlockTableRecordPointer spaceRec(curDoc()->database()->currentSpaceId(), AcDb::kForRead);
	//					// if ok
	//					if (spaceRec.openStatus() == Acad::eOk)
	//					{
	//						// add the current space AcDbBlockTableRecord to the gsview
	//						pView->add(spaceRec, pModel);
	//						// make sure it is closed
	//						spaceRec.close();

	//						// TODO: here you can set the visual style required
	//						// record what the visual style was
	//						AcDbObjectId defVisualStyle = pModel->visualStyle();
	//						// now set it to something
	//						pModel->setVisualStyle(defVisualStyle);

	//						// set the AcGsView to have the same view target and postion as the *Active* AutoCAD view
	//						AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
	//						AcGeMatrix3d viewMat;
	//						SetViewTo(pView, pDb, viewMat);

	//						// A Zoom extents to fill the frame to the offscreen device
	//						AcDbExtents viewExtents(pDb->extmin(), pDb->extmax());
	//						viewExtents.transformBy(viewMat);

	//						pView->zoomExtents(viewExtents.minPoint(), viewExtents.maxPoint());
	//						pView->zoom(0.95f);

	//						refreshView(pView);

	//						// send -1.0 to avoid dynamic tessellation while interactivity is enabled, 
	//						// regardless of whether degradation is enabled or not
	//						pView->beginInteractivity(-1.0);

	//						// get the filename to output
	//						struct resbuf *result = NULL;
	//						int status = acedGetFileNavDialog(_T("SnapShot-TTT"), NULL, _T("jpg;png;tif;bmp"), _T("BlockViewSnapshotBrowseDialog"), 1, &result);
	//						if (status == RTNORM)
	//						{
	//							// make the filename var more friendly
	//							ACHAR *pFileName = result->resval.rstring;
	//							// create the image and write to disk
	//							//if (!CreateAtilImage(pView, width, height, 32, 0, pFileName, true))
	//							AfxMessageBox(_T("Canceled to create image by John...@"));
	//						}
	//					}
	//				}
	//				// now do the various GS clean up ops
	//				pView->eraseAll();
	//				offDevice->erase(pView);
	//				factory->deleteView(pView);
	//				factory->deleteModel(pModel);
	//			}
	//		}
	//		// finally
	//		factory->deleteDevice(offDevice);
	//	}
	//}
}

///////////////////////////////////////////////////////////////////////////////
//ConfigGS或者CONFIGGS命令
void Zsdk_ConfigGS()
{
	//const TCHAR* regEntry = NULL;
	//TCHAR regPath[2024];

	//// Get the current AutoCAD registry path 
	////regEntry = acrxProductKey();
	//// this is the path we want	
	////_stprintf_s(regPath, _T("%s\\3DGS Configuration\\GSHEIDI10"), regEntry);

	//// get the GsManager from current MDI Client Window 
	//AcGsManager *pGsMgr = acgsGetGsManager(NULL);
	//// if we go the gs manager ok
	//if (pGsMgr != NULL)
	//{
	//	AcGsClassFactory* pClassFactory = pGsMgr->getGSClassFactory();
	//	// if we got it ok
	//	if (pClassFactory != NULL)
	//	{
	//		// now get the gs config class
	//		AcGsConfig *pConfig = pClassFactory->getConfig();
	//		// if we got this ok too
	//		if (pConfig != NULL)
	//		{
	//			pConfig->configure(regPath, true);
	//		}
	//	}

	//}
}

////////////////////////////////////////////////////////////////////////////
//
// Define the sole extension module object.
AC_IMPLEMENT_EXTENSION_MODULE(BlockViewDLL);

// Now you can use the CAcModuleRecourceOverride class in
// your application to switch to the correct resource instance.
// Please see the ObjectARX Documentation for more details

///////////////////////////////////////////////////////////////////////////
// DLL Entry Point
extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		// Extension DLL one time initialization
		BlockViewDLL.AttachInstance(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH) {
		// Terminate the library before destructors are called
		BlockViewDLL.DetachInstance();
	}
	return TRUE;    // ok
}

extern "C" AcRx::AppRetCode zcrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
	switch (msg)
	{
		case AcRx::kInitAppMsg:
		{
			acrxDynamicLinker->unlockApplication(appId);
			acrxDynamicLinker->registerAppMDIAware(appId);
			initapp();
		}
		break;
		case AcRx::kUnloadAppMsg:
		{
			unloadapp();
		}
		break;
		case AcRx::kLoadDwgMsg:
		{
			// Add your code here.
		}
		break;
		case AcRx::kUnloadDwgMsg:
		{
			// Add your code here.
		}
		break;
		case AcRx::kInvkSubrMsg:
		{
			// Add your code here.
		}
		break;
		default:
			break;
	}
	return AcRx::kRetOK;
}



#ifdef _WIN64
#pragma comment(linker, "/export:zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:zcrxGetApiVersion,PRIVATE")
#else // WIN32
#pragma comment(linker, "/export:_zcrxEntryPoint,PRIVATE")
#pragma comment(linker, "/export:_zcrxGetApiVersion,PRIVATE")
#endif

