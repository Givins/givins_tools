#include "stdafx.h"
//#include "ToolsBaseDialog.h"
#include "VersionPackagetInfo.h"

IMPLEMENT_DYNAMIC(CVersionPackageInfo, CWnd)

CVersionPackageInfo::CVersionPackageInfo() : CWnd()
{

}

CVersionPackageInfo::~CVersionPackageInfo()
{
}


BEGIN_MESSAGE_MAP(CVersionPackageInfo, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

int CVersionPackageInfo::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)	return -1;
	// TODO:  在此添加您专用的创建代码
	return 0;
}


void CVersionPackageInfo::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
}


void CVersionPackageInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CWnd::OnPaint()
	DrawMain(&dc);
}

void CVersionPackageInfo::DrawMain(CDC* pDC)
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