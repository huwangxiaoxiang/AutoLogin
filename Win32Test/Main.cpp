#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>
#include "winternl.h"
#include <Shlobj.h>
#include "BaseAPI.h"


typedef NTSTATUS(WINAPI* NtQueryInformationProcessFake)(HANDLE, DWORD, PVOID, ULONG, PULONG);

NtQueryInformationProcessFake ntQ = NULL;


LPTSTR getProcCMD(DWORD pid) {
	HANDLE hproc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	LPTSTR result = NULL;
	if (INVALID_HANDLE_VALUE != hproc) {
		HANDLE hnewdup = NULL;
		PEB peb;
		RTL_USER_PROCESS_PARAMETERS upps;
		WCHAR buffer[MAX_PATH] = { NULL };
		HMODULE hm = LoadLibrary(L"Ntdll.dll");
		if (hm != NULL) {
			ntQ = (NtQueryInformationProcessFake)GetProcAddress(hm, "NtQueryInformationProcess");
			if (DuplicateHandle(GetCurrentProcess(), hproc, GetCurrentProcess(), &hnewdup, 0, FALSE, DUPLICATE_SAME_ACCESS)) {
				PROCESS_BASIC_INFORMATION pbi;
				NTSTATUS isok = ntQ(hnewdup, 0/*ProcessBasicInformation*/, (PVOID)& pbi, sizeof(PROCESS_BASIC_INFORMATION), 0);
				if (BCRYPT_SUCCESS(isok)) {
					if (ReadProcessMemory(hnewdup, pbi.PebBaseAddress, &peb, sizeof(PEB), 0))
						if (ReadProcessMemory(hnewdup, peb.ProcessParameters, &upps, sizeof(RTL_USER_PROCESS_PARAMETERS), 0)) {
							WCHAR* buffer = new WCHAR[upps.CommandLine.Length + 1];
							ZeroMemory(buffer, (upps.CommandLine.Length + 1) * sizeof(WCHAR));
							ReadProcessMemory(hnewdup, upps.CommandLine.Buffer, buffer, upps.CommandLine.Length, 0);
							result = buffer;
						}
				}
				CloseHandle(hnewdup);
			}
		}
		CloseHandle(hproc);
	}
	return result;
}


using namespace std;
int main() {
	/*
	TCHAR DataDir[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, DataDir))) {
		lstrcat(DataDir, L"\\Tencent\\QQMicroGameBox\\1.2.1.7\\QQMicroGameBox.exe -/appid:1103413151");
	}
	STARTUPINFO si = { sizeof(si) };
	si.wShowWindow = SW_MINIMIZE;
	PROCESS_INFORMATION pi;
	BOOL tank = CreateProcess(NULL, DataDir, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	if (tank) {
		wcout << "OK" << endl;
		wcout << L"进程ID ：" << pi.dwProcessId << L"线程ID：" << pi.dwThreadId << endl;
	}*/
	BaseAPI api;
	//HWND h = api.getProcessHWND(L"UnityWndClass", L"Tank Battle");
	//SetForegroundWindow(h);
	Sleep(2000);
	std::cout << "开始模拟..." << endl;
	//api.KeyDown(87);
	//Sleep(3000);
	//api.KeyUp(87);
	POINT pos;
	GetCursorPos(&pos);
	int times = 0;
	int delta = 20;
	for (int i = 0; i < 200; i++,times++) {
		times = times % 50;
		if (times == 0) delta = -delta;
		mouse_event(MOUSEEVENTF_MOVE, delta, 0, 0, 0);
		Sleep(20);
	}

	std::cout << "模拟结束" << endl;
	
	return 0;
}