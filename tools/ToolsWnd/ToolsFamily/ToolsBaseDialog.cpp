#include "stdafx.h"
#include "ToolsBaseDialog.h"

IMPLEMENT_DYNAMIC(CToolsBaseDialog, CDialog)

CToolsBaseDialog::CToolsBaseDialog(UINT nID, CWnd* pParent) : CDialog(nID, pParent)
{
}

CToolsBaseDialog::~CToolsBaseDialog()
{
}


BEGIN_MESSAGE_MAP(CToolsBaseDialog, CDialog)

	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

int CToolsBaseDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void CToolsBaseDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
}


void CToolsBaseDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	DrawMain(&dc);
}

void CToolsBaseDialog::DrawMain(CDC* pDC)
{

}

LOGFONT CToolsBaseDialog::GetGivinsFont(int nType)
{
	switch (nType)
	{
	case 0:
	{
		LOGFONT lf;
		lf.lfHeight = 18;
		lf.lfWidth = 0;
		lf.lfWeight = FW_BLACK;
		lf.lfUnderline = 0;
		lf.lfStrikeOut = 0;
		wcscpy_s(lf.lfFaceName, _T("΢���ź�"));
		return lf;
	}
	break;
	default:
		break;
	}
	LOGFONT lf1;
	lf1.lfHeight = 18;
	lf1.lfWidth = 0;
	lf1.lfWeight = FW_BLACK;
	lf1.lfUnderline = 0;
	wcscpy_s(lf1.lfFaceName, _T("΢���ź�"));
	return lf1;
}

