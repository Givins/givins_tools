#pragma once
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsButton
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/23
  *Desc		:  list��Ԫ��
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/

/************************************************************************/
/* cell��Ҫ�Ĳ���                                                           */
/************************************************************************/

class TOOLSWND_API CToolsListCell
{
public:
	CToolsListCell();
	virtual ~CToolsListCell();

	/************************************************************************/
	/* ��ͼ                                                                  */
	/************************************************************************/
	virtual void Draw(CDC* pDC, CRect& rcCellRect);

	/************************************************************************/
	/* �ؼ�resize����                                                         */
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
