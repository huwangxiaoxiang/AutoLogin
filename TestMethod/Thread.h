#pragma once
#include <process.h>
#include <Windows.h>
#include <iostream>

//C++线程类，默认线程创建后挂起，
//若要使其创建后立即调度，请在子类中显式执行构造函数，参数为0
class Thread
{
public:
	void Resume();
	void Suspend();
	Thread(unsigned int flags=CREATE_SUSPENDED);
	virtual DWORD run()=0;

private:
	HANDLE thread_handle;
};

