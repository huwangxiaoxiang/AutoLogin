#pragma once
#include <process.h>
#include <Windows.h>
#include <iostream>

//C++�߳��࣬Ĭ���̴߳��������
//��Ҫʹ�䴴�����������ȣ�������������ʽִ�й��캯��������Ϊ0
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

