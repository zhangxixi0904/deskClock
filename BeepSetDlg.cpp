// BeepSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskclock.h"
#include "BeepSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BeepSetDlg dialog


BeepSetDlg::BeepSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(BeepSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(BeepSetDlg)
	m_typeBeep = -1;
	//}}AFX_DATA_INIT
	m_times = 5;
}


void BeepSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BeepSetDlg)
	DDX_Radio(pDX, IDC_XIAOJIUWO, m_typeBeep);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BeepSetDlg, CDialog)
	//{{AFX_MSG_MAP(BeepSetDlg)
	ON_BN_CLICKED(IDC_XIAOJIUWO, OnXiaoJiuWo)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_C1, OnC1)
	ON_BN_CLICKED(IDC_D1, OnC2)
	ON_BN_CLICKED(IDC_E1, OnC3)
	ON_BN_CLICKED(IDC_F1, OnC4)
	ON_BN_CLICKED(IDC_G1, OnC5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BeepSetDlg message handlers

void BeepSetDlg::OnXiaoJiuWo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::OnUp() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::OnDown() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::OnC1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::OnC2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::OnC3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::OnC4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::OnC5() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	ClockBeep();
}

void BeepSetDlg::ClockBeep()
{
	yf a[1000]={{z3,125},{z3,50},{z4,100},{z3,50},{z2,50}, //5
	{z2,125},{z2,50},{z5,100},{z2,50},{z1,50}, //10
	{z1,125},{z1,50},{z6,100},{z5,100},    //14
	{z3,125},{z4,25},{z3,25},{z2,100},{z2,100}, //19
	{z3,125},{z3,50},{z4,100},{z5,50},{z3,50}, //24
	{z5,125},{z5,50},{g2,100},{z7,50},{g1,50}, //29
	{g1,200},{g1,50},{z7,50},{z6,50},{z7,50}, //34
	{g1,125},{z7,50},{g1,200},      //37
	{g1,50},{z7,50},{g1,50},{z7,50},{g1,100},{z3,50},{z5,50}, //44
	{z5,250},{z6,50},{z7,50},      //47
	{g1,50},{z7,50},{g1,50},{z7,50},{g1,100},{g2,100},{g3,100}, //54
	{g3,300},{z6,50},{z7,50},   //57
	{g1,50},{z7,50},{g1,50},{z7,50},{g1,100},{g3,100}, //63
	{z7,50},{z6,50},{z7,50},{z6,50},{z7,50},{z5,50},{z5,50},{g1,50}, //71
	{g1,200},{g3,75},{g4,25},{g4,50},{g3,50}, //76
	{g2,200},{yaya,50},{z5,50},{g1,50},{g2,50}, //81
	{g3,50},{g1,50},{g1,50},{z5,50},{z5,100},{z5,50},{g3,50}, //88
	{g2,50},{g3,50},{g2,50},{g1,50},{z5,50},{z5,50},{z6,50},{z7,50}, //96
	{g1,50},{z6,50},{z6,50},{z3,50},{z3,100},{yaya,50},{z7,50}, //103
	{g1,50},{z7,50},{g1,50},{g2,50},{z6,50},{z5,50},{z5,100}, //110
	{z6,100},{z5,50},{z6,50},{z7,100},{g3,50},{g4,50}, //116
	{g3,50},{g4,50},{g3,50},{g2,50},{g2,50},{g1,100},{z5,50}, //123
	{z5,50},{z4,50},{z4,50},{g1,50},{g1,50},{g3,50},{g3,50},{g1,50}, //131
	{g2,200},{yaya,50},{z5,50},{g1,50},{g2,50}, //136
	{g3,50},{g1,50},{g1,50},{z5,50},{z5,100},{z5,50},{g3,50}, //143
	{g2,50},{g3,50},{g2,50},{g1,50},{z5,50},{z5,50},{z6,50},{z7,50}, //151
	{g1,50},{z6,50},{z6,50},{z3,50},{z3,100},{z3,50},{z7,50}, //158
	{g1,50},{z7,50},{g1,50},{g2,50},{z6,50},{z5,50},{z5,100}, //165
	{z6,50},{z7,50},{g1,50},{g2,100},{g3,50},{g4,50}, //171
	{g3,50},{g4,50},{g2,50},{g1,50},{g2,50},{g1,50},{g1,100}, //178
	{g2,50},{g1,50},{g2,50},{z6,50},{g1,100},{g2,50},{g1,50}, //185
	{g1,400},   //186
	{g2,50},{g1,50},{g2,50},{z6,50},{z7,100},{z7,50},{g1,50}, //193
	{g1,400},   //194
	};
	int i = 0;
	switch(m_typeBeep)
	{
	case 0:
		yf *atop;
		atop=a;
		while(m_times--)
		{
		   Beep(atop->s,atop->t*5);
		   atop++;
		}
		break;
	case 1:
		for(i = 5 ; i < 5 + m_times; i++)
		{
			Beep(i * 70,50);
			Sleep(200);
		}
		break;
	case 2:
		for(i =  5 + m_times ; i > 5; i--)
		{
			Beep(i * 70,50);
			Sleep(200);
		}
		break;
	case 3:
		for(i = 0 ; i < m_times; i++)
		{
			Beep(262,50);
			Sleep(200);
		}
		break;
	case 4:
		for(i = 0 ; i < m_times; i++)
		{
			Beep(294,50);
			Sleep(200);
		}
		break;
	case 5:
		for(i = 0 ; i < m_times; i++)
		{
			Beep(330,50);
			Sleep(200);
		}
		break;
	case 6:
		for(i = 0 ; i < m_times; i++)
		{
			Beep(349,50);
			Sleep(200);
		}
		break;
	case 7:
		for(i = 0 ; i < m_times; i++)
		{
			Beep(392,50);
			Sleep(200);
		}
		break;
	}

}
