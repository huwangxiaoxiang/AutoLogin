#pragma once
#include <Windows.h>
using namespace std;
class FileOp
{
private:
	CString path;
public:
	FileOp(CString);
	void Write(vector<Count>);
	void Read(vector<Count> &);
	~FileOp();
};

