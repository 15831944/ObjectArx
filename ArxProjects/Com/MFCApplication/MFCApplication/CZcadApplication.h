// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#import "C:\\Program Files\\Common Files\\ZWSoft Shared\\zwcad21.tlb" no_namespace
// CZcadApplication 包装器类

class CZcadApplication : public COleDispatchDriver
{
public:
	CZcadApplication() {} // 调用 COleDispatchDriver 默认构造函数
	CZcadApplication(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CZcadApplication(const CZcadApplication& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IZcadApplication 方法
public:
	BOOL get_Visible()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_Visible(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	CString get_Caption()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_ActiveDocument()
	{
		LPDISPATCH result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_ActiveDocument(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_FullName()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long get_Height()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Height(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_WindowLeft()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_WindowLeft(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_Path()
	{
		CString result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long get_LocaleId()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long get_WindowTop()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_WindowTop(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_Version()
	{
		CString result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long get_Width()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Width(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_Preferences()
	{
		LPDISPATCH result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	BOOL get_StatusId(LPDISPATCH VportObj)
	{
		BOOL result;
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms, VportObj);
		return result;
	}
	VARIANT ListZrx()
	{
		VARIANT result;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void LoadZrx(LPCTSTR Name)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Name);
	}
	LPDISPATCH GetInterfaceObject(LPCTSTR ProgID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ProgID);
		return result;
	}
	void UnloadZrx(LPCTSTR Name)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Name);
	}
	void Update()
	{
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void Quit()
	{
		InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void Zoom(long Type, VARIANT * vParams)
	{
		static BYTE parms[] = VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Type, vParams);
	}
	LPDISPATCH get_VBE()
	{
		LPDISPATCH result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_MenuGroups()
	{
		LPDISPATCH result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_MenuBar()
	{
		LPDISPATCH result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void LoadZVB(LPCTSTR Name)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Name);
	}
	void UnloadZVB(LPCTSTR Name)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Name);
	}
	LPDISPATCH get_Documents()
	{
		LPDISPATCH result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void Eval(LPCTSTR Expression)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Expression);
	}
	long get_WindowState()
	{
		long result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_WindowState(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void RunMacro(LPCTSTR MacroPath)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, MacroPath);
	}
	void ZoomExtents()
	{
		InvokeHelper(0x24, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void ZoomAll()
	{
		InvokeHelper(0x25, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void ZoomCenter(VARIANT& Center, double Magnify)
	{
		static BYTE parms[] = VTS_VARIANT VTS_R8;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &Center, Magnify);
	}
	void ZoomScaled(double scale, long ScaleType)
	{
		static BYTE parms[] = VTS_R8 VTS_I4;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, scale, ScaleType);
	}
	void ZoomWindow(VARIANT& LowerLeft, VARIANT& UpperRight)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &LowerLeft, &UpperRight);
	}
	void ZoomPickWindow()
	{
		InvokeHelper(0x29, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	LPDISPATCH GetZcadState()
	{
		LPDISPATCH result;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void ZoomPrevious()
	{
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	__int64 get_HWND()
	{
		__int64 result;
		InvokeHelper(0x2c, DISPATCH_PROPERTYGET, VT_I8, (void*)&result, nullptr);
		return result;
	}
	void GetLicenseSerial(long * retType, BSTR * Serial, long chkLock, long * retIsNet)
	{
		static BYTE parms[] = VTS_PI4 VTS_PBSTR VTS_I4 VTS_PI4;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, retType, Serial, chkLock, retIsNet);
	}

	// IZcadApplication 属性
public:

};
