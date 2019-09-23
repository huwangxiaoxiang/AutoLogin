#include "stdafx.h"
#include "Count.h"


Count::Count()
{
}


Count::~Count()
{
}

Count::Count(CString Count, CString key, BOOL s0, BOOL s1, BOOL s2, BOOL s3, BOOL s4, BOOL s5, BOOL s6) {
	this->SetNumber(Count);
	this->SetKey(key);
	this->SetService(s0, s1, s2, s3, s4, s5, s6);
}

void Count:: SetNumber(CString number) {
	this->Number = number;
}

void Count::SetKey(CString key) {
	this->Key = key;
}

CString Count::GetNumber() {
	return Number;
}

void Count::SetService(BOOL s0,BOOL s1, BOOL s2, BOOL s3, BOOL s4, BOOL s5, BOOL s6) {
	Service[0] = s0;
	Service[1] = s1;
	Service[2] = s2;
	Service[3] = s3; 
	Service[4] = s4;
	Service[5] = s5;
	Service[6] = s6;
}