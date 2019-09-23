#pragma once
#include <Windows.h>
#include <iostream>
#include <unordered_map>
class PixCollect
{
protected:
	int width;
	int height;
	std::vector<COLORREF> colors;
	std::unordered_map<COLORREF, int> computer;
	RECT getGameClient(HWND hwnd);
public:
	PixCollect(int width=3, int height=3);
	
	COLORREF Collection(HWND hwnd,POINT center);
	COLORREF Collection(HWND hwnd,int x, int y);
	int percent = 0;

private:
	void showColors();
	COLORREF getMost();
};

