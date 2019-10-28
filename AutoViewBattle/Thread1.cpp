#include "pch.h"
#include "Thread1.h"
#include "PageManager.h"
#include <vector>
#include <random>

IMPLEMENT_DYNCREATE(Thread1, CWinThread)

Thread1::Thread1()
{
}


Thread1::~Thread1()
{
	exit = false;
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
	BaseAPI api;
	PageManager::Instance();
	//int result = (int)ShellExecute(NULL, L"open", DataDir, NULL, NULL, SW_SHOW);//打开主程序
	api.CMDCommand(L"G:\\C++\\AutoLogin\\TankFlow\\bin\\Release\\TankFlow.exe");
	while (exit==false) {
		HWND hwnd = api.getProcessHWND(L"UnityWndClass", L"Tank Battle");
		if (hwnd == NULL) {
			exit = true;
			break;
		}
		Page* now = PageManager::isThisPage(1, hwnd);
		HWND old=GetForegroundWindow();
		if (now->getIndex() == 1) {
			SetForegroundWindow(hwnd);
			KeyPoint view_buttons(-40,31,0,BASEP_RIGHT_TOP);
			POINT m = view_buttons.getAbsoluteXY(hwnd);
			api.MoveTo(m);
			Sleep(200);
			api.LeftClick(1);
		}
		std::vector<int> avaliable;
		for (int i = 2; i < 8; i++) {
			now = PageManager::isThisPage(i, hwnd);
			if (now->getIndex() == i) {
				avaliable.push_back(i);
			}
		}
		if (avaliable.size() > 0) {
			std::default_random_engine e;
			int randm = e() % avaliable.size();
			now = PageManager::getPage(*(avaliable.begin()+randm));
			if (now->getIndex() == -1) {
				Sleep(5000);
				continue;
			}
			api.ActiveWindow(hwnd);
			KeyPoint p = *(now->getKeyPoints().begin());
			api.MoveTo(p.getAbsoluteXY(hwnd));
			Sleep(200);
			api.LeftClick(1);
			Sleep(1000);
		}
		SetForegroundWindow(old);
		Sleep(5000);
	}
	api.CMDCommand(L"taskkill /im TankFlow.exe");
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
	
}
