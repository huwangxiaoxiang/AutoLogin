#include "stdafx.h"
#include "PixCollect.h"

PixCollect::PixCollect(int width, int height)
{
	this->width = width;
	this->height = height;
}

RECT PixCollect::getGameClient(HWND client)
{
	if (client == NULL) return RECT();
	RECT result, clients;
	GetWindowRect(client, &result);
	GetClientRect(client, &clients);
	result.top = result.bottom - clients.bottom;
	return result;
}

COLORREF PixCollect::Collection(HWND hwnd,POINT center)
{
	return Collection(hwnd,center.x, center.y);
}

COLORREF PixCollect::Collection(HWND hwnd,int x, int y)
{
	this->colors.clear();
	this->computer.clear();
	POINT begin;
	begin.x = x - (int)(width/2);
	begin.y = y - (int)(height/2);
	HDC hdc=GetDC(hwnd);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			COLORREF temp = GetPixel(hdc, begin.x + j, begin.y + i);
			int m = computer[temp];
			if (m == 0) {
				computer[temp] = 1;
				colors.push_back(temp);
			}
			else
				computer[temp] += 1;
		}
	}
	ReleaseDC(hwnd,hdc);
	//showColors();
	return getMost();
}

void PixCollect::showColors()
{
	for (std::vector<COLORREF>::iterator i = colors.begin(); i != colors.end(); i++) {
		std::cout << (int)GetRValue(*i) << "," << (int)GetGValue(*i) << "," << (int)GetBValue(*i) <<" "<<computer[*i]<< " "<<*i<<std::endl;
	}
}

COLORREF PixCollect::getMost()
{
	int max = 0;
	this->percent = 0;
	int sum = 0;
	COLORREF result;
	for (std::vector<COLORREF>::iterator i = colors.begin(); i != colors.end(); i++) {
		if (computer[*i] >= max) {
			max = computer[*i];
			result = *i;
		}
		sum += computer[*i];
	}
	this->percent = (max * 100.0) / (sum+0.0);
	return result;
}
