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

int main()
{
	Sleep(3000);
	//DlgFind();
	//HANDLE hWnd = OpenProcess(NULL, TRUE, 13184);
	TCHAR temp1[MAX_PATH], temp2[MAX_PATH];
	HWND hwnd = GetFocus();
	::GetClassName(hwnd, temp1, MAX_PATH);
	::GetWindowText(hwnd, temp2, MAX_PATH);
	std::wcout << temp1 << " " << temp2 << std::endl;

	TCHAR temp3[MAX_PATH], temp4[MAX_PATH];
	HWND hwnd2=GetForegroundWindow();
	::GetClassName(hwnd2, temp3, MAX_PATH);
	::GetWindowText(hwnd2, temp4, MAX_PATH);

	std::wcout << temp1 << " " << temp2 << std::endl;
	Sleep(20000);
	return 0;
}

