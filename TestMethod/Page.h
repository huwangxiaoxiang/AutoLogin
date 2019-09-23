#pragma once
#include <vector>
#include <Windows.h>
#include "KeyPoint.h"
#include "PixCollect.h"
class Page
{
private:
	int index;//页面标识
	std::vector<KeyPoint> keypoints;//页面关键点及其颜色
	LPCTSTR name;
	PixCollect collect;
	KeyPoint close;//关闭按钮所在位置偏移量

public:
	void addKeyPoint(POINT point,COLORREF color,int base_flag=BASEP_LEFT_TOP);
	void addKeyPoint(int x, int y,COLORREF color,int base_flag=BASEP_LEFT_TOP);
	void addKeyPoint(KeyPoint keypoint);
	void setClose(POINT close,int base_flag);
	void setClose(int x, int y,int base_flag);
	POINT getClose(HWND hwnd);

	Page();
	Page(int index,LPCTSTR name=L"");
	Page(int index, std::vector<KeyPoint> keypoints, LPCTSTR name =L"");
	bool isThisPage(HWND process);

	int getIndex();
	std::vector<KeyPoint> getKeyPoints();
	LPCTSTR getPageName();

};

