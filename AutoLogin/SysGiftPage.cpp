#include "stdafx.h"
#include "SysGiftPage.h"

void SysGiftPage::init()
{
	this->red_point = KeyPoint(-301, -221, 2171347, BASEP_CENTER);
	this->affirm = KeyPoint(-73, 67, 0, BASEP_CENTER);
	this->look_point = KeyPoint(355, -192, 0, BASEP_CENTER);
	this->close_result = KeyPoint(177, -87, 0, BASEP_CENTER);
}

SysGiftPage::SysGiftPage()
{
	init();
}

SysGiftPage::SysGiftPage(int index, LPCTSTR name):Page(index,name)
{
	init();
}

SysGiftPage::SysGiftPage(int index, std::vector<KeyPoint> keypoints, LPCTSTR name):Page(index,keypoints,name)
{
	init();
}

BOOL SysGiftPage::has_gift(HWND process)
{
	COLORREF color = this->collect.Collection(process, this->red_point.getXY(process));
	if(color==this->red_point.color)
		return TRUE;
	return FALSE;
}
