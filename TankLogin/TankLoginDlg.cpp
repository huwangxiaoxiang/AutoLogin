
// TankLoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "TankLogin.h"
#include "TankLoginDlg.h"
#include "afxdialogex.h"
#include "FileOp.h"
#include "Count.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// TankLoginDlg 对话框



TankLoginDlg::TankLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TANKLOGIN_DIALOG, pParent)
	, store(TRUE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void TankLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COUNT, counts);
	DDX_Control(pDX, IDC_Server, servers);
	DDX_Control(pDX, IDC_PASSWD, Password);
	DDX_Check(pDX, IDC_REM, store);
}

BEGIN_MESSAGE_MAP(TankLoginDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &TankLoginDlg::OnLogin)
	ON_CBN_SELCHANGE(IDC_COUNT, &TankLoginDlg::OnChangeCount)
	ON_CBN_EDITCHANGE(IDC_COUNT, &TankLoginDlg::OnCountEdit)
	ON_BN_CLICKED(IDC_REM, &TankLoginDlg::OnBnClickedRem)
END_MESSAGE_MAP()


// TankLoginDlg 消息处理程序

BOOL TankLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	FileOp op(L"e:\\info.bv");

	op.Read(couterlist);
	while (counts.GetCount() != 0)
		counts.DeleteString(0);
	for (auto i = couterlist.cbegin(); i != couterlist.cend(); i++) {
		Count now = *i;
		counts.AddString(now.GetNumber());
		counts.SetWindowText(now.GetNumber());
		Password.SetWindowText(now.GetKey());
	}
	

	for (int i = 0; i < 7; i++) {
		servers.AddString(services[i]);
	}
	servers.SetCurSel(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void TankLoginDlg::OnPaint()
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
HCURSOR TankLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//点击了登录按钮
void TankLoginDlg::OnLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	CString password,number;
	int server=1;
	Password.GetWindowText(password);
	counts.GetWindowText(number);
	CString ser;
	servers.GetLBText(servers.GetCurSel(), ser);
	for (int i = 0; i < 7; i++) {
		if (ser == services[i]) {
			server = i+1;
			break;
		}
	}
	UpdateData(true);
	if (store) {
		Count temp(number, password, 1, 1, 1, 1, 1, 1, 1);
		for (auto i = couterlist.cbegin(); i != couterlist.cend(); i++) {
			Count now = *i;
			if (number == now.GetNumber()) {
				couterlist.erase(i);
				break;
			}
		}
		couterlist.push_back(temp);
		FileOp op(L"e:\\info.bv");
		op.Write(couterlist);
	}
	
	Start();
	Input(number, password);
	Count temp=getIDKey();
	startDirect(temp.getID(), temp.getPriKey(),server);

	TankLoginDlg::OnOK();
}

//选择账号框变化
void TankLoginDlg::OnChangeCount()
{
	CString now_count;
	int m=counts.GetCurSel();
	counts.GetLBText(m,now_count);
	for (auto i = couterlist.cbegin(); i != couterlist.cend(); i++) {
		Count temp = *i;
		if (temp.GetNumber() == now_count) {
			Password.SetWindowText(temp.GetKey());
			break;
		}
	}
	
}


void TankLoginDlg::OnCountEdit()
{
	Password.SetWindowTextW(L"");
	
}

void TankLoginDlg::ClearWindow()
{
	BaseAPI api;
	api.CMDCommand(L"taskkill /im Launcher.exe /im QQMicroGameBox.exe /im  QQMicroGameBoxTray.exe /im Tank.exe /f");
}


void TankLoginDlg::InputString(CString s)
{
	for (int i = 0; i < s.GetLength(); i++) {
		//Sleep(120);
		int asc = s.GetAt(i);
		if (asc >= 48 && asc <= 57) {//数字
			KeyPress(asc);
			continue;
		}
		if (asc >= 97 && asc <= 122) {//小写字母
			KeyPress(asc - 32);
			continue;
		}
		if (asc >= 65 && asc <= 96) {//大写字母
			KeyPress(16, asc);
			continue;
		}
		switch (asc) {
		case 33:
			KeyPress(16, 97);
			break;
		case 64:
			KeyPress(16, 98);
			break;
		case 35:
			KeyPress(16, 99);
			break;
		case 36:
			KeyPress(16, 100);
			break;
		case 37:
			KeyPress(16, 101);
			break;
		case 39:
			KeyPress(16, 102);
			break;
		case 38:
			KeyPress(16, 103);
			break;
		case 42:
			KeyPress(16, 104);
			break;
		case 40:
			KeyPress(16, 105);
			break;
		case 41:
			KeyPress(16, 96);
			break;
		}

	}

}

void TankLoginDlg::Start()
{
	ClearWindow();
	TCHAR DataDir[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, DataDir))) {
		PathAppend(DataDir, L"Tencent\\QQMicroGameBox\\坦克大战");
	}
	int result = (int)ShellExecute(NULL, L"open", DataDir, NULL, NULL, SW_SHOW);//打开主程序
	if (result < 32)
		MessageBox(NULL, L"启动错误", NULL);
	Sleep(3000);
}

void TankLoginDlg::Input(CString number,CString password)
{
	RECT rect = getProcessRect(L"LoginDlg", L"LoginDlg");
	MoveTo(rect.left + 210, rect.top + 381);
	Sleep(20);
	LeftClick(1);
	Sleep(1000);

	MoveTo(rect.left + 172, rect.top + 291);
	Sleep(20);
	LeftClick(1);
	Sleep(300);
	InputString(number);
	Sleep(500);

	MoveTo(rect.left + 174, rect.top + 336);
	Sleep(500);
	LeftClick(1);

	Sleep(500);
	InputString(password);
	Sleep(500);

	MoveTo(rect.left + 499, rect.top + 346);
	Sleep(100);
	LeftClick(1);
}


Count TankLoginDlg::getIDKey()
{
	Sleep(5000);
	Count source;
	HWND hwnd = getProcessHWND(L"#32770", L"坦克大战登陆器");
	DWORD pid;
	GetWindowThreadProcessId(hwnd, &pid);
	LPTSTR cmd = getProcCMD(pid);
	CString target(cmd);
	int pos1 = target.Find(L"ID=", 0);
	int pos2 = target.Find(L"Key=", 0);
	int pos3 = target.Find(L"ModelID=", 0);
	CString temp1 = target.Mid(pos1 + 3, 32);
	CString temp2 = target.Mid(pos2 + 4, 32);
	LPTSTR id = new TCHAR[temp1.GetLength() + 1];
	LPTSTR key = new TCHAR[temp2.GetLength() + 1];
	lstrcpy(id, temp1);
	lstrcpy(key, temp2);
	source.setID(id);
	source.setPriKey(key);

	return source;
}

BOOL TankLoginDlg::startDirect(LPTSTR ID, LPTSTR key, int serverID)
{
	ClearWindow();
	Sleep(1000);
	TCHAR DataDir[MAX_PATH] = { 0 };
	TCHAR dll_path[MAX_PATH] = { 0 };
	TCHAR target[MAX_PATH] = { 0 };
	TCHAR copy[MAX_PATH] = { 0 };

	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, DataDir))) {
		lstrcpy(dll_path, DataDir);
		lstrcat(DataDir, L"\\tkdz\\Tank.exe ID:");
		lstrcat(DataDir, ID);
		lstrcat(DataDir, L",Key:");
		lstrcat(DataDir, key);
		lstrcat(DataDir, L",PID:10,serverId:");
		CString s;
		s.Format(L"%d", serverID);
		lstrcat(DataDir, s.GetBuffer());
		lstrcat(dll_path, L"\\tkdz\\Tank_Data\\Managed\\");
		lstrcat(target, dll_path);
		lstrcat(copy, dll_path);
		lstrcat(target, L"Assembly-CSharp.dll");
		lstrcat(copy, L"Assembly.dll");

	}
	//this->CMDCommand(DataDir);//打开主程序;
	ifstream f(copy);
	ifstream p(target);
	if (f.good()&&p.good()) {
		f.close();
		p.close();
		TCHAR temp[MAX_PATH] = { 0 };
		lstrcat(temp, dll_path);
		lstrcat(temp, L"temp");
		_trename(target, temp);
		_trename(copy, target);
		STARTUPINFO si = { sizeof(si) };
		PROCESS_INFORMATION pi;
		BOOL tank = CreateProcess(NULL, DataDir, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		Sleep(2000);
		_trename(target,copy);
		_trename(temp,target);
		return tank;
	}
	else {
		STARTUPINFO si = { sizeof(si) };
		PROCESS_INFORMATION pi;
		BOOL tank = CreateProcess(NULL, DataDir, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		Sleep(1000);
		return tank;
	}

	
}


void TankLoginDlg::OnBnClickedRem()
{
}
