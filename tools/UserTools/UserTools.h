
// UserTools.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUserToolsApp: 
// �йش����ʵ�֣������ UserTools.cpp
//

class CUserToolsApp : public CWinApp
{
public:
	CUserToolsApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()

public:
		ULONG_PTR		m_gdiplusToken;

};

extern CUserToolsApp theApp;