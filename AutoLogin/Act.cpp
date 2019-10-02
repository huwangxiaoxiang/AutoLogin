#include "stdafx.h"
#include "Act.h"
#include "SysGiftPage.h"

void Act::ClearWindow()
{
	BaseAPI api;
	api.CMDCommand(L"taskkill /im Launcher.exe /im QQMicroGameBox.exe /im  QQMicroGameBoxTray.exe /im Tank.exe /f");
}


void Act::InputString(CString s)
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
			KeyPress(16,102);
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

void Act::Start()
{
	ClearWindow();
	TCHAR DataDir [MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, DataDir))) {
		PathAppend(DataDir, L"Tencent\\QQMicroGameBox\\坦克大战");
	}
	int result = (int)ShellExecute(NULL, L"open",DataDir, NULL, NULL, SW_SHOW);//打开主程序
	if (result < 32)
		MessageBox(NULL, L"启动错误", NULL, NULL);
	Sleep(3000);
}

void Act::Input()
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
	InputString(Number.GetNumber());
	Sleep(500);
	
	MoveTo(rect.left + 174, rect.top + 336);
	Sleep(500);
	LeftClick(1);
	
	Sleep(500);
	InputString(Number.GetKey());
	Sleep(500);
	
	MoveTo(rect.left + 499, rect.top + 346);
	Sleep(100);
	LeftClick(1);
}

void Act::ChooseService(int ser)
{
	Sleep(7000);
	RECT rect = getProcessRect(L"#32770", L"坦克大战登陆器");
	switch (ser) {
	case 0:
		MoveTo(rect.left + 268, rect.top + 289);
		break;
	case 1:
		MoveTo(rect.left + 471, rect.top + 289);
		break;
	case 2:
		MoveTo(rect.left + 665, rect.top + 289);
		break;
	case 3:
		MoveTo(rect.left + 840, rect.top + 289);
		break;
	case 4:
		MoveTo(rect.left + 274, rect.top + 366);
		break;
	case 5:
		MoveTo(rect.left + 461, rect.top +366);
		break;
	case 6:
		MoveTo(rect.left + 653, rect.top + 366);
		break;
	}
	Sleep(100);
	LeftClick(1);
	Sleep(1000);

	MoveTo(rect.left + 878, rect.top + 587);
	Sleep(100);
	LeftClick(1);

	
}

BOOL Act::prepare()
{
	std::vector<int> pagelist;
	pagelist.push_back(1);
	pagelist.push_back(3);
	pagelist.push_back(9);
	Page* page=waitPage(pagelist, this->GameClass, this->GameName, 25000);
	if (page->getIndex() == -1) return FALSE;
	BaseAPI api;
	HWND tank = api.getProcessHWND(this->GameClass,this->GameName);
	RECT client = api.getProcessClient(tank);
	ActiveWindow(tank);
	if (page->getIndex() != 1) {
		Sleep(1000);
		POINT close = page->getClose(tank);
		api.MoveTo(client.left + close.x, client.top + close.y);
		Sleep(300);
		api.LeftClick(1);
	}
	Sleep(1000);
	return TRUE;
}

void Act::getOnlineGift()
{
	CRect rect = getProcessRect();
	//MoveTo(rect.right - 56, rect.top + 168);
	MoveTo(rect.right - 200, rect.top + 168);
	Sleep(100);
	LeftClick(1);
	Sleep(1500);
}

void Act::getOfflineExperience()
{
	CRect rect = getProcessRect();
	CPoint  center;
	center.x = rect.left + (rect.right - rect.left) / 2;
	center.y = rect.top + (rect.bottom - rect.top) / 2;
	MoveTo(center.x - 30, rect.bottom - 147);
	Sleep(300);
	LeftClick(1);
	Sleep(600);
	MoveTo(center.x + 410, center.y - 192);
	Sleep(600);
	LeftClick(1);
	Sleep(400);
	MoveTo(center.x + 506, center.y - 283);
	Sleep(400);
	LeftClick(1);
}

void Act::getSysGift()
{
	Sleep(1000);
	HWND hwnd = this->getProcessHWND();
	ActiveWindow(hwnd);
	CRect rect = getProcessClient(hwnd);
	this->MoveTo(rect.right - 278, rect.top + 121);
	Sleep(400);
	this->MoveTo(rect.right - 270, rect.top + 209);
	Sleep(400);
	this->LeftClick(1);
	Sleep(1000);
	Page* page =PageManager::isThisPage(10, hwnd);
	if (page->getIndex() == -1)
		return;
	SysGiftPage* p = (SysGiftPage*)page;
	while (p->has_gift(hwnd)) {
		this->MoveTo(p->look_point.getAbsoluteXY(hwnd));//领取
		Sleep(200);
		this->LeftClick(1);
		Sleep(400);
		this->MoveTo(p->affirm.getAbsoluteXY(hwnd));//确认
		Sleep(200);
		this->LeftClick(1);
		Sleep(400);
		this->MoveTo(p->close_result.getAbsoluteXY(hwnd));//关闭
		Sleep(200);
		this->LeftClick(1);
		Sleep(400);
	}
	this->MoveTo(p->getCloseAbsolute(hwnd));
	Sleep(200);
	this->LeftClick(1);
	Sleep(1000);
}

void Act::exit()
{
	ClearWindow();
	Sleep(1000);
}

Page* Act::waitPage(int page, LPTSTR className, LPTSTR windowName, int timeout)
{
	std::vector<int> list;
	list.push_back(page);
	return waitPage(list, className, windowName, timeout);
}

Page* Act::waitPage(std::vector<int> page, LPTSTR className, LPTSTR windowName, int timeout)
{
	while (timeout >= 0) {
		HWND hwnd = FindWindow(className, windowName);
		for (auto i = page.cbegin(); i != page.cend(); i++) {
			int index = *i;
			Page* temp = PageManager::isThisPage(index, hwnd);
			if (temp->getIndex() == index)
				return temp;
		}
		timeout -= 1000;
		Sleep(1000);
	}
	return new Page(-1, L"无效Page");
}

void Act::getSkill()
{
	Sleep(1000);
	HWND hwnd = FindWindow(GameClass, GameName);
	Page* result = PageManager::isThisPage(5, hwnd);
	BaseAPI api;
	RECT client = api.getProcessClient(hwnd);
	KeyPoint open(-235, -138, 0,BASEP_CENTER_BOTTOM);
	if (result->getIndex() == 5) {
		//打开技能页面
		api.MoveTo(open.getAbsoluteXY(hwnd));
		Sleep(400);
		api.LeftClick(1);
		Sleep(1500);

		//点击抽取按钮
		open=KeyPoint(125, 88, 0, BASEP_CENTER);
		api.MoveTo(open.getAbsoluteXY(hwnd));
		Sleep(400);
		api.LeftClick(1);

		//点击确定按钮
		open = KeyPoint(-58, 44, 0, BASEP_CENTER);
		api.MoveTo(open.getAbsoluteXY(hwnd));
		Sleep(400);
		api.LeftClick(1);

		//关闭技能页面
		open = KeyPoint(486, -298,0, BASEP_CENTER);
		api.MoveTo(open.getAbsoluteXY(hwnd));
		Sleep(400);
		api.LeftClick(1);
	}
}

Count Act::setIDKey(Count source)
{
	Sleep(5000);
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

BOOL Act::startDirect(LPTSTR ID, LPTSTR key, int serverID)
{
	ClearWindow();
	Sleep(1000);
	TCHAR DataDir[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, DataDir))) {
		lstrcat(DataDir, L"\\tkdz\\Tank.exe ID:");
		lstrcat(DataDir, ID);
		lstrcat(DataDir,L",Key:");
		lstrcat(DataDir, key);
		lstrcat(DataDir, L",PID:10,serverId:");
		CString s;
		s.Format(L"%d", serverID + 1);
		lstrcat(DataDir, s.GetBuffer());
	}
	//this->CMDCommand(DataDir);//打开主程序;
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	BOOL tank = CreateProcess(NULL, DataDir, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	Sleep(1000);
	return tank;
}

Act::Act(Count ser)
{
	this->Number = ser;
	this->SetDefaultProcess(GameClass,GameName);
}
