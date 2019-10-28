
// AutoViewBattleDlg.h: 头文件
//

#pragma once
#include "Thread1.h"

// CAutoViewBattleDlg 对话框
class CAutoViewBattleDlg : public CDialogEx
{
// 构造
public:
	CAutoViewBattleDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOVIEWBATTLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

private:
	bool mode = false;
	CButton Start_Btn;
	Thread1* threads;
public:
	afx_msg void OnBnClickedCancel();
};
