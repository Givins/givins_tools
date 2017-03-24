#include "stdafx.h"
//#include "ToolsBaseDialog.h"
#include "ToolsList.h"
#include "ToolsListCell.h"

IMPLEMENT_DYNAMIC(CToolsList, CWnd)

CToolsList::CToolsList() : CWnd(), m_bTrack(FALSE)
{
	m_nRowHeight = 30;
	m_nCellWidth = 300;
	m_nRowCount  = 0;
	m_nColCount  = 0;
	InitialColor();
}

void CToolsList::InitialColor()
{
	m_vctColorref.clear();
	for (int nL = 0; nL < TOOLSLIST_COLOR_COUNT; nL++){
		switch (nL)
		{
		case color_bk_normal:
			m_vctColorref.push_back(RGB(107, 201, 175));
			break;
		case color_bk_row_normal:
			m_vctColorref.push_back(RGB(117, 176, 132));
			break;
		case  color_bk_row_Over:
			m_vctColorref.push_back(RGB(45, 79, 53));
			break;
		case color_bk_row_Select:
			m_vctColorref.push_back(RGB(74, 130, 88));
			break;
		case color_row_line:
			m_vctColorref.push_back(RGB(255,255,0));
			break;
		default:
			m_vctColorref.push_back(RGB(107, 201, 175));
			break;
		}
	}
}

CToolsListCellPosition CToolsList::GetPointCellPosition(CPoint& pt)
{
	CToolsListCellPosition pst;
	if (m_nRowHeight > 0){
		pst.m_nRow = pt.y / m_nRowHeight;
	}
	return pst;
}

CToolsList::~CToolsList()
{
}


BEGIN_MESSAGE_MAP(CToolsList, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

int CToolsList::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)	return -1;
	// TODO:  在此添加您专用的创建代码
	return 0;
}


void CToolsList::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	CRect rcRct; GetClientRect(&rcRct);
	if (rcRct.Width() > 0) m_nCellWidth = rcRct.Width();
	// TODO:  在此处添加消息处理程序代码
}


void CToolsList::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	DrawMain(&dc);
}

void CToolsList::DrawMain(CDC* pDC)
{
	Graphics gs(pDC->GetSafeHdc());
	CRect rcRect,rcRow; GetClientRect(&rcRect);
	COLORREF clrBack = m_vctColorref[color_bk_normal],
		     clrRowBk = m_vctColorref[color_bk_row_normal],
			 clrRowBkSelect = m_vctColorref[color_bk_row_Select],
			 clrRowBkOver = m_vctColorref[color_bk_row_Over],
			 clrRowLine = m_vctColorref[color_row_line];

	Color crBk,crRowBk,crRowBkSelect,crRowLine,crRowOver; 
	crBk.SetFromCOLORREF(clrBack);
	crRowBk.SetFromCOLORREF(clrRowBk);
	crRowBkSelect.SetFromCOLORREF(clrRowBkSelect);
	crRowOver.SetFromCOLORREF(clrRowBkOver);
	crRowLine.SetFromCOLORREF(clrRowLine);
	SolidBrush sb(crBk), sbRowBk(crRowBk), sbRowBkSelect(crRowBkSelect), sbRowBkOver(crRowOver);
	gs.FillRectangle(&sb, Rect(rcRect.left, rcRect.top, rcRect.Width(), rcRect.Height()));
	int nStartR = 0, nEndR = 0, nStartC = 0, nEndC = 0;
	GetValidRowColumn(nStartR, nEndR, nStartC, nStartR);
	int nRowSz = m_vctListData.size();
	SolidBrush* pSbBk;
	int nStartX = 0, nStartY = 0,nGap = 1;
	for (int nR = 0; nR < nRowSz; nR++){
		if (nR < nStartR) continue;
		else if (nR >nEndR) break;
		nStartX = 0;
		LIST_ROW lstRow = m_vctListData[nR];
		int nColSz = lstRow.size();
		for (int nC = 0; nC < nColSz; nC++){
			if (nC < nStartC) continue;
			if (nC > nEndC) break;
			CToolsListCell* pCell = lstRow[nC];
			rcRow = CRect(nStartX + nGap, nStartY + nGap, nStartX + m_nCellWidth - nGap * 2, nStartY + m_nRowHeight - nGap*2);
			if (nR == m_ptSelect.m_nRow) pSbBk = &sbRowBkSelect;
			else if (nR == m_ptMouse.m_nRow) pSbBk = &sbRowBkOver;
			else pSbBk = &sbRowBk;
			gs.FillRectangle(pSbBk, Rect(rcRow.left, rcRow.top, rcRow.Width(), rcRow.Height()));
			if (pCell) pCell->Draw(pDC,rcRow);
			nStartX += m_nCellWidth;
		}
		nStartY += m_nRowHeight;
	}
}

void CToolsList::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//if (m_bEnable){
	//	m_nMouseState = m_clrClick;
	//	Invalidate();
	//	GetParent()->PostMessage(GIVINS_BUTTON_CLICKON, (WPARAM)GetWndId(), 0);
	//}
	m_ptSelect = GetPointCellPosition(point);
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


void CToolsList::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//if (m_bEnable){
	//	m_nMouseState = state_Normal;
	//	Invalidate();
	//	GetParent()->PostMessage(GIVINS_BUTTON_CLICKUP,(WPARAM)GetWndId(), 0);
	//}
	CWnd::OnLButtonUp(nFlags, point);
}


void CToolsList::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (!m_bTrack){
		TRACKMOUSEEVENT    tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE;
		_TrackMouseEvent(&tme);
		m_bTrack = TRUE;
	}
	//m_ptMouse = 
	CToolsListCellPosition pt = GetPointCellPosition(point);
	if (pt.m_nRow != m_ptMouse.m_nRow){
		InvalidateRow(pt.m_nRow);
		InvalidateRow(m_ptMouse.m_nRow);
		m_ptMouse = pt;
	}
	//if (m_bEnable&&m_nMouseState != state_Over){
	//	m_nMouseState = state_Over;
	//	Invalidate();
	//}
	CWnd::OnMouseMove(nFlags, point);
}

void CToolsList::InvalidateRow(int nRow)
{
	CRect rcRect, rcRow; GetClientRect(&rcRect);
	rcRow = rcRect;
	rcRow.top = nRow*m_nRowHeight;
	rcRow.bottom = rcRow.top + m_nRowHeight;
	InvalidateRect(rcRow);
	//rcRow -= CPoint(0, m_nRowHeight);
}

void CToolsList::OnMouseLeave()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_bTrack = FALSE;
	//if (m_bEnable){
	//	m_nMouseState = state_Normal;
	//	Invalidate();
	//}
	m_ptMouse.Clear();
	InvalidateRow(m_ptMouse.m_nRow);
	CWnd::OnMouseLeave();
}

void CToolsList::SetColor(COLORREF& clrNormal, emColor nType)
{
	int nTp = (int)nType;
	if (nType < m_vctColorref.size()){
		m_vctColorref[nTp] = clrNormal;
	}
}

void CToolsList::InsertRow(int nCount)
{
	for (int nR = 0; nR < nCount; nR++){
		LIST_ROW lstRow;
		for (int nC = 0; nC < m_nColCount; nC++){
			CToolsListCell *pCell = new CToolsListCell;
			lstRow.push_back(pCell);
		}
		m_vctListData.push_back(lstRow);
	}
	if (nCount > 0) m_nRowCount += nCount;
}

void CToolsList::DelteRow(int& nRow)
{
	int nSz = m_vctListData.size();
	if (nRow < 0 || nRow >= nSz) return;
	LIST_ROW& lstRow = m_vctListData[nRow];
	int nCSz = lstRow.size();
	for (int nC = 0; nC < nCSz; nC++){
		delete lstRow[nC];
		lstRow[nC] = NULL;
	}
	m_vctListData.erase(m_vctListData.begin() + nRow);
	m_nRowCount -= 1;
}

void CToolsList::GetCell(int nRow, int nCol, CToolsListCell& cell)
{
	int nRsz = m_vctListData.size();
	if (nRow < 0 || nRow >= nRsz) return;
	LIST_ROW& lstRow = m_vctListData[nRow];
	int nCsz = lstRow.size();
	if (nCol < 0 || nCol >= nCsz) return;
	CToolsListCell* pCell = lstRow[nCol];
	if (pCell) cell = *pCell;
}

void CToolsList::SetCell(int nRow, int nCol,const CToolsListCell& cell)
{
	int nRsz = m_vctListData.size();
	if (nRow < 0 || nRow >= nRsz) return;
	LIST_ROW& lstRow = m_vctListData[nRow];
	int nCsz = lstRow.size();
	if (nCol < 0 || nCol >= nCsz) return;
	CToolsListCell* pCell = lstRow[nCol];
	if (pCell) *pCell = cell;
}

void CToolsList::Clear()
{
	int nRsz = m_vctListData.size();
	for (int nR = 0; nR < nRsz; nR++){
		LIST_ROW& lstRow = m_vctListData[nR];
		int nCsz = lstRow.size();
		for (int nC = 0; nC < nCsz; nC++){
			CToolsListCell* &pCell = lstRow[nC];
			if (pCell){
				delete pCell;
				pCell = NULL;
			}
		}
	}
	m_vctListData.clear();
	ReSetScrollBar();
}

void CToolsList::SetSize(const int& nRowCount, const int& nColCount)
{
	Clear();
	m_nRowCount = nRowCount;
	m_nColCount = nColCount;
	if (nRowCount > 0){
		InsertRow(nRowCount);
	}
	ReSetScrollBar();
}

void CToolsList::GetValidRowColumn(int& nStartRow, int &nEndRow, int &nStartColumn, int & nEndColumn)
{
	nStartColumn = nStartRow = 0;
	nEndRow = m_nRowCount - 1;
	nEndColumn = m_nColCount - 1;
}

void  CToolsList::ReSetScrollBar()
{

}
