// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#import "C:\\Program Files\\Common Files\\ZWSoft Shared\\zwcad21.tlb" no_namespace
// CZcadLayout 包装器类

class CZcadLayout : public COleDispatchDriver
{
public:
	CZcadLayout() {} // 调用 COleDispatchDriver 默认构造函数
	CZcadLayout(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CZcadLayout(const CZcadLayout& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IZcadLayout 方法
public:
	CString get_Handle()
	{
		CString result;
		InvokeHelper(0x400, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	CString get_ObjectName()
	{
		CString result;
		InvokeHelper(0x401, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void GetXData(LPCTSTR AppName, VARIANT * XDataType, VARIANT * XDataValue)
	{
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x402, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, AppName, XDataType, XDataValue);
	}
	void SetXData(VARIANT& XDataType, VARIANT& XDataValue)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT;
		InvokeHelper(0x403, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &XDataType, &XDataValue);
	}
	void Delete()
	{
		InvokeHelper(0x404, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	__int64 get_ObjectID()
	{
		__int64 result;
		InvokeHelper(0x405, DISPATCH_PROPERTYGET, VT_I8, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x406, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_Database()
	{
		LPDISPATCH result;
		InvokeHelper(0x407, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	BOOL get_HasExtensionDictionary()
	{
		BOOL result;
		InvokeHelper(0x408, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH GetExtensionDictionary()
	{
		LPDISPATCH result;
		InvokeHelper(0x409, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	__int64 get_OwnerID()
	{
		__int64 result;
		InvokeHelper(0x40a, DISPATCH_PROPERTYGET, VT_I8, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_Document()
	{
		LPDISPATCH result;
		InvokeHelper(0x40b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void Erase()
	{
		InvokeHelper(0x475, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_Name(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_ConfigName()
	{
		CString result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_ConfigName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_CanonicalMediaName()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_CanonicalMediaName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_PaperUnits()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_PaperUnits(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_PlotViewportBorders()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_PlotViewportBorders(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ShowPlotStyles()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ShowPlotStyles(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_PlotRotation()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_PlotRotation(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_CenterPlot()
	{
		BOOL result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_CenterPlot(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_PlotHidden()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_PlotHidden(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_PlotType()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_PlotType(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_ViewToPlot()
	{
		CString result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_ViewToPlot(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_UseStandardScale()
	{
		BOOL result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_UseStandardScale(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_StandardScale()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_StandardScale(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void GetCustomScale(double * Numerator, double * Denominator)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Numerator, Denominator);
	}
	void SetCustomScale(double Numerator, double Denominator)
	{
		static BYTE parms[] = VTS_R8 VTS_R8;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Numerator, Denominator);
	}
	BOOL get_ScaleLineweights()
	{
		BOOL result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ScaleLineweights(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_PlotWithLineweights()
	{
		BOOL result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_PlotWithLineweights(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_PlotViewportsFirst()
	{
		BOOL result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_PlotViewportsFirst(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_StyleSheet()
	{
		CString result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_StyleSheet(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void GetPaperMargins(VARIANT * LowerLeft, VARIANT * UpperRight)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, LowerLeft, UpperRight);
	}
	void GetPaperSize(double * Width, double * Height)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Width, Height);
	}
	VARIANT get_PlotOrigin()
	{
		VARIANT result;
		InvokeHelper(0x1e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void put_PlotOrigin(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x1e, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	void GetWindowToPlot(VARIANT * LowerLeft, VARIANT * UpperRight)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, LowerLeft, UpperRight);
	}
	void SetWindowToPlot(VARIANT& LowerLeft, VARIANT& UpperRight)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &LowerLeft, &UpperRight);
	}
	BOOL get_PlotWithPlotStyles()
	{
		BOOL result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_PlotWithPlotStyles(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ModelType()
	{
		BOOL result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void CopyFrom(LPDISPATCH pPlotConfig)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, pPlotConfig);
	}
	VARIANT GetCanonicalMediaNames()
	{
		VARIANT result;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	VARIANT GetPlotDeviceNames()
	{
		VARIANT result;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	VARIANT GetPlotStyleTableNames()
	{
		VARIANT result;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void RefreshPlotDeviceInfo()
	{
		InvokeHelper(0x27, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	CString GetLocaleMediaName(LPCTSTR Name)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Name);
		return result;
	}
	LPDISPATCH get_Block()
	{
		LPDISPATCH result;
		InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	long get_TabOrder()
	{
		long result;
		InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_TabOrder(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x31, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}

	// IZcadLayout 属性
public:

};
