#pragma once
#include <vector>
#include "Page.h"
#include <string>
#include <sstream>
class PageManager
{
private:
	static std::vector<Page> pages;
	

public:
	static void Instance();
	static std::wstring ShowPageList();
	static Page isThisPage(int index,HWND process);
};

