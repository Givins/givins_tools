#pragma once
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsButton
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/23
  *Desc		:  用来显示功能的BUTTON
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/

class TOOLSWND_API CToolsButton : public CWnd
{
public:
	CToolsButton();
	virtual ~CToolsButton();
	DECLARE_DYNAMIC(CToolsButton)
	DECLARE_MESSAGE_MAP()

private:
	enum emState
	{
		state_Normal = 0,
		state_Over,
		state_Click,
		state_Enable
	};

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	virtual void DrawMain(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();

public:
	void SetText(CString& strText){ m_strText = strText; }
	void SetColor(COLORREF clrNormal, COLORREF clrOver, COLORREF clrClick, COLORREF clrEnable){
		  m_clrNormal = clrNormal, m_clrOver = clrOver, m_clrClick = clrClick, m_clrEnable = clrEnable;}

private:
	int GetWndId();
private:
	int m_nMouseState;//状态
	BOOL m_bTrack,m_bEnable;
	CString m_strText;
	LOGFONT m_lfText;
	COLORREF m_clrNormal, m_clrOver, m_clrClick, m_clrEnable,m_clrText;
};
