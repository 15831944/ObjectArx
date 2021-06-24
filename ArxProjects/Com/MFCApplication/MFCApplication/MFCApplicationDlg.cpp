
// MFCApplicationDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication.h"
#include "MFCApplicationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationDlg 对话框



CMFCApplicationDlg::CMFCApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplicationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplicationDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplicationDlg 消息处理程序

BOOL CMFCApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include "CZcadApplication.h"
#include "CZcadDocument.h"
#include "CZcadDocuments.h"
#include "CZcadLayout.h"
#include "CZcadLayouts.h"
#include "CZcadPlot.h"
#include "CZcadPlotConfiguration.h"
#include "CZcadPlotConfigurations.h"
#include "CZcadState.h"
#include "CZcadPViewport.h"
void CMFCApplicationDlg::OnBnClickedButton1()
{
	// 通过COM获取当前存在的ZWCAD，若不存在，则创建
	CZcadApplication pZwcad;
	LPUNKNOWN pUnk;
	LPDISPATCH pDisp;
	CLSID clsid;
	::CLSIDFromProgID(L"ZWCAD.Application.2021", &clsid);
	if (::GetActiveObject(clsid, NULL, &pUnk) == S_OK)   //判断ZWCAD是否已启动
	{
		// CAD已经启动，则连接CAD即可
		if (pUnk->QueryInterface(IID_IDispatch, (void**)&pDisp) == S_OK)
		{
			pZwcad.AttachDispatch(pDisp, FALSE);
			pUnk->Release();
		}
	}
	// CAD没有启动，启动CAD
	else if (pZwcad.CreateDispatch(_T("ZWCAD.Application.2021"), NULL) == FALSE)
	{
		::AfxMessageBox(_T("启动ZWCAD 失败!"));
	}

	// 设置显示状态
	pZwcad.put_Visible(/*TRUE*/FALSE);

	// 设置显示最大化
	pZwcad.put_WindowState(/*zcMax*/zcMin);

	// 获取文档集
	CZcadDocuments docs;
	docs = pZwcad.get_Documents();

	// 获取当前文档
	CZcadDocument doc = pZwcad.get_ActiveDocument();

	// 源文件
	CString szSrcFile = _T("D:\\temp\\test.dwg");

	// 如果当前存在源文件则不打开
	long lCount = docs.get_Count();
	bool bIsExist(false);
	for (int i = 0; i < lCount; i++)
	{
		VARIANT index;
		VariantInit(&index);
		V_VT(&index) = VT_I4;
		V_I4(&index) = i;
		CZcadDocument docTemp = docs.Item(index);

		if (docTemp.get_FullName().Compare(szSrcFile) == 0)  
		{
			bIsExist = true;
			doc = docTemp;
			break;
		}
	}
	if (!bIsExist)
	{
		// 打开图纸
		CComVariant v1(true), v2(false);
		doc = docs.Open(LPCTSTR(szSrcFile), v1, v2);
	}

	// 激活要打印的文档
	doc.Activate();

	//可以加载之前的提供的zrx，执行命令进行打印
#if 0  
	// 加载功能zrx
	//pZwcad.LoadZrx(_T("D:\\temp\\HelloWorld.zrx"));
	// 执行命令
	//doc.SendCommand(_T("Test_plot "));
#endif

	// 设置为消隐模式
	doc.SendCommand(_T("shademode H "));

	//CZcadLayouts cadLayouts = doc.get_Layouts(); 
	// 添加一个布局
	//CZcadLayout cadLayout = cadLayouts.Add(_T("new_layout")); 
	//doc.put_ActiveLayout(cadLayout);

	//CZcadPViewport pViewport = doc.get_ActivePViewport(); // err
	//pViewport.put_ShadePlot(zcShadePlotHidden);

	// 获取当前布局
	CZcadLayout cadLayout = doc.get_ActiveLayout();
	//CZcadPViewport pViewport = doc.get_ActivePViewport(); // err
	//pViewport.put_ShadePlot(zcShadePlotHidden);

	// 设置打印机(这个打印机为zwcad开放的高DPI的打印机)
	cadLayout.put_ConfigName(_T("ZWCAD PDF(High Quality Print).pc5"));
	// 设置纸张
	cadLayout.put_CanonicalMediaName(_T("ISO_A4(210.00_x_297.00_MM)"));
	// 居中打印
	cadLayout.put_CenterPlot(true);
	// 取消打印线宽（由于图纸字体的精度问题，打印线宽会导致精度上的损失，显得十分模糊）
	cadLayout.put_PlotWithLineweights(false);
	// 打印区域为按显示范围(当前屏幕显示范围)
	cadLayout.put_PlotType(zcDisplay);
	//设置打印比例为标准布满
	cadLayout.put_UseStandardScale(true);
	cadLayout.put_StandardScale(zcScaleToFit); 

	CZcadPlot cadPlot = doc.get_Plot();
	VARIANT config;
	config.vt = VT_BSTR;
	config.bstrVal = _T("ZWCAD PDF(High Quality Print).pc5");
	// 输出为pdf
	cadPlot.PlotToFile(_T("D:\\Temp\\test.pdf"), config);

	//pZwcad.Quit();
	//doc.ReleaseDispatch();
	//docs.ReleaseDispatch();

	::AfxMessageBox(_T("Finished!"));
}


void CMFCApplicationDlg::OnBnClickedButton2()
{
	// 通过COM获取当前存在的ZWCAD，若不存在，则创建
	CZcadApplication pZwcad;
	LPUNKNOWN pUnk;
	LPDISPATCH pDisp;
	CLSID clsid;
	::CLSIDFromProgID(L"ZWCAD.Application.2021", &clsid);
	if (::GetActiveObject(clsid, NULL, &pUnk) == S_OK)   //判断ZWCAD是否已启动
	{
		// CAD已经启动，则连接CAD即可
		if (pUnk->QueryInterface(IID_IDispatch, (void**)&pDisp) == S_OK)
		{
			pZwcad.AttachDispatch(pDisp, FALSE);
			pUnk->Release();
		}
	}
	// CAD没有启动，启动CAD
	else if (pZwcad.CreateDispatch(_T("ZWCAD.Application.2021"), NULL) == FALSE)
	{
		::AfxMessageBox(_T("启动ZWCAD 失败!"));
	}

	// 设置显示状态
	pZwcad.put_Visible(TRUE);

	// 设置显示最大化
	pZwcad.put_WindowState(zcMax);

	// 创建一个新的文档
	CZcadDocuments docs = pZwcad.get_Documents();
	VARIANT newFile;
	newFile.vt = VT_BSTR;
	newFile.bstrVal = _T("C:\\Users\\Admin\\AppData\\Local\\ZWSOFT\\ZWCAD\\2021\\zh-CN\Template\\zwcadiso.dwt");
	docs.Add(newFile);

	// 获取当前文档
	CZcadDocument doc = pZwcad.get_ActiveDocument();

	// 不显示文件对话框
	doc.SendCommand(_T("filedia 0 "));
	// pdf以块的方式导入
	doc.SendCommand(_T("PDFIMPORTMODE 1 "));

	// 通过pdfimport命令插入pdf
	doc.SendCommand(_T("-pdfimport f D:\\Temp\\test.pdf 8    "));

	//CZcadState cadState = pZwcad.GetZcadState();
	//if (!cadState.get_IsQuiescent())
	//{
	//	::AfxMessageBox(_T("11111"));
	//}

	// 还原
	doc.SendCommand(_T("filedia 1 "));
	doc.SendCommand(_T("PDFIMPORTMODE 6 "));

	// 保存文件
	VARIANT saveAsType, vSecurityParams;
	saveAsType.vt = VT_I4;
	saveAsType.iVal = zc2013_dwg;
	vSecurityParams.vt = VT_I4;
	vSecurityParams.iVal = 0;

	// 需要关闭同名文件后保存
	doc.SaveAs(_T("D:\\Temp\\pdfImportTest.dwg"), saveAsType, vSecurityParams);
	DWORD err = GetLastError();

	//VARIANT sType, fName;
	//sType.vt = VT_BOOL;
	//sType.boolVal = VARIANT_FALSE;
	//fName.vt = VT_BSTR;
	//fName.bstrVal = _T("D:\\Temp\\pdfImportTest.dwg");
	//doc.Close(sType, fName);
	
	::AfxMessageBox(_T("Finished!"));
}
