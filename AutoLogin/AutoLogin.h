
// AutoLogin.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAutoLoginApp: 
// �йش����ʵ�֣������ AutoLogin.cpp
//

class CAutoLoginApp : public CWinApp
{
public:
	CAutoLoginApp();
	
// ��д
public:
	virtual BOOL InitInstance();
	
// ʵ��

	DECLARE_MESSAGE_MAP()


};

extern CAutoLoginApp theApp;
