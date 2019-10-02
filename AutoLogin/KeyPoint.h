#pragma once
#include <Windows.h>

#define BASEP_LEFT_TOP 1
#define BASEP_RIGHT_TOP 2
#define BASEP_LEFT_BOTTOM 3
#define BASEP_RIGHT_BOTTOM 4
#define BASEP_CENTER 5
#define BASEP_CENTER_TOP 6
#define BASEP_CENTER_BOTTOM 7

class KeyPoint
{
public:
	COLORREF color;
	KeyPoint();
	KeyPoint(POINT point, COLORREF color,int base_flag=BASEP_LEFT_TOP);
	KeyPoint(int x, int y, COLORREF color,int base_flag=BASEP_LEFT_TOP);
	//��ȡ�õ������Ļ�ľ�������
	POINT getAbsoluteXY(HWND hwnd);
	//��ȡ�õ�����ڴ˴��ڿͻ��������λ������
	POINT getXY(HWND hwnd);
	//��ȡ�õ������ ��׼�� ��X�����ƫ��
	int getOffsetX();
	//��ȡ�õ������ ��׼�� ��Y�����ƫ��
	int getOffsetY();
private:
	//�ؼ���ƫ����
	POINT point;
	//��׼���־
	int base_flag;
	//��̬����ؼ���λ�ã���ֹ��Ϊ����λ�ñ仯���¹ؼ���λ�ô���
	POINT getBasePoint(int base_flag, HWND hwnd);
	int getX(HWND hwnd);
	int getY(HWND hwnd);
};

