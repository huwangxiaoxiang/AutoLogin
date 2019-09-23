#include "PageRecThread.h"
CRITICAL_SECTION g_cs;

PageRecThread::PageRecThread(LPCTSTR className, LPCTSTR windowName)
{
	this->className = className;
	this->windowName = windowName;
	this->not_exit = true;
	this->nowpage = NULL;
	InitializeSRWLock(&lock);
}


void PageRecThread::Exit()
{
	this->not_exit = false;
}

Page PageRecThread::whatPage()
{
	Page result;
	AcquireSRWLockExclusive(&lock);
	result = this->nowpage;
	ReleaseSRWLockExclusive(&lock);
	return result;
}

void PageRecThread::addPage(Page page)
{
	this->pagelist.push_back(page);
}

void PageRecThread::test()
{
}

DWORD PageRecThread::run()
{
	while (this->not_exit) {
		HWND target = FindWindow(this->className, this->windowName);
		if (!target) this->nowpage = NULL;
		bool is_find = false;
		for (std::vector<Page>::iterator i = this->pagelist.begin(); i != this->pagelist.end(); i++) {
			if (i->isThisPage(target)) {
				setNowPage(*i);
				LeaveCriticalSection(&g_cs);
				is_find = true;
				break;
			}
		}
		if (!is_find) setNowPage(NULL);
		Sleep(200);
	}
	return 0;
}

void PageRecThread::setNowPage(Page newpage)
{
	AcquireSRWLockExclusive(&lock);
	this->nowpage = newpage;
	ReleaseSRWLockExclusive(&lock);
}
