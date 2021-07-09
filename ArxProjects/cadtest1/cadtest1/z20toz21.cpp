// z20 -> z21 (a08 -> a19)
/*
 * 1.ide升级：2021请使用vs201715.9及其以上版本
 * 2.SDK升级：从以前的对标acad2008的SDK升级到了对标acad2019的SDK，存在部分接口升级，更换，删除。比如worldDraw变为subWorldDraw
*/

#include "stdafx.h"
#include "AcGsManager.h"

void funs20To21Test()
{
	// 以blockview的GsPreviewCtrl为例
	AcGsManager *m_pManager = acgsGetGsManager();
#if ((defined ZRX) && ZRX == 2020) || ((defined ARX) && ARX < 2019)
	// get the GS class factory
	AcGsClassFactory* m_pFactory = m_pManager->getGSClassFactory();
	ASSERT(m_pFactory);
#else
	// get the Graphics Kernel
	AcGsKernelDescriptor descriptor;
	descriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
	AcGsGraphicsKernel* m_pFactory = AcGsManager::acquireGraphicsKernel(descriptor);
	ASSERT(m_pFactory);
#endif

	HWND m_hWnd = nullptr;
#if ((defined ZRX) && ZRX == 2020) || ((defined ARX) && ARX < 2019)
	AcGsDevice* m_pDevice = m_pManager->createAutoCADDevice(m_hWnd);
#else
	AcGsDevice* m_pDevice = m_pManager->createAutoCADDevice(*m_pFactory, m_hWnd);
#endif

#if ((defined ZRX) && ZRX == 2020) || ((defined ARX) && ARX < 2019)
	AcGsModel* m_pModel = m_pManager->createAutoCADModel();
#else
	AcGsModel* m_pModel = m_pManager->createAutoCADModel(*m_pFactory);
#endif
}