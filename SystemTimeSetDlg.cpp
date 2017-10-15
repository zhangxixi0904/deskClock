// SystemTimeSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskclock.h"
#include "SystemTimeSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SystemTimeSetDlg dialog


SystemTimeSetDlg::SystemTimeSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SystemTimeSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SystemTimeSetDlg)
	m_hour = 0;
	m_minute = 0;
	m_second = 0;
	m_pickerTime = 0;
	//}}AFX_DATA_INIT
	SYSTEMTIME time;
	GetLocalTime(&time);
	m_pickerTime = time;
	m_hour   = time.wHour;
	m_minute = time.wMinute;
	m_second = time.wSecond;
}


void SystemTimeSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SystemTimeSetDlg)
	DDX_Text(pDX, IDC_HO, m_hour);
	DDX_Text(pDX, IDC_MI, m_minute);
	DDX_Text(pDX, IDC_SE, m_second);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_pickerTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SystemTimeSetDlg, CDialog)
	//{{AFX_MSG_MAP(SystemTimeSetDlg)
	ON_WM_TIMER()
	ON_EN_SETFOCUS(IDC_SE, OnSetfocusSe)
	ON_EN_KILLFOCUS(IDC_SE, OnKillfocusSe)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SystemTimeSetDlg message handlers

BOOL SystemTimeSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void SystemTimeSetDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	SYSTEMTIME time;
	GetLocalTime(&time);
	m_second = time.wSecond;
	CString str; 
	str.Format("%d",m_second);
	GetDlgItem(IDC_SE)->SetWindowText(str);
	CDialog::OnTimer(nIDEvent);
}

void SystemTimeSetDlg::OnSetfocusSe() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
}

void SystemTimeSetDlg::OnKillfocusSe() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,1000,NULL);
}
