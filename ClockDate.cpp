// ClockDate.cpp: implementation of the CClockDate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "deskclock.h"
#include "ClockDate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClockDate::CClockDate()
{
	m_dColor = RGB(0,255,0);
	m_wColor = RGB(0,255,0);
	m_position = 0;
	m_inType = 1;
	m_outType = 1;
	m_bUp = false;
}

CClockDate::~CClockDate()
{

}

void CClockDate::DrawDate(CDC *pDc, CRect rectClient, CTime oTime)
{
	SetPosition(rectClient);

	UINT nYear,nMonth, nDay,nDayOfWeek;
	nYear = oTime.GetYear();
	nMonth = oTime.GetMonth();
	nDay = oTime.GetDay();
	CString strDate,strYear,strMonth,strDay,strDayOfWeek;
	strYear.Format("%d",nYear);
	strMonth.Format("%d",nMonth);
	if (nMonth <10)
	{
		strMonth.Format("0%d",nMonth);
	}
	strDay.Format("%d",nDay);
	if (nDay <10)
	{
		strDay.Format("0%d",nDay);
	}
	strDate.Format("%s��%s��%s��",strYear,strMonth,strDay);

	strDayOfWeek = weekDay( oTime);
		
	int nBKMode = pDc->SetBkMode(TRANSPARENT);
	pDc->SetTextColor(m_dColor);
	pDc->TextOut(m_DX,m_DY,strDate);
	pDc->SetTextColor(m_wColor);
	pDc->TextOut(m_WX,m_WY,strDayOfWeek);
	pDc->SetBkMode(nBKMode);


}

void CClockDate::SetPosition(CRect rectClient)
{
	CPoint ptMiddle;
	ptMiddle.x = rectClient.Width()/2;    
	ptMiddle.y = rectClient.Height()/2 - 15;
	int nRidius  = min(ptMiddle.x,ptMiddle.y);

	if(!m_bUp)
	{
		m_DX = ptMiddle.x + nRidius * 0.8 - 110;
		m_DY = ptMiddle.y + 20 ;
		m_WX = ptMiddle.x - nRidius * 0.8 + 35;
		m_WY = ptMiddle.y + 20 ;
		return;
	}
	if(m_position == 0)	
	{	// �ڲ�
		switch(m_inType)
		{
		case 0:				// ��
			m_DX = ptMiddle.x - 46;
			m_DY = ptMiddle.y - nRidius * 0.7 + 50;
			m_WX = ptMiddle.x - 16;
			m_WY = ptMiddle.y - nRidius * 0.7 + 30;
			break;
		case 1:				// ��
			m_DX = ptMiddle.x - 46;
			m_DY = ptMiddle.y + nRidius * 0.7 - 50;
			m_WX = ptMiddle.x - 16;
			m_WY = ptMiddle.y + nRidius * 0.7 - 30;
			break;
		case 2:				// ��
			m_DX = ptMiddle.x - nRidius * 0.8 + 10;
			m_DY = ptMiddle.y  + 50;
			m_WX = ptMiddle.x - nRidius * 0.8 + 45;
			m_WY = ptMiddle.y + 30 ;
			break;
		case 3:				// ��
			m_DX = ptMiddle.x + nRidius * 0.8 - 110;
			m_DY = ptMiddle.y + 50 ;
			m_WX = ptMiddle.x + nRidius * 0.8 - 75;
			m_WY = ptMiddle.y + 30 ;
			break;
		}
	}
	else if(m_position == 1)
	{	// �ⲿ
		switch(m_outType)
		{
		case 0:				// ���Ͻ�
			m_DX = 10;
			m_DY = 60;
			m_WX = 40;
			m_WY = 40;
			break;
		case 1:				// ���Ͻ�
			m_DX = rectClient.right - 112;
			m_DY = 60;
			m_WX = rectClient.right - 82;
			m_WY = 40;
			break;
		case 2:				// ���½�
			m_DX = 10;
			m_DY = rectClient.bottom - 80 ;
			m_WX = 40;
			m_WY = rectClient.bottom - 60 ;
			break;
		case 3:				// ���½�
			m_DX = rectClient.right - 112;
			m_DY = rectClient.bottom - 80 ;
			m_WX = rectClient.right - 82;
			m_WY = rectClient.bottom - 60 ;
			break;
		}
	}
}

CString CClockDate::weekDay(CTime oTime)
{	
	CString str;

	int nDayOfWeek = oTime.GetDayOfWeek();
	switch(nDayOfWeek )
	{
	case 1:
		str = "������";
		break;
	case 2:
		str = "����һ";
		break;
	case 3:
		str = "���ڶ�";
		break;
	case 4:
		str = "������";
		break;
	case 5:
		str = "������";
		break;
	case 6:
		str = "������";
		break;
	case 7:
		str = "������";
		break;
	}
	return str;
}
