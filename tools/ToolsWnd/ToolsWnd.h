// ToolsWnd.h : ToolsWnd DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// CToolsWndApp
// �йش���ʵ�ֵ���Ϣ������� ToolsWnd.cpp
//

class CToolsWndApp : public CWinApp
{
public:
	CToolsWndApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
