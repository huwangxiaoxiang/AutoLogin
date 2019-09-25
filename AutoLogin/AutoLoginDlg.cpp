
// AutoLoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AutoLoginDlg.h"
#include "afxdialogex.h"
#include"Thread1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAutoLoginDlg �Ի���



CAutoLoginDlg::CAutoLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AUTOLOGIN_DIALOG, pParent)
	, Number(_T(""))
	, Key(_T(""))
	, s1(FALSE)
	, s2(FALSE)
	, s3(FALSE)
	, e1(FALSE)
	, e2(FALSE)
	, e3(FALSE)
	, n1(FALSE)
	, NowNumber(_T(""))
	, NowService(_T(""))
	, state_text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CAutoLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, CountList);
	DDX_Text(pDX, NUMBER, Number);
	DDX_Text(pDX, KEY, Key);
	DDX_Check(pDX, IDC_CHECK2, s1);
	DDX_Check(pDX, IDC_CHECK3, s2);
	DDX_Check(pDX, IDC_CHECK4, s3);
	DDX_Check(pDX, IDC_CHECK5, e1);
	DDX_Check(pDX, IDC_CHECK6, e2);
	DDX_Check(pDX, IDC_CHECK7, e3);
	DDX_Check(pDX, IDC_CHECK8, n1);
	DDX_Text(pDX, IDC_EDIT3, NowNumber);
	DDX_Text(pDX, IDC_EDIT4, NowService);
	DDX_Control(pDX, IDC_LIST1, CountList);
	DDX_Text(pDX, IDC_STATUE_TEXT, state_text);
}

BEGIN_MESSAGE_MAP(CAutoLoginDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT3, &CAutoLoginDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(ADDNUMBER, &CAutoLoginDlg::OnBnClickedAddnumber)
	ON_LBN_SELCHANGE(IDC_LIST1, &CAutoLoginDlg::OnLbnSelchangeList1)
	ON_LBN_SELCANCEL(IDC_LIST1, &CAutoLoginDlg::OnLbnSelcancelList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAutoLoginDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAutoLoginDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CAutoLoginDlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON6, &CAutoLoginDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CAutoLoginDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDCANCEL, &CAutoLoginDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON4, &CAutoLoginDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CAutoLoginDlg::OnBnClickedButton7)
	ON_MESSAGE(UPDATE_STATE, &CAutoLoginDlg::OnUpdateState)
	ON_MESSAGE(UPDATE_COUNTS, &CAutoLoginDlg::OnUpdateCounts)
	ON_MESSAGE(PAUSE, &CAutoLoginDlg::OnPause)
END_MESSAGE_MAP()


// CAutoLoginDlg ��Ϣ�������

BOOL CAutoLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);

	keybordDll = LoadLibrary(L"../Debug/KeyBoardHOOK.dll");
	if (keybordDll == NULL) {
		AfxMessageBox(L"ȫ�ֿ�ݼ�����ʧ�ܣ�ȫ�ֿ�ݼ��������ã�");
	}
	else {
		startHook = (StartHook)GetProcAddress(keybordDll, "Start");
		exitHook = (ExitHook)GetProcAddress(keybordDll, "Exit_");
		if (startHook && exitHook) {
			startHook(this->m_hWnd);
		}
		else {
			AfxMessageBox(L"ȫ�ֿ�ݼ�����ʧ�ܣ�ȫ�ֿ�ݼ��������ã�");
		}
	}
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAutoLoginDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAutoLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CAutoLoginDlg::OnUpdateState(WPARAM wParam, LPARAM lParam)
{
	/**/switch (wParam) {
	case 0:
		this->state_text = L"���ڴ���Ϸ...";
		break;
	case 1:
		this->state_text = L"�����˺ź�����...";
		break;
	case 2:
		this->state_text = L"����ѡ������...";
		break;
	case 3:
		this->state_text = L"���ڵȴ���Ϸ��...";
		break;
	case 4:
		this->state_text = L"�˳���Ϸ...";
		break;
	case 5:
		this->state_text = L"����ͣ��¼";
		break;
	case 6:
		this->state_text = L"������ȡ�������...";
		break;
	case 7:
		this->state_text = L"���������";
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
		LogThread = NULL;
		break;
	case 8:
		this->state_text = L"��ȡѵ������...";
		break;
	default:
		this->state_text = L"";
		break;
	 }
	UpdateData(false);
	return 0;
}

LRESULT CAutoLoginDlg::OnUpdateCounts(WPARAM wParam, LPARAM lParam)
{
	this->NowNumber = CString((BSTR)wParam);
	this->NowService = services[lParam];
	UpdateData(false);
	SysFreeString((BSTR)wParam);
	return 0;
}

LRESULT CAutoLoginDlg::OnPause(WPARAM wParam, LPARAM lParam)
{
	if (GetDlgItem(IDC_BUTTON4)->IsWindowVisible()) {
		OnBnClickedButton4();
	}
	else {
		OnBnClickedButton7();
	}
	return 0;
}

void CAutoLoginDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAutoLoginDlg::OnBnClickedAddnumber()
{
	BOOL flag = false;
	UpdateData(true);
	if (!Number.IsEmpty()&&!Key.IsEmpty()) {
		for (vector<Count>::iterator find=CountNumber.begin(); find < CountNumber.end(); find++) {
			if (find->GetNumber()==Number) {
				AfxMessageBox(_T("���˺��Ѿ���ӹ���"));
				flag = true;
				break;
			}
		}
		if (flag == false) {
			Count hu(Number, Key, s1, s2, s3, e1, e2, e3, n1);
			CountNumber.push_back(hu);
			CountList.AddString(Number);
			UpdateData(false);
		}
		
	}
	else
		AfxMessageBox(_T("�˺�������Ϣ��������"));
}


void CAutoLoginDlg::OnLbnSelchangeList1()
{
	
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
}


void CAutoLoginDlg::OnLbnSelcancelList1()
{
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
}


void CAutoLoginDlg::OnBnClickedButton2()//ɾ����ť
{
	CString selected;
	CountList.GetText(CountList.GetCurSel(), selected);
	for (vector<Count>::iterator find = CountNumber.begin(); find < CountNumber.end(); find++) {
		if (selected == find->GetNumber()) {
			CountNumber.erase(find);
			break;
		}
	}
	CountList.DeleteString(CountList.GetCurSel());
	UpdateData(false);
	UpdateData(true);
	//AfxMessageBox(CountNumber.begin()->GetNumber());
}

//��ʼ��¼��ť
void CAutoLoginDlg::OnBnClickedButton3()
{
	if (CountNumber.size() == 0) {
		AfxMessageBox(_T("�б���û���˺���Ϣ����������˺ţ�"));
	}
	else 
	{
	FileOp* file=new FileOp(CString("e:\\now.bv"));
	file->Write(CountNumber);
	LogThread=AfxBeginThread(RUNTIME_CLASS(Thread1));
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(0);
	 LogThread->PostThreadMessage(WM_Thread1, 0, NULL);
	}
}

//���԰�ť
void CAutoLoginDlg::OnBnClickedButton1()
{
	/*CString a("3185271559");
	CString b("2587963op");
	Count test1(a, b, 1, 1, 0, 1, 0, 0, 0);
	Act test(test1);

	for (int i = 0; i < 7; i++) {
		test.Start();
		test.Input();
		test.ChooseService(i);
		test.prepare();
		test.exit();
	}

	test.Find();*/
	
}

HBRUSH CAutoLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	CFont theFont;
	HBRUSH theBrush;

	if (pWnd->GetDlgCtrlID() == IDC_STATIC) {
		pDC->SetTextColor(RGB(212,81,0));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(200, L"�����п�");
		//theFont.CreatePointFont(200, EnumFontFamilies();
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC101|| pWnd->GetDlgCtrlID() == IDC_STATIC102||
		pWnd->GetDlgCtrlID() == IDC_STATIC106 || pWnd->GetDlgCtrlID() == IDC_STATIC107) {
		pDC->SetTextColor(RGB(0,0,0));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(120, L"΢���ź�");
		//theFont.CreatePointFont(200, EnumFontFamilies();
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}


	if (pWnd->GetDlgCtrlID() == IDC_STATIC104|| pWnd->GetDlgCtrlID() == IDC_STATIC105) {
		pDC->SetTextColor(RGB(0,128,0));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(140, L"����");
		//theFont.CreatePointFont(200, EnumFontFamilies();
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC110) {
		pDC->SetTextColor(RGB(255,69,0));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(150, L"�����п�");
		//theFont.CreatePointFont(200, EnumFontFamilies();
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}
	if (pWnd->GetDlgCtrlID() == NUMBER|| pWnd->GetDlgCtrlID() == KEY
		|| pWnd->GetDlgCtrlID() == IDC_EDIT3 || pWnd->GetDlgCtrlID() == IDC_EDIT4)
	{
		pDC->SetTextColor(RGB(0,122,204));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(150, L"����");
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}
	//������Ͽ����������
	if (pWnd->GetDlgCtrlID() == IDC_STATIC0|| pWnd->GetDlgCtrlID()== IDC_STATIC100 ||
		pWnd->GetDlgCtrlID() == IDC_STATIC103 || pWnd->GetDlgCtrlID() == IDC_STATIC108 || 
		pWnd->GetDlgCtrlID() == IDC_STATIC109)
	{
		pDC->SetTextColor(RGB(43,156,201));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(90, L"������κ");
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}

	//ѡ���������������
	if (pWnd->GetDlgCtrlID() == IDC_CHECK2 || pWnd->GetDlgCtrlID() == IDC_CHECK3 ||
		pWnd->GetDlgCtrlID() == IDC_CHECK4 || pWnd->GetDlgCtrlID() == IDC_CHECK5 ||
		pWnd->GetDlgCtrlID() == IDC_CHECK6 || pWnd->GetDlgCtrlID() == IDC_CHECK7 || 
		pWnd->GetDlgCtrlID() == IDC_CHECK8)
	{
		pDC->SetTextColor(RGB(111,0,138));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(70, L"΢���ź�");
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_BUTTON2 || pWnd->GetDlgCtrlID() == IDC_BUTTON5 ||
		pWnd->GetDlgCtrlID() == IDC_BUTTON6 || pWnd->GetDlgCtrlID() == IDC_BUTTON3 ||
		pWnd->GetDlgCtrlID() == IDCANCEL || pWnd->GetDlgCtrlID() == ADDNUMBER )
	{
		pDC->SetTextColor(RGB(248, 148, 242));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(70, L"΢���ź�");
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}

	//�˺��б��
	if (pWnd->GetDlgCtrlID() == IDC_LIST1) {
		pDC->SetTextColor(RGB(132,0,139));//���ñ༭���������ɫ
		pDC->SetBkMode(TRANSPARENT);//�������屳��Ϊ͸��
		theBrush = CreateSolidBrush(RGB(245, 245, 245));
		theFont.CreatePointFont(120, L"����");
		pDC->SelectObject(&theFont);//��������  
		return theBrush;
	}

	if (nCtlColor == CTLCOLOR_DLG) {
		//theBrush = CreateSolidBrush(RGB(29,99,60));
		theBrush = CreateSolidBrush(RGB(245,245,245));
		return theBrush;
	}

}

//��ȡ�б�
void CAutoLoginDlg::OnBnClickedButton6()
{
	FileOp *file = new FileOp(CString("e:\\info.bv"));
	file->Read(CountNumber);
	while (CountList.GetCount() != 0)
		CountList.DeleteString(0);
	for (vector<Count>::iterator index = CountNumber.begin(); index < CountNumber.end(); index++) {
		CountList.AddString(index->GetNumber());
	}
	FileOp *filew = new FileOp(CString("e:\\now.bv"));
	filew->Write(CountNumber);
	UpdateData(false);
}


void CAutoLoginDlg::OnBnClickedButton5()//�����б�
{
	
	FileOp *file = new FileOp(CString("e:\\info.bv"));
	file->Write(CountNumber);
	AfxMessageBox(CString("�б��ѱ��棡"));
	delete file;
}



void CAutoLoginDlg::OnBnClickedCancel()
{
	GetDlgItem(IDC_BUTTON3)->EnableWindow(1);
	CDialogEx::OnCancel();
}



void CAutoLoginDlg::OnBnClickedButton4()//��ͣ���а�ť
{
	if (LogThread == NULL) {
		AfxMessageBox(L"����û�п�ʼ��");
		return;
	}
	LogThread->SuspendThread();
	GetDlgItem(IDC_BUTTON7)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(FALSE);
}


void CAutoLoginDlg::OnBnClickedButton7()//�������а�ť
{
	if (LogThread == NULL) {
		AfxMessageBox(L"����û�п�ʼ��");
		return;
	}
	LogThread->ResumeThread();
	GetDlgItem(IDC_BUTTON4)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON7)->ShowWindow(FALSE);
}



