// TankLauncher.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include "BaseAPI.h"
#include <Shlobj.h>  


int main(int argc, char* argv[])
{

	/**/if (argc == 2) {
		CHAR* DataDir = new CHAR[MAX_PATH];
		if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, 0, DataDir))) {
			StrCatA(DataDir, "\\tkdz\\Tank.exe ");
			StrCatA(DataDir, argv[1]);
			//std::cout << DataDir << std::endl;
		}
		STARTUPINFOA si = { sizeof(si) };
		PROCESS_INFORMATION pi;
		BOOL tank = CreateProcessA(NULL, DataDir, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
		
	}
}

