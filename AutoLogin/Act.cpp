#include "stdafx.h"
#include "Act.h"

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

void Act::prepare()
{
	std::vector<int> pagelist;
	pagelist.push_back(1);
	pagelist.push_back(3);
	pagelist.push_back(9);
	Page page=waitPage(pagelist, L"UnityWndClass", L"Tank Battle", 25000);
	BaseAPI api;
	HWND tank = api.getProcessHWND(L"UnityWndClass", L"Tank Battle");
	RECT client = api.getProcessClient(tank);
	Sleep(1000);
	POINT close = page.getClose(tank);
	api.MoveTo(client.left + close.x, client.top + close.y);
	Sleep(300);
	api.LeftClick(1);
	Sleep(1000);
	
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
	Sleep(1500);
}

void Act::exit()
{
	ClearWindow();
	Sleep(1000);
}

Page Act::waitPage(int page, LPTSTR className, LPTSTR windowName, int timeout)
{
	std::vector<int> list;
	list.push_back(page);
	return waitPage(list, className, windowName, timeout);
}

Page Act::waitPage(std::vector<int> page, LPTSTR className, LPTSTR windowName, int timeout)
{
	while (timeout >= 0) {
		HWND hwnd = FindWindow(className, windowName);
		for (auto i = page.cbegin(); i != page.cend(); i++) {
			int index = *i;
			Page temp = PageManager::isThisPage(index, hwnd);
			if (temp.getIndex() == index)
				return temp;
		}
		timeout -= 1000;
		Sleep(1000);
	}
	return Page(-1, L"无效Page");
}

Act::Act(Count ser)
{
	this->Number = ser;
	this->SetDefaultProcess(L"UnityWndClass",L"Tank Battle");
}
