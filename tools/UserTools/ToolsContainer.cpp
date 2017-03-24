#include "stdafx.h"
#include "ToolsContainer.h"
#include "Window\CalculateDialog.h"
#include "Window\DlgVersionManager.h"

IMPLEMENT_DYNAMIC(CToolsContainer, CWnd)
#define FUCTION_START_ID 1188
const int m_gGap = 10;
const int m_gFucHeight = 30;

CToolsContainer::CToolsContainer() : CWnd()
{
	for (int nL = 0; nL < m_gFuctionCount; nL++){
		m_pBtnArray[nL] = NULL;
	}
}

CToolsContainer::~CToolsContainer()
{

}

void CToolsContainer::OnDestroy()
{
	for (int nL = 0; nL < m_gFuctionCount; nL++){
		if (m_pBtnArray[nL] && m_pBtnArray[nL]->GetSafeHwnd()){
			m_pBtnArray[nL]->DestroyWindow();
			delete(m_pBtnArray[nL]);
			m_pBtnArray[nL] = NULL;
		}
	}
	CWnd::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
}

BEGIN_MESSAGE_MAP(CToolsContainer, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_MESSAGE(GIVINS_BUTTON_CLICKON,OnFuctionClickOn)
	ON_MESSAGE(GIVINS_BUTTON_CLICKUP, OnFuctionClickUp)
END_MESSAGE_MAP()

int CToolsContainer::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	CreateButton();
	// TODO:  在此添加您专用的创建代码

	return 0;
}

void CToolsContainer::CreateButton()
{
	for (int nL = 0; nL < m_gFuctionCount; nL++){
		m_pBtnArray[nL] = new CToolsButton;
		m_pBtnArray[nL]->Create(NULL, NULL , WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, CRect(0, 0, 0, 0), this, FUCTION_START_ID + nL);
		m_pBtnArray[nL]->SetText(GetFuctionText(nL));
		m_pBtnArray[nL]->ShowWindow(SW_SHOW);
	}
}

void CToolsContainer::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	ResizeFuction();
	// TODO:  在此处添加消息处理程序代码
}

void CToolsContainer::ResizeFuction()
{
	CRect rcRect; GetClientRect(&rcRect);

	if (m_gFuctionCount < 1 || rcRect.Width() <= 0) return;

	int nRowCount = ((m_gFuctionCount + 1) * m_gGap + m_gFuctionCount * GetFuctionWidth()) / rcRect.Width() + 1;
	int nTemp = 0,nColCount = 0;
	while (nTemp < rcRect.Width()){
		nTemp += GetFuctionWidth();
		if (nTemp <= rcRect.Width()) nColCount += 1;
		nTemp += m_gGap;
	}
	if (nColCount < 1) return;
	if (m_gFuctionCount < nColCount) nColCount = m_gFuctionCount;
	int nRGap = (rcRect.Height() - m_gFuctionCount * m_gFucHeight) / (nRowCount + 1),
		nCGap = (rcRect.Width() - m_gFuctionCount * GetFuctionWidth()) / (nColCount + 1);

	CRect rcFuction;
	int nX, nY;
	for (int nL = 0; nL < m_gFuctionCount; nL++){
		nX = (nL%nColCount) * (nCGap + GetFuctionWidth()) + nCGap;
		nY = (nL / nColCount) * (nRGap + m_gFucHeight) + nRGap;
		rcFuction = CRect(nX, nY, nX + GetFuctionWidth(), nY + m_gFucHeight);
		if (m_pBtnArray[nL] && m_pBtnArray[nL]->GetSafeHwnd())
			m_pBtnArray[nL]->MoveWindow(rcFuction);
	}
}

int  CToolsContainer::GetFuctionWidth(int nIndex)
{
	return 100;
}
CString CToolsContainer::GetFuctionText(int nIndex)
{
	switch (nIndex)
	{
	case (int)fuc_Calculate:
		return _T("计算相关");
	case (int)fuc_VersionManager:
		return _T("版本管理");
	default:
		return _T("");
	}
}

void CToolsContainer::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	DrawMain(&dc);
}

void CToolsContainer::DrawMain(CDC* pDC)
{

}


LRESULT CToolsContainer::OnFuctionClickOn(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CToolsContainer::OnFuctionClickUp(WPARAM wParam, LPARAM lParam)
{
	switch ((int)wParam)
	{
	case FUCTION_START_ID + fuc_Calculate:// 计算
	{
		/*CRect rcRect;
		GetClientRect(&rcRect);
		ClientToScreen(&rcRect);
		CCalculateDialog calDlg(CCalculateDialog::IDD, this);
		calDlg.Create(CCalculateDialog::IDD, this);
		calDlg.MoveWindow(rcRect);
		calDlg.ShowWindow(SW_SHOW);*/
		CCalculateDialog calDlg(CCalculateDialog::IDD, this);
		calDlg.DoModal();
	}
		break;
	case FUCTION_START_ID + fuc_VersionManager://版本管理
	{
		CDlgVersionManager version(CDlgVersionManager::IDD, this);
		version.DoModal();
	}
	break;
	default:
		break;
	}
	return 0;
}

