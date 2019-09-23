#pragma once


// Dia2 对话框

class Dia2 : public CDialogEx
{
	DECLARE_DYNAMIC(Dia2)

public:
	Dia2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dia2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUITEST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
