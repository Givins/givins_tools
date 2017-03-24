#pragma once
//#include "..\Resource.h"
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsContainer
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/22
  *Desc		:  QB可能用到的工具集合 
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/
const int m_gFuctionCount = 2;
class CToolsContainer : public CWnd
{
public:
	CToolsContainer();
	virtual ~CToolsContainer();
	DECLARE_DYNAMIC(CToolsContainer)
	DECLARE_MESSAGE_MAP()

public:
	enum emFuction{
		fuc_Calculate = 0,//计算
		fuc_VersionManager//版本管理
	};

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();

	afx_msg LRESULT OnFuctionClickOn(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnFuctionClickUp(WPARAM wParam, LPARAM lParam);
public:
	virtual void  DrawMain(CDC* pDC);

private:
	/*创建功能按钮*/
	void CreateButton();
	void ResizeFuction();
	int  GetFuctionWidth(int nIndex = 0);
	CString GetFuctionText(int nIndex = 0);
private:
	CToolsButton *m_pBtnArray[m_gFuctionCount];
public:
};
