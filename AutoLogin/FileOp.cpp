#include "stdafx.h"
#include "FileOp.h"


FileOp::FileOp(vector<Count> number, CString path)
{
	Number = number;
	this->path = path;
}


void FileOp::Write() {
	std::wofstream da(path);
	for (vector<Count>::iterator index = Number.begin(); index < Number.end(); index++){
		da << index->GetNumber().GetBuffer(0);
		da << " ";
		da << (index->GetKey().GetBuffer(0));
		da << " ";
		BOOL* service;
		service = index->GetService();
		for (int ser = 0; ser < 7; ser++) {
			if (service[ser])
				da << "1";
			else
				da << "0";
			//AfxMessageBox(service[ser]);
		}
		da << "\n";
	}
	da.close();
}

void FileOp::Read(vector<Count> &CountNumber) {
	std::wifstream da(path);
	Count midcount;
	BOOL service[7];
	if (da.fail())
		AfxMessageBox(CString("上次未登陆任何账号"));
	else {
		CountNumber.clear();
		do{
			std::wstring mid[3];
			da >> mid[0];
			if (mid[0] == L"")
				break;
			da >> mid[1];
			da >> mid[2];
			midcount.SetNumber(mid[0].c_str());
			midcount.SetKey(mid[1].c_str());
			for (int index = 0; index < 7; index++) {
				if (mid[2][index] == '1')
					service[index] = TRUE;
				else
					service[index] = FALSE;
			}
			midcount.SetService(service[0],service[1],service[2],service[3],service[4],service[5],service[6]);
			CountNumber.push_back(midcount);
			/*AfxMessageBox(mid[0].c_str());
			AfxMessageBox(mid[1].c_str());
			AfxMessageBox(mid[2].c_str());*/
		} while (!da.eof());
	}
	da.close();
}

FileOp::~FileOp()
{
}
