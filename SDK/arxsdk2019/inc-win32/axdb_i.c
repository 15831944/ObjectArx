//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2018 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for idlsource\axdb.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0620 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


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

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_AXDBLib,0x541FA939,0x551A,0x4FC2,0x83,0xA1,0xCB,0xB1,0xB2,0x37,0xAC,0xD2);


MIDL_DEFINE_GUID(IID, IID_IAcadObject,0xC06E408D,0x2D36,0x49EE,0xB5,0x82,0x2A,0xE7,0x73,0xF8,0x00,0x59);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionary,0x2E5C87E6,0x20AE,0x4430,0x9F,0x47,0x61,0x17,0x53,0x7F,0x5C,0xAD);


MIDL_DEFINE_GUID(IID, IID_IAcadEntity,0x4AC75A4D,0x8991,0x4284,0x9A,0x41,0xDD,0xB2,0x13,0x55,0xD0,0xD6);


MIDL_DEFINE_GUID(IID, IID_IAcadBlock,0x6E304C83,0xB0A0,0x4888,0xB2,0x2F,0xF0,0x76,0x3B,0xC1,0xBE,0x15);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabase,0xDD99BDAB,0xC269,0x4D06,0xA2,0x25,0x6B,0xF7,0xC2,0xC4,0xF1,0x0E);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings,0x1A75D439,0x3222,0x499E,0x83,0xE8,0x0D,0xDF,0x83,0xD2,0xD3,0x29);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings2,0xFB6160AD,0x36EB,0x4CEF,0x98,0x51,0xC7,0x9A,0xE1,0x89,0xAA,0x9C);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlink,0x9E113B96,0x8ECD,0x436A,0xB8,0x71,0xA7,0x9F,0x3F,0x78,0x3A,0x1D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlink,0x7BBE29A9,0x522F,0x402E,0xA3,0xA8,0xC0,0x31,0x35,0x73,0x50,0x67);


MIDL_DEFINE_GUID(IID, IID_IAcadDynamicBlockReferenceProperty,0x37248038,0x69E1,0x466A,0x8F,0x6E,0xCE,0xD8,0x43,0xC4,0x4E,0xF9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDynamicBlockReferenceProperty,0xB3593347,0xA1DA,0x4935,0x8C,0x70,0x21,0x41,0x3D,0x4F,0x5F,0xFF);


MIDL_DEFINE_GUID(IID, IID_IAcadAcCmColor,0x2FF52886,0xAD9A,0x4986,0x8B,0x87,0x61,0x5E,0x7B,0xF2,0xA3,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAcCmColor,0xADE381BD,0xD32B,0x4E2E,0x93,0xD7,0x0D,0xF3,0x57,0x57,0x10,0xED);


MIDL_DEFINE_GUID(IID, IID_IAcadObjectEvents,0x9F4E558B,0x6D02,0x401E,0x94,0x8B,0xCD,0x25,0x59,0x56,0x59,0xAC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadObject,0x019768E6,0xD267,0x4031,0x81,0x17,0xB2,0xB1,0xA1,0x0F,0xD4,0xA3);


MIDL_DEFINE_GUID(IID, IID_IAcadXRecord,0x4EB81665,0xDF1C,0x4A97,0xA7,0xA5,0x0B,0xD0,0x99,0x15,0xDC,0x3D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXRecord,0x23CBC146,0x98D8,0x4E9E,0xA1,0xE6,0x29,0x19,0x78,0x7F,0x95,0x76);


MIDL_DEFINE_GUID(IID, IID_IAcadSortentsTable,0x7FCA062F,0xD7D3,0x4C53,0xA0,0x8D,0xB9,0x23,0xB9,0x28,0xFE,0x19);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSortentsTable,0x712D0FAE,0x2064,0x4583,0x8D,0x92,0xFA,0x01,0x18,0xC6,0x0C,0x11);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyle,0x64C44E88,0x7C79,0x4287,0xAE,0xCA,0x45,0xEB,0x0F,0xE5,0x46,0xF4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyle,0xF2DCADF9,0xA4EF,0x4DEE,0xAB,0xCB,0x47,0xC7,0xCA,0x9E,0x10,0xCF);


MIDL_DEFINE_GUID(IID, IID_IAcadLayer,0xA3773784,0x14B7,0x44CF,0x84,0xEC,0x4D,0xD6,0xFC,0x53,0x18,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayer,0xA466FCE1,0xE28A,0x4483,0xB2,0x1E,0xA7,0xB8,0x1F,0x80,0xE6,0xAD);


MIDL_DEFINE_GUID(IID, IID_IAcadLineType,0xD82B3083,0x67E0,0x4432,0x95,0x6F,0x41,0x2D,0x51,0x83,0x0D,0x09);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineType,0xF1DD5F23,0x20B5,0x43B8,0xBB,0x0E,0xD0,0xE5,0x87,0x03,0x81,0x43);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterial,0x194FFFB8,0x96F1,0x4F5C,0x88,0x88,0x2D,0xDF,0xA2,0x13,0x55,0xB4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterial,0x850EB596,0x2512,0x4403,0xB4,0x11,0xC8,0x26,0x58,0xC8,0xF2,0xF6);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplication,0xD36A71E9,0xE77B,0x487F,0xB5,0x4C,0x3D,0x7B,0xA5,0x05,0x59,0x83);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplication,0xE78A05F9,0x0BAE,0x4D39,0xB0,0xCE,0x3A,0x49,0xFC,0xBC,0x8F,0x59);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyle,0x19F6314A,0x1BDF,0x47F6,0x89,0x6F,0xB2,0xFE,0x30,0x12,0x0A,0x75);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyle,0x046FFE5D,0x7C9F,0x4A63,0x90,0x2B,0xF9,0x4A,0xD6,0x67,0x15,0x22);


MIDL_DEFINE_GUID(IID, IID_IAcadUCS,0x9FAD74F5,0xB9E3,0x4B36,0x8F,0x11,0xE6,0x99,0x10,0xFE,0x94,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCS,0x7667F63F,0x9932,0x4848,0xA4,0x0F,0x0F,0x85,0x37,0x06,0xF6,0xB9);


MIDL_DEFINE_GUID(IID, IID_IAcadView,0xDA4809F0,0x5A98,0x49F6,0x8B,0xFC,0xBE,0x85,0x84,0xF6,0xE4,0x42);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadView,0xA79EB9E4,0xC596,0x4B44,0xAF,0x05,0x35,0x4D,0xE9,0x29,0xF0,0x77);


MIDL_DEFINE_GUID(IID, IID_IAcadViewport,0x53AA6AD5,0xA5F5,0x4083,0xA1,0x03,0x30,0xC3,0x68,0x05,0x93,0xB1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewport,0x77CB9A09,0xC61D,0x4506,0x8B,0x7A,0x0A,0x91,0x10,0xE5,0xC3,0x21);


MIDL_DEFINE_GUID(IID, IID_IAcadGroup,0x1AE25872,0xADF0,0x42F9,0xA2,0xA9,0x1C,0xF1,0x07,0xC3,0x2D,0x3A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroup,0x3CDCC615,0x9670,0x48C7,0x87,0x7B,0x26,0xAD,0xA8,0x05,0x20,0xA2);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfiguration,0xD1B16124,0xF67D,0x4B9D,0x94,0x4D,0x1C,0x0B,0x09,0x21,0xAD,0x44);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfiguration,0xF455089D,0xB191,0x4903,0x92,0x42,0x3A,0x16,0xF9,0x5D,0xC8,0x12);


MIDL_DEFINE_GUID(IID, IID_IAcadLayout,0x35F89BED,0xDC95,0x49D8,0xB3,0x76,0xCF,0x23,0xE6,0x6E,0xE1,0xD1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayout,0xF887D63A,0x8593,0x4C81,0x81,0xC8,0x35,0x85,0x6B,0x97,0xBB,0x0E);


MIDL_DEFINE_GUID(IID, IID_IAcadIdPair,0xA690833C,0x41F7,0x40D7,0xB8,0xDF,0x8D,0x92,0x8A,0xF1,0xD2,0xFF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadIdPair,0xEDDFF2AE,0x52D8,0x4008,0xBF,0xBB,0x86,0xA2,0x44,0xD4,0x2B,0xF6);


MIDL_DEFINE_GUID(IID, IID_IAcadTableStyle,0xCC3A51FC,0x60E4,0x4A18,0xA0,0x61,0xCF,0xDC,0xAD,0xF3,0x28,0xAA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTableStyle,0xABB18238,0x5156,0x4F3D,0xBB,0x26,0x8B,0xEE,0x2D,0xAA,0x80,0xB7);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionSettings,0x48AB468D,0x226C,0x4F7A,0xAE,0x6E,0x13,0xB6,0x0F,0x01,0x24,0x53);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionSettings,0x011AC315,0xB963,0x444A,0x91,0x59,0xD8,0x59,0xAB,0x0F,0x5A,0x18);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionTypeSettings,0x46D3F96D,0xEE56,0x49D3,0xBB,0x00,0x4D,0x4A,0x8C,0x81,0xCA,0x30);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderStyle,0xD92DC57F,0x46D5,0x453A,0xAF,0x92,0xDB,0x9E,0x60,0x0F,0x44,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderStyle,0xE80BBC1D,0x7395,0x4EBE,0x9F,0x89,0x29,0x64,0x3B,0x7D,0x3F,0xB6);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlinks,0x25241724,0x6E58,0x4616,0xAC,0xB4,0x0A,0x64,0x7A,0x91,0xA6,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlinks,0x4B22D397,0xB540,0x4D6B,0xBF,0x3E,0x04,0x4C,0xDB,0x8E,0xE3,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionary,0xD25257CA,0xEC8B,0x493D,0xA1,0x71,0xB9,0xB5,0x3B,0x81,0x42,0xC0);


MIDL_DEFINE_GUID(IID, IID_IAcadLayers,0x7CDD0113,0x0C11,0x444C,0x93,0x60,0xEF,0xD1,0xA0,0xCB,0x44,0x42);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayers,0xE6BD9695,0xF7CD,0x4643,0xB4,0xC4,0x6E,0x8B,0x03,0x67,0x61,0x22);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyles,0x18AA2C2D,0x5FDC,0x46A0,0xBE,0xBF,0x0A,0xAD,0x93,0x47,0x0F,0x17);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyles,0x1BCDBFD2,0xB949,0x499E,0xA3,0xA9,0x93,0x9F,0xD8,0x4A,0xB4,0x6C);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionaries,0x11EEA9DF,0xDB09,0x4AB5,0x91,0x86,0xE0,0x57,0xC6,0x0B,0xA8,0x0B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionaries,0xABDEEF4C,0x8071,0x4B46,0xB8,0x6D,0xFE,0x76,0xE9,0xD9,0xD6,0x43);


MIDL_DEFINE_GUID(IID, IID_IAcadLineTypes,0x43FBB760,0xB38C,0x48B0,0xA0,0xCE,0xBE,0xAB,0xEE,0x9C,0x05,0xA3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineTypes,0x36C42ADD,0xD37B,0x4F18,0xA6,0x2F,0x4E,0x57,0xF8,0x9F,0x29,0x45);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterials,0x0ED2D6DC,0x33B7,0x4ABB,0xB1,0x95,0x05,0xBC,0x11,0x8A,0x71,0x5F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterials,0xC18BE1F3,0xE54F,0x4AD4,0x89,0x8E,0x5F,0xB9,0x17,0xD5,0x6F,0xD6);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyles,0xDCEA6391,0x0B9A,0x45F3,0xAE,0xBA,0xF7,0x4A,0x0A,0x7F,0xB4,0xF8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyles,0x1AD82D0B,0xBA64,0x4C43,0xAC,0x44,0xAB,0x3A,0xBE,0x17,0xF7,0xE0);


MIDL_DEFINE_GUID(IID, IID_IAcadUCSs,0x36379570,0xE374,0x4B73,0xA8,0x59,0x24,0x3E,0x83,0x66,0xB9,0xB2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCSs,0xE4B59728,0x2B82,0x4B0B,0x96,0x08,0x12,0xD1,0x75,0x95,0x1A,0x84);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplications,0x6E794B54,0xC9CB,0x4F21,0x9F,0x69,0x4D,0x9F,0x58,0xD4,0xA5,0x27);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplications,0x58B7D405,0xBBE4,0x458D,0xAA,0x3E,0x1D,0x43,0xD8,0x9D,0xEF,0x15);


MIDL_DEFINE_GUID(IID, IID_IAcadViews,0x887FE762,0x1031,0x4D84,0x9F,0xD0,0xBB,0xEA,0xE2,0x17,0x2B,0x49);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViews,0x7C3B67FF,0x4204,0x428F,0x8F,0x59,0x77,0x82,0x39,0x75,0x22,0x2F);


MIDL_DEFINE_GUID(IID, IID_IAcadViewports,0x6E84D2BD,0xB287,0x4C46,0x80,0x35,0x28,0x81,0x92,0x88,0x9A,0x03);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewports,0x905CBCFD,0xDAD5,0x4257,0xB5,0xD9,0xC5,0x12,0x68,0x21,0xBD,0xF0);


MIDL_DEFINE_GUID(IID, IID_IAcadGroups,0xCD1DEB50,0x6E31,0x47A9,0x99,0x73,0x5E,0x20,0xF4,0x53,0xE7,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroups,0x803CDB85,0x4A2C,0x41ED,0x85,0x1B,0xE7,0xFE,0xA5,0xA6,0x0E,0x57);


MIDL_DEFINE_GUID(IID, IID_IAcadBlocks,0xED1AAE3E,0x7CFB,0x41D4,0x94,0xC8,0xA0,0x3F,0xF3,0x7E,0xBA,0xF9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlocks,0x464C3F7F,0x5C75,0x4132,0x90,0xDB,0xA5,0xD8,0xAD,0x50,0x2C,0x36);


MIDL_DEFINE_GUID(IID, IID_IAcadLayouts,0x8106DA88,0x7DC7,0x4478,0xA0,0x82,0x3F,0xB2,0x6F,0x4A,0xDD,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayouts,0x53AF1CBD,0x06D7,0x452C,0xBA,0x1D,0x6F,0x61,0x08,0x55,0xA1,0x36);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfigurations,0x03C71A73,0xD382,0x423B,0xBD,0x8E,0xE1,0xB1,0xD4,0xB9,0x07,0x91);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfigurations,0x8923CB2E,0x3389,0x4DDE,0xAC,0x28,0xE9,0x61,0x92,0xF2,0x96,0xFB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEntity,0x841AAB90,0xA544,0x42D5,0xB2,0xFA,0xFF,0x85,0x89,0x8B,0x83,0x3F);


MIDL_DEFINE_GUID(IID, IID_IAcadShadowDisplay,0x791D075B,0x4A4E,0x4BC4,0x8A,0xE0,0x48,0x57,0x76,0x63,0x83,0x17);


MIDL_DEFINE_GUID(IID, IID_IAcadRasterImage,0xC938ED57,0x7761,0x443B,0x98,0xDE,0xC1,0xBF,0xDE,0xED,0x8D,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRasterImage,0x1DD039BF,0x4222,0x4CAE,0xA2,0x6E,0x0E,0x90,0x4B,0xA1,0x02,0x8D);


MIDL_DEFINE_GUID(IID, IID_IAcad3DFace,0x57048EF5,0x64F3,0x4745,0x98,0xD1,0x10,0x8A,0x44,0x93,0xF2,0x3B);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DFace,0xFD2DA2DB,0x0005,0x4E58,0xB5,0x5D,0x84,0xAE,0xEB,0xC1,0x89,0xD2);


MIDL_DEFINE_GUID(IID, IID_IAcad3DPolyline,0x627BA4A8,0x73A4,0x4E81,0xA5,0x7C,0x6F,0xF1,0xAD,0x07,0x49,0xC8);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DPolyline,0xDC5BCCC0,0x3BE5,0x4980,0xA8,0x32,0xFF,0x06,0x73,0x2F,0x67,0x84);


MIDL_DEFINE_GUID(IID, IID_IAcadRegion,0x8732F58C,0xED9B,0x469D,0x8C,0xA3,0x3C,0x49,0xFD,0x28,0x4E,0x7B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegion,0x97301F71,0xD4BF,0x48B4,0x98,0x54,0x88,0xD3,0x5F,0x5B,0x15,0xE6);


MIDL_DEFINE_GUID(IID, IID_IAcad3DSolid,0x18B97D4E,0x7E44,0x49C1,0xAE,0x81,0x83,0x3F,0x55,0xC4,0xC3,0xD5);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DSolid,0xB28EA1F5,0x377C,0x4CB5,0xBA,0xF0,0x27,0x6B,0x4C,0x08,0xC6,0x3E);


MIDL_DEFINE_GUID(IID, IID_IAcadArc,0x826562F7,0x19D4,0x44D0,0x8D,0x34,0x77,0x34,0x2D,0xA9,0xD7,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadArc,0xFAB2E2EB,0xD704,0x4945,0xAA,0x94,0xD8,0x92,0xC6,0x5A,0xB4,0x17);


MIDL_DEFINE_GUID(IID, IID_IAcadAttribute,0x4CD7D0A4,0xB6BD,0x4C5F,0xB9,0xFC,0xE6,0x12,0x1F,0xB1,0x71,0x04);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttribute,0x8C7E4D87,0x69A5,0x4145,0x95,0xF3,0x4E,0xA8,0xB0,0x85,0x16,0xDC);


MIDL_DEFINE_GUID(IID, IID_IAcadAttributeReference,0x8D239D13,0x1849,0x4E92,0xA1,0x75,0xF1,0x7D,0xB9,0xF9,0xA5,0xBB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttributeReference,0xC787FBDD,0x86D8,0x4705,0xA0,0xAE,0x8B,0xF7,0xB9,0x79,0x7B,0x06);


MIDL_DEFINE_GUID(IID, IID_IAcadBlockReference,0x771E10CD,0xDEE0,0x4976,0x84,0x94,0x51,0x82,0x58,0x23,0x90,0x19);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlockReference,0x7E25E7AB,0x34AD,0x4809,0xAB,0x13,0x2E,0xF5,0xD1,0x47,0xAC,0xF5);


MIDL_DEFINE_GUID(IID, IID_IAcadCircle,0x1B261EE4,0x4177,0x4135,0xBE,0x78,0xD6,0xA1,0x80,0xF0,0xDE,0xF8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadCircle,0x39377239,0xA97F,0x4C11,0x88,0x52,0x7C,0x8F,0x78,0xB2,0xA6,0xEA);


MIDL_DEFINE_GUID(IID, IID_IAcadEllipse,0x018F5553,0x748B,0x4683,0xA7,0x30,0xDA,0xAB,0x54,0x14,0x9C,0x72);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEllipse,0x8866130D,0x9F22,0x4456,0x82,0xB1,0x5E,0xAD,0x2C,0x14,0x5F,0x4E);


MIDL_DEFINE_GUID(IID, IID_IAcadHatch,0x1B655EBB,0x4204,0x4A1D,0x91,0xD4,0xBE,0xBF,0x59,0x91,0x93,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHatch,0xFEF1A108,0x9FEA,0x4466,0xA8,0x52,0x7F,0x20,0xA5,0x5C,0x2E,0x91);


MIDL_DEFINE_GUID(IID, IID_IAcadLeader,0x781ACFE7,0xC4E7,0x458E,0x8E,0x03,0x45,0x51,0x2D,0x63,0x34,0x5A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLeader,0xC7B713A8,0x343A,0x4638,0x87,0x22,0x0E,0x3B,0xDD,0x05,0xA8,0x37);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntity,0x6875D16A,0x36AD,0x4CE4,0x89,0xF6,0x6D,0x81,0x03,0x28,0x25,0x96);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderLeader,0xAD7A9B65,0x5F5B,0x43D7,0x92,0x31,0xFC,0x1F,0xB8,0xC2,0x0B,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderLeader,0xBD5DFA9B,0xBCE7,0x4E0D,0x95,0x79,0x36,0x18,0xC7,0xFC,0x65,0xE0);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeader,0xBB1F769B,0xEEE3,0x4F4B,0x8B,0x38,0xBD,0xE6,0x31,0xAA,0xCB,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeader,0x7A51AB44,0xBBB1,0x406F,0xBA,0x70,0xCE,0xF3,0x6C,0x03,0x70,0xB7);


MIDL_DEFINE_GUID(IID, IID_IAcadLWPolyline,0x990768F3,0x064B,0x4A62,0x8D,0x07,0x9E,0x68,0xB7,0xA7,0x12,0x2A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLWPolyline,0x9199C360,0xBA0B,0x4D0C,0x9A,0xB7,0x9A,0xF0,0xCE,0x29,0x9F,0x5E);


MIDL_DEFINE_GUID(IID, IID_IAcadLine,0x239C9052,0x2B50,0x4127,0x93,0x20,0xB7,0xC1,0x40,0x05,0x1E,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLine,0xAA08BC6E,0xB516,0x4704,0xB5,0x6F,0x82,0x61,0xA7,0x94,0x12,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAcadMText,0x38F23F39,0x7570,0x4BA0,0x95,0x34,0x9F,0xE2,0xEB,0xF6,0xDC,0xAC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMText,0x2DD08AFC,0x2DB2,0x4646,0xA9,0x23,0x46,0xCD,0x0C,0x3C,0xC9,0xF9);


MIDL_DEFINE_GUID(IID, IID_IAcadPoint,0xED7635C9,0xAC57,0x4515,0xA6,0x74,0x11,0x8D,0x7F,0xC0,0xD7,0x03);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPoint,0xC185DBA6,0xE853,0x409A,0xA3,0x12,0xFD,0x4F,0x14,0x81,0x47,0x30);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyline,0xC58BA619,0xBA5A,0x4B57,0xBB,0x02,0xFB,0x41,0x21,0xED,0x72,0x8A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyline,0xA3DFA5C1,0xCD6F,0x4B7D,0xAB,0x38,0xCC,0xFF,0x8C,0x1F,0x8E,0xF3);


MIDL_DEFINE_GUID(IID, IID_IAcadPolygonMesh,0x367C200E,0xA2E9,0x4836,0xB4,0x43,0xE8,0x23,0x0B,0xC6,0xB8,0xAC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolygonMesh,0x7A16067D,0xEE4F,0x4894,0x88,0x16,0xF3,0xB7,0xAD,0x22,0x26,0x62);


MIDL_DEFINE_GUID(IID, IID_IAcadRay,0x76D7A3C3,0xC87E,0x405F,0x91,0x7D,0x98,0xEC,0x5C,0xD1,0x5E,0xAE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRay,0xA7782804,0xA60A,0x43FC,0xBE,0xB8,0xA4,0x5F,0x3A,0x79,0xD9,0x8E);


MIDL_DEFINE_GUID(IID, IID_IAcadShape,0xDF2DD97B,0xDB16,0x447E,0x9A,0x83,0x0D,0xA3,0x6B,0xE7,0x2E,0xE2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadShape,0x4A536FCB,0xFAEC,0x4374,0x84,0x6F,0xAA,0x51,0xF4,0x41,0x5C,0x8C);


MIDL_DEFINE_GUID(IID, IID_IAcadSolid,0xC644A95F,0x9848,0x4A76,0x8E,0x37,0xC2,0xEF,0x2C,0xA6,0x64,0xD5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSolid,0x8AE6CDBF,0x0937,0x4220,0xA5,0x78,0x57,0x2A,0xF1,0x6A,0x74,0x89);


MIDL_DEFINE_GUID(IID, IID_IAcadSpline,0xD421AD0B,0xE2F3,0x4F66,0xBD,0x59,0x90,0x83,0x8B,0xA0,0xD1,0x2E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSpline,0x6FE64BEC,0x800C,0x4E24,0x8E,0xBF,0x34,0x08,0xBF,0xFB,0x71,0xED);


MIDL_DEFINE_GUID(IID, IID_IAcadText,0xBB51BE40,0x07EE,0x4D67,0xA1,0x72,0x7A,0x07,0xD1,0xE6,0x03,0xB4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadText,0xE2C265C0,0x204D,0x415F,0x8A,0xEC,0x54,0x4B,0xE8,0xAF,0x68,0xFF);


MIDL_DEFINE_GUID(IID, IID_IAcadTolerance,0x94422D08,0x3633,0x4876,0x89,0xA5,0x86,0xAC,0xBA,0x39,0xF4,0xED);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTolerance,0xA0FED68F,0x514A,0x4869,0x9F,0x8A,0xF9,0x3D,0x60,0x33,0xA4,0x9C);


MIDL_DEFINE_GUID(IID, IID_IAcadTrace,0x4E40A2DC,0xCAEA,0x4C24,0x87,0xC5,0xBA,0x09,0xEB,0xCE,0xA9,0x87);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTrace,0x37B679E0,0xC47E,0x464C,0x94,0xF6,0xE1,0x19,0x73,0x6B,0x4C,0xAA);


MIDL_DEFINE_GUID(IID, IID_IAcadXline,0x7E5F824B,0xC07A,0x4B2D,0xA6,0x4A,0xB7,0xB1,0x1E,0xDB,0xDC,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXline,0x8E37D60E,0xD340,0x45E6,0x80,0xC9,0xB9,0xEF,0x25,0xBF,0x3D,0x93);


MIDL_DEFINE_GUID(IID, IID_IAcadPViewport,0xE7959D38,0xF4E9,0x452A,0x86,0x95,0x8D,0x2F,0x51,0x3C,0xDB,0x42);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPViewport,0x3FAFEB42,0xA801,0x4DB0,0xA1,0xF3,0x89,0xC4,0x4C,0x7D,0x77,0xC0);


MIDL_DEFINE_GUID(IID, IID_IAcadMInsertBlock,0x9DC211F7,0x97D4,0x465F,0xBF,0xF0,0x5E,0x82,0x86,0x36,0x73,0x43);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMInsertBlock,0x0CAFAD60,0x1D6F,0x40B3,0x96,0x09,0xD9,0x6C,0x85,0xF2,0x75,0x5C);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyfaceMesh,0x5106E708,0xF85F,0x4920,0x97,0x03,0x0E,0x29,0xFF,0x53,0xA2,0xCD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyfaceMesh,0x062CB83B,0xE783,0x4B29,0x95,0x9E,0x75,0x68,0x32,0x58,0x22,0xAA);


MIDL_DEFINE_GUID(IID, IID_IAcadMLine,0x15F3DA57,0xAC35,0x46B8,0xBC,0x58,0x66,0x83,0x79,0xB7,0x38,0xEF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLine,0xF1CBC019,0xA066,0x4A29,0x9D,0x3F,0x66,0xBB,0x30,0x65,0xD8,0x94);


MIDL_DEFINE_GUID(IID, IID_IAcadExternalReference,0xF81646E3,0xD884,0x48DE,0xB4,0x47,0xA9,0xD8,0x94,0xE4,0xE9,0x0C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExternalReference,0xBAB08DA6,0xBFCE,0x4BC2,0x8A,0xCD,0xDD,0xC2,0x43,0xD6,0x1A,0xE5);


MIDL_DEFINE_GUID(IID, IID_IAcadTable,0x8E16AEC9,0x23A7,0x44EE,0x83,0xB6,0x92,0x19,0x9D,0x23,0xA0,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTable,0xFE098961,0xA041,0x4F85,0xB9,0xE8,0x9E,0xC5,0x16,0xD8,0xCB,0x75);


MIDL_DEFINE_GUID(IID, IID_IAcadOle,0xCED03844,0xEFEF,0x4B46,0xAA,0x39,0xF1,0x76,0xC2,0x38,0x8E,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadOle,0x153DFA66,0x1583,0x4AA7,0x81,0xA0,0x51,0xD3,0x63,0xF0,0x4A,0x36);


MIDL_DEFINE_GUID(IID, IID_IAcadHelix,0xF17F537B,0x2688,0x4075,0x89,0x14,0x71,0x6B,0xB3,0x2A,0x03,0x62);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHelix,0x26EC3A1A,0xBDDF,0x4DE1,0x96,0x48,0xB3,0xC6,0xE2,0xBA,0x86,0xF0);


MIDL_DEFINE_GUID(IID, IID_IAcadSurface,0xABE23DEB,0x5E22,0x4052,0x9C,0xF3,0xDD,0xBB,0xDD,0xAC,0x91,0x3C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSurface,0x30C97AE4,0x20CD,0x4881,0xBA,0x17,0xCA,0x4B,0xEB,0x49,0x8E,0xB4);


MIDL_DEFINE_GUID(IID, IID_IAcadPlaneSurface,0x43E924A9,0x7007,0x43F9,0x82,0xF3,0x9B,0x6E,0x65,0x5F,0x88,0x8F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlaneSurface,0xF7C80149,0x5703,0x4E2E,0x97,0x75,0x43,0xC5,0x22,0x95,0x63,0x6A);


MIDL_DEFINE_GUID(IID, IID_IAcadExtrudedSurface,0xAE4AD1C6,0x458A,0x4E17,0xB4,0x67,0x2A,0xA2,0x55,0x43,0x69,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExtrudedSurface,0xC8C275A3,0xC162,0x4E62,0xAD,0xB5,0xD0,0xAB,0x85,0x03,0x9E,0x9C);


MIDL_DEFINE_GUID(IID, IID_IAcadRevolvedSurface,0xB481E127,0xB7E0,0x4541,0x9C,0x56,0x1A,0xE8,0xFC,0xFD,0xFE,0x87);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRevolvedSurface,0xC3EA055A,0x2857,0x427D,0xAD,0xD4,0x6B,0x78,0xF0,0x29,0x66,0x45);


MIDL_DEFINE_GUID(IID, IID_IAcadSweptSurface,0x619EA034,0xFC1F,0x436C,0xBB,0xA0,0x48,0xE1,0x47,0xA9,0xCB,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSweptSurface,0x1E51BAEE,0xE537,0x4F46,0x85,0xA6,0xE1,0xF7,0x28,0x5E,0x49,0xBF);


MIDL_DEFINE_GUID(IID, IID_IAcadLoftedSurface,0x5D8428EF,0x9E49,0x470A,0xBF,0x39,0xCF,0xFC,0x29,0xAA,0x1B,0x3C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLoftedSurface,0x4799F75F,0x57B5,0x4004,0x83,0x17,0xCB,0xD0,0x75,0x7D,0x63,0xC3);


MIDL_DEFINE_GUID(IID, IID_IAcadSection,0x1E9CFAB8,0xA55F,0x4D2E,0x8F,0x29,0xBA,0x5A,0xD7,0x25,0x2D,0xEE);


MIDL_DEFINE_GUID(IID, IID_IAcadSection2,0x1EFB1BD1,0x7F23,0x451C,0xAA,0x54,0xC6,0xB3,0xC3,0x40,0x42,0x80);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSection,0xBCA3382C,0x271F,0x4A76,0x82,0xFF,0x09,0x36,0xAF,0x82,0x5D,0xA5);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionManager,0xB899D424,0xC80B,0x4200,0xAB,0xB0,0x86,0x53,0xE8,0x83,0xCA,0x97);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionManager,0x220186B6,0x5FBA,0x4F2D,0xBF,0x5A,0x37,0x08,0x90,0x72,0x5B,0x73);


MIDL_DEFINE_GUID(IID, IID_IAcadUnderlay,0x9C96D74C,0x6728,0x4857,0xB4,0x46,0xC3,0x85,0xF1,0xF1,0xF2,0x47);


MIDL_DEFINE_GUID(IID, IID_IAcadDwfUnderlay,0x5AEB8933,0x440A,0x40FF,0xBA,0x88,0xD0,0xBD,0x53,0x23,0xE5,0xD8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDwfUnderlay,0xA8F954E2,0xB175,0x4A40,0xAC,0x54,0xCA,0xB8,0xDB,0x56,0x4A,0x6A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDgnUnderlay,0x869A1263,0xE48B,0x4C92,0x80,0xF7,0xB5,0xA7,0x92,0x13,0x0E,0xCF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPdfUnderlay,0xD371DFF8,0xFE25,0x49A0,0x87,0x12,0x8A,0x4D,0x53,0x55,0xE1,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntity,0x9E665DF1,0x60B8,0x4A8E,0xA3,0x29,0xA7,0x13,0x0E,0x13,0xE9,0x93);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidFace,0xF0631F6A,0x8D9D,0x42BA,0x83,0x51,0xA2,0x71,0xB4,0xF4,0x57,0x89);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidFace,0xFEC95969,0xB15A,0x4F1F,0x8E,0xE7,0xB3,0x40,0xF9,0x64,0x1C,0xC5);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidEdge,0xA62D9526,0x2FD4,0x4F38,0xB3,0xAB,0x7B,0xFE,0xA9,0xD0,0xF5,0x32);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidEdge,0xAF487F16,0x02BD,0x45E0,0xA2,0x44,0x0E,0x83,0xB0,0x44,0x8E,0x79);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidVertex,0x00E3E2E0,0x9F2B,0x4480,0x87,0xBA,0x96,0x7B,0x8F,0x7B,0xA7,0x9C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidVertex,0x43CBC6C0,0x702E,0x4022,0x8F,0x76,0xEE,0xF4,0x75,0x0B,0x16,0x40);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidNode,0x62962DF4,0xB04F,0x4B1C,0x85,0x79,0xCE,0xC7,0xB0,0x94,0x02,0x39);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidNode,0xD3D356F4,0xCD96,0x4D9F,0xA2,0x55,0x90,0x55,0x4E,0x72,0x0D,0xA7);


MIDL_DEFINE_GUID(IID, IID_IAcadWipeout,0x514AEBD7,0x9106,0x4AAA,0x80,0xE5,0x40,0x06,0xE6,0x8E,0xFC,0x83);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadWipeout,0x2968CFC1,0x5B62,0x4647,0x88,0xE7,0x97,0x52,0xFC,0x0D,0x57,0x04);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMesh,0x3CD8D834,0x73A5,0x4DBC,0xB1,0x6E,0x24,0xD3,0x91,0x4A,0x39,0x60);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMesh,0x856CAA91,0x0EE9,0x48E6,0x87,0xF1,0xD8,0x20,0xCD,0x4F,0xF9,0x81);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshFace,0x5AD7FEC5,0xF5D0,0x4243,0x81,0x75,0xAD,0x3D,0x8D,0xED,0xA1,0x31);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshFace,0x531A2A4D,0x0858,0x4C9D,0x93,0x04,0x99,0xB3,0xE0,0xBE,0xDD,0xB6);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshEdge,0x3AC2B290,0x22C2,0x4AE1,0xA7,0xA9,0xD4,0x72,0x0E,0xE0,0x34,0xD9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshEdge,0xF47D13B6,0xD75A,0x4D10,0x89,0x08,0x27,0xC9,0x79,0xAE,0x26,0xFA);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshVertex,0x4D255855,0x0AF8,0x4AD8,0x89,0xB6,0x7A,0xD2,0xF8,0xA2,0x4A,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshVertex,0xDB7C5F97,0xE520,0x4AA0,0xA1,0x6E,0xB0,0x68,0xBC,0x77,0x8A,0xCB);


MIDL_DEFINE_GUID(IID, IID_IAcadNurbSurface,0xE57F957F,0xFFEC,0x4E54,0x92,0xEC,0x35,0x40,0xCA,0x88,0xBB,0x7F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadNurbSurface,0x47C6E003,0x5A7B,0x46A1,0x88,0x15,0x5E,0xC6,0x21,0x78,0xC4,0x94);


MIDL_DEFINE_GUID(IID, IID_IAcadGeoPositionMarker,0x55E6FA31,0x1A86,0x4288,0xBD,0x76,0xA0,0x0B,0xDD,0x46,0xC7,0x7F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGeoPositionMarker,0x9CF9E023,0xBAA7,0x431C,0xB6,0xD9,0x3D,0xE6,0xCF,0xBC,0x13,0xAA);


MIDL_DEFINE_GUID(IID, IID_IAcadGeomapImage,0xFD661492,0xE8EE,0x46DA,0xA2,0xA4,0x84,0x33,0x4B,0x2B,0x07,0x3A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGeomapImage,0x8BECB042,0xFE26,0x4817,0xA6,0x35,0x0D,0x18,0xAA,0x19,0x4C,0xC1);


MIDL_DEFINE_GUID(IID, IID_IAcadDimension,0x5E32D089,0x9E15,0x4EC1,0x9A,0x6D,0xF1,0xF0,0xD8,0xDE,0x34,0x48);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimension,0x4396C90D,0xB7D7,0x4BEF,0x92,0x11,0x4A,0x15,0xD2,0x8E,0x3A,0xC1);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAligned,0x645E72A2,0x73BF,0x47AE,0x8D,0xDD,0xFB,0x2D,0x2A,0x15,0x47,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAligned,0xEE618583,0xD387,0x43AB,0xA8,0x92,0xBB,0x8D,0x53,0xEE,0x84,0x19);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAngular,0x04CE3E41,0xAD71,0x461B,0xA2,0x16,0x15,0x97,0xC3,0x40,0x4D,0xBE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAngular,0xB6A7FBC4,0x2FD3,0x486D,0xAF,0x27,0x23,0x20,0xDA,0xF6,0x95,0x3B);


MIDL_DEFINE_GUID(IID, IID_IAcadDimDiametric,0x7B873F3D,0x5CF9,0x4200,0xBC,0x40,0x62,0x13,0x73,0xD8,0x6A,0xA5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimDiametric,0x5E68F4DF,0x460C,0x4CBD,0xA6,0xDF,0xE6,0x74,0x78,0xA0,0xC8,0xFA);


MIDL_DEFINE_GUID(IID, IID_IAcadDimOrdinate,0xACE68271,0xE97A,0x4E70,0xBE,0xC3,0x7C,0x41,0x7E,0x18,0xCC,0x76);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimOrdinate,0x45B1BFBC,0x6991,0x40C6,0x88,0x9B,0x86,0x52,0x0B,0x3D,0x81,0xCC);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadial,0x5749DE4E,0x73C1,0x4324,0xA8,0xD0,0x93,0xEA,0xEA,0xB8,0xC0,0xC7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadial,0x84FF7C8C,0xA978,0x4947,0x99,0x75,0x94,0x0F,0x81,0x6C,0x64,0x15);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRotated,0x53EFA583,0x1B0C,0x483C,0x88,0x78,0x22,0x0F,0x6E,0x49,0x0B,0xAD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRotated,0x5FF9195D,0x327D,0x4424,0xB5,0xBF,0x58,0xA7,0x3A,0x35,0x75,0x34);


MIDL_DEFINE_GUID(IID, IID_IAcadDim3PointAngular,0xC580D261,0xA56E,0x42CC,0xB6,0x46,0x01,0x74,0x5D,0x0E,0x16,0x7D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDim3PointAngular,0x7C13B851,0xD711,0x49A9,0xBC,0xBB,0x4B,0x78,0x4C,0x13,0xA4,0x90);


MIDL_DEFINE_GUID(IID, IID_IAcadDimArcLength,0xA7D3CC24,0xB136,0x4E74,0x92,0x22,0xB3,0xD5,0x27,0x45,0x2C,0xCB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimArcLength,0x387A7BC2,0x26BA,0x4D85,0x90,0xDB,0x21,0x93,0x26,0x62,0x80,0xA4);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadialLarge,0x364C32D7,0x9593,0x4D9A,0xAB,0xED,0x37,0x11,0x53,0x53,0x1C,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadialLarge,0x0E6AB755,0xA618,0x4579,0x87,0x8E,0x30,0x4A,0xD9,0xD6,0x2F,0x1A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlock,0xF99ED60B,0x2B64,0x4749,0x81,0xAF,0x1D,0x3D,0x3D,0xCC,0x29,0xC6);


MIDL_DEFINE_GUID(IID, IID_IAcadModelSpace,0x9A4F51B4,0xC00C,0x42CF,0x84,0x90,0xCE,0x2E,0x56,0xA5,0xBB,0x1E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadModelSpace,0xC6601B80,0x9394,0x4BBA,0x91,0x64,0xFE,0xAB,0x63,0xF6,0xA0,0x9C);


MIDL_DEFINE_GUID(IID, IID_IAcadPaperSpace,0x63A59136,0x71BB,0x4034,0x92,0xA9,0x81,0x31,0x17,0x16,0x3E,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPaperSpace,0x1350C71F,0xF9F3,0x4A2E,0x95,0xA8,0x86,0xE1,0x8D,0x11,0x57,0x19);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloud,0x9E911A73,0x7FE3,0x40BD,0x97,0x85,0xEF,0xBA,0x78,0x2D,0x43,0x2D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPointCloud,0x449AEA0B,0xA290,0x469A,0xB3,0xB4,0xE8,0x88,0xE8,0x35,0xE2,0xFB);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloudEx,0xE8A12021,0x2B62,0x4D4D,0xB8,0x0C,0xE8,0xED,0xB1,0x4F,0xB4,0x32);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloudEx2,0x489CB51E,0x6BDB,0x46AC,0x92,0x08,0xFE,0x47,0xF8,0xFE,0x76,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPointCloudEx,0x0D72F4DB,0x9504,0x4A88,0x85,0x13,0xE7,0x6A,0x28,0xE0,0xCC,0x37);


MIDL_DEFINE_GUID(IID, IID_IAcadSummaryInfo,0x921B2455,0x3D21,0x43C8,0xA5,0x68,0xB1,0x83,0x47,0x55,0x2E,0xB3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSummaryInfo,0xA368E2FB,0x5D40,0x4A13,0xBA,0x25,0x1E,0xEA,0x18,0xD9,0xE0,0x1D);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabasePreferences,0x7CE414A9,0xBEC0,0x4025,0xBC,0x9D,0x81,0x44,0x2D,0x09,0xE7,0x0D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabasePreferences,0x1674FC08,0x8162,0x43A8,0x85,0xDD,0x41,0x40,0x76,0xA3,0xAE,0x14);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabase,0x794AD62B,0x2BF1,0x4BE2,0xBB,0xAC,0x4B,0xF4,0xFE,0x9F,0x93,0x2B);


MIDL_DEFINE_GUID(IID, IID_IAcadSecurityParams,0xE10B311B,0x656F,0x486B,0xB2,0xE3,0xA8,0xE8,0x36,0xE5,0x0D,0x80);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSecurityParams,0xE47A3C32,0x7DF0,0x483D,0x85,0x37,0x05,0xA2,0xB0,0xE1,0x7A,0x7E);


MIDL_DEFINE_GUID(IID, IID_IAcadLayerStateManager,0x70C11E89,0x0211,0x426A,0x87,0xC0,0xAB,0xEF,0x26,0xC7,0xE4,0xC2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayerStateManager,0xC6158D81,0xD054,0x460B,0x84,0x83,0x0A,0xD0,0xB8,0x05,0x7B,0xCD);


MIDL_DEFINE_GUID(IID, IID_IAxDbDocumentEvents,0xE9CE20A5,0x79BD,0x4DA9,0xAC,0x79,0x61,0xAE,0x5B,0x99,0x34,0xA8);


MIDL_DEFINE_GUID(IID, IID_IAxDbDocument,0x96217EB5,0x9B37,0x4B0D,0x9E,0x93,0x7B,0xFE,0x56,0x16,0x96,0xDF);


MIDL_DEFINE_GUID(CLSID, CLSID_AxDbDocument,0x12A11FEE,0xFE9A,0x4E50,0x9D,0xD8,0x1A,0xB5,0xE6,0xAB,0x9B,0x7A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



