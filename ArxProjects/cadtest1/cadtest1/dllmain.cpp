//
#include "stdafx.h"
#include "AcExtensionModule.h"

#ifdef _USRDLL
#undef _USRDLL
#endif

AC_IMPLEMENT_EXTENSION_MODULE(theArxDLL);

//#ifdef _USRDLL
//#pragma comment(linker, "/include:__afxForceUSRDLL") 
//#endif

//#ifdef _X86_
//extern "C" { int _afxForceUSRDLL; }
//#else
//extern "C" { int __afxForceUSRDLL; }
//#endif

//extern "C" int APIENTRY
//DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
//{
//	// Remove this if you use lpReserved
//	UNREFERENCED_PARAMETER(lpReserved);
//
//	if (dwReason == DLL_PROCESS_ATTACH)
//	{
//		// Extension DLL one time initialization
//		theArxDLL.AttachInstance(hInstance);
//		//_hdllInstance = hInstance;
//	}
//	else if (dwReason == DLL_PROCESS_DETACH)
//	{
//		// Terminate the library before destructors are called
//		theArxDLL.DetachInstance();
//	}
//	return 1;   // ok
//}