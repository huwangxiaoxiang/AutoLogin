#pragma once
#include <Windows.h>
#include "winternl.h"
#include <bcrypt.h>
#include <Shlwapi.h>

typedef NTSTATUS(WINAPI* NtQueryInformationProcessFake)(HANDLE, DWORD, PVOID, ULONG, PULONG);

class BaseAPI
{
public:
	/*������ƶ�����Ļ(x,y)λ��*/
	void MoveTo(int x, int y);
	void MoveTo(POINT p);

	//ʹ�����ⰴť�ķ�ʽģ�������count��
	void LeftClick(int count);

	//ʹ�ý�����Ϣ���͵ķ�ʽ��������������贰�ڼ���
	void LeftClick(HWND hwnd, int x, int y);

	//����ĳ�����̴��ڷ�������ǰ
	void ActiveWindow(HWND hwnd);

	//ʹ�����ⰴ����ʽ���а�ť����ģ��
	void KeyPress(int);

	//ʹ�����ⰴ����ʽ������ϼ�����ģ��
	void KeyPress(int, int);

	//��ȡ���̴��ھ��Σ�����������
	RECT getProcessRect();
	RECT getProcessRect(LPCTSTR className, LPCTSTR windowName);
	RECT getProcessRect(HWND hwnd);

	//��ȡ�ͻ������Σ�ȥ����������
	RECT getProcessClient();
	RECT getProcessClient(LPCTSTR className, LPCTSTR windowName);
	RECT getProcessClient(HWND hwnd);

	//��ȡ��Ϸ���ھ��
	HWND getProcessHWND(LPCTSTR className, LPCTSTR windowName);
	HWND getProcessHWND();

	//����Ŀ����̴������ƺ�����
	void SetDefaultProcess(LPCTSTR className, LPCTSTR windowName);

	//ִ�п���̨����
	void CMDCommand(LPCTSTR command);

	//��ȡ�����������
	LPTSTR getProcCMD(WORD pid);

private:
	int TransformWidth(int);
	int TransformHeight(int);
	//��Ļ�ֱ�����Ϣ
	DEVMODE screen;
	LPCTSTR className = NULL;
	LPCTSTR windowName = NULL;
public:
	BaseAPI();
};

