// HandSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskClock.h"
#include "HandSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HandSetDlg dialog


HandSetDlg::HandSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(HandSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(HandSetDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void HandSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(HandSetDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(HandSetDlg, CDialog)
	//{{AFX_MSG_MAP(HandSetDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_HBCOLOR, OnHbcolor)
	ON_BN_CLICKED(IDC_HCOLOR, OnHcolor)
	ON_BN_CLICKED(IDC_MBCOLOR, OnMbcolor)
	ON_BN_CLICKED(IDC_MCOLOR, OnMcolor)
	ON_BN_CLICKED(IDC_SBCOLOR, OnSbcolor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// HandSetDlg message handlers

void HandSetDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CPen penBorderH(PS_SOLID,1,RGB(200,200,200));
	CPen *ppenOld = dc.SelectObject(&penBorderH);
	CBrush brPointH(m_HbordColor);
	CBrush* pbrOld = dc.SelectObject(&brPointH);

	dc.Rectangle(60,75,120,105);


	CBrush brH(m_HColor);
	dc.SelectObject(&brH);

	dc.Rectangle(60,175,120,205);

	CBrush brPointM(m_MbordColor);
	dc.SelectObject(&brPointM);

	dc.Rectangle(194,75,254,105);

	CBrush brM(m_MColor);
	dc.SelectObject(&brM);

	dc.Rectangle(194,175,254,205);

	CBrush brS(m_SbordColor);
	dc.SelectObject(&brS);

	dc.Rectangle(328,75,388,105);
	dc.SelectObject(ppenOld);
	dc.SelectObject(pbrOld);

}

void HandSetDlg::OnHbcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_HbordColor;
	if(IDOK==dlg.DoModal())
	{
	   m_HbordColor = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}

void HandSetDlg::OnHcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_HColor;
	if(IDOK==dlg.DoModal())
	{
	   m_HColor = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}

void HandSetDlg::OnMbcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_MbordColor;
	if(IDOK==dlg.DoModal())
	{
	   m_MbordColor = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}

void HandSetDlg::OnMcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_MColor;
	if(IDOK==dlg.DoModal())
	{
	   m_MColor = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}

void HandSetDlg::OnSbcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_SbordColor;
	if(IDOK==dlg.DoModal())
	{
	   m_SbordColor = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}
