// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE 类
#include <afxodlgs.h>       // MFC OLE 对话框类
#include <afxdisp.h>        // MFC 自动化类
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC 数据库类
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO 数据库类
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC 对 Windows 公共控件的支持
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

//》关闭软件进程停驻。如果只是一会儿很快，那是正常的，如果时间比较长，可能是还是有问题。当然，cpu忙，硬盘忙也可能会这样。
//进程长时间不退的原因是很复杂的，最简单的方式是调试方式，退出进程，如果进程驻留，调试器应该也没有退出去，暂停看看在做什么，如果什么都没有做，那就是系统来不及处理。
//》有没有响应器，是在undo实体之前的？
//没有。编辑反应器的commandwillstart可以监听在undo执行之前，但是对于undo实体之前就不能准确监听了。
//对象反应器的unappended和数据库反应器的objectUnAppended触发时机在之后。（看代码fire_objectUnAppended在哪里调用）
//》U命令已禁用，使用UNDO命令将其打开   UNDO　执行c,n分支禁用，c,o分支打开
//》启动zwcad Fail to load one of SCLAD's module, the install maybe incomplete提示框     vc2010框架缺失
//》启动zwcad 1、弹出空白提示框 2、Exception processing Message 0xc000005 Parameters系统错误提示框  .NET Firework 4.0缺失
//》Coudn't find any installed languages!提示框 语言包没安装上，重装一次
//》defualt下有customresfile导致闪退。平台以哪个profile启动，就在哪个profile下面读取customresfile
//》命令不识别，看看相应模块是否加载