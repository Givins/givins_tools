#include "stdafx.h"
#include "CalculateDialog.h"
//#include "..\..\MacroFiles\GivinsFont.h"

#define  EDIT_ID_BEGIN 1008
#define  BTN_ID_BEGIN  2008

IMPLEMENT_DYNAMIC(CCalculateDialog, CToolsBaseDialog)

static float m_gColumn[CALCULATE_COL_COUNT] = { 100, 100, 1.0 };
static int   m_gGap = 5;
CCalculateDialog::CCalculateDialog(UINT nID, CWnd* pParent) : CToolsBaseDialog(nID,pParent)
{
	for (int nE = 0; nE < CALCULATE_ROW_COUNT; nE++){
		m_pEdit[nE] = NULL;
		m_pBtn[nE] = NULL;
		m_vctRowText.push_back(_T(""));
	}
}

CCalculateDialog::~CCalculateDialog()
{

}

void CCalculateDialog::OnDestroy()
{
	for (int nE = 0; nE < CALCULATE_ROW_COUNT; nE++){
		if (m_pEdit[nE]) delete m_pEdit[nE];
		m_pEdit[nE] = NULL;
		if (m_pBtn[nE]) delete m_pBtn[nE];
		m_pBtn[nE] = NULL;
	}
}
BEGIN_MESSAGE_MAP(CCalculateDialog, CToolsBaseDialog)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_COMMAND_RANGE(BTN_ID_BEGIN, BTN_ID_BEGIN + CALCULATE_ROW_COUNT, OnBtnClick)
	//ON_BN_CLICKED(BTN_ID_BEGIN, OnBtnClick)
END_MESSAGE_MAP()

void CCalculateDialog::OnBtnClick(UINT nCmdID)
{
	switch (nCmdID)
	{
	case BTN_ID_BEGIN + row_Time:
	{
		CString  strResult = _T(""), strTemp = GetEditText(row_Time);
		int nCal = _ttoi(strTemp);
		if (nCal > 0){
			CTime tTemp(nCal);
			strResult.Format(_T("%04d-%02d-%02d %02d:%02d:%02d"), tTemp.GetYear(), tTemp.GetMonth(), tTemp.GetDay(),
				tTemp.GetHour(), tTemp.GetMinute(), tTemp.GetSecond());
		}
		SetRowText(row_Time, strResult);
	}
	break;
	default:
		break;
	}
}

void CCalculateDialog::OnPaint()
{
	CPaintDC dc(this);
	DrawMain(&dc);
}

void CCalculateDialog::DrawMain(CDC* pDC)
{
	Graphics gs(pDC->GetSafeHdc());
	CRect rcDraw;
	LOGFONT lf = GetGivinsFont();
	Gdiplus::Font ft(pDC->GetSafeHdc(), &lf);
	Color crText, crBack;// (125, 248, 251, 117);
	crText.SetFromCOLORREF(RGB(0, 0, 0));
	crBack.SetFromCOLORREF(RGB(248, 251, 117));
	SolidBrush sb(crBack);//; sb.SetColor(cr);
	CRect rcRect; GetClientRect(&rcRect);
	gs.FillRectangle(&sb,RectF(rcRect.left,rcRect.top,rcRect.Width(),rcRect.Height()));
	sb.SetColor(crText);
	StringFormat sf;
	sf.SetAlignment(StringAlignmentCenter);
	sf.SetLineAlignment(StringAlignmentCenter);
	for (int nE = 0; nE < CALCULATE_ROW_COUNT; nE++){
		rcDraw = m_rcRow[nE];
		rcDraw.left += (m_gColumn[col_Edit] + m_gColumn[col_Btn] + 2 * m_gGap);
		gs.DrawString(GetRowText(nE), GetRowText(nE).GetLength(), &ft, RectF(rcDraw.left, rcDraw.top, rcDraw.Width(), rcDraw.Height()),
			&sf, &sb);
		//gs.FillRectangle()
	}
}

CString  CCalculateDialog::GetRowText(int nRow)
{
	if (nRow < 0 || nRow >= m_vctRowText.size()) return _T("");
	return m_vctRowText[nRow];
}

CString  CCalculateDialog::GetEditText(int nRow)
{
	CString strReturn = _T("");
	if (nRow < 0 || nRow >= m_vctRowText.size()) return strReturn;
	if (m_pEdit[nRow] && m_pEdit[nRow]->GetSafeHwnd()){
		m_pEdit[nRow]->GetWindowTextW(strReturn);
	}
	return strReturn;
}

void CCalculateDialog::SetRowText(int nRow,CString & strText)
{
	if (nRow < 0 || nRow >= m_vctRowText.size()) return;
	m_vctRowText[nRow] = strText;
	CRect rcRow = m_rcRow[nRow];
	rcRow.left += (m_gColumn[col_Edit] + m_gColumn[col_Btn] + 2 * m_gGap);
	InvalidateRect(rcRow);
}

int CCalculateDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CToolsBaseDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetWindowText(_T("计算相关"));
	// TODO:  在此添加您专用的创建代码
	for (int nE = 0; nE < CALCULATE_ROW_COUNT; nE++){
		m_pEdit[nE] = CreateEdit(EDIT_ID_BEGIN + nE);
		m_pBtn[nE] = CreateBtn(BTN_ID_BEGIN + nE, GetBtnText(nE));
	}
	return 0;
}

CEdit * CCalculateDialog::CreateEdit(int nId)
{
	CEdit *pEdit = new CEdit;
	pEdit->Create(WS_CHILD | WS_CLIPCHILDREN |ES_CENTER| WS_VISIBLE|ES_AUTOHSCROLL|ES_MULTILINE, CRect(0, 0, 0, 0), this, nId);
	//CFont font;
	//LOGFONT lf = GetGivinsFont();
	//lf.lfHeight = 60;
	//font.CreateFontIndirectW(&lf);
	//pEdit->SetFont(&font);
	pEdit->ShowWindow(SW_SHOW);
	return pEdit;
}

CButton* CCalculateDialog::CreateBtn(int nId, CString& strText)
{
	CButton * pBtn = new CButton;
	pBtn->Create(strText, WS_CHILD | WS_CLIPCHILDREN | WS_VISIBLE, CRect(0, 0, 0, 0), this, nId);
	pBtn->ShowWindow(SW_SHOW);
	return pBtn;
}

void CCalculateDialog::OnSize(UINT nType, int cx, int cy)
{
	CToolsBaseDialog::OnSize(nType, cx, cy);
	ResizeWindow();
	// TODO:  在此处添加消息处理程序代码
}

void CCalculateDialog::ResizeWindow()
{
	int nTopGap = 20,nLeftGap = 20,nRowHgt = 30;
	CRect rcRect,rcEdit,rcBtn; GetClientRect(&rcRect);
	int nTop = nTopGap,nLeft = nLeftGap;
	for (int nL = 0; nL < CALCULATE_ROW_COUNT; nL++){
		m_rcRow[nL] = CRect(nLeft,nTop,rcRect.right,nTop + nRowHgt);
		nTop += (nRowHgt + m_gGap);
		rcEdit = rcBtn = m_rcRow[nL];
		rcEdit.right = rcEdit.left + m_gColumn[col_Edit];
		//rcEdit.top += m_gGap;
		rcBtn.left = rcEdit.right + m_gGap;
		rcBtn.right = rcBtn.left + m_gColumn[col_Btn];
		if (m_pEdit[nL] && m_pEdit[nL]->GetSafeHwnd()) m_pEdit[nL]->MoveWindow(rcEdit);
		if (m_pBtn[nL] && m_pBtn[nL]->GetSafeHwnd()) m_pBtn[nL]->MoveWindow(rcBtn);
	}
}


CString  CCalculateDialog::GetBtnText(int nIdex)
{
	switch (nIdex)
	{
	case row_Time:
		return _T("time转时分秒");
		break;
	default:
		break;
	}
	return _T("");
}
