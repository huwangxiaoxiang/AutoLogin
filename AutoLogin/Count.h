#pragma once
class Count
{
private:
	CString Number;
	CString Key;
	BOOL Service[7];
	LPTSTR ID;
	LPTSTR priKey;
public:
	Count();
	Count(CString count, CString key, BOOL s0, BOOL s1, BOOL s2, BOOL s3, BOOL s4, BOOL s5, BOOL s6);
	void SetNumber(CString count);
	void SetKey(CString key);
	void SetService(BOOL s0, BOOL s1, BOOL s2, BOOL s3, BOOL s4, BOOL s5, BOOL s6);
	void setID(LPTSTR id);
	void setPriKey(LPTSTR priKey);
	LPTSTR getID();
	LPTSTR getPriKey();
	CString GetNumber();
	CString GetKey() { return Key; }
	BOOL* GetService() { return Service; }
	~Count();
	
};

