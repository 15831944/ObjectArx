// z20 -> z21 (a08 -> a19)
/*
 * 1.ide������2021��ʹ��vs201715.9�������ϰ汾
 * 2.SDK����������ǰ�ĶԱ�acad2008��SDK�������˶Ա�acad2019��SDK�����ڲ��ֽӿ�������������ɾ��������worldDraw��ΪsubWorldDraw
*/

#include "stdafx.h"
#include "AcGsManager.h"

void funs20To21Test()
{
	// ��blockview��GsPreviewCtrlΪ��
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