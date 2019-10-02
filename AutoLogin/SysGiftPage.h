#pragma once
#include "Page.h"
class SysGiftPage :
	public Page
{
private:
	KeyPoint red_point;
	void init();

public:
	KeyPoint look_point;
	KeyPoint affirm;
	KeyPoint close_result;

public:
	SysGiftPage();
	SysGiftPage(int index, LPCTSTR name = L"");
	SysGiftPage(int index, std::vector<KeyPoint> keypoints, LPCTSTR name = L"");
	BOOL has_gift(HWND process);

};

