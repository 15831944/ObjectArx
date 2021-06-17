// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE ��
#include <afxodlgs.h>       // MFC OLE �Ի�����
#include <afxdisp.h>        // MFC �Զ�����
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC ���ݿ���
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO ���ݿ���
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT


#include "resource.h"
#include "AutoAAD.h"

#include "aced.h"
#include "accmd.h"
#include "AcString.h"
#include "gepnt3d.h"
#include "geassign.h"
#include "dbents.h"
#include "dbmain.h"
#include "acdocman.h"
#include "acarray.h"
#include "adscodes.h"
#include "acedads.h"
#include "dbapserv.h"
#include "migrtion.h"
#include "dbobjptr.h"
#include "acestext.h"
#include "axlock.h"
#include "acgs.h"
#include "gs.h"

#if ARX == 2020
#include "acedCmdNF.h"
#endif

#include "CADUtils.h"

#include <afxcontrolbars.h>
#include <afxcontrolbars.h>

#define cmd_group_name _T("cadtest1")
#define __STR(x)    #x
#define _STR(x)     __STR(x)
////////////////////////////////////////////////////////////////////////////////////////
struct OCmdData
{
    AcString        gname;
    AcString        lname;
    AcRxFunctionPtr func;
    Adesk::Int32    flags;
};


#pragma section("arxcmds$__a", read, shared)
#pragma section("arxcmds$__z", read, shared)
#pragma section("arxcmds$__m", read, shared)

extern "C" {
	__declspec(selectany) __declspec(allocate("arxcmds$__a")) OCmdData* __pArxCmdMapEntryFirst = NULL;
	__declspec(selectany) __declspec(allocate("arxcmds$__z")) OCmdData* __pArxCmdMapEntryLast = NULL;
}

#if defined(_WIN64)
#define ARXCMD_ENTRY_PRAGMA(gname) __pragma(comment(linker, "/include:__pArxCmdMap_" #gname)) ;
#else
#define ARXCMD_ENTRY_PRAGMA(gname) __pragma(comment(linker, "/include:___pArxCmdMap_" #gname)) ;
#endif

#define ARXCMD(gname, lname, flags) \
	__declspec(selectany) OCmdData __ArxCmdMap_##gname = { _T(#gname), _T(#lname), gname, flags }; \
	extern "C" __declspec(allocate("arxcmds$__m")) __declspec(selectany) OCmdData* __pArxCmdMap_##gname = &__ArxCmdMap_##gname; \
	ARXCMD_ENTRY_PRAGMA(gname)

#define ARXCMD2(name, flags) \
	void name( void ); \
	ARXCMD(name, name, flags); \
	void name( void )

#define ARXCMD3(name) ARXCMD2(name, ACRX_CMD_MODAL)

////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////
typedef int(*AdsFunctionPtr)(resbuf* rb);
struct OFuncData
{
    AcString        szFuncName;
    AdsFunctionPtr  pFunc;
};

#pragma section("adscmds$__a", read, shared)
#pragma section("adscmds$__z", read, shared)
#pragma section("adscmds$__m", read, shared)

extern "C" {
	__declspec(selectany) __declspec(allocate("adscmds$__a")) OFuncData* __pAdsCmdMapEntryFirst = NULL;
	__declspec(selectany) __declspec(allocate("adscmds$__z")) OFuncData* __pAdsCmdMapEntryLast = NULL;
}

#if defined(_WIN64)
#define ADSCMD_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:__pAdsCmdMap_" #name)) ;
#else
#define ADSCMD_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:___pAdsCmdMap_" #name)) ;
#endif

#define ADSCMD(name, funcname) \
	__declspec(selectany) OFuncData __AdsCmdMap_##funcname = { _T(#name), funcname }; \
	extern "C" __declspec(allocate("adscmds$__m")) __declspec(selectany) OFuncData* __pAdsCmdMap_##funcname = &__AdsCmdMap_##funcname; \
	ADSCMD_ENTRY_PRAGMA(funcname)

#define ADSCMD2(name, funcname) \
	int funcname( resbuf* rb ); \
	ADSCMD(name, funcname); \
	int funcname( resbuf* rb )

#define ADSFUNC(name) ADSCMD2(name, name)
////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////
struct OCustomObjData {
	AcRxClass* (*desc) ();
	void(*rxInit) ();
	bool bRegistered;
};

#pragma section("DBXCUSTOBJ$__a", read, shared)
#pragma section("DBXCUSTOBJ$__z", read, shared)
#pragma section("DBXCUSTOBJ$__m", read, shared)

extern "C" {
	__declspec(selectany) __declspec(allocate("DBXCUSTOBJ$__a")) OCustomObjData* __pDbCustObjMapEntryFirst = NULL;
	__declspec(selectany) __declspec(allocate("DBXCUSTOBJ$__z")) OCustomObjData* __pDbCustObjMapEntryLast = NULL;
}


#if defined(_WIN64)
#define DB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:__pDbCustObjMap_" #classname)) ;
#else
#define DB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:___pDbCustObjMap_" #classname)) ;
#endif


#define REGISTER_OBJECT(classname) \
    __declspec(selectany) OCustomObjData __DbCustObjMap_##classname = { classname::desc, classname::rxInit } ; \
    extern "C" __declspec(allocate("DBXCUSTOBJ$__m")) __declspec(selectany) OCustomObjData* __pDbCustObjMap_##classname = &__DbCustObjMap_##classname ; \
    DB_REGISTER_OBJECT_ENTRY_PRAGMA(classname)
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////

//���ر��������ͣפ�����ֻ��һ����ܿ죬���������ģ����ʱ��Ƚϳ��������ǻ��������⡣��Ȼ��cpuæ��Ӳ��æҲ���ܻ�������
//���̳�ʱ�䲻�˵�ԭ���Ǻܸ��ӵģ���򵥵ķ�ʽ�ǵ��Է�ʽ���˳����̣��������פ����������Ӧ��Ҳû���˳�ȥ����ͣ��������ʲô�����ʲô��û�������Ǿ���ϵͳ����������
//����û����Ӧ��������undoʵ��֮ǰ�ģ�
//û�С��༭��Ӧ����commandwillstart���Լ�����undoִ��֮ǰ�����Ƕ���undoʵ��֮ǰ�Ͳ���׼ȷ�����ˡ�
//����Ӧ����unappended�����ݿⷴӦ����objectUnAppended����ʱ����֮�󡣣�������fire_objectUnAppended��������ã�
//��U�����ѽ��ã�ʹ��UNDO������   UNDO��ִ��c,n��֧���ã�c,o��֧��
//������zwcad Fail to load one of SCLAD's module, the install maybe incomplete��ʾ��     vc2010���ȱʧ
//������zwcad 1�������հ���ʾ�� 2��Exception processing Message 0xc000005 Parametersϵͳ������ʾ��  .NET Firework 4.0ȱʧ
//��Coudn't find any installed languages!��ʾ�� ���԰�û��װ�ϣ���װһ��
//��defualt����customresfile�������ˡ�ƽ̨���ĸ�profile�����������ĸ�profile�����ȡcustomresfile
//�����ʶ�𣬿�����Ӧģ���Ƿ����