// deskClockDlg.cpp : implementation file
//

#include "stdafx.h"
#include "deskClock.h"
#include "deskClockDlg.h"
#include   "mmsystem.h "

#include <math.h>
#include "ScaleSetDlg.h"
#include "HandSetDlg.h"
#include "NumTimeSetDlg.h"
#include "DateSetDlg.h"
#include "BackSetDlg.h"
#include "SystemTimeSetDlg.h"
#include "AlarmSetDlg.h"
#include "BeepSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PI (3.14159)
#pragma comment(lib,"winmm.lib")
#define WM_DESKCLOCK	(WM_USER + 101)
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeskClockDlg dialog

CDeskClockDlg::CDeskClockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeskClockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeskClockDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	GetLocalTime(&m_oTime);//			= CTime::GetCurrentTime();
	m_nHour					= m_oTime.wHour;
	m_nMinute				= m_oTime.wMinute;
	m_nSecond				= m_oTime.wSecond;
	m_numShow				= true;
	m_dateShow				= true;
	m_bFullScreen			= false;
	m_bBkStre				= false;
	m_bPicture				= false;
	m_strBk					= "";
	m_colorBk				= RGB(0,0,0);
	m_alarm.m_bMusic		= false;
	m_alarm.m_bSound		= true;
	m_alarm.m_strAlarmMusic	= "";	
	m_alarm.m_typeBeep		= 0;
	m_alarmTimes			= 0;
	m_hIcon					= AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDeskClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeskClockDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDeskClockDlg, CDialog)
	//{{AFX_MSG_MAP(CDeskClockDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_SET_SCALE, OnSetScale)
	ON_COMMAND(IDM_SET_HAND, OnSetHand)
	ON_COMMAND(IDM_SET_NUMTIME, OnSetNumtime)
	ON_COMMAND(IDM_SET_DATE, OnSetDate)
	ON_COMMAND(IDM_SET_BACK, OnSetBack)
	ON_COMMAND(IDM_FULL, OnFull)
	ON_WM_GETMINMAXINFO()
	ON_COMMAND(IDM_TIME_TIME, OnTimeTime)
	ON_COMMAND(IDM_TIME_ALARM, OnTimeAlarm)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_DESKCLOCK, OnShowDeskClock)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeskClockDlg message handlers

BOOL CDeskClockDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	SetTimer(1,1000,NULL);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDeskClockDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDeskClockDlg::OnPaint() 
{
		
	CRect rectClient;
	GetClientRect(&rectClient);
	CPaintDC dc(this);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);

	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc,rectClient.Width(),rectClient.Height());
	memDC.SelectObject(&bmp);

	if(m_bPicture)
	{
		CDC bkDC;
		bkDC.CreateCompatibleDC(&memDC);
		HBITMAP hBitmap;
		CBitmap bitmap;
		hBitmap=(HBITMAP)::LoadImage(::AfxGetInstanceHandle(),m_strBk,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		if(hBitmap == 0)
		{
			m_bPicture = false;
			return;
		}
		bitmap.Attach(hBitmap);

		BITMAP  pbmp;
		bitmap.GetBitmap(&pbmp);
		int bh = pbmp.bmHeight;
		int bw = pbmp.bmWidth;
		bkDC.SelectObject(&bitmap);
		if(m_bBkStre)
		{
			memDC.StretchBlt(0,0,rectClient.Width(),rectClient.Height(),&bkDC,0,0,bw,bh,SRCCOPY);
		}
		else
		{
			int sx = (rectClient.Width() - bw) / 2;
			int sy = (rectClient.Height() - bh) / 2;
			memDC.BitBlt(sx, sy, bw, bh, &bkDC, 0, 0,SRCCOPY);
		}	
	}
	else
	{
		
		CBrush bkBrush(m_colorBk);
		memDC.FillRect(&rectClient,&bkBrush);
	}
	m_ptMiddle.x = rectClient.Width()/2;    
	m_ptMiddle.y = rectClient.Height()/2 - 15;
	m_nRidius  = min(m_ptMiddle.x,m_ptMiddle.y);
	//���������̶�֮��ľ���
	m_nPointWidth = (int)m_nRidius/20;
	
	m_ClockScale.DrawScale(&memDC,m_ptMiddle);
	m_ClockHand.DrawHand(&memDC,m_nMinute,MINUTE_HAND,m_ptMiddle,m_oTime);	// ����	
	m_ClockHand.DrawHand(&memDC,m_nHour,HOUR_HAND,m_ptMiddle,m_oTime);		// ʱ��
	m_ClockHand.DrawHand(&memDC,m_nSecond,SECOND_HAND,m_ptMiddle,m_oTime);	// ����
	if(m_nPointWidth > 6)
	{
		if(m_numShow)
		{	//  ��������ʱ��
			m_ClockNum.DrawTime(&memDC,rectClient,m_oTime);
		}
		if(m_dateShow)
		{
			m_ClockDate.DrawDate(&memDC,rectClient,m_oTime);
		}
	}
	dc.StretchBlt(0,0,rectClient.Width(),rectClient.Height(),&memDC,0,0,rectClient.Width(),rectClient.Height(),SRCCOPY);

//	dc.SetTextColor(RGB(0,255,0));
//	dc.SetBkMode(TRANSPARENT);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDeskClockDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDeskClockDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	GetLocalTime(&m_oTime);// = CTime::GetCurrentTime();
	m_nHour = m_oTime.wHour;
	m_nMinute = m_oTime.wMinute;
	m_nSecond = m_oTime.wSecond;
	//���»���
	Invalidate();
	if(IsAlarmTime())
	{
		Alarm();
	}

	CDialog::OnTimer(nIDEvent);
}


BOOL CDeskClockDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
	return CDialog::OnEraseBkgnd(pDC);
}

void CDeskClockDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);
}

void CDeskClockDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMenu menu;//�˵�
	CMenu* pPopupMenu;//�˵�ָ��
	menu.LoadMenu(IDR_MENU1);//����IDΪIDR_MENU1�Ĳ˵�
	pPopupMenu = menu.GetSubMenu(0);   //��ȡ�����˵��ĵ�һ���Ӳ˵�����ָ��
	ClientToScreen(&point);//����굥����������ת��Ϊ��Ļ����
	pPopupMenu->TrackPopupMenu(TPM_BOTTOMALIGN,point.x,point.y + 100,this,NULL);

	CDialog::OnRButtonDown(nFlags, point);
}

void CDeskClockDlg::OnSetScale() 
{
	// TODO: Add your command handler code here
	ScaleSetDlg dlg;
	dlg.m_type = m_ClockScale.GetScaleStyle();
	dlg.m_color = m_ClockScale.GetScaleColor();
	dlg.m_logColor = m_ClockScale.GetLogColor();
	if(dlg.DoModal() == IDOK)
	{
		m_ClockScale.SetScaleStyle(MAJORTYPE(dlg.m_type));
		m_ClockScale.SetScaleColor(dlg.m_color);
		m_ClockScale.SetLogColor(dlg.m_logColor);
		Invalidate();
	}

}

void CDeskClockDlg::OnSetHand() 
{
	// TODO: Add your command handler code here
	HandSetDlg dlg;
	m_ClockHand.GetHandColor(dlg.m_HbordColor, dlg.m_HColor, dlg.m_MbordColor, dlg.m_MColor,dlg.m_SbordColor);
	if(dlg.DoModal())
	{
		m_ClockHand.SetHandColor(dlg.m_HbordColor, dlg.m_HColor, dlg.m_MbordColor, dlg.m_MColor,dlg.m_SbordColor);
		Invalidate();
	}

}

void CDeskClockDlg::OnSetNumtime() 
{
	// TODO: Add your command handler code here
	NumTimeSetDlg dlg;

	dlg.m_position = m_ClockNum.m_position;
	dlg.m_inType = m_ClockNum.m_inType;
	dlg.m_outType = m_ClockNum.m_outType;

	dlg.m_x = m_ClockNum.m_X;
	dlg.m_y = m_ClockNum.m_Y;

	dlg.m_color = m_ClockNum.m_color;
	dlg.m_bgColor = m_ClockNum.m_bgColor;

	dlg.m_show = m_numShow;
	if(dlg.DoModal() ==  IDOK)
	{	
		// ��ɫ
		m_ClockNum.m_color = dlg.m_color;
		m_ClockNum.m_bgColor = dlg.m_bgColor;
		
		// λ��
		m_ClockNum.m_position = dlg.m_position;
		m_ClockNum.m_inType = dlg.m_inType;
		m_ClockNum.m_outType = dlg.m_outType;
		if(dlg.m_position == 2)
		{
			m_ClockNum.m_X = dlg.m_x;
			m_ClockNum.m_Y = dlg.m_y;
		}
		m_numShow = dlg.m_show;
		Invalidate();
	}
}

void CDeskClockDlg::OnSetDate() 
{
	// TODO: Add your command handler code here
	DateSetDlg dlg;
	dlg.m_up = m_ClockDate.m_bUp;
	dlg.m_inType = m_ClockDate.m_inType;
	dlg.m_outType = m_ClockDate.m_outType;
	dlg.m_in = m_ClockDate.m_position;
	
	dlg.m_show = m_dateShow;
	dlg.m_dColor = m_ClockDate.m_dColor;
	dlg.m_wColor = m_ClockDate.m_wColor;
	if(dlg.DoModal() ==  IDOK)
	{
		m_ClockDate.m_bUp = dlg.m_up;
		m_ClockDate.m_inType = dlg.m_inType;
		m_ClockDate.m_outType = dlg.m_outType;
		m_ClockDate.m_position = dlg.m_in;
		
		m_dateShow = dlg.m_show;
		m_ClockDate.m_dColor = dlg.m_dColor;
		m_ClockDate.m_wColor = dlg.m_wColor;

		Invalidate();
	}
}

void CDeskClockDlg::OnSetBack() 
{
	// TODO: Add your command handler code here
	BackSetDlg dlg;
	dlg.m_bPicture	= m_bPicture;
	dlg.m_colorBk	= m_colorBk;
	dlg.m_strBk		= m_strBk;
	dlg.m_bBkStre	= m_bBkStre;
	if(dlg.DoModal() == IDOK)
	{
		m_bPicture	= dlg.m_bPicture;
		m_colorBk	= dlg.m_colorBk;
		m_strBk		= dlg.m_strBk;	
		m_bBkStre	= dlg.m_bBkStre;

		Invalidate();
	}
}

void CDeskClockDlg::OnFull() 
{
	if(m_bFullScreen)
	{	//�˳�ȫ����ʾ, �ָ�ԭ������ʾ
		ShowWindow(SW_HIDE);
		SetWindowPlacement(&m_OldWndPlacement);
		m_bFullScreen = false;
	}
	else
	{
		GetWindowPlacement(&m_OldWndPlacement);
		CRect WindowRect;
		GetWindowRect(&WindowRect);
		CRect ClientRect;
		RepositionBars(0, 0xffff, AFX_IDW_PANE_FIRST, reposQuery, &ClientRect);
		ClientToScreen(&ClientRect);
		// ��ȡ��Ļ�ķֱ���
		int nFullWidth=GetSystemMetrics(SM_CXSCREEN);
		int nFullHeight=GetSystemMetrics(SM_CYSCREEN);
		//������������Ŀͻ���ȫ����ʾ����(0,0)��(nFullWidth, nFullHeight)����, ��(0,0)��(nFullWidth, nFullHeight)������������ԭ���ںͳ�������֮��� �ͻ���λ�ü�Ĳ�ֵ, �͵õ�ȫ����ʾ�Ĵ���λ��
		m_FullScreenRect.left=WindowRect.left-ClientRect.left;
		m_FullScreenRect.top=WindowRect.top-ClientRect.top;
		m_FullScreenRect.right=WindowRect.right-ClientRect.right+nFullWidth;
		m_FullScreenRect.bottom=WindowRect.bottom-ClientRect.bottom+nFullHeight;
		m_bFullScreen=TRUE; //����ȫ����ʾ��־Ϊ TRUE
		//����ȫ����ʾ״̬
		WINDOWPLACEMENT wndpl;
		wndpl.length=sizeof(WINDOWPLACEMENT);
		wndpl.flags=0;
		wndpl.showCmd=SW_SHOWNORMAL;
		wndpl.rcNormalPosition=m_FullScreenRect;
		SetWindowPlacement(&wndpl);
	}
	Invalidate();
}

void CDeskClockDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bFullScreen)
	{
		lpMMI->ptMaxSize.x=m_FullScreenRect.Width();
		lpMMI->ptMaxSize.y=m_FullScreenRect.Height();
		lpMMI->ptMaxPosition.x=m_FullScreenRect.Width();
		lpMMI->ptMaxPosition.y=m_FullScreenRect.Height();
		//����Track�ߴ�ҲҪ�ı�
		lpMMI->ptMaxTrackSize.x=m_FullScreenRect.Width();
		lpMMI->ptMaxTrackSize.y=m_FullScreenRect.Height();
	}

	CDialog::OnGetMinMaxInfo(lpMMI);
}

BOOL CDeskClockDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg-> message == WM_KEYDOWN) 
	{ 
		if(pMsg-> wParam == VK_RETURN) 
		{ 
			return TRUE; 
		} 
		else if(pMsg-> wParam == VK_ESCAPE && m_bFullScreen)
		{
			OnFull();
			return TRUE;
		}
	}
	 

	return CDialog::PreTranslateMessage(pMsg);
}

void CDeskClockDlg::OnTimeTime() 
{
	SystemTimeSetDlg dlg;
	if(dlg.DoModal() == IDOK)
	{	
		SYSTEMTIME time;
		GetSystemTime(&time);						//��ȡ��ǰʱ�䣬���time�е�������ֵ
		time.wHour = dlg.m_hour;
		time.wMinute = dlg.m_minute;
		time.wSecond = dlg.m_second;
		time.wYear = dlg.m_pickerTime.GetYear();	//�޸���
		time.wMonth= dlg.m_pickerTime.GetMonth();	//��
		time.wDay = dlg.m_pickerTime.GetDay();		//��
		SetLocalTime(&time);
	}
}

void CDeskClockDlg::OnTimeAlarm() 
{
	// TODO: Add your command handler code here
	AlarmSetDlg dlg;
	dlg.m_bMusic		= m_alarm.m_bMusic;
	dlg.m_bSound		= m_alarm.m_bSound;
	dlg.m_strAlarmMusic	= m_alarm.m_strAlarmMusic;
	dlg.m_typeBeep		= m_alarm.m_typeBeep;
	if(dlg.DoModal() == IDOK)
	{
		m_alarm.m_bMusic		= dlg.m_bMusic;
		m_alarm.m_bSound		= dlg.m_bSound;
		m_alarm.m_strAlarmMusic	= dlg.m_strAlarmMusic;
		m_alarm.m_typeBeep		= dlg.m_typeBeep;
		m_alarm.m_oTime.wYear	= dlg.m_pickerTime.GetYear();
		m_alarm.m_oTime.wMonth	= dlg.m_pickerTime.GetMonth();
		m_alarm.m_oTime.wDay	= dlg.m_pickerTime.GetDay();
		m_alarm.m_oTime.wHour	= dlg.m_hour;
		m_alarm.m_oTime.wMinute	= dlg.m_minute;
		m_alarm.m_oTime.wSecond	= dlg.m_second;
	}
}

bool CDeskClockDlg::IsAlarmTime()
{
	bool bYear		= (m_alarm.m_oTime.wYear == m_oTime.wYear);
	bool bMonth		= (m_alarm.m_oTime.wMonth == m_oTime.wMonth);
	bool bDay		= (m_alarm.m_oTime.wDay == m_oTime.wDay);
	bool bHour		= (m_alarm.m_oTime.wHour == m_oTime.wHour);
	bool bMinute	= (m_alarm.m_oTime.wMinute == m_oTime.wMinute);
	bool bSecond	= (m_alarm.m_oTime.wSecond == m_oTime.wSecond);
	if(bYear && bMonth && bDay && bHour && bMinute && bSecond)
		return true;
	else 
		return false;
		
}

void CDeskClockDlg::Alarm()
{
	m_alarmTimes = 0;
	if(m_alarm.m_bSound)
	{
		if(!m_alarm.m_bMusic)
		{
			if(m_alarm.m_strAlarmMusic != "")
			{
					bool bend = PlaySound(m_alarm.m_strAlarmMusic,NULL,SND_FILENAME | SND_ASYNC); 
					MessageBox("����ʱ�䵽��! \n\n����:  "+m_alarm.m_strAlarmMusic,"��ܰ��ʾ");
					m_alarmTimes = 1;
					
			}
			else
			{
					MessageBox("����ʱ�䵽��! \n\n �޷�������:"+m_alarm.m_strAlarmMusic,"��ܰ��ʾ");
			}
		}
		else
		{
			AfxBeginThread(BeepThread, this);
			MessageBox("����ʱ�䵽��! \n\n ��������ʾ��","��ܰ��ʾ");	
		}
	}
	else
	{
		MessageBox("����ʱ�䵽��! \n\n ������","��ܰ��ʾ");
	}
}

UINT CDeskClockDlg::BeepThread(LPVOID pParam)
{
	CDeskClockDlg *pDlg = (CDeskClockDlg *)pParam;
	BeepSetDlg dlg;
	dlg.m_typeBeep	= pDlg->m_alarm.m_typeBeep;
	dlg.m_times		= 10;
	dlg.ClockBeep();
	return 1;
}

void CDeskClockDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	 switch( nType )
     {
     case SIZE_RESTORED:
		break;
     case SIZE_MINIMIZED:
		 NOTIFYICONDATA nid; 
		nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA); 
		nid.hWnd=this->m_hWnd; 
		nid.uID=IDR_MAINFRAME; 
		nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ; 
		nid.uCallbackMessage=WM_DESKCLOCK;//�Զ������Ϣ���� 
		nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME)); 
		strcpy(nid.szTip,"MusicPlayer");//��Ϣ��ʾ��Ϊ���ƻ��������ѡ� 
		Shell_NotifyIcon(NIM_ADD,&nid);//�����������ͼ�� 
		ShowWindow(SW_HIDE);//����������
         break;
     case SIZE_MAXIMIZED:
		 
         break;
     }

}

void CDeskClockDlg::OnOK() 
{
	CDialog::OnOK();
}

void CDeskClockDlg::OnDestroy() 
{

	NOTIFYICONDATA nid; 
	nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA); 
	nid.hWnd=this->m_hWnd; 
	nid.uID=IDR_MAINFRAME; 
	nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ; 
	nid.uCallbackMessage=WM_DESKCLOCK;//�Զ������Ϣ���� 
	nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME)); 
	strcpy(nid.szTip,"MusicPlayer");//��Ϣ��ʾ��Ϊ���ƻ��������ѡ� 
	Shell_NotifyIcon(NIM_DELETE,&nid);//�����������ͼ�� 
	ShowWindow(SW_HIDE);//����������
	CDialog::OnDestroy();
	// TODO: Add your message handler code here
	
}

LRESULT CDeskClockDlg::OnShowDeskClock(WPARAM wParam, LPARAM lParam)
{
	if(wParam!=IDR_MAINFRAME) 
	return 1; 
	switch(lParam) 
	{ 
	case WM_RBUTTONUP://�Ҽ�����ʱ������ݲ˵�������ֻ��һ�����رա� 
	{ 

		LPPOINT lpoint=new tagPOINT; 
		::GetCursorPos(lpoint);//�õ����λ�� 
		CMenu menu; 
		menu.CreatePopupMenu();//����һ������ʽ�˵� 
		//���Ӳ˵���رա������������ϢWM_DESTROY�������ڣ��� 
		//���أ��������������
		menu.AppendMenu(MF_STRING,IDC_SHOW,"��ʾ"); 
		menu.AppendMenu(MF_STRING,IDC_EXIT,"�˳�");
		//ȷ������ʽ�˵���λ�� 
		menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this); 
		//��Դ���� 
		HMENU hmenu=menu.Detach(); 
		menu.DestroyMenu(); 
		delete lpoint; 
	} 
	break; 
	case WM_LBUTTONDBLCLK://˫������Ĵ��� 
	{ 
		this->ShowWindow(SW_SHOW); 
	} 
	break; 
	} 
	return 0; 
}

void CDeskClockDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnDestroy();
	OnOK();
}

void CDeskClockDlg::OnShow() 
{
	// TODO: Add your control notification handler code here

	this->ShowWindow(SW_SHOW);
}
