#pragma once
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsButton
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/23
  *Desc		:  list单元格
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/

/************************************************************************/
/* cell需要的参数                                                           */
/************************************************************************/

class TOOLSWND_API CToolsListCell
{
public:
	CToolsListCell();
	virtual ~CToolsListCell();

	/************************************************************************/
	/* 画图                                                                  */
	/************************************************************************/
	virtual void Draw(CDC* pDC, CRect& rcCellRect);

	/************************************************************************/
	/* 控件resize操作                                                         */
	/************************************************************************/
	virtual void OnSize(CRect& rcCellRect);


public:
	CString m_strText;
	CString m_strValue1;
	CString m_strValue2;
	CString m_strValue3;

	LOGFONT  m_lf;
	COLORREF m_clrText;

};
