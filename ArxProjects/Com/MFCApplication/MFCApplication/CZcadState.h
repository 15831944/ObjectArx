// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#import "C:\\Program Files\\Common Files\\ZWSoft Shared\\zwcad21.tlb" no_namespace
// CZcadState ��װ����

class CZcadState : public COleDispatchDriver
{
public:
	CZcadState() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CZcadState(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CZcadState(const CZcadState& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IZcadState ����
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

	// IZcadState ����
public:

};
