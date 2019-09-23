#pragma once
#include <Windows.h>
#include "BaseAPI.h"
#define BASEP_LEFT_TOP 1
#define BASEP_RIGHT_TOP 2
#define BASEP_LEFT_BOTTOM 3
#define BASEP_RIGHT_BOTTOM 4
#define BASEP_CENTER 5
#define BASEP_CENTER_TOP 6
#define BASEP_CENTER_BOTTOM 7

class KeyPoint
{
public:
	COLORREF color;
	KeyPoint();
	KeyPoint(POINT point, COLORREF color,int base_flag=BASEP_LEFT_TOP);
	KeyPoint(int x, int y, COLORREF color,int base_flag=BASEP_LEFT_TOP);

	
	POINT getXY(HWND hwnd);
	int getOffsetX();
	int getOffsetY();

private:
	//关键点偏移量
	POINT point;
	//基准点标志
	int base_flag;
	//动态计算关键点位置，防止因为窗口位置变化导致关键点位置错误
	POINT getBasePoint(int base_flag, HWND hwnd);

	int getX(HWND hwnd);
	int getY(HWND hwnd);
};

