
#pragma warning( disable: 4049 )  


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else 

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif 

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif 

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IZcadToolProperties,0xEC923006,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolProperties2,0xEC92303E,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadStockTool,0xEC9230FD,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolContextMenu,0xEC923113,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadTool,0xEC9231AF,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadTool2,0xEC9230CD,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolFlyoutShape,0xEC9230B2,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolSort,0xEC92318B,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolDropTarget,0xEC9231AA,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolDragSource,0xEC923052,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolCopyPaste,0xEC923129,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, IID_IZcadToolImage,0xEC922FE9,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(IID, LIBID_ZcTcLib,0xEC9231CA,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(CLSID, CLSID_ZcadToolProperties,0xEC923066,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);


MIDL_DEFINE_GUID(CLSID, CLSID_ZcadToolImage,0xEC922FD4,0x5A17,0x11E7,0xB7,0x2E,0xBC,0x5F,0xF4,0x2A,0xC8,0x39);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



