#pragma once
#include "afxwin.h"
#define WM_Thread1 WM_USER+1

class Thread1 :
	public CWinThread
{
	DECLARE_DYNCREATE(Thread1)
public:
	void run();
	virtual BOOL InitInstance();
	virtual int  ExitInstance();
	virtual BOOL OnIdle(LONG ICount);
	BOOL exit;
	
	Thread1();
	~Thread1();
	void Exit();
	afx_msg void OnMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	void Notify(WPARAM wParam);
	
};

