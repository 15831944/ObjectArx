// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#import "C:\\Program Files\\Common Files\\ZWSoft Shared\\zwcad21.tlb" no_namespace
// CZcadDocuments 包装器类

class CZcadDocuments : public COleDispatchDriver
{
public:
	CZcadDocuments() {} // 调用 COleDispatchDriver 默认构造函数
	CZcadDocuments(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CZcadDocuments(const CZcadDocuments& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IZcadDocuments 方法
public:
	LPDISPATCH Item(VARIANT& Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, nullptr);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	LPDISPATCH Add(VARIANT& TemplateName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &TemplateName);
		return result;
	}
	LPDISPATCH Open(LPCTSTR File, VARIANT& ReadOnly, VARIANT& Password)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT;
		InvokeHelper(0x60020005, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, File, &ReadOnly, &Password);
		return result;
	}
	void Close()
	{
		InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020007, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void CloseAll(BOOL AskSave)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x60020008, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, AskSave);
	}
	void SaveAll()
	{
		InvokeHelper(0x60020009, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}

	// IZcadDocuments 属性
public:

};
