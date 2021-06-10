//
#include "stdafx.h"
#include <vector>

#if ARX >= 2020 || ZRX >= 2021

#ifdef ARX
#define ZcRxFunctionPtr AcRxFunctionPtr
#define ZTCHAR ACHAR
#define ZSoft Adesk
#define ZcEdUIContext AcEdUIContext
#define ZcEdCommand AcEdCommand
#endif // 

template<typename Tret, typename T>
Tret lambda_ptr_exec(T* v) {
	return (Tret)(*v)();
}
template<typename Tret = void, typename Tfp = void*(*)(), typename T>
Tfp lambda_ptr(T& v) {
	return (Tfp)lambda_ptr_exec<Tret, T>;
}
std::vector<ZcRxFunctionPtr> funVec;
void addCommand(const ZTCHAR* cmdGroupName, const ZTCHAR* cmdGlobalName,
	const ZTCHAR* cmdLocalName, ZSoft::Int32 commandFlags,
	void* FunctionAddr, ZcEdUIContext* UIContext = NULL,
	int fcode = -1, HINSTANCE hResourceHandle = NULL,
	ZcEdCommand** cmdPtrRet = NULL)
{
	//static void(*f0)() = (ZcRxFunctionPtr)FunctionAddr;  //静态变量，只针对单命令的示例
	funVec.push_back((ZcRxFunctionPtr)FunctionAddr);
	auto func = [&]()->void/***/ {
		try
		{
			//FunctionAddr;
			/*f0();*/
			funVec.back()();
			acutPrintf(_T("\n111!"));
		}
		catch (...)
		{
			acutPrintf(_T("\nexception in func!"));
		}
	};
	//void (*f)() = func;
	void*(*f)() = lambda_ptr(func);
#if 0
	class Func0
	{
	private:
		void* m_FunctionAddr;
	public:
		void operator()(void* vptr)
		{
			m_FunctionAddr = vptr;
		}
		void* ptr()
		{
			void(*f0)() = (ZcRxFunctionPtr)m_FunctionAddr;
			try
			{
				acutPrintf(_T("\nf0() in Fun0!"));
				f0();
			}
			catch (const std::exception&)
			{
				acutPrintf(_T("\nexception in Fun0!"));
			}
			return f0;
		}
	};
	Func0 func0;
	func0(FunctionAddr);
	ZcRxFunctionPtr f1 = (ZcRxFunctionPtr)func0.ptr();
#endif
	Acad::ErrorStatus es = acedRegCmds->addCommand(cmdGroupName, cmdGlobalName, cmdLocalName, commandFlags, (ZcRxFunctionPtr)f, UIContext, fcode, hResourceHandle, cmdPtrRet);
}
#endif

//addCommand(_T("Hello1"), _T("HelloWorld_try"), _T("HelloWorld_try"), ACRX_CMD_MODAL, HelloWorld_try);

void HelloWorld_try(void)
{
	try
	{
		acutPrintf(_T("\nHello World1!"));
		int* p = nullptr;
		*p = 1;
	}
	catch (/*const std::exception&*/...)
	{
		acutPrintf(_T("\nexception in helloworld1!"));
		throw _T("Error! NULL pointer!");
	}
}

#define  MyARXFunc(name) \
	void name0();\
	void name() {\
		try{name0();}\
		catch(...){acutPrintf(_T("\nexception in %s!"), _T(#name));}\
	}\
	void name0()\

MyARXFunc(HelloWorld_MyARX)
{
	acutPrintf(_T("\nHello World2!"));
	int* p = nullptr;
	*p = 1;
}