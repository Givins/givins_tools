#pragma once
//#include "..\Resource.h"

/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsBaseDialog
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/21
  *Desc		:  QB可能用到的工具集合 
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/

class TOOLSWND_API CToolsBaseDialog : public CDialog
{
public:
	CToolsBaseDialog(UINT nID, CWnd* pParent = NULL);
	virtual ~CToolsBaseDialog();
	DECLARE_DYNAMIC(CToolsBaseDialog)
	DECLARE_MESSAGE_MAP()

private:


public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();

public:
	virtual void  DrawMain(CDC* pDC);

	LOGFONT GetGivinsFont(int nType = 0);
};
