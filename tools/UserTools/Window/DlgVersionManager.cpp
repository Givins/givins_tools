#include "stdafx.h"
#include "DlgVersionManager.h"
//#include "..\..\MacroFiles\GivinsFont.h"

IMPLEMENT_DYNAMIC(CDlgVersionManager, CToolsBaseDialog)
#define  LIST_COL_COUNT 1
CDlgVersionManager::CDlgVersionManager(UINT nID, CWnd* pParent) : CToolsBaseDialog(nID, pParent), m_pList(NULL)
{
	m_pSetting = NULL;
	m_pInfo = NULL;
}

CDlgVersionManager::~CDlgVersionManager()
{

}

void CDlgVersionManager::OnDestroy()
{
	if (m_pList&&m_pList->GetSafeHwnd()){
		m_pList->DestroyWindow();
		delete m_pList;
		m_pList = NULL;
	}
	if (m_pSetting&&m_pSetting->GetSafeHwnd()){
		m_pSetting->DestroyWindow();
		delete m_pSetting;
		m_pSetting = NULL;
	}
	if (m_pInfo&&m_pInfo->GetSafeHwnd()){
		m_pInfo->DestroyWindow();
		delete m_pInfo;
		m_pInfo = NULL;
	}
	//for (int nE = 0; nE < CALCULATE_ROW_COUNT; nE++){

}
BEGIN_MESSAGE_MAP(CDlgVersionManager, CToolsBaseDialog)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_PAINT()

	//ON_BN_CLICKED(BTN_ID_BEGIN, OnBtnClick)
END_MESSAGE_MAP()


void CDlgVersionManager::OnPaint()
{
	CPaintDC dc(this);
	DrawMain(&dc);
}

void CDlgVersionManager::DrawMain(CDC* pDC)
{
	Graphics gs(pDC->GetSafeHdc());
	CRect rcDraw;
	//LOGFONT lf = GetGivinsFont();
	//Gdiplus::Font ft(pDC->GetSafeHdc(), &lf);
	//Color crText, crBack;// (125, 248, 251, 117);
	//crText.SetFromCOLORREF(RGB(0, 0, 0));
	//crBack.SetFromCOLORREF(RGB(248, 251, 117));
	//SolidBrush sb(crBack);//; sb.SetColor(cr);
	//CRect rcRect; GetClientRect(&rcRect);
	//gs.FillRectangle(&sb,RectF(rcRect.left,rcRect.top,rcRect.Width(),rcRect.Height()));
	//sb.SetColor(crText);
	//StringFormat sf;
	//sf.SetAlignment(StringAlignmentCenter);
	//sf.SetLineAlignment(StringAlignmentCenter);
	//for (int nE = 0; nE < CALCULATE_ROW_COUNT; nE++){
	//	rcDraw = m_rcRow[nE];
	//	rcDraw.left += (m_gColumn[col_Edit] + m_gColumn[col_Btn] + 2 * m_gGap);
	//	gs.DrawString(GetRowText(nE), GetRowText(nE).GetLength(), &ft, RectF(rcDraw.left, rcDraw.top, rcDraw.Width(), rcDraw.Height()),
	//		&sf, &sb);
	//	//gs.FillRectangle()
	//}
}

int CDlgVersionManager::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CToolsBaseDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetWindowText(_T("版本管理"));

	CreateCtrl();
	InitialData();
	UpdateCtrl();

	return 0;
}

void CDlgVersionManager::OnSize(UINT nType, int cx, int cy)
{
	CToolsBaseDialog::OnSize(nType, cx, cy);
	ResizeWindow();
	// TODO:  在此处添加消息处理程序代码
}

void CDlgVersionManager::ResizeWindow()
{
	CRect rcRect,rcSetting,rcInfo,rcList;
	GetClientRect(&rcRect);
	int nGap = 4 , nInfoHgt = 40;
	float fListScale = 0.7;
	rcRect.InflateRect(-nGap, -nGap, -nGap, -nGap);
	rcSetting = rcInfo = rcList = rcRect;
	rcSetting.bottom = nInfoHgt;
	rcInfo.top = rcList.top = rcSetting.bottom + nGap;

	rcList.right = rcList.left + rcList.Width() * fListScale;
	rcInfo.left = rcList.right + nGap;

	if (m_pSetting&&m_pSetting->GetSafeHwnd()) m_pSetting->MoveWindow(rcSetting);
	if (m_pList&&m_pList->GetSafeHwnd()) m_pList->MoveWindow(rcList);
	if (m_pInfo&&m_pInfo->GetSafeHwnd()) m_pInfo->MoveWindow(rcInfo);
}

void CDlgVersionManager::CreateCtrl()
{
	m_pList = new CToolsList;
	m_pList->Create(NULL,NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, CRect(0, 0, 0, 0), this, 1888);
	m_pList->ShowWindow(SW_SHOW);

	m_pSetting = new CVersionGlobelSetting;
	m_pSetting->Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, CRect(0, 0, 0, 0), this, 1688);
	m_pSetting->ShowWindow(SW_SHOW);

	m_pInfo = new CVersionPackageInfo;
	m_pInfo->Create(NULL, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, CRect(0, 0, 0, 0), this, 1988);
	m_pInfo->ShowWindow(SW_SHOW);
}

void  CDlgVersionManager::InitialData()
{
	CFTPDataInfo& severInfo = FTPMANAGER.GetFtpData();

}

void  CDlgVersionManager::UpdateCtrl()
{
	if (!m_pList || !m_pList->GetSafeHwnd()) return;
	int nRow = 0, nRowSz = FTPMANAGER.GetFtpData().m_lstPackage.size();
	m_pList->SetSize(nRowSz, LIST_COL_COUNT);
	USES_CONVERSION;
	for (std::list<CPackageInfo>::const_iterator itr = FTPMANAGER.GetFtpData().m_lstPackage.begin();
		itr != FTPMANAGER.GetFtpData().m_lstPackage.end(); itr++){
		if ((itr->m_nFileType) | FILE_ATTRIBUTE_NORMAL){
			CToolsListCell lstCell;
			lstCell.m_strText.Format(_T("%s"), A2W(itr->m_cRarName));
			m_pList->SetCell(nRow++, 0, lstCell);
		}
	}

}