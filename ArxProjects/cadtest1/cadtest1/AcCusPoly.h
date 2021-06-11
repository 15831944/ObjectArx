// AcCuspoly.h

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _ACCUSPOLY_H_
#define _ACCUSPOLY_H_

#include "dbcurve.h"


// The following is part of the code used to export a poly API 
// and/or use the exported API.
//
#pragma warning( disable: 4275 4251 )
#ifdef ACCUSPOLYSAMPLE
#define DLLIMPEXP __declspec( dllexport )
#else
//
// Note: we don't use __declspec(dllimport) here, because of the
// "local vtable" problem with msvc.  If you use __declspec(dllimport),
// then, when a client dll does a new on the class, the object's
// vtable pointer points to a vtable allocated in that client dll.  
// If the client dll then passes the object to another dll,
// and the client dll is then unloaded, the vtable becomes invalid
// and any virtual calls on the object will access invalid memory.
//
// By not using __declspec(dllimport), we guarantee that the
// vtable is allocated in the server dll during the ctor and the
// client dll does not overwrite the vtable pointer after calling
// the ctor.  And, since we expect the server dll to remain in
// memory indefinitely, there is no problem with vtables unexpectedly
// going away.
// 
#define DLLIMPEXP
#endif

// The "DLLIMPEXP" is only required for exporting a poly API or using the exported API.  
// It is not necessary for any custom classes that are not exporting an API of their own.
//
class DLLIMPEXP AcCusPoly :public AcDbCurve
{
public:
	ACRX_DECLARE_MEMBERS(AcCusPoly);

	AcCusPoly();
	virtual ~AcCusPoly();

};


#endif

