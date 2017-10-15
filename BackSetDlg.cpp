// BackSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskclock.h"
#include "BackSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BackSetDlg dialog


BackSetDlg::BackSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(BackSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(BackSetDlg)
	m_bPicture = 0;
	m_strBk = _T("");
	m_bBkStre = -1;
	//}}AFX_DATA_INIT
}


void BackSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BackSetDlg)
	DDX_Radio(pDX, IDC_COLOR, m_bPicture);
	DDX_Text(pDX, IDC_EDITPICTURE, m_strBk);
	DDX_Radio(pDX, IDC_CENTER, m_bBkStre);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BackSetDlg, CDialog)
	//{{AFX_MSG_MAP(BackSetDlg)
	ON_BN_CLICKED(IDC_COLOR, OnColor)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BKCOLOR, OnBkcolor)
	ON_BN_CLICKED(IDC_BKPICTURE, OnBkpicture)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BackSetDlg message handlers

BOOL BackSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetEnable();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void BackSetDlg::SetEnable()
{
	if(!m_bPicture)
	{
		GetDlgItem(IDC_BKCOLOR)->EnableWindow(true);
		GetDlgItem(IDC_BKPICTURE)->EnableWindow(false);
		GetDlgItem(IDC_EDITPICTURE)->EnableWindow(false);
		GetDlgItem(IDC_STRE)->EnableWindow(false);
		GetDlgItem(IDC_CENTER)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_BKCOLOR)->EnableWindow(false);
		GetDlgItem(IDC_BKPICTURE)->EnableWindow(true);
		GetDlgItem(IDC_EDITPICTURE)->EnableWindow(true);
		GetDlgItem(IDC_STRE)->EnableWindow(true);
		GetDlgItem(IDC_CENTER)->EnableWindow(true);
	}
}

void BackSetDlg::OnColor() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetEnable();
}

void BackSetDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetEnable();
}

void BackSetDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CPen penBorderH(PS_SOLID,1,RGB(200,200,200));
	CPen *ppenOld = dc.SelectObject(&penBorderH);
	CBrush brPointH(m_colorBk);
	CBrush* pbrOld = dc.SelectObject(&brPointH);

	dc.Rectangle(70,105,130,135);
}

void BackSetDlg::OnBkcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_colorBk;
	if(IDOK==dlg.DoModal())
	{
	   m_colorBk = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}

void BackSetDlg::OnBkpicture() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE,"bmp",NULL,NULL,"bmp file(*.bmp)|*.BMP|",NULL);

	if (dlg.DoModal()==IDOK)
	{
		m_strBk = dlg.GetPathName();
		UpdateData(false);
	} 
}
