
// TankLoginDlg.h: 头文件
//

#pragma once
#include <vector>
#include "Count.h"
#include "BaseAPI.h"

// TankLoginDlg 对话框
class TankLoginDlg : public CDialogEx,BaseAPI
{
// 构造
public:
	TankLoginDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TANKLOGIN_DIALOG };
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
	// 账号列表框
	CComboBox counts;
	std::vector<Count> couterlist;
	CString services[7] = { CString("华南一区"),CString("华东一区"),CString("华东二区"),CString("华南二区"),CString("华北一区"),CString("华东三区"),CString("华南三区") };

public:
	// 区服列表框
	CComboBox servers;
	afx_msg void OnLogin();
	afx_msg void OnChangeCount();
	afx_msg void OnCountEdit();
	void ClearWindow();
	void ClearGame();
	void InputString(CString s);
	void Start();
	void Input(CString number, CString password);
	Count getIDKey();
	BOOL startDirect(LPTSTR ID, LPTSTR key, int serverID);
	// 密码框
	CEdit Password;
	// 记住密码选项
	BOOL remember;
	BOOL store;
	afx_msg void OnBnClickedRem();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
