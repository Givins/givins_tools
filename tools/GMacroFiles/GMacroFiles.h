// GMacroFiles.h : GMacroFiles DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGMacroFilesApp
// �йش���ʵ�ֵ���Ϣ������� GMacroFiles.cpp
//

class CGMacroFilesApp : public CWinApp
{
public:
	CGMacroFilesApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
