// NetManager.h : NetManager DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNetManagerApp
// �йش���ʵ�ֵ���Ϣ������� NetManager.cpp
//

class FTP_API CNetManagerApp : public CWinApp
{
public:
	CNetManagerApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
