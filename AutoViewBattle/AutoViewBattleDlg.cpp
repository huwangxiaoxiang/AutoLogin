
// AutoViewBattleDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "AutoViewBattle.h"
#include "AutoViewBattleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoViewBattleDlg 对话框



CAutoViewBattleDlg::CAutoViewBattleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTOVIEWBATTLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoViewBattleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, START_BTN, Start_Btn);
}

BEGIN_MESSAGE_MAP(CAutoViewBattleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(START_BTN, &CAutoViewBattleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAutoViewBattleDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CAutoViewBattleDlg 消息处理程序

BOOL CAutoViewBattleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAutoViewBattleDlg::OnPaint()
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
HCURSOR CAutoViewBattleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HWND CAutoViewBattleDlg::findWindow() {
	CWnd* window = FindWindow(L"WindowsForms10.Window.8.app.0.141b42a_r6_ad1", L"TankFlow");
	if (!window) {
		window = FindWindow(L"WindowsForms10.Window.8.app.0.141b42a_r8_ad1", L"TankFlow");
		if (!window)
			return NULL;
	}
	return window->GetSafeHwnd();
}

void CAutoViewBattleDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	if (mode) {//这是按下了停止按钮
		HWND hwnd = findWindow();
		//::PostMessage(hwnd,WM_CLOSE, 0, 0);
		GetDlgItem(START_BTN)->SetWindowText(L"开始观战");
		threads->exit = true;
		mode = false;
	}
	else {//这是按下了开始按钮
		BaseAPI api;
		//api.CMDCommand(L"TankFlow.exe");
		GetDlgItem(START_BTN)->SetWindowText(L"停止运行");
		threads=(Thread1*)AfxBeginThread(RUNTIME_CLASS(Thread1));
		threads->PostThreadMessage( WM_Thread1, 0, 0);
		PostMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		mode=true;
	}

}


void CAutoViewBattleDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
