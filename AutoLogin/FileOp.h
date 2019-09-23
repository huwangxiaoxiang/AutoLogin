#pragma once
#include <Windows.h>
using namespace std;
class FileOp
{
private:
	vector<Count> Number;
	CString path;
public:
	FileOp(vector<Count> ,CString);
	void Write();
	void Read(vector<Count> &);
	~FileOp();
};

