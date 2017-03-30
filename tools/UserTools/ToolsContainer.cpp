#include "stdafx.h"
#include "ToolsContainer.h"
#include "Window\CalculateDialog.h"
#include "Window\DlgVersionManager.h"

IMPLEMENT_DYNAMIC(CToolsContainer, CWnd)
#define FUCTION_START_ID 1188
#define COMBOX_ID 1888
const int m_gGap = 10;
const int m_gFucHeight = 30;
const int m_gComboxHeight = 30;
const int m_gComboxWidth = 100;
const int m_gFuctionMinHeight = 50;//内嵌模式最小高度
CToolsContainer::CToolsContainer() : CWnd(), m_nDisplayModel(display_Child), m_pComBoxDisplay(NULL), m_pChildWnd(NULL)
{
	for (int nL = 0; nL < m_gFuctionCount; nL++){
		m_pBtnArray[nL] = NULL;
		m_vctBtnRect.push_back(CRect(0, 0, 0, 0));
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
	if (m_pComBoxDisplay&&m_pComBoxDisplay->GetSafeHwnd()){
		m_pComBoxDisplay->DestroyWindow();
		delete m_pComBoxDisplay;
		m_pComBoxDisplay = NULL;
	}
	DestoryChildWnd();
	CWnd::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
}

void CToolsContainer::DestoryChildWnd()
{
	if (m_pChildWnd&&m_pChildWnd->GetSafeHwnd()){
		m_pChildWnd->DestroyWindow();
		delete m_pChildWnd;
		m_pChildWnd = NULL;
	}
}

BEGIN_MESSAGE_MAP(CToolsContainer, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_MESSAGE(GIVINS_BUTTON_CLICKON,OnFuctionClickOn)
	ON_MESSAGE(GIVINS_BUTTON_CLICKUP, OnFuctionClickUp)
	//ON_NOTIFY(TCN_SELCHANGE, COMBOX_ID, OnSelectChange)
	ON_CBN_SELCHANGE(COMBOX_ID,OnSelectChange)
END_MESSAGE_MAP()

int CToolsContainer::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	CreateButton();
	CreateCombox();
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

void CToolsContainer::CreateCombox()
{
	m_pComBoxDisplay = new CComboBox;
	m_pComBoxDisplay->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, CRect(0, 0, 0, 0), this, COMBOX_ID);
	m_pComBoxDisplay->AddString(_T("内嵌模式"));
	m_pComBoxDisplay->AddString(_T("弹出模式"));
	m_pComBoxDisplay->SetCurSel(0);
	m_pComBoxDisplay->ShowWindow(SW_SHOW);
}

void CToolsContainer::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	ResizeWnd();
	// TODO:  在此处添加消息处理程序代码
}

void CToolsContainer::ResizeWnd()
{
	CRect rcRect,rcCombox; GetClientRect(&rcRect);
	if (m_gFuctionCount < 1 || rcRect.Width() <= 0) return;
	rcCombox = CRect(m_gGap,m_gGap,m_gGap + m_gComboxWidth,m_gGap + m_gComboxHeight);
	rcRect.top = rcCombox.bottom + m_gGap;
	m_rcMain = rcRect;
	//rcCombox.bottom += 100;
	if (m_pComBoxDisplay&&m_pComBoxDisplay->GetSafeHwnd()) m_pComBoxDisplay->MoveWindow(rcCombox);
	ReSizeChild();
	ResizePopUp();

}

void CToolsContainer::ReSizeChild()
{
	if (m_nDisplayModel != display_Child) return;
	m_rcChild = m_rcMain;
	m_rcChild.bottom -= (m_gFuctionMinHeight + 2);
	m_rcChild.left += m_gGap;
	m_rcChild.right -= m_gGap;
	if (m_pChildWnd&&m_pChildWnd->GetSafeHwnd()){
		m_pChildWnd->MoveWindow(m_rcChild);
		m_pChildWnd->ShowWindow(SW_SHOW);
	}
}

void CToolsContainer::ResizePopUp()
{
	CRect rcRect = m_rcMain;
	if (m_nDisplayModel == display_Child){
		rcRect.top = rcRect.bottom - m_gFuctionMinHeight;
	}
	else{
		if (m_pChildWnd&&m_pChildWnd->GetSafeHwnd()){
			m_pChildWnd->ShowWindow(SW_HIDE);
		}
	}
	int nRowCount = ((m_gFuctionCount + 1) * m_gGap + m_gFuctionCount * GetFuctionWidth()) / rcRect.Width() + 1;
	int nTemp = 0, nColCount = 0;
	while (nTemp < rcRect.Width()){
		nTemp += GetFuctionWidth();
		if (nTemp <= rcRect.Width()) nColCount += 1;
		nTemp += m_gGap;
	}
	if (nColCount < 1) return;
	if (m_gFuctionCount < nColCount) nColCount = m_gFuctionCount;
	int nRGap = (rcRect.Height() - m_gFuctionCount * m_gFucHeight) / (nRowCount + 1),
		nCGap = (rcRect.Width() - m_gFuctionCount * GetFuctionWidth()) / (nColCount + 1);
	if (m_nDisplayModel == display_Child){
		nRGap = nCGap = m_gGap;
	}
	CRect rcFuction;
	int nX, nY;
	for (int nL = 0; nL < m_gFuctionCount; nL++){
		nX = (nL%nColCount) * (nCGap + GetFuctionWidth()) + nCGap;
		nY = rcRect.top + (nL / nColCount) * (nRGap + m_gFucHeight) + nRGap;
		rcFuction = CRect(nX, nY, nX + GetFuctionWidth(), nY + m_gFucHeight);
		if (m_pBtnArray[nL] && m_pBtnArray[nL]->GetSafeHwnd())
			m_pBtnArray[nL]->MoveWindow(rcFuction);
		m_pBtnArray[nL]->Invalidate();
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
	if (!pDC) return;
	Graphics gs(pDC->GetSafeHdc());
	Color crBack,crChild;
	crBack.SetFromCOLORREF(RGB(255, 255, 255));
	crChild.SetFromCOLORREF(RGB(33, 61, 171));
	SolidBrush sb(crBack);//; sb.SetColor(cr);
	CRect rcRect; GetClientRect(&rcRect);
	gs.FillRectangle(&sb, RectF(rcRect.left, rcRect.top, rcRect.Width(), rcRect.Height()));

	if (m_nDisplayModel == display_Child){
		CRect rcChild = m_rcChild;
		int nPenWidth = 4;
		if (rcChild.Width() > 10 && rcChild.Height() > 10){
			rcChild.InflateRect(nPenWidth, nPenWidth, nPenWidth, nPenWidth);
			Gdiplus::Pen penRec(crChild, nPenWidth);
			gs.DrawRectangle(&penRec, Rect(rcChild.left, rcChild.top, rcChild.Width(), rcChild.Height()));
		}
	}
}


LRESULT CToolsContainer::OnFuctionClickOn(WPARAM wParam, LPARAM lParam)
{
	return 0;
}

void CToolsContainer::OnSelectChange()
{
	if (m_pComBoxDisplay&&m_pComBoxDisplay->GetSafeHwnd()){
		int nSel = m_pComBoxDisplay->GetCurSel();
		m_nDisplayModel = (nSel == 0 ? display_Child : display_Popup);
	}
	ResizeWnd();
	Invalidate();
}

//void CToolsContainer::OnSelectChange(WPARAM wParam, LPARAM lParam)
//{
//	ResizeFuction();
//	//return 0;
//}

LRESULT CToolsContainer::OnFuctionClickUp(WPARAM wParam, LPARAM lParam)
{
	switch ((int)wParam)
	{
	case FUCTION_START_ID + fuc_Calculate:// 计算
	{
		if (m_nDisplayModel == display_Child){
			DestoryChildWnd();
			CCalculateDialog* pDlg = new CCalculateDialog(CCalculateDialog::IDD, this);
			pDlg->Create(CCalculateDialog::IDD, this);
			if (pDlg&&pDlg->GetSafeHwnd()){
				DWORD lStyle = ::GetWindowLong(pDlg->GetSafeHwnd(), GWL_STYLE);
				lStyle &= (!WS_POPUP);
				lStyle |= WS_CHILD;
				SetWindowLong(pDlg->GetSafeHwnd(), GWL_STYLE, lStyle);
				pDlg->SetParent(this);
				//pDlg->ModifyStyle(WS_POPUP,WS_CHILD);
			}
			pDlg->ShowWindow(SW_SHOW);
			m_pChildWnd = pDlg;
			ResizeWnd();
		}
		else{
			CCalculateDialog calDlg(CCalculateDialog::IDD, this);
			calDlg.DoModal();
		}
	}
		break;
	case FUCTION_START_ID + fuc_VersionManager://版本管理
	{
		if (m_nDisplayModel == display_Child){
			DestoryChildWnd();
			CDlgVersionManager* pDlg = new CDlgVersionManager(CDlgVersionManager::IDD, this);
			pDlg->Create(CDlgVersionManager::IDD, this);
			if (pDlg&&pDlg->GetSafeHwnd()){
				DWORD lStyle = ::GetWindowLong(pDlg->GetSafeHwnd(), GWL_STYLE);
				lStyle &= (!WS_POPUP);
				lStyle |= WS_CHILD;
				SetWindowLong(pDlg->GetSafeHwnd(), GWL_STYLE, lStyle);
				pDlg->SetParent(this);
				//pDlg->ModifyStyle(WS_POPUP,WS_CHILD);
			}
			pDlg->ShowWindow(SW_SHOW);
			m_pChildWnd = pDlg;
			ResizeWnd();
		}
		else{
			CDlgVersionManager version(CDlgVersionManager::IDD, this);
			version.DoModal();
		}
	}
	break;
	default:
		break;
	}
	return 0;
}

