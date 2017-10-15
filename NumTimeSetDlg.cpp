// NumTimeSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskClock.h"
#include "NumTimeSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NumTimeSetDlg dialog


NumTimeSetDlg::NumTimeSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(NumTimeSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(NumTimeSetDlg)
	m_position = 0;
	m_x = 0;
	m_y = 0;
	m_bgColor = FALSE;
	m_show = -1;
	//}}AFX_DATA_INIT
	m_inType = 1;
	m_outType = 5;
}


void NumTimeSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NumTimeSetDlg)
	DDX_Control(pDX, IDC_COMOUT, m_comOut);
	DDX_Control(pDX, IDC_COMIN, m_comIn);
	DDX_Radio(pDX, IDC_IN, m_position);
	DDX_Text(pDX, IDC_COMX, m_x);
	DDX_Text(pDX, IDC_COMY, m_y);
	DDX_Check(pDX, IDC_CHECK1, m_bgColor);
	DDX_Radio(pDX, IDC_HIDE, m_show);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NumTimeSetDlg, CDialog)
	//{{AFX_MSG_MAP(NumTimeSetDlg)
	ON_BN_CLICKED(IDC_IN, OnIn)
	ON_BN_CLICKED(IDC_OUT, OnOut)
	ON_BN_CLICKED(IDC_USER, OnUser)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	ON_BN_CLICKED(IDC_HIDE, OnHide)
	ON_CBN_SELCHANGE(IDC_COMIN, OnSelchangeComin)
	ON_CBN_SELCHANGE(IDC_COMOUT, OnSelchangeComout)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_COLOR, OnColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NumTimeSetDlg message handlers

BOOL NumTimeSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_comIn.InsertString(0,"正上方");
	m_comIn.InsertString(1,"正下方");
	m_comIn.InsertString(2,"正左方");
	m_comIn.InsertString(3,"正右方");

	m_comIn.SetCurSel(m_inType);

	m_comOut.InsertString(0,"左上角");
	m_comOut.InsertString(1,"右上角");
	m_comOut.InsertString(2,"左下角");
	m_comOut.InsertString(3,"右下角");
	m_comOut.InsertString(4,"上侧居中");
	m_comOut.InsertString(5,"下侧居中");
	m_comOut.InsertString(6,"左侧居中");
	m_comOut.InsertString(7,"右侧居中");

	m_comOut.SetCurSel(m_outType);

	SetPositionEnable();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void NumTimeSetDlg::SetPositionEnable()
{
	switch(m_position)
	{
	case 0:
		GetDlgItem(IDC_COMIN)->EnableWindow(true);
		GetDlgItem(IDC_COMOUT)->EnableWindow(false);
		GetDlgItem(IDC_COMX)->EnableWindow(false);
		GetDlgItem(IDC_COMY)->EnableWindow(false);
		break;
	case 1:
		GetDlgItem(IDC_COMIN)->EnableWindow(false);
		GetDlgItem(IDC_COMOUT)->EnableWindow(true);
		GetDlgItem(IDC_COMX)->EnableWindow(false);
		GetDlgItem(IDC_COMY)->EnableWindow(false);
		break;
	case 2:
		GetDlgItem(IDC_COMIN)->EnableWindow(false);
		GetDlgItem(IDC_COMOUT)->EnableWindow(false);
		GetDlgItem(IDC_COMX)->EnableWindow(true);
		GetDlgItem(IDC_COMY)->EnableWindow(true);
		break;
	}
}

void NumTimeSetDlg::OnIn() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetPositionEnable();
}

void NumTimeSetDlg::OnOut() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetPositionEnable();
}

void NumTimeSetDlg::OnUser() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetPositionEnable();
}

void NumTimeSetDlg::OnShow() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
}

void NumTimeSetDlg::OnHide() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
}

void NumTimeSetDlg::OnSelchangeComin() 
{
	// TODO: Add your control notification handler code here
	m_inType = m_comIn.GetCurSel();
}

void NumTimeSetDlg::OnSelchangeComout() 
{
	// TODO: Add your control notification handler code here
	m_outType = m_comOut.GetCurSel();
}

void NumTimeSetDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CPen penBorder(PS_SOLID,1,RGB(200,200,200));
	CPen *ppenOld = dc.SelectObject(&penBorder);
	CBrush brPoint(m_color);
	CBrush* pbrOld = dc.SelectObject(&brPoint);

	dc.Rectangle(260,75,320,105);
	// Do not call CDialog::OnPaint() for painting messages
}

void NumTimeSetDlg::OnColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_color;
	if(IDOK==dlg.DoModal())
	{
	   m_color = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}
