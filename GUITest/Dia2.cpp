// Dia2.cpp: 实现文件
//

#include "pch.h"
#include "GUITest.h"
#include "Dia2.h"
#include "afxdialogex.h"


// Dia2 对话框

IMPLEMENT_DYNAMIC(Dia2, CDialogEx)

Dia2::Dia2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GUITEST_DIALOG, pParent)
{

}

Dia2::~Dia2()
{
}

void Dia2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dia2, CDialogEx)
END_MESSAGE_MAP()


// Dia2 消息处理程序
