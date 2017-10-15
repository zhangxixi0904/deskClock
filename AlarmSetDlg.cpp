// AlarmSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskclock.h"
#include "AlarmSetDlg.h"
#include "BeepSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AlarmSetDlg dialog


AlarmSetDlg::AlarmSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AlarmSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(AlarmSetDlg)
	m_bSound = TRUE;
	m_bMusic = 0;
	m_strAlarmMusic = _T("");
	m_pickerTime = 0;
	//}}AFX_DATA_INIT
	SYSTEMTIME time;
	GetLocalTime(&time);
	m_pickerTime = time;
	m_hour   = time.wHour;
	m_minute = time.wMinute;
	m_second = time.wSecond;
}



void AlarmSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AlarmSetDlg)
	DDX_Text(pDX, IDC_HO, m_hour);
	DDX_Text(pDX, IDC_MI, m_minute);
	DDX_Text(pDX, IDC_SE, m_second);
	DDX_Check(pDX, IDC_BMUSIC, m_bSound);
	DDX_Radio(pDX, IDC_MUSIC, m_bMusic);
	DDX_Text(pDX, IDC_PATHMUSIC, m_strAlarmMusic);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_pickerTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AlarmSetDlg, CDialog)
	//{{AFX_MSG_MAP(AlarmSetDlg)
	ON_BN_CLICKED(IDC_MUSIC, OnMusic)
	ON_BN_CLICKED(IDC_BEEP, OnBeep)
	ON_BN_CLICKED(IDC_BMUSIC, OnBmusic)
	ON_BN_CLICKED(IDC_SMUSIC, OnSelectMusic)
	ON_BN_CLICKED(IDC_SBEEP, OnSelectBeep)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AlarmSetDlg message handlers

BOOL AlarmSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetEnable();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void AlarmSetDlg::SetEnable()
{
	if(m_bSound)
	{
		GetDlgItem(IDC_MUSIC)->EnableWindow(true);
		GetDlgItem(IDC_BEEP)->EnableWindow(true);
		if(!m_bMusic)
		{
			GetDlgItem(IDC_PATHMUSIC)->EnableWindow(true);
			GetDlgItem(IDC_SMUSIC)->EnableWindow(true);
			GetDlgItem(IDC_SBEEP)->EnableWindow(false);
		}
		else
		{
			GetDlgItem(IDC_PATHMUSIC)->EnableWindow(false);
			GetDlgItem(IDC_SMUSIC)->EnableWindow(false);
			GetDlgItem(IDC_SBEEP)->EnableWindow(true);
		}
	}
	else
	{
		GetDlgItem(IDC_PATHMUSIC)->EnableWindow(false);
		GetDlgItem(IDC_SMUSIC)->EnableWindow(false);
		GetDlgItem(IDC_SBEEP)->EnableWindow(false);
		GetDlgItem(IDC_MUSIC)->EnableWindow(false);
		GetDlgItem(IDC_BEEP)->EnableWindow(false);
	}
}

void AlarmSetDlg::OnMusic() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetEnable();
}

void AlarmSetDlg::OnBeep() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetEnable();
}

void AlarmSetDlg::OnBmusic() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	SetEnable();
}

void AlarmSetDlg::OnSelectMusic() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE,"wave",NULL,NULL,"wave file(*.wav)|*.WAV",NULL);

	if (dlg.DoModal()==IDOK)
	{
		m_strAlarmMusic = dlg.GetPathName();
		UpdateData(false);
	} 
}

void AlarmSetDlg::OnSelectBeep() 
{
	// TODO: Add your control notification handler code here
	BeepSetDlg dlg;
	dlg.m_typeBeep = m_typeBeep;
	if(dlg.DoModal() == IDOK)
	{
		m_typeBeep = dlg.m_typeBeep;
	}

}
