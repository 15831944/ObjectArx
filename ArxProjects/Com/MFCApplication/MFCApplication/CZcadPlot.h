// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#import "C:\\Program Files\\Common Files\\ZWSoft Shared\\zwcad21.tlb" no_namespace
// CZcadPlot ��װ����

class CZcadPlot : public COleDispatchDriver
{
public:
	CZcadPlot() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CZcadPlot(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CZcadPlot(const CZcadPlot& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IZcadPlot ����
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	BOOL get_QuietErrorMode()
	{
		BOOL result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_QuietErrorMode(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_NumberOfCopies()
	{
		long result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_NumberOfCopies(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_BatchPlotProgress()
	{
		BOOL result;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_BatchPlotProgress(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void DisplayPlotPreview(long Preview)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Preview);
	}
	BOOL PlotToFile(LPCTSTR plotFile, VARIANT& plotConfig)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT;
		InvokeHelper(0x60020008, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, plotFile, &plotConfig);
		return result;
	}
	BOOL PlotToDevice(VARIANT& plotConfig)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x60020009, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &plotConfig);
		return result;
	}
	void SetLayoutsToPlot(VARIANT& layoutList)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &layoutList);
	}
	void StartBatchMode(long entryCount)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, entryCount);
	}

	// IZcadPlot ����
public:

};
