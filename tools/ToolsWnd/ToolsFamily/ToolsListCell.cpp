#include "stdafx.h"
#include "ToolsListCell.h"


CToolsListCell::CToolsListCell()
{
	m_strText=m_strValue1=m_strValue2=m_strValue3 =_T("");
	m_lf = /*GFont::*/GetGivinsFont();
	m_clrText = RGB(255,0,0);
}

CToolsListCell::~CToolsListCell()
{

}

void CToolsListCell::Draw(CDC* pDC, CRect& rcCellRect)
{
	if (!pDC) return;
	Graphics gs(pDC->GetSafeHdc());
	Gdiplus::Font ft(pDC->GetSafeHdc(), &m_lf);
	StringFormat sf;
	sf.SetAlignment(StringAlignmentNear);
	sf.SetLineAlignment(StringAlignmentCenter);
	sf.SetFormatFlags(StringFormatFlagsNoWrap);
	sf.SetTrimming(StringTrimmingEllipsisPath);
	Color crText; crText.SetFromCOLORREF(m_clrText);
	SolidBrush sb(crText);
	gs.DrawString(m_strText, m_strText.GetLength(), &ft
		, RectF(rcCellRect.left, rcCellRect.top, rcCellRect.Width(), rcCellRect.Height()), &sf, &sb);
}

void CToolsListCell::OnSize(CRect& rcCellRect)
{

}
