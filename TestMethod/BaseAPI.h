#pragma once
#include <Windows.h>
#include <string.h>
class BaseAPI
{
public:
	/*������ƶ�����Ļ(x,y)λ��*/
	void MoveTo(int x, int y);

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
	RECT getProcessRect(LPCSTR className, LPCSTR windowName);
	RECT getProcessRect(HWND hwnd);

	//��ȡ�ͻ������Σ�ȥ����������
	RECT getProcessClient();
	RECT getProcessClient(LPCSTR className, LPCSTR windowName);
	RECT getProcessClient(HWND hwnd);

	//��ȡ��Ϸ���ھ��
	HWND getProcessHWND(LPCSTR className, LPCSTR windowName);
	HWND getProcessHWND();

	//����Ŀ����̴������ƺ�����
	void SetDefaultProcess(LPCSTR className, LPCSTR windowName);

	//ִ�п���̨����
	void CMDCommand(LPTSTR command);

private:
	int TransformWidth(int);
	int TransformHeight(int);
	//��Ļ�ֱ�����Ϣ
	DEVMODE screen;
	LPCSTR className = NULL;
	LPCSTR windowName = NULL;
public:
	BaseAPI();
};

