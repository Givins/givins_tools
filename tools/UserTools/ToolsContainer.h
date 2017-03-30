#pragma once
//#include "..\Resource.h"
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsContainer
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/22
  *Desc		:  QB�����õ��Ĺ��߼��� 
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/
const int m_gFuctionCount = 2;
const int m_gDisplayCount = 2;//��ʾģʽ����
class CToolsContainer : public CWnd
{
public:
	CToolsContainer();
	virtual ~CToolsContainer();
	DECLARE_DYNAMIC(CToolsContainer)
	DECLARE_MESSAGE_MAP()

public:
	enum emFuction{
		fuc_Calculate = 0,//����
		fuc_VersionManager//�汾����
	};
	enum emDisplay{
		display_Child = 0,//��Ƕģʽ
		display_Popup,//����ʽ
	};
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();

	afx_msg LRESULT OnFuctionClickOn(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnFuctionClickUp(WPARAM wParam, LPARAM lParam);
	//afx_msg void    OnSelectChange(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void    OnSelectChange();
	//afx_msg void OnSelectChange(WPARAM wParam, LPARAM lParam);

public:
	virtual void  DrawMain(CDC* pDC);

private:
	/*�������ܰ�ť*/
	void CreateButton();
	void CreateCombox();
	void ResizeWnd();
	void ReSizeChild();
	void ResizePopUp();
	void DestoryChildWnd();
	int  GetFuctionWidth(int nIndex = 0);
	CString GetFuctionText(int nIndex = 0);
private:
	CToolsButton *m_pBtnArray[m_gFuctionCount];
	int  m_nDisplayModel;////��ʾģʽ  0,��Ƕ   1,����
	CComboBox* m_pComBoxDisplay;
	CWnd* m_pChildWnd;
	std::vector<CRect> m_vctBtnRect;
	CRect m_rcMain,m_rcChild;
public:
};
