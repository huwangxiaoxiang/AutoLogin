#pragma once


// Dia1 对话框

class Dia1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dia1)

public:
	Dia1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dia1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUITEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
