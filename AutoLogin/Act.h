#pragma once
#include <Windows.h>
#include <conio.h>
#include "Count.h"
#include "BaseAPI.h"
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

public:
	void Start();
	void Input();
	void ChooseService(int ser);
	void prepare();
	void getOnlineGift();
	void getOfflineExperience();
	void exit();
};

