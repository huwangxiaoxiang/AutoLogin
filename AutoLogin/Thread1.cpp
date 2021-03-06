#include "stdafx.h"
#include "Thread1.h"
#include "AutoLoginDlg.h"

IMPLEMENT_DYNCREATE(Thread1, CWinThread)

Thread1::Thread1()
{
}


Thread1::~Thread1()
{
}

void Thread1::Exit()
{
	AfxEndThread(0, NULL);
}

BEGIN_MESSAGE_MAP(Thread1, CWinThread)
	ON_THREAD_MESSAGE(WM_Thread1, OnMessage)
END_MESSAGE_MAP()

void Thread1::run()
{
	FileOp num(L"e:\\now.bv");
	num.Read(numberlist);
	CAutoLoginDlg* dlg = (CAutoLoginDlg*)GetMainWnd();
	PageManager::Instance();
	for (vector<Count>::iterator beg = numberlist.begin(); beg != numberlist.end(); beg++)
	{
		Count now_count = *beg;
		int retry_times = 5;//失败时重新尝试的次数
		Act now(*beg);
		BOOL* cservice = now.Number.GetService();
		for (int ser = 0; ser <7; ser++)
		{
			dlg->PostMessage(UPDATE_COUNTS, (WPARAM)now_count.GetNumber().AllocSysString(), ser);
			if (cservice[ser]) {
				if (now_count.getID() == NULL || now_count.getPriKey() == NULL) {
					Notify(0);
					now.Start();
					Notify(1);
					now.Input();
					//Notify(2);
					//now.ChooseService(ser);
					now_count=now.setIDKey(now_count);
				}

				Notify(3);
				BOOL start=now.startDirect(now_count.getID(), now_count.getPriKey(), ser);
				if (!start && retry_times > 0) { ser--; retry_times--; now_count.setID(NULL); continue; }
				if (retry_times <= 0) break;
				BOOL pre=now.prepare();
				if(!pre&& retry_times > 0) { ser--; retry_times--;  now_count.setID(NULL); continue; }
				if (retry_times <= 0) break;

				Notify(6);
				now.getOnlineGift();
				Notify(8);
				now.getOfflineExperience();
				Notify(9);
				now.getSkill();
				Notify(10);
				now.getSysGift();
				Notify(4);
				now.exit();/**/
				
			}
		}
	}
	Notify(7);
	
}

BOOL Thread1::InitInstance()
{
	return TRUE;
}

int Thread1::ExitInstance()
{
	return CWinThread::ExitInstance();
}

BOOL Thread1::OnIdle(LONG ICount)
{
	CWinThread::OnIdle(ICount);
	return 0;
}

void Thread1::OnMessage(WPARAM wParam, LPARAM lParam)
{
	switch (wParam) {
	case 0:
		this->run();
		AfxEndThread(3);
		break;
	default:
		AfxMessageBox(CString("test"));
		break;
	}
	
}

void Thread1::Notify(WPARAM wParam)
{
	CAutoLoginDlg* dlg = (CAutoLoginDlg*)GetMainWnd();
	dlg->SendMessage(UPDATE_STATE, wParam, 0);
}
