#pragma once
#include <iostream>
#include "Thread.h"
#include "Page.h"
#include <vector>


class PageRecThread :public Thread
{
public:
	PageRecThread(LPCTSTR className,LPCTSTR windowName);
	void Exit();
	Page whatPage();
	void addPage(Page page);
	void test();


protected:
	DWORD run();

public:
	LPCTSTR className;
	LPCTSTR windowName;
	bool not_exit=true;
	Page nowpage;
	std::vector<Page> pagelist;
	void setNowPage(Page newpage);
	SRWLOCK lock;
};

