// TestMethod.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma once
#include "PixCollect.h"
#include "BaseAPI.h"
#include "PageRecThread.h"
#include "Page.h"
#include <tchar.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#pragma comment(lib,"G:\\C++\\AutoLogin\\Debug\\KeyBoardHOOK.lib")

void showPix(KeyPoint point) {
	BaseAPI api;
	HWND tank = api.getProcessHWND("UnityWndClass", "Tank Battle");
	RECT rect = api.getProcessClient(tank);
	std::cout << "客户区矩形：(" << rect.left << "," << rect.top << ") " << rect.right - rect.left << "x" << rect.bottom - rect.top << std::endl;

	PixCollect col(3,3);
	POINT offset = point.getXY(tank);
	COLORREF color=col.Collection(tank,offset);
	std::cout << "(" << point.getOffsetX() << "," << point.getOffsetY() << ") (" <<offset.x<<","<<offset.y<<") "<< color <<" 置信度："<<col.percent<<"%"<< std::endl;

}

HWND service;

void CALLBACK send(HWND hWnd) {
	SetForegroundWindow(hWnd);
	BaseAPI api;
	api.KeyPress(51);
	
}

BOOL CALLBACK EnumChild2(HWND hWnd, LPARAM Param)
{
	TCHAR temp1[MAX_PATH], temp2[MAX_PATH];
	::GetWindowText(hWnd, temp1, MAX_PATH);
	::GetClassName(hWnd, temp2, MAX_PATH);
	if (lstrcmp(temp2, L"Edit")==0||TRUE) {
		send(hWnd);

	}
	return true;
}



BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lP)
{
	TCHAR temp1[MAX_PATH], temp2[MAX_PATH];
	::GetClassName(hWnd, temp1, MAX_PATH);
	::GetWindowText(hWnd, temp2, MAX_PATH);
	DWORD id;
	GetWindowThreadProcessId(hWnd, &id);
	if (id==3120) {
		//EnumChildWindows(hWnd, EnumChild2, (LPARAM)hWnd);
		//send(hWnd);
		std::wcout << temp1 << " " << temp2 << std::endl;
	}
	return true;
}

void DlgFind() {
	EnumChildWindows(NULL,EnumChildProc, 0);
}

typedef BOOL(*StartHook)(HWND hwnd);
typedef void (*ExitHook)();
typedef void (*ReportMessage)(LPWSTR str);
HMODULE keybordDll = NULL;
ReportMessage reportMessage;

int count = 0;

DWORD WINAPI thread_func(LPVOID lpvoid) {
	int s = (int)lpvoid;
	Sleep(300);
	WCHAR m[20];
	_itow_s(s, m, 20, 10);
	reportMessage(m);
	return 0;
}

HWND findWindow() {
	HWND window = FindWindow(L"WindowsForms10.Window.8.app.0.141b42a_r6_ad1", L"TankFlow");
	if (!window) {
		window = FindWindow(L"WindowsForms10.Window.8.app.0.141b42a_r8_ad1", L"TankFlow");
		if (!window)
			return NULL;
	}
	return window;
}

int main()
{
	//Sleep(3000);
	BaseAPI api;
	//DlgFind();
	//HANDLE hWnd = OpenProcess(NULL, TRUE, 13184);
	/*TCHAR temp1[MAX_PATH], temp2[MAX_PATH];
	HWND hwnd = GetFocus();
	::GetClassName(hwnd, temp1, MAX_PATH);
	::GetWindowText(hwnd, temp2, MAX_PATH);
	std::wcout << temp1 << " " << temp2 << std::endl;

	TCHAR temp3[MAX_PATH], temp4[MAX_PATH];
	HWND hwnd2=GetForegroundWindow();
	::GetClassName(hwnd2, temp3, MAX_PATH);
	::GetWindowText(hwnd2, temp4, MAX_PATH);

	std::wcout << temp1 << " " << temp2 << std::endl;
	Sleep(20000);*/

	/*keybordDll = LoadLibrary(L"G:\\C++\\AutoLogin\\Release\\KeyBoardHOOK.dll");
	HANDLE th;
	if (keybordDll == NULL) {
		std::cout << ("DLL加载失败") << std::endl;
	}
	else {
		reportMessage = (ReportMessage)GetProcAddress(keybordDll, "ReportMessage");
		if (reportMessage == NULL) {
			std::cout << "reportMessage函数加载失败" << std::endl;
			Sleep(3000);
			return 0;
		}
		clock_t start, end;
		start = clock();
		for (int i = 0; i < 100; i++) {
			DWORD id = 0;
			CreateThread(NULL, 0, thread_func, (LPVOID)count, 0, &id);
			Sleep(1000);
			count++;
		}
		end = clock();
		std::cout << "结束发送时间：" << end-start << std::endl;

	}


	//HWND hwnd = api.getProcessHWND("WindowsForms10.Window.8.app.0.141b42a_r6_ad1", "TankFlow");
	HWND hwnd = findWindow();
	RECT rect= api.getProcessRect(hwnd);
*/


	HWND h3 = api.getProcessHWND("UnityWndClass", "Tank Battle");
	
	RECT r = api.getProcessClient(h3);
	POINT m;
	GetCursorPos(&m);
	//mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 0, 0, 0, 0);
	//SetForegroundWindow(h3);
	for (int i = 0; i < 2; i++) {
		//api.MoveTo(1557, 66);
		
		api.LeftClick(h3, 1557, 66);
		Sleep(1000);
		//api.MoveTo(1251, 199);
		api.LeftClick(h3, 1251, 199);
		Sleep(1000);
	}

	return 0;
}

