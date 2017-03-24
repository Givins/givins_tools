#include "stdafx.h"
//#include "ToolsBaseDialog.h"
#include "ToolsButton.h"

IMPLEMENT_DYNAMIC(CToolsButton, CWnd)

CToolsButton::CToolsButton() : CWnd(), m_nMouseState(state_Normal), m_bTrack(FALSE), m_bEnable(TRUE), m_strText(_T(""))
{
	m_clrNormal = RGB(107, 201, 175);
	m_clrOver = RGB(63, 171, 141);
	m_clrClick = RGB(46, 124, 103);
	m_clrEnable = RGB(198,198,198);
}

CToolsButton::~CToolsButton()
{
}


BEGIN_MESSAGE_MAP(CToolsButton, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

int CToolsButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)	return -1;
	// TODO:  在此添加您专用的创建代码
	USES_CONVERSION;
	memset(&m_lfText, 0, sizeof(LOGFONT));
	m_lfText.lfHeight = 20;
	m_lfText.lfWidth = 0;
	m_lfText.lfWeight = FW_NORMAL;
	m_lfText.lfUnderline = 0;
	wcscpy_s(m_lfText.lfFaceName,A2W("Microsoft Yahei"));
	////strcpy_s(m_lfText.lfFaceName, _T("Microsoft Yahei"));
	//wcscpy_s(m_lfText.lfFaceName, sizeof(m_lfText.lfFaceName), _T("Microsoft Yahei"));
	return 0;
}


void CToolsButton::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
}


void CToolsButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	DrawMain(&dc);
}

void CToolsButton::DrawMain(CDC* pDC)
{
	Graphics gs(pDC->GetSafeHdc());
	COLORREF clrBack = m_clrNormal;
	if (m_bEnable){
		if (m_nMouseState == state_Normal) clrBack = m_clrNormal;
		else if (m_nMouseState == state_Over) clrBack = m_clrOver;
		else clrBack = m_clrClick;
	}
	else clrBack = m_clrEnable;
	CRect rcRect; GetClientRect(&rcRect);
	Color crBack,crText;
	crBack.SetFromCOLORREF(clrBack);
	crText.SetFromCOLORREF(m_clrText);
	SolidBrush sb(crBack), sbT(crText);
	gs.FillRectangle(&sb,Rect(rcRect.left,rcRect.top,rcRect.Width(),rcRect.Height()));
	Gdiplus::Font ft(pDC->GetSafeHdc(), &m_lfText);
	StringFormat sf;
	sf.SetAlignment(StringAlignmentCenter);
	sf.SetLineAlignment(StringAlignmentCenter);
	gs.DrawString(m_strText, m_strText.GetLength(), &ft, RectF(0, 0, rcRect.Width(), rcRect.Height()), &sf, &sbT);
}

void CToolsButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_bEnable){
		m_nMouseState = m_clrClick;
		Invalidate();
		GetParent()->PostMessage(GIVINS_BUTTON_CLICKON, (WPARAM)GetWndId(), 0);
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CToolsButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_bEnable){
		m_nMouseState = state_Normal;
		Invalidate();
		GetParent()->PostMessage(GIVINS_BUTTON_CLICKUP,(WPARAM)GetWndId(), 0);
	}
	CWnd::OnLButtonUp(nFlags, point);
}


void CToolsButton::OnMouseMove(UINT nFlags, CPoint point)
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
	if (m_bEnable&&m_nMouseState != state_Over){
		m_nMouseState = state_Over;
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CToolsButton::OnMouseLeave()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_bTrack = FALSE;
	if (m_bEnable){
		m_nMouseState = state_Normal;
		Invalidate();
	}
	CWnd::OnMouseLeave();
}

int CToolsButton::GetWndId()
{
	return GetWindowLong(this->GetSafeHwnd(), GWL_ID);
}