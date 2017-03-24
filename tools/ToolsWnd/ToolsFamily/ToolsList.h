#pragma once
#include <vector>
/***************************************************************************************************
  *Copyright(C),2017-2020,
  *FileName	:  ToolsButton
  *Author	:  Givins.zhu
  *Version	:  1.0
  *Date		:  2017/02/23
  *Desc		:  list�ؼ�
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
		color_bk_normal = 0, //��������
		color_bk_row_normal, //����������
		color_bk_row_Over,  //over��
		color_bk_row_Select, //ѡ����
		color_row_line       //�м���
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
	void InitialColor();//��ʼ��������ɫ
	void InvalidateRow(int nRow);
	/*��λ�û�ȡ����*/
	CToolsListCellPosition GetPointCellPosition(CPoint& pt);
public:
	/***************
		������ɫ
	***************************/
	void SetColor(COLORREF& clrNormal, emColor nType);

	/******************
		��������Ŀ
	*****************************/
	virtual void InsertRow(int nCount = 1);

	/**********************
		ɾ��������
	*******************************/
	virtual void DelteRow(int& nRow);


	/************************************************************************/
	//��ȡ�������
	virtual void GetCell(int nRow, int nCol, CToolsListCell& cell);
	/************************************************************************/

	/************************************************************************/
	/*���ñ������                                                            */
	virtual void SetCell(int nRow, int nCol, const CToolsListCell& cell);
	/************************************************************************/

	/************************************************************************/
	/* ɾ����������                                                           */
	virtual void Clear();
	/************************************************************************/

	/************************************************************************/
	/* ���ô�С                                                               */
	/************************************************************************/
	virtual void SetSize(const int& nRowCount, const int& nColCount);

	/************************************************************************/
	/* ��ȡ��Ч����                                                             */
	/************************************************************************/

	virtual void  GetValidRowColumn(int& nStartRow, int &nEndRow, int &nStartColumn, int & nEndColumn);

	/************************************************************************/
	/* ���ù�����                                                            */
	/************************************************************************/
	virtual void  ReSetScrollBar();
private:
	//int  m_nFocus;//������
	BOOL m_bTrack,m_bEnable;
	//CString m_strText;
	//LOGFONT m_lfText;
	std::vector<COLORREF> m_vctColorref; //��ɫ����
	std::vector<LIST_ROW> m_vctListData;
	int m_nRowCount, m_nColCount;
	int m_nRowHeight, m_nCellWidth;
	CToolsListCellPosition m_ptMouse/*���λ��*/, m_ptSelect/*ѡ����*/;
};
