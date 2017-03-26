/***************************************************************************************************
  *Copyright(C),2017-2020,Sumscope
  *FileName	:  VersionGlobelSetting
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/03/24
  *Desc		:  版本管理---全局设置
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  Givins.zhu@sumscope.com  
***************************************************************************************************/

#pragma once

class CVersionGlobelSetting : public CWnd
{
public:
	CVersionGlobelSetting();
	virtual ~CVersionGlobelSetting();
	DECLARE_DYNAMIC(CVersionGlobelSetting)
	DECLARE_MESSAGE_MAP()

private:

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	virtual void DrawMain(CDC* pDC);

private:


};
