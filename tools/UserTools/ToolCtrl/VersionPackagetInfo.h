/***************************************************************************************************
  *Copyright(C),2017-2020,Sumscope
  *FileName	:  VersionPackagetInfo
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/03/24
  *Desc		:  版本管理---包信息管理
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  Givins.zhu@sumscope.com  
***************************************************************************************************/
#pragma once

class CVersionPackageInfo : public CWnd
{
public:
	CVersionPackageInfo();
	virtual ~CVersionPackageInfo();
	DECLARE_DYNAMIC(CVersionPackageInfo)
	DECLARE_MESSAGE_MAP()

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	virtual void DrawMain(CDC* pDC);
};
