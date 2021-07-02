//
#include "stdafx.h"
#undef UNICODE

#ifndef UNICODE
#define UNICODE
#include "acpublishreactors.h"
#undef UNICODE
#endif

//#include "opmimp.h"
//#include "aduiEdit.h"  

/**
* reason: 头文件中根据UNICODE宏执行UNICODE函数或者MBCS多字节函数，用户未定义UNICODE宏宽字节传入多字节函数中执行导致编译出错
* method: 1>头文件去除UNICODE宏 2>报错的地方#define UNICODE 使用后 
*/