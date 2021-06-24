// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类

#import "C:\\Program Files\\Common Files\\ZWSoft Shared\\zwcad21.tlb" no_namespace
// CZcadPViewport 包装器类

class CZcadPViewport : public COleDispatchDriver
{
public:
	CZcadPViewport() {} // 调用 COleDispatchDriver 默认构造函数
	CZcadPViewport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CZcadPViewport(const CZcadPViewport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IZcadPViewport 方法
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
	LPDISPATCH get_TrueColor()
	{
		LPDISPATCH result;
		InvokeHelper(0x516, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_TrueColor(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x516, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_Layer()
	{
		CString result;
		InvokeHelper(0x501, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_Layer(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x501, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_Linetype()
	{
		CString result;
		InvokeHelper(0x502, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_Linetype(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x502, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	double get_LinetypeScale()
	{
		double result;
		InvokeHelper(0x503, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, nullptr);
		return result;
	}
	void put_LinetypeScale(double newValue)
	{
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0x503, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_Visible()
	{
		BOOL result;
		InvokeHelper(0x504, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_Visible(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x504, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	VARIANT ArrayPolar(long NumberOfObjects, double AngleToFill, VARIANT& CenterPoint)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_R8 VTS_VARIANT;
		InvokeHelper(0x505, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, NumberOfObjects, AngleToFill, &CenterPoint);
		return result;
	}
	VARIANT ArrayRectangular(long NumberOfRows, long NumberOfColumns, long NumberOfLevels, double DistBetweenRows, double DistBetweenCols, double DistBetweenLevels)
	{
		VARIANT result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_R8 VTS_R8 VTS_R8;
		InvokeHelper(0x506, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, NumberOfRows, NumberOfColumns, NumberOfLevels, DistBetweenRows, DistBetweenCols, DistBetweenLevels);
		return result;
	}
	void Highlight(BOOL HighlightFlag)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x507, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, HighlightFlag);
	}
	LPDISPATCH Copy()
	{
		LPDISPATCH result;
		InvokeHelper(0x508, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void Move(VARIANT& FromPoint, VARIANT& ToPoint)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT;
		InvokeHelper(0x509, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &FromPoint, &ToPoint);
	}
	void Rotate(VARIANT& BasePoint, double RotationAngle)
	{
		static BYTE parms[] = VTS_VARIANT VTS_R8;
		InvokeHelper(0x50a, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &BasePoint, RotationAngle);
	}
	void Rotate3D(VARIANT& Point1, VARIANT& Point2, double RotationAngle)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_R8;
		InvokeHelper(0x50b, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &Point1, &Point2, RotationAngle);
	}
	LPDISPATCH Mirror(VARIANT& Point1, VARIANT& Point2)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT;
		InvokeHelper(0x50c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Point1, &Point2);
		return result;
	}
	LPDISPATCH Mirror3D(VARIANT& Point1, VARIANT& Point2, VARIANT& point3)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT;
		InvokeHelper(0x50d, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Point1, &Point2, &point3);
		return result;
	}
	void ScaleEntity(VARIANT& BasePoint, double ScaleFactor)
	{
		static BYTE parms[] = VTS_VARIANT VTS_R8;
		InvokeHelper(0x50e, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &BasePoint, ScaleFactor);
	}
	void TransformBy(VARIANT& TransformationMatrix)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x50f, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, &TransformationMatrix);
	}
	void Update()
	{
		InvokeHelper(0x510, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void GetBoundingBox(VARIANT * MinPoint, VARIANT * MaxPoint)
	{
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT;
		InvokeHelper(0x511, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, MinPoint, MaxPoint);
	}
	VARIANT IntersectWith(LPDISPATCH IntersectObject, long option)
	{
		VARIANT result;
		static BYTE parms[] = VTS_DISPATCH VTS_I4;
		InvokeHelper(0x512, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, IntersectObject, option);
		return result;
	}
	CString get_PlotStyleName()
	{
		CString result;
		InvokeHelper(0x513, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_PlotStyleName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x513, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_Lineweight()
	{
		long result;
		InvokeHelper(0x514, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_Lineweight(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x514, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_EntityTransparency()
	{
		CString result;
		InvokeHelper(0x579, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_EntityTransparency(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x579, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_Hyperlinks()
	{
		LPDISPATCH result;
		InvokeHelper(0x515, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	CString get_Material()
	{
		CString result;
		InvokeHelper(0x577, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_Material(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x577, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_EntityName()
	{
		CString result;
		InvokeHelper(0x575, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	long get_EntityType()
	{
		long result;
		InvokeHelper(0x576, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	long get_color()
	{
		long result;
		InvokeHelper(0x500, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_color(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x500, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	VARIANT get_Center()
	{
		VARIANT result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void put_Center(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	VARIANT get_Direction()
	{
		VARIANT result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void put_Direction(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	BOOL get_GridOn()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_GridOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	double get_Height()
	{
		double result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, nullptr);
		return result;
	}
	void put_Height(double newValue)
	{
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	double get_Width()
	{
		double result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, nullptr);
		return result;
	}
	void put_Width(double newValue)
	{
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ViewportOn()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ViewportOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_Clipped()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	BOOL get_DisplayLocked()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_DisplayLocked(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_StandardScale()
	{
		long result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_StandardScale(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	double get_CustomScale()
	{
		double result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, nullptr);
		return result;
	}
	void put_CustomScale(double newValue)
	{
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	CString get_StyleSheet()
	{
		CString result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, nullptr);
		return result;
	}
	void put_StyleSheet(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_UCSPerViewport()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_UCSPerViewport(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_LayerPropertyOverrides()
	{
		BOOL result;
		InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	VARIANT get_SnapBasePoint()
	{
		VARIANT result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void put_SnapBasePoint(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	BOOL get_SnapOn()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_SnapOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	double get_SnapRotationAngle()
	{
		double result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, nullptr);
		return result;
	}
	void put_SnapRotationAngle(double newValue)
	{
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_UCSIconOn()
	{
		BOOL result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_UCSIconOn(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_UCSIconAtOrigin()
	{
		BOOL result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_UCSIconAtOrigin(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void GetGridSpacing(double * XSpacing, double * YSpacing)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, XSpacing, YSpacing);
	}
	void SetGridSpacing(double XSpacing, double YSpacing)
	{
		static BYTE parms[] = VTS_R8 VTS_R8;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, XSpacing, YSpacing);
	}
	void GetSnapSpacing(double * XSpacing, double * YSpacing)
	{
		static BYTE parms[] = VTS_PR8 VTS_PR8;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, XSpacing, YSpacing);
	}
	void SetSnapSpacing(double XSpacing, double YSpacing)
	{
		static BYTE parms[] = VTS_R8 VTS_R8;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, XSpacing, YSpacing);
	}
	void Display(BOOL bStatus)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, bStatus);
	}
	double get_TwistAngle()
	{
		double result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, nullptr);
		return result;
	}
	void put_TwistAngle(double newValue)
	{
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	double get_LensLength()
	{
		double result;
		InvokeHelper(0x18, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, nullptr);
		return result;
	}
	void put_LensLength(double newValue)
	{
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0x18, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_RemoveHiddenLines()
	{
		BOOL result;
		InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_RemoveHiddenLines(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x19, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	VARIANT get_Target()
	{
		VARIANT result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void put_Target(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	long get_ArcSmoothness()
	{
		long result;
		InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_ArcSmoothness(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1b, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_VisualStyle()
	{
		long result;
		InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_VisualStyle(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1c, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_ShadePlot()
	{
		long result;
		InvokeHelper(0x1d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_ShadePlot(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1d, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_ModelView()
	{
		LPDISPATCH result;
		InvokeHelper(0x20, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_ModelView(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x20, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_SheetView()
	{
		LPDISPATCH result;
		InvokeHelper(0x21, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_SheetView(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x21, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	__int64 get_LabelBlockId()
	{
		__int64 result;
		InvokeHelper(0x22, DISPATCH_PROPERTYGET, VT_I8, (void*)&result, nullptr);
		return result;
	}
	void put_LabelBlockId(__int64 * newValue)
	{
		static BYTE parms[] = VTS_PI8;
		InvokeHelper(0x22, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_HasSheetView()
	{
		BOOL result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void SyncModelView()
	{
		InvokeHelper(0x24, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	long get_StandardScale2()
	{
		long result;
		InvokeHelper(0x27, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_StandardScale2(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x27, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}

	// IZcadPViewport 属性
public:

};
