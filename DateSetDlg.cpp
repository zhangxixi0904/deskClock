// DateSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskclock.h"
#include "DateSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DateSetDlg dialog


DateSetDlg::DateSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DateSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DateSetDlg)
	m_up = 0;
	m_in = 0;
	m_show = 0;
	//}}AFX_DATA_INIT
}


void DateSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DateSetDlg)
	DDX_Control(pDX, IDC_COMOUT, m_comOut);
	DDX_Control(pDX, IDC_COMIN, m_comIn);
	DDX_Radio(pDX, IDC_UP, m_up);
	DDX_Radio(pDX, IDC_IN, m_in);
	DDX_Radio(pDX, IDC_SHOW, m_show);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DateSetDlg, CDialog)
	//{{AFX_MSG_MAP(DateSetDlg)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_LEFT, OnLeft)
	ON_BN_CLICKED(IDC_IN, OnIn)
	ON_BN_CLICKED(IDC_OUT, OnOut)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_DATECOLOR, OnDatecolor)
	ON_BN_CLICKED(IDC_WEEKCOLOR, OnWeekcolor)
	ON_CBN_SELCHANGE(IDC_COMIN, OnSelchangeComIn)
	ON_CBN_SELCHANGE(IDC_COMOUT, OnSelchangeComOut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DateSetDlg message handlers

BOOL DateSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_comIn.InsertString(0,"正上方");
	m_comIn.InsertString(1,"正下方");
	m_comIn.InsertString(2,"正左方");
	m_comIn.InsertString(3,"正右方");

	m_comIn.SetCurSel(m_inType);

	m_comOut.InsertString(0,"左上角");
	m_comOut.InsertString(1,"右上角");
	m_comOut.InsertString(2,"左下角");
	m_comOut.InsertString(3,"右下角");

	m_comOut.SetCurSel(m_outType);

	SetPositionEnable();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DateSetDlg::SetPositionEnable()
{
	if(m_up == 0)
	{
		GetDlgItem(IDC_IN)->EnableWindow(false);
		GetDlgItem(IDC_COMIN)->EnableWindow(false);
		GetDlgItem(IDC_OUT)->EnableWindow(false);
		GetDlgItem(IDC_COMOUT)->EnableWindow(false);
		return;
	}
	if(m_in == 0)
	{
		GetDlgItem(IDC_IN)->EnableWindow(true);
		GetDlgItem(IDC_COMIN)->EnableWindow(true);
		GetDlgItem(IDC_OUT)->EnableWindow(true);
		GetDlgItem(IDC_COMOUT)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_IN)->EnableWindow(true);
		GetDlgItem(IDC_COMIN)->EnableWindow(false);
		GetDlgItem(IDC_OUT)->EnableWindow(true);
		GetDlgItem(IDC_COMOUT)->EnableWindow(true);
	}
}

void DateSetDlg::OnUp() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetPositionEnable();
}

void DateSetDlg::OnLeft() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetPositionEnable();
}

void DateSetDlg::OnIn() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetPositionEnable();	
}

void DateSetDlg::OnOut() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetPositionEnable();	
}

void DateSetDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CPen penBorder(PS_SOLID,1,RGB(200,200,200));
	CPen *ppenOld = dc.SelectObject(&penBorder);
	CBrush brPoint(m_dColor);
	CBrush* pbrOld = dc.SelectObject(&brPoint);

	dc.Rectangle(250,95,310,125);

	CBrush brPointw(m_wColor);
	dc.SelectObject(&brPointw);

	dc.Rectangle(345,95,405,125);
	// Do not call CDialog::OnPaint() for painting messages
}

void DateSetDlg::OnDatecolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_dColor;
	if(IDOK==dlg.DoModal())
	{
	   m_dColor = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}

void DateSetDlg::OnWeekcolor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_RGBINIT ;
	dlg.m_cc.rgbResult=m_wColor;
	if(IDOK==dlg.DoModal())
	{
	   m_wColor = dlg.m_cc.rgbResult;
	   Invalidate();
	} 
}

void DateSetDlg::OnSelchangeComIn() 
{
	// TODO: Add your control notification handler code here
	m_inType = m_comIn.GetCurSel();
}

void DateSetDlg::OnSelchangeComOut() 
{
	// TODO: Add your control notification handler code here
	m_outType = m_comOut.GetCurSel();
}
