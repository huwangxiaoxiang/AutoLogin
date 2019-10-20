
// GUITestDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "GUITest.h"
#include "GUITestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
typedef void(*Send)(LPTSTR);

// CGUITestDlg 对话框



CGUITestDlg::CGUITestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUITEST_DIALOG, pParent)
	, Pos(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGUITestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC1, Pos);
	DDX_Control(pDX, IDC_EDIT1, infos);
	DDX_Control(pDX, IDC_LIST2, messages);
}

BEGIN_MESSAGE_MAP(CGUITestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_MESSAGE(WM_USER + 1, &CGUITestDlg::OnMessageRecv)
	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDOK, &CGUITestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGUITestDlg 消息处理程序

BOOL CGUITestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowText(L"GUITest");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGUITestDlg::OnPaint()
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
HCURSOR CGUITestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGUITestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CPoint now;
	GetCursorPos(&now);

	this->Pos.Format(L"鼠标位置:%d,%d  消息位置:%d,%d", now.x, now.y, point.x, point.y);
	UpdateData(false);
	CDialogEx::OnMouseMove(nFlags, point);
}


void CGUITestDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->Pos.Format(L"点击消息位置:%d,%d", point.x, point.y);
	UpdateData(false);
	CDialogEx::OnLButtonDown(nFlags, point);
}


afx_msg LRESULT CGUITestDlg::OnMessageRecv(WPARAM wParam, LPARAM lParam)
{
	CString m;
	infos.GetWindowText(m);
	m.AppendFormat(L"\n%s", wParam);
	return 0;
}


BOOL CGUITestDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	CString wParam = (LPCTSTR)(pCopyDataStruct->lpData);
	CString m;
	infos.GetWindowText(m);
	m.AppendFormat(L"\n%s", wParam);
	infos.SetWindowText(m);
	messages.AddString(wParam);

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}


void CGUITestDlg::OnBnClickedOk()
{
	HINSTANCE hDLL;
	Send sendMessage;
	hDLL = LoadLibrary(L"KeyBoardHook.dll");//加载动态链接库MyDll.dll文件；
	sendMessage = (Send)GetProcAddress(hDLL, "ReportMessage");
	sendMessage(L"Hello World");
}
