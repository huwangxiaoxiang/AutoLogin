// TestMethod.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma once
#include "PixCollect.h"
#include "BaseAPI.h"
#include "PageRecThread.h"
#include "Page.h"
#include <tchar.h>

void showPix(KeyPoint point) {
	BaseAPI api;
	HWND tank = api.getProcessHWND("UnityWndClass", "Tank Battle");
	RECT rect = api.getProcessClient(tank);
	std::cout << "客户区左上角位置：(" << rect.left << "," << rect.top << ")" << std::endl;

	PixCollect col(3,3);
	POINT offset = point.getXY(tank);
	COLORREF color=col.Collection(tank,offset);
	std::cout << "(" << point.getOffsetX() << "," << point.getOffsetY() << ") (" <<offset.x<<","<<offset.y<<") "<< color <<" 置信度："<<col.percent<<"%"<< std::endl;

}

HWND service;

BOOL CALLBACK EnumChild2(HWND hWnd, LPARAM lParam)
{
	TCHAR temp1[MAX_PATH], temp2[MAX_PATH];
	::GetWindowText(hWnd, temp1, MAX_PATH);
	if (lstrcmp(temp1, L"Button11")==0) {
		//std::wcout << L"找到了" << temp1 << L" " << hWnd << std::endl;
		service = (HWND)lParam;
	}
	return true;
}

BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam)
{
	TCHAR temp1[MAX_PATH], temp2[MAX_PATH];
	::GetClassName(hWnd, temp1, MAX_PATH);
	/**/if (lstrcmp(temp1,L"#32770")==0) {
		EnumChildWindows(hWnd, EnumChild2, (LPARAM)hWnd);
	}
	return true;
}

void DlgFind() {
	BaseAPI api;
	HWND tank = api.getProcessHWND("#32770", "坦克大战登陆器");
	
	HWND nHwnd = ::FindWindow(L"#32770",NULL);
	EnumChildWindows(NULL,EnumChildProc, 0);
	
}

int main()
{
	/*PageRecThread th(L"UnityWndClass", L"Tank Battle");
	Page home(1, L"主界面");
	POINT dm;
	dm.x = 832;
	dm.y = 105;
	KeyPoint keys=KeyPoint(832,105, 16039495);
	home.addKeyPoint(keys);
	th.addPage(home);
	th.Resume();
	while (true) {
		std::cout << "现在页是:"<<th.whatPage().getIndex() << std::endl;
		Sleep(1000);
	}*/
	/*BaseAPI api;
	HWND hwnd = api.getProcessHWND("UnityWndClass", "Tank Battle");
	RECT rect=api.getProcessRect("UnityWndClass", "Tank Battle");
	PixCollect collect;
	std::cout << collect.Collection(hwnd, 832, 105) << std::endl;*/

	/*
	Page home = Page(1, L"主页");
	home.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	home.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	home.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	home.addKeyPoint(KeyPoint(-263, 13, 16777215, BASEP_RIGHT_TOP));

	Page searchExperience = Page(2, L"可以领取研发经验");
	searchExperience.addKeyPoint(KeyPoint(-12, -159, 2171347, BASEP_CENTER_BOTTOM));
	searchExperience.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	searchExperience.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	searchExperience.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));


	Page updateInfo = Page(3, L"更新公告面板");
	updateInfo.addKeyPoint(KeyPoint(458, -295, 16777215, BASEP_CENTER));
	updateInfo.addKeyPoint(KeyPoint(435, -174, 2171347, BASEP_CENTER));
	updateInfo.addKeyPoint(KeyPoint(435, 267, 1067519, BASEP_CENTER));
	updateInfo.setClose(458, -295, BASEP_CENTER);
	
	Page obtainskill = Page(4, L"可以免费抽取技能（主页）");
	obtainskill.addKeyPoint(KeyPoint(-220, -157, 2171347, BASEP_CENTER_BOTTOM));
	obtainskill.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	obtainskill.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	obtainskill.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	
	Page obtaincond = Page(5, L"可以免费抽取指挥官（主页）");
	obtaincond.addKeyPoint(KeyPoint(92, -158, 2171347, BASEP_CENTER_BOTTOM));
	obtaincond.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	obtaincond.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	obtaincond.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));
	
	Page onlinegift = Page(6, L"可以领取在线礼包");
	onlinegift.addKeyPoint(KeyPoint(-59,138, 16775151, BASEP_RIGHT_TOP));
	onlinegift.addKeyPoint(KeyPoint(281, 61, 1059906, BASEP_LEFT_TOP));
	onlinegift.addKeyPoint(KeyPoint(-468, -71, 1066495, BASEP_CENTER_BOTTOM));
	onlinegift.addKeyPoint(KeyPoint(468, -71, 1262847, BASEP_CENTER_BOTTOM));

	Page remakepage = Page(7, L"改装界面");
	remakepage.addKeyPoint(KeyPoint(486,-298, 16777215, BASEP_CENTER));
	remakepage.addKeyPoint(KeyPoint(-450, 229, 1262847, BASEP_CENTER));
	remakepage.addKeyPoint(KeyPoint(450, 229, 1262847, BASEP_CENTER));
	remakepage.addKeyPoint(KeyPoint(346, -37, 4342338, BASEP_CENTER));
	remakepage.setClose(486, -298, BASEP_CENTER);

	Page skillpage = Page(8, L"抽取技能界面");
	skillpage.addKeyPoint(KeyPoint(486, -298, 16777215, BASEP_CENTER));
	skillpage.addKeyPoint(KeyPoint(-147,-250, 1778517, BASEP_CENTER));
	skillpage.addKeyPoint(KeyPoint(227, -77, 4346268, BASEP_CENTER));
	skillpage.addKeyPoint(KeyPoint(-93, 135, 4342338, BASEP_CENTER));
	skillpage.setClose(486, -298, BASEP_CENTER);
	*/

	
	/*
	std::vector<KeyPoint> lists;
	lists.push_back(KeyPoint(281, 61, 0,BASEP_LEFT_TOP));
	lists.push_back(KeyPoint(-468, -71,0, BASEP_CENTER_BOTTOM));
	lists.push_back(KeyPoint(468, -71,0, BASEP_CENTER_BOTTOM));
	lists.push_back(KeyPoint(-263, 13, 0,BASEP_RIGHT_TOP));
	for (auto i = lists.cbegin(); i != lists.cend(); i++) {
		showPix(*i);
	}

	int a, b, flag;
	while (true) {
		std::cin >> a;
		std::cin >> b;
		std::cin >> flag;
		KeyPoint po(a, b, 0, flag);
		showPix(po);
	}
	*/
	/*
	int x1, y1, x2, y2;
	int R, G, B;
	
	PixCollect coll;
	BaseAPI api;
	
	std::cout << "输入格式:  x1 x2 y1 y2 r g b" << std::endl;
	while (true) {
		HWND tank = api.getProcessHWND("UnityWndClass", "Tank Battle");
		RECT rect = api.getProcessClient(tank);
		std::cout << "客户区左上角位置：(" << rect.left << "," << rect.top << ")" << std::endl;
		std::cin >> x1>>y1;
		std::cin >> x2>>y2;
		std::cin >> R >> G >> B;
		COLORREF co = RGB(R, G, B);
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				if (coll.Collection(tank, j, i) == co) {
					std::cout << "(" << j << "," << i << ")  " << co << " 置信度：" << coll.percent << "%" << std::endl;
				}
			}
		}
	}*/
	/*Sleep(2000);
	
	HWND tank = api.getProcessHWND("#32770", "坦克大战登陆器");
	//
	Sleep(2000);
	BaseAPI api;
	DlgFind();
	RECT rec = api.getProcessClient(service);
	POINT p;
	p.x = rec.left +502;
	p.y = rec.top + 107;
	api.MoveTo(p.x,p.y);
	Sleep(100);
	api.LeftClick(service, 502,107);*/
	
	int result = (int)ShellExecute(NULL, L"open",L"C:\\Users\\12703\\AppData\\Roaming\\Tencent\\QQMicroGameBox\\坦克大战", NULL, NULL, SW_SHOW);//打开主程序
	if (result < 32)
		MessageBox(NULL, L"启动错误", NULL, NULL);
	
	return 0;
}

