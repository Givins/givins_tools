/***************************************************************************************************
*Copyright(C),2017-2020,
*FileName	:  CalculateDialog
*Author	:  Givins.zhu
*Version	:  1.0
*Date		:  2017/02/21
*Desc		:  QB可能用到的工具集合  版本管理
*Relation :
*Module   :
*Others   :
*Function :
*History	:
*Email    :  zhumushun3550@163.com
***************************************************************************************************/
#pragma once
#include "..\stdafx.h"
#include "..\Resource.h"
#include "..\ToolCtrl\VersionGlobelSetting.h"
#include "..\ToolCtrl\VersionPackagetInfo.h"
#include <vector>

class CDlgVersionManager : public CToolsBaseDialog
{
public:
	CDlgVersionManager(UINT nID, CWnd* pParent = NULL);
	virtual ~CDlgVersionManager();

	enum
	{
		IDD = IDD_TOOLS_VERSIONMANAGER_DIALOG
	};

	DECLARE_DYNAMIC(CDlgVersionManager)
	DECLARE_MESSAGE_MAP()


private:
	CEdit * CreateEdit(int nId);
	CButton* CreateBtn(int nId,CString& strText);
	CString  GetBtnText(int nIdex);
	void     ResizeWindow();
	CString  GetRowText(int nRow);
	CString  GetEditText(int nRow);
	void     SetRowText(int nRow, CString & strText);

private:
	void     CreateCtrl();
	void     InitialData();
	void     UpdateCtrl();
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg  void  OnBtnClick(UINT nCmdID);
protected:
	virtual void  DrawMain(CDC* pDC);


private:
	CToolsList* m_pList;
	CVersionGlobelSetting* m_pSetting;
	CVersionPackageInfo*   m_pInfo;
};
