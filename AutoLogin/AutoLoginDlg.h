
// AutoLoginDlg.h : 头文件
//
#pragma once
#include "afxwin.h"
#define UPDATE_STATE WM_USER+2
#define UPDATE_COUNTS WM_USER+3
#define PAUSE WM_USER+4
#pragma comment(lib,"../Debug/KeyBoardHOOK.lib")

typedef BOOL(*StartHook)(HWND hwnd);
typedef void (*ExitHook)();
using namespace std;

// CAutoLoginDlg 对话框
class CAutoLoginDlg : public CDialogEx
{
// 构造
public:
	CAutoLoginDlg(CWnd* pParent = NULL);	// 标准构造函数
	CFont* count;
	CFont* button;
	CFont* service;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOLOGIN_DIALOG };
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
	afx_msg LRESULT OnUpdateState(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdateCounts(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnPause(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()


public:
	afx_msg void OnEnChangeEdit3();
private:
	// 要添加的账号
	CString Number;
	// 添加账号的密码
	CString Key;
	// 华南一区是否选择
	BOOL s1;
	BOOL s2;
	BOOL s3;
	BOOL e1;
	BOOL e2;
	BOOL e3;
	BOOL n1;

	CString services[7] = { CString("华南一区"),CString("华东一区"),CString("华东二区"),CString("华南二区"),CString("华北一区"),CString("华东三区"),CString("华南三区") };
	HMODULE keybordDll = NULL;
	StartHook startHook;
	ExitHook exitHook;
	
public:
	CString NowNumber;
	CString NowService;
	vector<Count> CountNumber;
	afx_msg void OnBnClickedAddnumber();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLbnSelcancelList1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	
	CListBox CountList;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();

	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	CString state_text;
protected:
	CWinThread* LogThread;
};
