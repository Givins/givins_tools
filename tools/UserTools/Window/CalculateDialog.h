#pragma once
#include "..\stdafx.h"
#include "..\Resource.h"
#include <vector>
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  CalculateDialog
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/21
  *Desc		:  QB可能用到的工具集合  计算器
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/
#define  CALCULATE_ROW_COUNT 1
#define  CALCULATE_COL_COUNT 3
class CCalculateDialog : public CToolsBaseDialog
{
public:
	CCalculateDialog(UINT nID, CWnd* pParent = NULL);
	virtual ~CCalculateDialog();

	enum
	{
		IDD = IDD_TOOLS_CALCULATE_DIALOG
	};

	DECLARE_DYNAMIC(CCalculateDialog)
	DECLARE_MESSAGE_MAP()

	enum em_Row{
		row_Time = 0
	};

	enum em_Col{
		col_Edit = 0,
		col_Btn,
		col_Result//结果
	};

private:
	CEdit * CreateEdit(int nId);
	CButton* CreateBtn(int nId,CString& strText);
	CString  GetBtnText(int nIdex);
	void     ResizeWindow();
	CString  GetRowText(int nRow);
	CString  GetEditText(int nRow);
	void     SetRowText(int nRow, CString & strText);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg  void  OnBtnClick(UINT nCmdID);
protected:
	virtual void  DrawMain(CDC* pDC);

	CEdit* m_pEdit[CALCULATE_ROW_COUNT];
	CButton* m_pBtn[CALCULATE_ROW_COUNT];
	CRect  m_rcRow[CALCULATE_ROW_COUNT];

private:
	std::vector<CString>       m_vctRowText;
};
