// ScaleSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskClock.h"
#include "ScaleSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ScaleSetDlg dialog


ScaleSetDlg::ScaleSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ScaleSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ScaleSetDlg)
	m_type = -1;
	m_logColor = -1;
	//}}AFX_DATA_INIT
}


void ScaleSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ScaleSetDlg)
	DDX_Radio(pDX, IDC_ELLIPSE, m_type);
	DDX_Radio(pDX, IDC_O, m_logColor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ScaleSetDlg, CDialog)
	//{{AFX_MSG_MAP(ScaleSetDlg)
	ON_BN_CLICKED(IDC_OTHER, OnOther)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ScaleSetDlg message handlers

void ScaleSetDlg::OnOther() 
{
	// TODO: Add your control notification handler code here
	 CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_color;
	if(IDOK==dlg.DoModal())
	{
	   m_color = dlg.m_cc.rgbResult;
	} 
}

void ScaleSetDlg::OnPaint() 
{
	CPaintDC dc(this);

	CPen penBorder(PS_SOLID,1,RGB(255,255,255));
	CPen *ppenOld = dc.SelectObject(&penBorder);
	CBrush brPoint(m_color);
	CBrush* pbrOld = dc.SelectObject(&brPoint);

	dc.Rectangle(180,55,240,85);
	dc.SelectObject(ppenOld);
	dc.SelectObject(pbrOld);
}
