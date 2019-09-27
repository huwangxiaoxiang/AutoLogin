#pragma once
#include <Windows.h>
#include <conio.h>
#include "Count.h"
#include "BaseAPI.h"
#include "PageManager.h"

class Act:public BaseAPI
{
public:
	Count Number;//保存着账号信息
	Act(Count ser);
	Act() {}
	~Act() {}
private:
	void ClearWindow();
	void InputString(CString s);
	LPTSTR GameClass = L"UnityWndClass";
	LPTSTR GameName = L"Tank Battle";

public:
	void Start();
	void Input();
	void ChooseService(int ser);
	void prepare();
	void getOnlineGift();
	void getOfflineExperience();
	void exit();
	Page waitPage(int page, LPTSTR className,LPTSTR windowName, int timeout);
	Page waitPage(std::vector<int> page, LPTSTR className, LPTSTR windowName, int timeout);
	void getSkill();
};

