#pragma once
#include <vector>
#include <Windows.h>
#include "KeyPoint.h"
#include "PixCollect.h"
class Page
{
private:
	int index;//ҳ���ʶ
	std::vector<KeyPoint> keypoints;//ҳ��ؼ��㼰����ɫ
	LPCTSTR name;
	PixCollect collect;
	KeyPoint close;//�رհ�ť����λ��ƫ����

public:
	void addKeyPoint(POINT point,COLORREF color,int base_flag=BASEP_LEFT_TOP);
	void addKeyPoint(int x, int y,COLORREF color,int base_flag=BASEP_LEFT_TOP);
	void addKeyPoint(KeyPoint keypoint);
	void setClose(POINT close,int base_flag);
	void setClose(int x, int y,int base_flag);
	POINT getClose(HWND hwnd);

	Page();
	Page(int index,LPCTSTR name=L"");
	Page(int index, std::vector<KeyPoint> keypoints, LPCTSTR name =L"");
	bool isThisPage(HWND process);

	int getIndex();
	std::vector<KeyPoint> getKeyPoints();
	LPCTSTR getPageName();

};

