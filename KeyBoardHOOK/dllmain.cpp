// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <fstream>
#include <iostream>
#include <sstream>

#define PAUSE WM_USER+4
HHOOK hook=NULL;
HWND hwnd=NULL;
HINSTANCE   g_hInstance = NULL;
int m = 12;


void log(std::string s) {
	std::ofstream out("E:\\test.txt", std::ios::app);
	out << s << std::endl;
	out.close();
}

LRESULT CALLBACK KeyBoardProcess(int nCode, WPARAM wParam, LPARAM lParam)
{
	//std::ostringstream out;
	switch (nCode)
	{
	case HC_ACTION:
	{
		KBDLLHOOKSTRUCT* kHook = (KBDLLHOOKSTRUCT*)lParam;
		if (wParam == WM_KEYUP&&hwnd!=NULL)
		{
			//out << "nCode:" << nCode << " wparam:" << wParam << " lparam:" << kHook->vkCode;
			//log(out.str());
			if (kHook->vkCode == VK_F2)
			{
				PostMessage(hwnd, PAUSE, NULL, NULL);
			}
		}
	}

	break;
	}
	return CallNextHookEx(hook, nCode, wParam, lParam);
}

extern "C" _declspec(dllexport)
BOOL  Start(HWND hwnds) {
	//log("start");
	hwnd = hwnds;
	hook = (HHOOK)SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyBoardProcess,g_hInstance,NULL);
	if (hook == NULL) {
		return FALSE;
	}
	return TRUE;
}

extern "C" _declspec(dllexport)
void Exit_() {
	//log("exit");
	UnhookWindowsHookEx(hook);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	g_hInstance = (HINSTANCE)hModule;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		//log("process attach");
		break;
    case DLL_THREAD_ATTACH:
		//log("thread attach");
		break;
    case DLL_THREAD_DETACH:
		//log("thread detach");
		break;
    case DLL_PROCESS_DETACH:
		//log("process detach");
        break;
    }
    return TRUE;
}


