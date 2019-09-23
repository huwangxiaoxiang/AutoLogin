// Dia1.cpp: 实现文件
//

#include "pch.h"
#include "GUITest.h"
#include "Dia1.h"
#include "afxdialogex.h"


// Dia1 对话框

IMPLEMENT_DYNAMIC(Dia1, CDialogEx)

Dia1::Dia1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUITEST_DIALOG, pParent)
{

}

Dia1::~Dia1()
{
}

void Dia1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dia1, CDialogEx)
END_MESSAGE_MAP()


// Dia1 消息处理程序
