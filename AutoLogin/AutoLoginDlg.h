
// AutoLoginDlg.h : ͷ�ļ�
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

// CAutoLoginDlg �Ի���
class CAutoLoginDlg : public CDialogEx
{
// ����
public:
	CAutoLoginDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CFont* count;
	CFont* button;
	CFont* service;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOLOGIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	// Ҫ��ӵ��˺�
	CString Number;
	// ����˺ŵ�����
	CString Key;
	// ����һ���Ƿ�ѡ��
	BOOL s1;
	BOOL s2;
	BOOL s3;
	BOOL e1;
	BOOL e2;
	BOOL e3;
	BOOL n1;

	CString services[7] = { CString("����һ��"),CString("����һ��"),CString("��������"),CString("���϶���"),CString("����һ��"),CString("��������"),CString("��������") };
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
