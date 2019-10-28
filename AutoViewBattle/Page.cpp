#include "pch.h"
#include "Page.h"
#include <tchar.h>


void Page::addKeyPoint(POINT point, COLORREF color,int base_flag)
{
	KeyPoint p(point, color,base_flag);
	addKeyPoint(p);
}

void Page::addKeyPoint(int x, int y, COLORREF color,int base_flag)
{
	KeyPoint p(x, y, color,base_flag);
	addKeyPoint(p);
}

void Page::addKeyPoint(KeyPoint keypoint)
{
	this->keypoints.push_back(keypoint);
}

void Page::setClose(POINT close, int base_flag)
{
	this->close = KeyPoint(close, 0, base_flag);
}

void Page::setClose(int x, int y, int base_flag)
{
	this->close = KeyPoint(x, y, 0, base_flag);
}

POINT Page::getClose(HWND hwnd)
{
	return close.getXY(hwnd);
}

POINT Page::getCloseAbsolute(HWND hwnd)
{
	return close.getAbsoluteXY(hwnd);
}

Page::Page()
{
	this->index = -1;
	this->keypoints.clear();
	this->name = L"";
}

Page::Page(int index,LPCTSTR name)
{
	this->index =index;
	this->keypoints.clear();
	this->name = name;
}

Page::Page(int index, std::vector<KeyPoint> keypoints,LPCTSTR name)
{
	this->index = index;
	this->keypoints = keypoints;
	this->name = name;
}

bool Page::isThisPage(HWND process)
{
	for (std::vector<KeyPoint>::iterator i = this->keypoints.begin(); i != keypoints.end(); i++) {
		COLORREF m = collect.Collection(process, i->getXY(process));
		if (!( m== i->color)) return false;
	}
	return true;
}

int Page::getIndex()
{
	return this->index;
}

std::vector<KeyPoint> Page::getKeyPoints()
{
	return this->keypoints;
}

LPCTSTR Page::getPageName()
{
	return this->name;
}
