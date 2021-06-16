//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2012 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Feb 06 18:11:55 2012
 */
/* Compiler settings for idlsource\acad.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
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
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_AutoCAD,0xD5C3CB6F,0xAA0A,0x4D45,0xB0,0x2D,0xCF,0x29,0x74,0xEF,0xD4,0xBE);


MIDL_DEFINE_GUID(IID, IID_IAcadObject,0x63728D11,0xC9D2,0x425A,0x9F,0x67,0x42,0x74,0x56,0x2D,0x9F,0xBE);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionary,0x8C6D9EC3,0xDC7C,0x444C,0x80,0x28,0x8F,0x1E,0x4B,0x7C,0x7D,0x1A);


MIDL_DEFINE_GUID(IID, IID_IAcadEntity,0xF0B53585,0x38E5,0x4416,0xAD,0x39,0x49,0x32,0x21,0x7E,0xC2,0xC3);


MIDL_DEFINE_GUID(IID, IID_IAcadBlock,0x1C571198,0x3F59,0x4544,0x9E,0x27,0x09,0xC6,0x11,0xB1,0x44,0xCE);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabase,0xCB9F73AA,0x4982,0x4EFE,0x99,0x95,0x8D,0x03,0xA2,0x5C,0x21,0x5C);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings,0x73F5F200,0x81AF,0x4EDB,0xBA,0x2C,0x1F,0x23,0x8C,0x16,0xD1,0x2F);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionTypeSettings2,0x0FEA0736,0x6F59,0x4F84,0x81,0x77,0xA2,0xD8,0xC3,0xDD,0x35,0xA3);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlink,0x7F061BAC,0x1C8E,0x4B3A,0x9D,0x8D,0x3F,0x72,0x1C,0x7D,0x13,0xD8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlink,0xFA94BF6B,0xBC70,0x465E,0xA5,0x26,0xDD,0xBE,0x92,0x55,0xD4,0x35);


MIDL_DEFINE_GUID(IID, IID_IAcadDynamicBlockReferenceProperty,0x8D8EE217,0x8311,0x49B6,0x8B,0xBA,0x78,0xE0,0x66,0x62,0xB4,0x09);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDynamicBlockReferenceProperty,0x49797B12,0xC08D,0x4BCB,0xAE,0x97,0xBD,0x14,0x3E,0xE4,0x71,0x94);


MIDL_DEFINE_GUID(IID, IID_IAcadAcCmColor,0xA18C1129,0x535F,0x4AB1,0x8E,0x94,0xC8,0x4F,0xA8,0x62,0x22,0x4F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAcCmColor,0x8C683E36,0x9174,0x40FC,0xAA,0xC7,0x83,0xFA,0xF8,0x18,0x38,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAcadObjectEvents,0x9363B49E,0xC710,0x49FC,0x98,0xFD,0xC0,0xEF,0xA6,0x20,0x7C,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadObject,0xF00E2D02,0x19C3,0x4F5E,0x93,0xE0,0xEC,0x45,0x6E,0xFC,0x8D,0xA7);


MIDL_DEFINE_GUID(IID, IID_IAcadXRecord,0xCABDBE61,0x8824,0x4727,0xA6,0xAE,0x3D,0xF8,0xB4,0xB7,0xEB,0x73);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXRecord,0xF384210E,0x79A9,0x4DA1,0xB7,0xE9,0xB0,0x20,0xFC,0xA4,0x7F,0xCC);


MIDL_DEFINE_GUID(IID, IID_IAcadSortentsTable,0xAD48B770,0x3AA3,0x4402,0xBB,0xE0,0xCF,0x92,0xCF,0x0B,0x08,0x89);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSortentsTable,0x3E328A0D,0x7398,0x4089,0x95,0x50,0x09,0xB5,0xFC,0x23,0x13,0xE0);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyle,0x33E3DE44,0xB114,0x4644,0xA2,0x0A,0x42,0x84,0x2A,0x89,0x94,0x63);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyle,0xD008989C,0xCC3F,0x4F81,0xB7,0x47,0x4C,0xF9,0x38,0x79,0xCF,0x37);


MIDL_DEFINE_GUID(IID, IID_IAcadLayer,0xC673CECB,0x6735,0x4DEA,0xA2,0x24,0xEB,0x72,0x20,0x02,0xF0,0xF4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayer,0x37168B1B,0x7468,0x483E,0xBA,0x7B,0x92,0xC0,0xE6,0xF9,0x06,0xA2);


MIDL_DEFINE_GUID(IID, IID_IAcadLineType,0x934AC2B2,0x3FD6,0x49F3,0xB5,0xA5,0xF0,0x1E,0x51,0xBE,0x6D,0xEB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineType,0xCE8D119A,0x1A4E,0x4932,0x8C,0x43,0xD3,0x88,0x85,0xDE,0xCC,0x8C);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterial,0x1944B9E6,0x84C8,0x40DA,0xB1,0xFE,0xE9,0x39,0x08,0x3D,0x4D,0x0F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterial,0x2F462DDE,0x3901,0x414A,0x83,0x0B,0x30,0x2A,0xF9,0x7F,0xF9,0x9A);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplication,0xA3F43F6D,0x30D3,0x4E8F,0xB8,0xB7,0x81,0xB9,0xDF,0x5A,0x3C,0xDA);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplication,0x6650FB0E,0x3939,0x47BF,0xA7,0xB0,0x62,0xE8,0x50,0x15,0x89,0x9B);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyle,0xDD3EC6BC,0x25CD,0x4C8B,0x99,0x9F,0x2D,0x52,0xA7,0x09,0x2F,0xAF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyle,0x1CFE58D5,0x6F0E,0x4484,0x99,0x04,0x80,0x11,0x23,0x96,0x1A,0xD4);


MIDL_DEFINE_GUID(IID, IID_IAcadUCS,0x416967C6,0x4F89,0x4C6E,0x96,0xF5,0x9D,0x71,0x7F,0xB0,0x60,0x81);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCS,0x822EB4C7,0x8927,0x4469,0x90,0x43,0x66,0x35,0xFB,0x85,0x56,0xCA);


MIDL_DEFINE_GUID(IID, IID_IAcadView,0x04B6E68B,0x0D0E,0x489A,0xA6,0x28,0x59,0x61,0x1E,0x4C,0xDE,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadView,0xB54FA711,0x4D1D,0x4A7B,0x89,0x64,0x5D,0x3F,0x5E,0x0F,0xF5,0xB4);


MIDL_DEFINE_GUID(IID, IID_IAcadViewport,0x3B687DFC,0x7BAD,0x42A1,0x91,0x64,0xB4,0x2F,0xD0,0x4F,0x47,0xE0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewport,0x383D4834,0x5927,0x452B,0xA1,0xC6,0x3E,0xA3,0x6D,0xDE,0x19,0xAC);


MIDL_DEFINE_GUID(IID, IID_IAcadGroup,0x84CFC127,0xF4D0,0x4E3A,0x87,0x2E,0x1F,0x45,0x06,0xD5,0xC1,0xFB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroup,0x7B947EE3,0xE174,0x45D9,0x94,0xC6,0x54,0x7F,0x6E,0xB5,0x91,0xBD);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfiguration,0x6F8622E1,0xB557,0x4E60,0xB0,0x0A,0x68,0x3B,0x3B,0x19,0x26,0xB1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfiguration,0xEAC1F1A0,0x9334,0x467C,0x9A,0x77,0x82,0x09,0x9E,0xB2,0x17,0x0D);


MIDL_DEFINE_GUID(IID, IID_IAcadLayout,0x5B23EEDB,0xF352,0x4C4C,0xBA,0x95,0xC1,0x3E,0xD5,0xC0,0x04,0x92);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayout,0xF26F4CE6,0xF27E,0x4F03,0x8F,0xDD,0x21,0x97,0x10,0x20,0x0D,0xC1);


MIDL_DEFINE_GUID(IID, IID_IAcadIdPair,0xDC5A1434,0x5861,0x4BB3,0xB1,0xE7,0x44,0xCF,0x7F,0x22,0x12,0x95);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadIdPair,0x43EB97E1,0x180C,0x473E,0xB8,0xE8,0x9E,0x23,0xC5,0x34,0x8D,0x9F);


MIDL_DEFINE_GUID(IID, IID_IAcadTableStyle,0x21863473,0xDBCE,0x4DAE,0xBD,0x22,0x02,0x39,0xA7,0x31,0x0D,0xA3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTableStyle,0x29B93DFA,0xD02F,0x4A09,0x85,0x2F,0xE6,0xB9,0x9E,0x0B,0xBA,0xC2);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionSettings,0x7D8E71C8,0x511C,0x43EA,0xB4,0x22,0xE1,0x81,0x88,0xFC,0x14,0x95);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionSettings,0x5A05870C,0xF60F,0x40C5,0xA3,0xBF,0xC2,0x93,0xC0,0xF4,0x94,0x24);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionTypeSettings,0x41CB9E9A,0x9EDC,0x4802,0x9B,0x7F,0xEF,0x76,0xE1,0x3E,0xBD,0x46);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderStyle,0x83C173D0,0x9315,0x4146,0x9E,0x35,0xA2,0x2F,0x6E,0x2B,0xBD,0x93);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderStyle,0xB15C676C,0x4009,0x4DAF,0xB5,0x82,0xF4,0xD2,0xD0,0x78,0xE6,0x56);


MIDL_DEFINE_GUID(IID, IID_IAcadHyperlinks,0x6CCBBBE6,0x029F,0x4595,0xAA,0xE9,0xC5,0x2D,0x43,0x30,0xD5,0x6D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHyperlinks,0x7E0DCF9A,0xABD8,0x4B5B,0xB6,0x8A,0xB8,0xD8,0x0E,0xA8,0xE9,0x1A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionary,0x001C9E6B,0xC922,0x4F3F,0xA3,0x7E,0x93,0x28,0xDA,0x98,0x47,0xEF);


MIDL_DEFINE_GUID(IID, IID_IAcadLayers,0x0E1E19A7,0x6FEE,0x4FE2,0x9A,0x8F,0xDB,0xD1,0x96,0x71,0x3B,0x2D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayers,0xAB4CA9F2,0x1901,0x4522,0xBF,0x24,0x2E,0x74,0x99,0x6E,0xAC,0x4B);


MIDL_DEFINE_GUID(IID, IID_IAcadDimStyles,0x8D7CC814,0x16C3,0x4560,0xBB,0x34,0x53,0xE0,0x48,0xE7,0xB3,0x35);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimStyles,0xEA36DC05,0xBE53,0x426E,0x89,0xFB,0x43,0x59,0xB9,0x66,0xC3,0x91);


MIDL_DEFINE_GUID(IID, IID_IAcadDictionaries,0x53E6F723,0x7C00,0x4262,0x80,0x86,0x4D,0x7D,0x20,0x8B,0x7F,0x13);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDictionaries,0x36086B26,0x7206,0x4A6D,0xA1,0x1B,0x4F,0x75,0x79,0xA9,0x2E,0x22);


MIDL_DEFINE_GUID(IID, IID_IAcadLineTypes,0x32B9F121,0xA9E3,0x4E9D,0x89,0x24,0x0B,0x65,0xF2,0x6C,0x6B,0xBC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLineTypes,0x2E7A407C,0xF68E,0x49D8,0xB4,0xE2,0x04,0x75,0xBC,0x4B,0x6B,0xF6);


MIDL_DEFINE_GUID(IID, IID_IAcadMaterials,0xF86AC5DE,0xF30C,0x40A3,0x81,0x95,0x45,0xC3,0x90,0x7E,0xD4,0xB6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMaterials,0x1C7D4EF7,0x9055,0x4411,0xB3,0x34,0x92,0xD3,0x00,0x32,0x96,0x1B);


MIDL_DEFINE_GUID(IID, IID_IAcadTextStyles,0xAA337271,0x0B49,0x4C2F,0xBB,0x52,0x0A,0x12,0x73,0x00,0x46,0xEB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTextStyles,0xCD65A024,0x37D8,0x453D,0x85,0x54,0xBA,0x12,0x48,0x86,0x38,0x9F);


MIDL_DEFINE_GUID(IID, IID_IAcadUCSs,0x4A594C1E,0xB99D,0x4AAB,0xA0,0x65,0x87,0xB4,0x1A,0x9D,0x33,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUCSs,0xD0A86B06,0xE32B,0x4149,0xBA,0xF7,0x42,0x2E,0x8D,0x53,0x2B,0xFF);


MIDL_DEFINE_GUID(IID, IID_IAcadRegisteredApplications,0x7F2212FC,0x9E17,0x4CA4,0x9B,0xB9,0x20,0xA8,0xE2,0x46,0x0A,0xFF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegisteredApplications,0x2A66EE8A,0x6BBE,0x4C67,0xB7,0xB0,0xD8,0x30,0x70,0x12,0x3F,0x8D);


MIDL_DEFINE_GUID(IID, IID_IAcadViews,0x3264959C,0x0EF8,0x410C,0x9A,0x46,0x7C,0xAB,0xD9,0xFA,0xE3,0x30);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViews,0xA0240841,0x8312,0x4A08,0x8C,0x5C,0xF6,0x78,0x82,0x0D,0x42,0x26);


MIDL_DEFINE_GUID(IID, IID_IAcadViewports,0xD550A4FC,0xF761,0x4E36,0x96,0x0E,0xBA,0x7E,0xD1,0xE1,0xE2,0x4F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadViewports,0xA2519397,0x1495,0x42AB,0x96,0x93,0xFE,0x67,0x5D,0xA4,0x09,0x70);


MIDL_DEFINE_GUID(IID, IID_IAcadGroups,0xEF090384,0xFC63,0x4FA4,0x9A,0x5B,0x41,0xBF,0x11,0xA8,0x5A,0x31);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadGroups,0x1D779502,0x833F,0x499F,0x98,0x72,0xED,0xED,0xD7,0x1A,0x69,0x7B);


MIDL_DEFINE_GUID(IID, IID_IAcadBlocks,0xA737727E,0x08C5,0x4F2E,0xAA,0x5E,0xB5,0x33,0xBC,0xF9,0x3F,0x8A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlocks,0xE7CD447F,0x2108,0x4C4F,0x9A,0xE0,0x81,0x06,0x74,0x55,0xB9,0x7B);


MIDL_DEFINE_GUID(IID, IID_IAcadLayouts,0xB21D78EE,0xBBAF,0x4CE7,0xBB,0x34,0x59,0x55,0xEA,0x12,0x46,0x0F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayouts,0x05F24253,0xF73E,0x42C0,0xB9,0xF8,0xCF,0xF5,0x97,0xE3,0xBF,0x57);


MIDL_DEFINE_GUID(IID, IID_IAcadPlotConfigurations,0xFC0DAA89,0x01F1,0x43B2,0xBD,0x48,0x0A,0x31,0x7A,0x71,0x19,0x5F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlotConfigurations,0x833FEEC3,0xCC36,0x4168,0xB7,0x99,0x93,0xEF,0x7E,0x21,0x03,0x36);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEntity,0x7528C76A,0x64B8,0x4FBC,0x9B,0x0E,0x1B,0x14,0xBD,0x1F,0xEB,0xB9);


MIDL_DEFINE_GUID(IID, IID_IAcadShadowDisplay,0x46EA39E8,0x0FAA,0x43DA,0xBE,0xB6,0x34,0x61,0xFA,0xA9,0x00,0x65);


MIDL_DEFINE_GUID(IID, IID_IAcadRasterImage,0x2BDFFEA2,0x6626,0x4BC0,0x84,0xE2,0xB2,0xA8,0x52,0x36,0xF2,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRasterImage,0xF5BBD54B,0x3D4F,0x4600,0x8B,0xF3,0x3F,0xC4,0x9B,0x2E,0xEC,0xA8);


MIDL_DEFINE_GUID(IID, IID_IAcad3DFace,0x2F75320C,0xEE68,0x474E,0x8B,0x56,0x9C,0x95,0xDB,0x59,0xBA,0xDC);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DFace,0x2FF8E222,0x54C4,0x424A,0xBF,0x9B,0x93,0x51,0x6F,0x48,0x16,0x63);


MIDL_DEFINE_GUID(IID, IID_IAcad3DPolyline,0x217FB1DE,0x0E62,0x4576,0xBF,0x53,0xC7,0x93,0x0C,0xC7,0xAD,0xC7);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DPolyline,0xB780E477,0xA33B,0x4F00,0x98,0xA6,0xCE,0x25,0xC9,0x33,0xF9,0x81);


MIDL_DEFINE_GUID(IID, IID_IAcadRegion,0x7AA694C9,0x1F36,0x45C3,0xB6,0x95,0x2E,0xD9,0x3E,0xDD,0xF4,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRegion,0xFA44D186,0xB2E8,0x4EEE,0xA3,0xA7,0x0D,0xA8,0x82,0x57,0xF9,0xAB);


MIDL_DEFINE_GUID(IID, IID_IAcad3DSolid,0x30D8AEE7,0x4077,0x46DF,0xA9,0xEB,0xEB,0x60,0xAF,0x69,0x30,0x97);


MIDL_DEFINE_GUID(CLSID, CLSID_Acad3DSolid,0x70F9BBC4,0x783A,0x492B,0x84,0x19,0x61,0xA1,0xC0,0x5B,0xDE,0x48);


MIDL_DEFINE_GUID(IID, IID_IAcadArc,0x3456D54E,0xC6E4,0x469C,0xBA,0xF3,0xCF,0x3E,0x3B,0x03,0x7D,0x55);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadArc,0xCFEC3461,0x7B68,0x44C6,0xB2,0x27,0x59,0xE3,0x64,0xE8,0xCC,0x39);


MIDL_DEFINE_GUID(IID, IID_IAcadAttribute,0xD66F7254,0x97EE,0x4F39,0xB7,0xC8,0x96,0x3A,0x8F,0x9E,0x0A,0x84);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttribute,0x4EF1F485,0xA272,0x4F84,0x85,0x52,0xFA,0xD2,0x5A,0x3B,0x7E,0xDD);


MIDL_DEFINE_GUID(IID, IID_IAcadAttributeReference,0x80AF52AA,0x964A,0x40CC,0x90,0x9D,0x8C,0x71,0xE4,0x0E,0x9C,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadAttributeReference,0xFA996286,0x0F03,0x47E4,0xBE,0xBD,0xEC,0x4E,0xA9,0xC8,0x37,0xEA);


MIDL_DEFINE_GUID(IID, IID_IAcadBlockReference,0xF36DC546,0xA602,0x456D,0xA6,0x87,0xDB,0xE2,0xE9,0xFD,0xC4,0x5A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlockReference,0x1143D075,0xF1F5,0x4EFC,0xA6,0xFB,0xB1,0x82,0x79,0x04,0x26,0x96);


MIDL_DEFINE_GUID(IID, IID_IAcadCircle,0xC490C9BD,0x5661,0x4B3C,0xB7,0x4A,0x85,0x79,0xBF,0xEC,0x8A,0x3C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadCircle,0xDFE38E50,0x3209,0x424E,0x87,0x2B,0xDD,0xB2,0x3B,0xCD,0x4C,0xFC);


MIDL_DEFINE_GUID(IID, IID_IAcadEllipse,0x4344BB8D,0x7D90,0x48F0,0xA4,0x49,0xA4,0x53,0xC6,0xC8,0x72,0xDB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadEllipse,0x39801984,0xF2A2,0x470A,0xAE,0xEA,0x3B,0xD9,0x35,0x83,0x51,0x15);


MIDL_DEFINE_GUID(IID, IID_IAcadHatch,0x2122AAFA,0xE832,0x4CFC,0xB5,0x0D,0x02,0xC8,0x74,0x86,0xAE,0xB9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHatch,0x21A1F483,0x4634,0x41C7,0x83,0x79,0x83,0x7D,0x24,0x75,0x98,0x37);


MIDL_DEFINE_GUID(IID, IID_IAcadLeader,0xD9D757E9,0xC847,0x4E7C,0xA5,0x27,0xDE,0x5E,0xE0,0xFE,0xC2,0xDE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLeader,0xA9765A6D,0x19DA,0x42AE,0xBE,0xDB,0xA0,0xAB,0x53,0xD9,0x2D,0x39);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntity,0x187637E1,0xB4AE,0x40F3,0xB0,0xC3,0xCD,0x3D,0x2E,0x25,0xF8,0x75);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeaderLeader,0x3C27E34C,0x16FD,0x4F7F,0xB6,0x71,0xDC,0x83,0x96,0x0A,0x47,0x50);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeaderLeader,0x9B321A13,0x6CE7,0x4481,0x9E,0xEA,0xF2,0x28,0x02,0xBA,0xFF,0x88);


MIDL_DEFINE_GUID(IID, IID_IAcadMLeader,0xD412986F,0x1338,0x4A82,0xAE,0x5F,0x4F,0x96,0xE6,0xD9,0x85,0x00);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLeader,0x68DFB05E,0xC0B6,0x436F,0xA9,0x24,0x9D,0x6F,0x19,0x1D,0x8D,0x55);


MIDL_DEFINE_GUID(IID, IID_IAcadLWPolyline,0x745F1B02,0xDE82,0x41AB,0x83,0xD7,0xE2,0xD3,0xFF,0xE1,0x39,0x71);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLWPolyline,0xCBECB295,0x246A,0x4A97,0x8F,0xF8,0x4E,0x6C,0x7F,0xE3,0xE1,0x49);


MIDL_DEFINE_GUID(IID, IID_IAcadLine,0x98C39D14,0x5C8C,0x4928,0x83,0x5E,0x67,0xB9,0xA2,0x9F,0x09,0x60);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLine,0xE23A9445,0xE89E,0x44D3,0xBD,0x7B,0x6B,0x07,0xD9,0x73,0x0E,0x9E);


MIDL_DEFINE_GUID(IID, IID_IAcadMText,0x4FA813C4,0x0953,0x4C18,0x97,0xDB,0x78,0xC5,0xA4,0xFD,0x08,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMText,0xD8449ECF,0xF172,0x46F3,0xA1,0x32,0xD5,0x6E,0x7E,0x86,0xC0,0x8E);


MIDL_DEFINE_GUID(IID, IID_IAcadPoint,0x438023C7,0x441D,0x495E,0xB1,0x5B,0xFB,0x3D,0x97,0x66,0x2F,0x3D);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPoint,0x9A2B5ED0,0x7D3C,0x435D,0x87,0x90,0x45,0xD2,0x04,0x35,0xB9,0xDB);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyline,0x20704759,0xF2DD,0x4E37,0x96,0x64,0x68,0x96,0x39,0x46,0x9D,0xE7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyline,0x82A6B685,0x6316,0x4A73,0xB2,0x87,0xCC,0x2C,0x59,0xBF,0xB6,0x42);


MIDL_DEFINE_GUID(IID, IID_IAcadPolygonMesh,0x7DF849FA,0xF890,0x4024,0x81,0x90,0x00,0xFC,0x51,0x95,0x51,0xA7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolygonMesh,0x8DD8A48A,0x7150,0x4295,0x8E,0x88,0x06,0x6F,0x34,0x80,0x80,0x0D);


MIDL_DEFINE_GUID(IID, IID_IAcadRay,0x1137A576,0xFD66,0x4F35,0xB6,0xD5,0x4C,0x73,0x61,0x9E,0x0B,0xC1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRay,0x20EA8E69,0xD28E,0x47C4,0x9A,0x41,0xDE,0x49,0x9E,0x72,0xAD,0xD6);


MIDL_DEFINE_GUID(IID, IID_IAcadShape,0xEA86852D,0x029A,0x43A5,0xA5,0x25,0x75,0xAF,0x70,0xC9,0xC4,0xC8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadShape,0x804AA8B5,0xAF7E,0x4588,0xB4,0xD7,0x6A,0x0C,0x35,0x6C,0x85,0xC3);


MIDL_DEFINE_GUID(IID, IID_IAcadSolid,0x3C08FAB2,0xC62F,0x46DD,0xB6,0x7B,0xAD,0x54,0x99,0x08,0xC1,0xFD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSolid,0xDB442F82,0x1C89,0x4F44,0x8E,0x4A,0xFE,0x56,0xE8,0x34,0x17,0x39);


MIDL_DEFINE_GUID(IID, IID_IAcadSpline,0xC8A5A564,0x4278,0x482C,0xA1,0xC8,0x3E,0x7C,0x7C,0xFF,0xB0,0x4F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSpline,0xF5642C17,0x04BD,0x461B,0xBB,0x44,0xB4,0x3F,0xB1,0x91,0xFB,0xAB);


MIDL_DEFINE_GUID(IID, IID_IAcadText,0xA94E091F,0xE3A4,0x4230,0x8F,0xA9,0x4A,0x78,0xC1,0x9B,0x98,0xA5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadText,0xBB804E3F,0x871C,0x4C93,0x9E,0xF0,0xDC,0x8C,0x8C,0x25,0xA9,0x73);


MIDL_DEFINE_GUID(IID, IID_IAcadTolerance,0x8F58B9FA,0x56C0,0x429C,0x97,0x5E,0x1A,0x23,0x1F,0x49,0xAD,0xD6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTolerance,0x3B917D35,0x58B5,0x4241,0x88,0xEC,0x3F,0xDF,0xFE,0x5E,0xE7,0xBB);


MIDL_DEFINE_GUID(IID, IID_IAcadTrace,0x72F52267,0x9D93,0x403A,0xA6,0xD1,0xB5,0x16,0xB9,0xBC,0xA7,0x16);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTrace,0x5B863C76,0x0448,0x4D59,0xB4,0x4D,0xE4,0xB1,0xDF,0x2F,0x60,0xB0);


MIDL_DEFINE_GUID(IID, IID_IAcadXline,0xA6021869,0x03B9,0x4AE7,0xA2,0x74,0x83,0xF4,0xC1,0x01,0xC3,0xB9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadXline,0x637E9BE3,0xA3EA,0x4C72,0x8D,0xDB,0x04,0x2C,0x42,0x70,0x2F,0x4D);


MIDL_DEFINE_GUID(IID, IID_IAcadPViewport,0x1A32C6EF,0x2444,0x4E9F,0x8E,0xA1,0x68,0xC0,0x82,0x7A,0x12,0xB9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPViewport,0xCE75F892,0x6AA0,0x4E4F,0x8C,0xDA,0x1E,0xD5,0x7C,0x28,0xB6,0x69);


MIDL_DEFINE_GUID(IID, IID_IAcadMInsertBlock,0x7F6D3808,0xC8A3,0x463A,0xBA,0xD5,0xD3,0xCA,0x25,0x1A,0x49,0xC6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMInsertBlock,0x92A89199,0xADF3,0x4077,0xB7,0x0E,0x22,0xC1,0x68,0xA3,0x7B,0x7A);


MIDL_DEFINE_GUID(IID, IID_IAcadPolyfaceMesh,0x2C2E24FC,0xBA01,0x42A3,0x9C,0x39,0x9B,0xE1,0xD5,0x21,0x17,0xAE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPolyfaceMesh,0xAAD96012,0x9374,0x4EDF,0x82,0x80,0x1F,0x0F,0xBE,0x5D,0xCE,0x51);


MIDL_DEFINE_GUID(IID, IID_IAcadMLine,0x1ADD0CEF,0xFC3F,0x4118,0x8F,0x79,0x31,0x3C,0x1D,0x16,0x88,0xC3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMLine,0x6A7E8842,0xFAD8,0x4548,0x8B,0x1C,0x8C,0x27,0xB0,0xEE,0x4C,0x4B);


MIDL_DEFINE_GUID(IID, IID_IAcadExternalReference,0x846AE370,0xB27D,0x486C,0xB2,0x9E,0x7B,0x00,0x37,0x07,0x7C,0x99);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExternalReference,0x7C378249,0x6A4E,0x4447,0x88,0xD9,0x0B,0x15,0xAF,0xF0,0x38,0xB5);


MIDL_DEFINE_GUID(IID, IID_IAcadTable,0xC823CC0C,0x3D96,0x48A0,0x92,0x93,0x2F,0x08,0xB6,0xB2,0x41,0x69);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadTable,0xE51E67A2,0x4F9D,0x4B05,0xAE,0xB0,0xB4,0x4C,0x83,0x91,0xF6,0x54);


MIDL_DEFINE_GUID(IID, IID_IAcadOle,0x44C98A67,0x3B3A,0x459D,0x99,0xAF,0x75,0x88,0x64,0xE1,0xD8,0x3C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadOle,0xB9714567,0x1AF7,0x4F36,0x9C,0xAE,0x5A,0x0A,0x64,0xD4,0x78,0x6C);


MIDL_DEFINE_GUID(IID, IID_IAcadHelix,0x5F241F39,0xFEF3,0x4169,0x9D,0xFA,0x60,0x80,0x47,0x97,0x35,0xA6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadHelix,0x751E5205,0x42A7,0x444F,0x90,0x33,0x35,0x4A,0xC4,0xC6,0x3A,0x92);


MIDL_DEFINE_GUID(IID, IID_IAcadSurface,0x80BE3266,0xF1F7,0x4F13,0x95,0x24,0xDA,0x63,0xF4,0xCA,0xE6,0x6B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSurface,0x61DEA7D6,0x2C60,0x44DA,0xA4,0xAF,0x59,0x0A,0x6E,0x4A,0x8B,0xE4);


MIDL_DEFINE_GUID(IID, IID_IAcadPlaneSurface,0x503C3ECF,0xE57F,0x4100,0x81,0x81,0x8F,0x43,0xB4,0xE7,0x91,0x8F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlaneSurface,0x7E49F8C0,0x3739,0x4369,0x9A,0x4C,0xEB,0x79,0xB2,0x8C,0xC5,0x2B);


MIDL_DEFINE_GUID(IID, IID_IAcadExtrudedSurface,0x8ACC2140,0x44FA,0x4281,0xBA,0x12,0x75,0x9F,0x72,0x43,0x30,0xEF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadExtrudedSurface,0x161ED34A,0x21F6,0x49EF,0xAF,0xA9,0x5F,0x35,0x48,0xCF,0x12,0x06);


MIDL_DEFINE_GUID(IID, IID_IAcadRevolvedSurface,0x11789D18,0x1182,0x4D4A,0xB7,0x11,0x85,0x53,0xC7,0xF4,0x90,0xF4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadRevolvedSurface,0x63A5DE2E,0x5C40,0x4379,0xA2,0xFC,0x21,0x5A,0x2E,0x1E,0x83,0xD4);


MIDL_DEFINE_GUID(IID, IID_IAcadSweptSurface,0x532C04E8,0xA04C,0x40A5,0x91,0x59,0xFE,0x25,0x43,0xF6,0x1A,0x5E);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSweptSurface,0x62FEB258,0xFCF2,0x4187,0xA3,0x84,0xB9,0x8E,0xB8,0x62,0x6D,0x2D);


MIDL_DEFINE_GUID(IID, IID_IAcadLoftedSurface,0xBBCF2EF8,0xDF8E,0x4DF4,0xBA,0x78,0xF1,0xE2,0x73,0xAE,0x9B,0xFC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLoftedSurface,0xB506EF59,0x2C35,0x49A4,0xB2,0x6E,0x5C,0x53,0x82,0x6D,0xA5,0x48);


MIDL_DEFINE_GUID(IID, IID_IAcadSection,0x0548B482,0xF365,0x4174,0x89,0x76,0x7A,0x3F,0x3B,0x6A,0x50,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSection,0xFFD094CF,0x76E3,0x473B,0xB5,0xDF,0x45,0xDD,0xC4,0x2A,0x31,0xC7);


MIDL_DEFINE_GUID(IID, IID_IAcadSectionManager,0xA4D79A6D,0x5BF7,0x4A13,0x82,0x1C,0x71,0x6E,0x04,0xBC,0x67,0x47);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSectionManager,0x6C55F1E0,0x9AA8,0x44BA,0x96,0x32,0x4B,0xB2,0xB1,0x73,0xC3,0x27);


MIDL_DEFINE_GUID(IID, IID_IAcadUnderlay,0x06C336F9,0xDC24,0x42D4,0x9C,0xEF,0xB9,0xAA,0x98,0xCE,0x85,0xB0);


MIDL_DEFINE_GUID(IID, IID_IAcadDwfUnderlay,0x2AD7F9D8,0x6458,0x44F2,0x92,0x71,0x7F,0xC8,0x56,0x4E,0x47,0xB3);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDwfUnderlay,0x26A2974C,0x89C3,0x410D,0xB5,0xBC,0xC4,0xC7,0x89,0xA8,0x9C,0xE8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDgnUnderlay,0xD7322BD4,0xA003,0x4557,0x8A,0x39,0x68,0x09,0xCC,0x73,0x17,0xE6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPdfUnderlay,0xFABB88BC,0xF9CB,0x422C,0x83,0x97,0xD1,0x80,0xB3,0xAA,0xA8,0x7B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntity,0x41B97764,0x0707,0x4378,0x9B,0xB5,0xE7,0x86,0xD0,0x6A,0x73,0xA9);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidFace,0x249EC36A,0x2297,0x4DB0,0x82,0x08,0xEF,0xFE,0x0A,0xA6,0x28,0x59);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidFace,0x8CB29CC7,0xF5AE,0x4268,0xA1,0x86,0xED,0x08,0x1B,0x13,0x95,0x95);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidEdge,0xDD28E836,0xBE6A,0x44F9,0xB2,0xCF,0xF0,0x48,0xBA,0x30,0xF3,0x6B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidEdge,0xA8AADF45,0x4C8E,0x4988,0xA9,0xAC,0xCC,0xD5,0x41,0x8E,0xCB,0x10);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidVertex,0x8F15D4FD,0xB2D2,0x4B40,0xA7,0x2C,0x3D,0xA6,0xFD,0x2B,0x7E,0x8A);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidVertex,0x2EBFB6DD,0xB4E7,0x4ED6,0x9F,0x9E,0x02,0x97,0xDB,0xE1,0xE8,0x17);


MIDL_DEFINE_GUID(IID, IID_IAcadSubEntSolidNode,0x8423B884,0xD720,0x4E0E,0xAD,0xA1,0x84,0xF9,0x65,0x90,0x6B,0xBE);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubEntSolidNode,0x9E5B5877,0xFEF0,0x4DF7,0x98,0xC1,0x93,0xB2,0x44,0x71,0xBD,0x0A);


MIDL_DEFINE_GUID(IID, IID_IAcadWipeout,0x4DE0B3C0,0x8C8C,0x4F60,0x98,0x5E,0x5E,0x3A,0x48,0xCA,0x7D,0x41);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadWipeout,0xC242F211,0x25FA,0x4F6F,0xB5,0x58,0x7F,0x99,0x01,0x45,0xA4,0x63);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMesh,0x00C04E1C,0x0800,0x49FA,0xB9,0x98,0x4F,0xEB,0x50,0x8B,0x7E,0xA0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMesh,0xA753601C,0xDDC1,0x48E0,0x84,0x9D,0x9D,0x01,0xD0,0x64,0x0D,0x39);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshFace,0x7E6A1C2C,0x560B,0x468D,0x82,0x26,0xF2,0x97,0xAA,0x53,0x95,0x66);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshFace,0x6D6809F5,0xE09B,0x45F7,0xA9,0x02,0x79,0x0F,0x39,0x81,0x00,0xBA);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshEdge,0x5598B010,0x6955,0x45B3,0x96,0x39,0x04,0x44,0x6C,0x24,0x24,0x64);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshEdge,0xD4998B7F,0x22BC,0x4BCB,0x8B,0x6B,0x1C,0x57,0xE5,0x35,0x2B,0x8E);


MIDL_DEFINE_GUID(IID, IID_IAcadSubDMeshVertex,0x8224C5E8,0x87E2,0x4659,0xB8,0x3E,0xFE,0xB5,0xF1,0x20,0xD2,0xCC);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSubDMeshVertex,0xD8A3FC19,0x3298,0x4004,0x80,0x08,0xB5,0xA6,0x09,0x23,0x3A,0xAF);


MIDL_DEFINE_GUID(IID, IID_IAcadNurbSurface,0x9577DF57,0xF14E,0x4E23,0xB4,0xEB,0x0A,0x83,0x02,0xA8,0x9E,0x67);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadNurbSurface,0x093E27C7,0xDED1,0x4A4D,0xB5,0x28,0xAC,0x80,0xC4,0x8F,0x44,0xD8);


MIDL_DEFINE_GUID(IID, IID_IAcadDimension,0xFE1E3E07,0x1179,0x4CAB,0x9C,0x3E,0xA8,0xDA,0xB7,0xCD,0x40,0xB8);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimension,0x3E205563,0xBF33,0x48EA,0xBD,0x75,0x51,0xB3,0x40,0xFB,0x48,0xBB);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAligned,0xDC6C4464,0x9AE4,0x45D5,0xBE,0x35,0xA6,0xC6,0x22,0x48,0x21,0x3C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAligned,0x0D3897F5,0xB1C6,0x44A1,0xA0,0xD8,0x7F,0x64,0x5F,0x6B,0xB9,0x80);


MIDL_DEFINE_GUID(IID, IID_IAcadDimAngular,0xB606EC4B,0x90EF,0x47D9,0x99,0x07,0x51,0x7B,0xDE,0xD3,0x10,0x91);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimAngular,0x20A717D1,0x9D4B,0x45E2,0xA3,0x82,0xBF,0xF2,0x76,0x04,0xCB,0x33);


MIDL_DEFINE_GUID(IID, IID_IAcadDimDiametric,0x16CF4ABC,0xBAA8,0x4353,0xBB,0x67,0xD1,0x3A,0xE0,0x6A,0x76,0xA2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimDiametric,0x53D14ED5,0xFF5E,0x40BF,0x90,0x0C,0x76,0xBF,0x10,0x47,0x33,0x66);


MIDL_DEFINE_GUID(IID, IID_IAcadDimOrdinate,0xA5ED6DCC,0x9ED3,0x4DF4,0x8A,0x4A,0xE2,0xB7,0x74,0x39,0xAC,0x22);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimOrdinate,0xA2CA0DA3,0x476E,0x451D,0xA4,0x1F,0xFC,0xEA,0xAE,0xD5,0x5F,0x1D);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadial,0xA28F9617,0x345E,0x4F99,0xA4,0x8C,0xC3,0xA7,0x2E,0x63,0xC2,0x42);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadial,0x9FFB97D4,0x55B4,0x42DA,0x8C,0x11,0x9A,0x61,0x96,0xD1,0x92,0x06);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRotated,0x58DA9A91,0x96DC,0x4FA1,0x8D,0xBD,0x6E,0x18,0xA7,0xCC,0x88,0x97);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRotated,0x93C1A226,0xACA2,0x4670,0xB9,0x2E,0xF2,0xE3,0x35,0xD7,0x58,0x46);


MIDL_DEFINE_GUID(IID, IID_IAcadDim3PointAngular,0x713644CA,0xD4E5,0x43F5,0x9C,0x82,0x24,0xDA,0x4C,0x1A,0x23,0x11);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDim3PointAngular,0xE532BF49,0xCC98,0x4FF7,0xB3,0x9A,0x63,0x0E,0x14,0xC4,0xE5,0x9B);


MIDL_DEFINE_GUID(IID, IID_IAcadDimArcLength,0xD3E8ECC7,0x4A4C,0x45A7,0x93,0x9D,0xBF,0x05,0x98,0xAB,0xF3,0x4B);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimArcLength,0xD4C2BE13,0x62CD,0x42BD,0xBE,0x03,0x92,0xF6,0x1B,0x3E,0x82,0x1D);


MIDL_DEFINE_GUID(IID, IID_IAcadDimRadialLarge,0x71447ED7,0x4C62,0x47DC,0xBC,0x77,0xC4,0xD2,0x2D,0x4D,0xFC,0xF6);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDimRadialLarge,0xCADE6B06,0x183A,0x4A63,0xB8,0x9D,0x10,0xD3,0xF7,0x25,0xB1,0x69);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadBlock,0xF23A1A9C,0xA043,0x4A61,0xB0,0x4C,0xFA,0x8C,0x47,0xDD,0xC2,0x8F);


MIDL_DEFINE_GUID(IID, IID_IAcadModelSpace,0x3816ECCF,0x7721,0x442A,0xA4,0x7A,0xD9,0x51,0xC7,0x81,0xB0,0xA9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadModelSpace,0x6679407F,0x523D,0x4D00,0x8F,0x3D,0x04,0x6D,0x3B,0xE9,0x81,0x8D);


MIDL_DEFINE_GUID(IID, IID_IAcadPaperSpace,0x6662B016,0xC39E,0x4B58,0xA8,0xE6,0xF0,0x21,0x8A,0xB5,0x34,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPaperSpace,0xFE90013D,0x557A,0x4E57,0x85,0x10,0x7C,0xE4,0x50,0x7A,0xCA,0x92);


MIDL_DEFINE_GUID(IID, IID_IAcadPointCloud,0x16B74D4D,0x10B6,0x452E,0xA9,0xA5,0x0D,0xCC,0x8A,0x04,0x4B,0xD2);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPointCloud,0xAD939B01,0x9EE1,0x4747,0x85,0xAD,0x8F,0x54,0x8A,0xA6,0xEB,0xAF);


MIDL_DEFINE_GUID(IID, IID_IAcadFileDependency,0x4B01FF27,0xF52C,0x4E49,0xBE,0x3C,0xB1,0xA9,0xE3,0xB8,0x50,0x30);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadFileDependency,0xE1023292,0xC157,0x40BE,0x8C,0xD8,0xDB,0xD8,0x32,0x66,0x63,0x29);


MIDL_DEFINE_GUID(IID, IID_IAcadFileDependencies,0xBF7BDBF3,0x2062,0x4B29,0xAB,0xD4,0x1E,0x0F,0x8E,0x41,0x77,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadFileDependencies,0x8CFA36DA,0xA44B,0x489E,0x91,0x29,0x51,0xBC,0xD9,0x2D,0x54,0xD5);


MIDL_DEFINE_GUID(IID, IID_IAcadSummaryInfo,0x2F622E8B,0x8571,0x439A,0x9F,0xC6,0x06,0xF5,0xD4,0x0B,0x83,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSummaryInfo,0xB7FE720C,0xD82C,0x4422,0x81,0x71,0x5F,0x72,0x81,0xD1,0x6E,0x88);


MIDL_DEFINE_GUID(IID, IID_IAcadDatabasePreferences,0x6B2742BA,0x98A9,0x44AE,0xA3,0x74,0xBD,0x42,0x18,0x4C,0xAC,0xE4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabasePreferences,0xB40CEB1C,0xE4C8,0x4683,0x97,0xE4,0xCC,0xC7,0xC1,0x55,0xA1,0xCF);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDatabase,0x0B06F972,0xEF3C,0x434A,0xB7,0x21,0x23,0x23,0xCE,0x72,0x1E,0xAC);


MIDL_DEFINE_GUID(IID, IID_IAcadSecurityParams,0xC66DEC0E,0x2987,0x4258,0xAA,0x29,0x7D,0xE1,0xF6,0x6F,0x9C,0x6C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSecurityParams,0x6A90643D,0x2752,0x4E46,0x88,0xF2,0xA9,0x4C,0x73,0xFE,0xCE,0xDA);


MIDL_DEFINE_GUID(IID, IID_IAcadLayerStateManager,0xA6FEB7FF,0x4B13,0x4EE6,0xB7,0xF9,0x76,0x3B,0x51,0x82,0xB9,0x5C);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadLayerStateManager,0xB89F32C9,0xC786,0x49FF,0x81,0xEC,0x2C,0xDC,0x5C,0x03,0x06,0x0A);


MIDL_DEFINE_GUID(IID, DIID__DAcadApplicationEvents,0x740492A4,0xCD10,0x42E4,0x94,0xDC,0x3C,0xE6,0x91,0x5C,0x5D,0x37);


MIDL_DEFINE_GUID(IID, IID_IAcadDocument,0x849850B8,0x84BA,0x44A4,0xAD,0xF5,0xC7,0xFE,0x74,0xF1,0x11,0xFC);


MIDL_DEFINE_GUID(IID, IID_IAcadDocuments,0xF032C182,0xB579,0x446F,0xB8,0x5B,0xE6,0x67,0x1B,0xAA,0xB4,0x2E);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferences,0x864F8855,0xBCBC,0x4BE0,0xB5,0x20,0xC1,0x9B,0x13,0x64,0x5D,0x73);


MIDL_DEFINE_GUID(IID, IID_IAcadMenuGroups,0x403247AE,0xAF21,0x404C,0xB2,0x05,0x2A,0xC7,0x5E,0x3B,0xF7,0xB3);


MIDL_DEFINE_GUID(IID, IID_IAcadMenuBar,0x23BC1D22,0xAAF9,0x46EF,0x86,0x7E,0xA0,0x70,0x04,0xAC,0x7B,0xE7);


MIDL_DEFINE_GUID(IID, IID_IAcadApplication,0x070AA05D,0xDFC1,0x4E64,0x83,0x79,0x43,0x22,0x69,0xB4,0x8B,0x07);


MIDL_DEFINE_GUID(IID, IID_IAcadState,0x92021D7A,0xC980,0x465F,0xA2,0x22,0x05,0x3E,0x42,0xA8,0x38,0xE1);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadState,0xBA1A40C0,0x534F,0x4309,0x89,0x2C,0x95,0x9B,0x38,0xA3,0xB0,0xEB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadApplication,0xBD0DEB94,0x63DB,0x4392,0x94,0x20,0x6E,0xEE,0x05,0x09,0x4B,0x1F);


MIDL_DEFINE_GUID(IID, IID_IAcadSelectionSet,0x489F6D49,0x0903,0x4EED,0x87,0xEB,0xD1,0xA7,0x28,0x45,0x39,0xD5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSelectionSet,0x2895AED8,0xFCE7,0x4ED6,0x8F,0x67,0xEA,0x66,0x5A,0xA7,0x42,0xAE);


MIDL_DEFINE_GUID(IID, IID_IAcadSelectionSets,0x7B8DED20,0x669F,0x4CD1,0x94,0xC1,0x48,0x04,0xD3,0x38,0x73,0xF7);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadSelectionSets,0xE4EF8F0F,0x1F15,0x499F,0x97,0x48,0xDC,0xB0,0xE8,0x44,0xC7,0x69);


MIDL_DEFINE_GUID(IID, IID_IAcadPlot,0x1D0E79C6,0x0D4C,0x42D1,0x8C,0xD1,0x4D,0x62,0x80,0xCE,0x84,0x38);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPlot,0x3020EA80,0xA655,0x4767,0xAA,0x17,0xCD,0x1C,0x30,0xED,0x93,0x93);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesFiles,0xABF6E61E,0x68CC,0x499A,0xA7,0x54,0x10,0x71,0x4D,0x08,0x3E,0x87);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesDisplay,0x46728F0B,0x4A87,0x41F5,0xAC,0xBE,0xCC,0x5F,0x01,0x8A,0x78,0x1F);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesOpenSave,0x3EC951C1,0x6071,0x4641,0x8A,0xC8,0xEF,0xA9,0xED,0xEE,0x73,0xAD);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesUser,0x948A929B,0x9E5E,0x4870,0xA0,0x3F,0x09,0xBB,0x12,0xFA,0x7B,0x60);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesProfiles,0xB8368F75,0xFBA3,0x4DB9,0x9C,0xC0,0x8A,0x70,0x1B,0x1B,0x27,0x0C);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesDrafting,0x8F10987A,0xF692,0x4DFA,0x89,0x42,0x13,0x2F,0x8B,0x8F,0x72,0x7E);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesOutput,0x4F6191AE,0x0948,0x48FA,0x93,0xE9,0x60,0xDB,0x0A,0xC0,0x2F,0x48);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesSelection,0x8F11CCE2,0x7363,0x49EE,0xA8,0xBA,0xD6,0x9B,0x0F,0x2A,0x28,0x7E);


MIDL_DEFINE_GUID(IID, IID_IAcadPreferencesSystem,0xDC5526CB,0xAF8A,0x4537,0xA9,0x39,0xB3,0xB1,0x7C,0x8E,0xA3,0x1F);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferences,0x0F7FC423,0xA03C,0x46DD,0x89,0x0B,0xBC,0xAA,0x80,0xDE,0xF8,0x40);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesDrafting,0x8BFF9AFC,0xFC19,0x4780,0xB5,0x50,0x4A,0xF9,0x74,0x63,0x79,0xD5);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesDisplay,0x61C3009A,0x4B37,0x406F,0xA3,0x58,0x88,0x79,0x7A,0xBA,0x5D,0xC4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesFiles,0xEDE25C38,0x79E8,0x46DD,0xBC,0xE4,0xC3,0x6F,0x9A,0xC2,0xEA,0xA4);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesOpenSave,0xDD4BCD14,0x4116,0x487D,0x80,0x08,0x31,0x34,0x23,0xBB,0x4D,0x47);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesOutput,0x5CFCE7A8,0x978F,0x4822,0xBB,0xB3,0x70,0xAE,0xB5,0xBA,0x6D,0xC9);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesProfiles,0x29CB2A81,0xBB4A,0x4784,0xB2,0xD6,0x86,0x74,0x3F,0x08,0x81,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesSelection,0x9F609989,0x5BB7,0x472C,0xBF,0xD6,0x58,0x25,0x79,0x6E,0xDD,0x96);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesSystem,0xC12C67F4,0x5B44,0x46F6,0x86,0xFE,0x1B,0x91,0xD8,0x6C,0x37,0x27);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPreferencesUser,0xBCCDD9AD,0x6D11,0x4853,0xA1,0xBE,0x5A,0x9B,0x63,0x05,0x0E,0xAE);


MIDL_DEFINE_GUID(IID, IID_IAcadMenuGroup,0xBF24947E,0x1F2C,0x45FF,0xBF,0x43,0x7E,0x2B,0xC5,0x06,0x04,0x26);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMenuGroups,0xE0CC7F11,0x8046,0x45FC,0xA4,0x66,0xD5,0xA1,0x46,0x98,0x67,0x21);


MIDL_DEFINE_GUID(IID, IID_IAcadPopupMenus,0xB79EF39F,0x9A09,0x4F4E,0x91,0xDE,0xC2,0x82,0x48,0x10,0x20,0xE5);


MIDL_DEFINE_GUID(IID, IID_IAcadToolbars,0x8B842485,0x24D3,0x4B01,0x87,0xC0,0xBC,0xF0,0xC9,0xB3,0xB2,0x08);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMenuGroup,0x8713D3B3,0x2D28,0x468E,0xA6,0x81,0x50,0x77,0xE4,0xBC,0x67,0xC6);


MIDL_DEFINE_GUID(IID, IID_IAcadPopupMenu,0xB4E37366,0x0E66,0x4D36,0xA7,0xCA,0xD1,0x77,0xD3,0xEC,0x87,0x10);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadMenuBar,0xEF0E879D,0x9578,0x4DD9,0x8E,0xA3,0x3A,0x1C,0x66,0x61,0x2A,0x93);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPopupMenus,0x53A5FCA9,0xC4EE,0x4DA0,0xB0,0x10,0x8F,0xBF,0x7A,0x3B,0xA3,0xDC);


MIDL_DEFINE_GUID(IID, IID_IAcadPopupMenuItem,0x6A657446,0x8493,0x429D,0xB7,0xFE,0xD2,0xA0,0x80,0x3C,0xDA,0x44);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPopupMenu,0xF3FD4C2C,0xA1AD,0x42DE,0xA0,0x41,0x32,0x74,0x22,0xEC,0xBB,0x70);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadPopupMenuItem,0xADB4A0DA,0x8630,0x488A,0x89,0x51,0xC2,0x17,0x1D,0xBD,0x3C,0x17);


MIDL_DEFINE_GUID(IID, IID_IAcadUtility,0x9F8DEF7D,0x3BC0,0x475D,0x8F,0xEF,0xCE,0x87,0x65,0xB2,0x53,0xA0);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadUtility,0x9EA241B2,0xB17A,0x4D7E,0xAC,0xEA,0x66,0xDD,0x10,0xF1,0xDD,0x31);


MIDL_DEFINE_GUID(IID, DIID__DAcadDocumentEvents,0x94228FB1,0xC8A5,0x4294,0x9A,0x7B,0x3C,0x4E,0x8E,0x23,0xCB,0xFD);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDocument,0x6A221957,0x2D85,0x42A7,0x8E,0x19,0xBE,0x33,0x95,0x0D,0x1D,0xEB);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadDocuments,0x208ED56C,0x7ACF,0x4BEF,0x87,0xAC,0x3A,0xE6,0xAF,0x5B,0x7F,0x22);


MIDL_DEFINE_GUID(IID, IID_IAcadToolbar,0xC9BB5352,0xAEA9,0x44E3,0x80,0xD2,0xD0,0x65,0x3F,0xF3,0xC5,0x19);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadToolbars,0xAD2092CA,0x860A,0x4BED,0xB7,0xD3,0xE8,0x62,0x5A,0x61,0x29,0xE7);


MIDL_DEFINE_GUID(IID, IID_IAcadToolbarItem,0x6F7EB25B,0x8435,0x4A7F,0xA5,0xFF,0x9F,0xDB,0xAF,0xBB,0x67,0x76);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadToolbar,0x7BCA18E8,0x59DA,0x4E84,0x94,0xED,0x3C,0x8F,0x8A,0x86,0x71,0x44);


MIDL_DEFINE_GUID(CLSID, CLSID_AcadToolbarItem,0x8D6E4A9B,0x8013,0x498D,0x9E,0x9B,0x31,0xD8,0x35,0x9B,0xF8,0x64);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



