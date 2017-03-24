#include "stdafx.h"
//#include "ToolsBaseDialog.h"
#include "VersionGlobelSetting.h"

IMPLEMENT_DYNAMIC(CVersionGlobelSetting, CWnd)

CVersionGlobelSetting::CVersionGlobelSetting() : CWnd()
{

}

CVersionGlobelSetting::~CVersionGlobelSetting()
{
}


BEGIN_MESSAGE_MAP(CVersionGlobelSetting, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

int CVersionGlobelSetting::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)	return -1;
	return 0;
}


void CVersionGlobelSetting::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
}


void CVersionGlobelSetting::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	DrawMain(&dc);
}

void CVersionGlobelSetting::DrawMain(CDC* pDC)
{
	//Graphics gs(pDC->GetSafeHdc());
	//COLORREF clrBack = m_clrNormal;
	//if (m_bEnable){
	//	if (m_nMouseState == state_Normal) clrBack = m_clrNormal;
	//	else if (m_nMouseState == state_Over) clrBack = m_clrOver;
	//	else clrBack = m_clrClick;
	//}
	//else clrBack = m_clrEnable;
	//CRect rcRect; GetClientRect(&rcRect);
	//Color crBack,crText;
	//crBack.SetFromCOLORREF(clrBack);
	//crText.SetFromCOLORREF(m_clrText);
	//SolidBrush sb(crBack), sbT(crText);
	//gs.FillRectangle(&sb,Rect(rcRect.left,rcRect.top,rcRect.Width(),rcRect.Height()));
	//Gdiplus::Font ft(pDC->GetSafeHdc(), &m_lfText);
	//StringFormat sf;
	//sf.SetAlignment(StringAlignmentCenter);
	//sf.SetLineAlignment(StringAlignmentCenter);
	//gs.DrawString(m_strText, m_strText.GetLength(), &ft, RectF(0, 0, rcRect.Width(), rcRect.Height()), &sf, &sbT);
}