// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#import "C:\\Program Files\\Common Files\\ZWSoft Shared\\zwcad21.tlb" no_namespace
// CZcadState 包装器类

class CZcadState : public COleDispatchDriver
{
public:
	CZcadState() {} // 调用 COleDispatchDriver 默认构造函数
	CZcadState(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CZcadState(const CZcadState& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IZcadState 方法
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	BOOL get_IsQuiescent()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}

	// IZcadState 属性
public:

};
