#pragma once
#include"Act.h"
class MidData
{
public:
	Act Number;
	HANDLE semaphroe;
	MidData(Act number, HANDLE sem) { Number = number; semaphroe = sem; }
	MidData() {}
	~MidData();
};

