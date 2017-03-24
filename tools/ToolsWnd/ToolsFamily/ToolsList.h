#pragma once
#include <vector>
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsButton
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/23
  *Desc		:  list控件
  *Relation :  
  *Module   :  
  *Others   :  
  *Function :  
  *History	:
  *Email    :  zhumushun3550@163.com  
***************************************************************************************************/
#define TOOLSLIST_COLOR_COUNT  10
class CToolsListCell;

#define LIST_ROW std::vector<CToolsListCell*>
class TOOLSWND_API CToolsListCellPosition
{
public:
	CToolsListCellPosition(){
		Clear();
	}
	CToolsListCellPosition(int nRow,int nCol){
		m_nRow = nRow;
		m_nColumn = nCol;
	}
	void Clear(){
		m_nRow = m_nColumn = -1;
	}
	int m_nRow;
	int m_nColumn;
};

class TOOLSWND_API CToolsList : public CWnd
{
public:
	CToolsList();
	virtual ~CToolsList();
	DECLARE_DYNAMIC(CToolsList)
	DECLARE_MESSAGE_MAP()

private:
	enum emState
	{
		state_Normal = 0,
		state_Over,
		state_Click,
		state_Enable
	};

	enum emColor{
		color_bk_normal = 0, //正常背景
		color_bk_row_normal, //行正常背景
		color_bk_row_Over,  //over行
		color_bk_row_Select, //选择行
		color_row_line       //行间线
	};
public:
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	virtual void DrawMain(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();


private:
	void InitialColor();//初始化各种颜色
	void InvalidateRow(int nRow);
	/*从位置获取行列*/
	CToolsListCellPosition GetPointCellPosition(CPoint& pt);
public:
	/***************
		设置颜色
	***************************/
	void SetColor(COLORREF& clrNormal, emColor nType);

	/******************
		插入行数目
	*****************************/
	virtual void InsertRow(int nCount = 1);

	/**********************
		删除行数据
	*******************************/
	virtual void DelteRow(int& nRow);


	/************************************************************************/
	//获取表格数据
	virtual void GetCell(int nRow, int nCol, CToolsListCell& cell);
	/************************************************************************/

	/************************************************************************/
	/*设置表格数据                                                            */
	virtual void SetCell(int nRow, int nCol, const CToolsListCell& cell);
	/************************************************************************/

	/************************************************************************/
	/* 删除所有数据                                                           */
	virtual void Clear();
	/************************************************************************/

	/************************************************************************/
	/* 设置大小                                                               */
	/************************************************************************/
	virtual void SetSize(const int& nRowCount, const int& nColCount);

	/************************************************************************/
	/* 获取有效区域                                                             */
	/************************************************************************/

	virtual void  GetValidRowColumn(int& nStartRow, int &nEndRow, int &nStartColumn, int & nEndColumn);

	/************************************************************************/
	/* 重置滚动条                                                            */
	/************************************************************************/
	virtual void  ReSetScrollBar();
private:
	//int  m_nFocus;//焦点行
	BOOL m_bTrack,m_bEnable;
	//CString m_strText;
	//LOGFONT m_lfText;
	std::vector<COLORREF> m_vctColorref; //颜色容器
	std::vector<LIST_ROW> m_vctListData;
	int m_nRowCount, m_nColCount;
	int m_nRowHeight, m_nCellWidth;
	CToolsListCellPosition m_ptMouse/*鼠标位置*/, m_ptSelect/*选择行*/;
};
