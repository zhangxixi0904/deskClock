// ClockNum.cpp: implementation of the CClockNum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "deskClock.h"
#include "ClockNum.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClockNum::CClockNum()
{
	m_position = 0;
	m_inType = 1;
	m_outType = 5;
	m_color = RGB(0,255,0);
	m_bgColor = false;
}

CClockNum::~CClockNum()
{

}

void CClockNum::DrawTime(CDC *pDc, CRect rectClient,CTime oTime)
{
	SetPosition(rectClient);

	UINT nHour,nMinute,nSecond;
	nHour = oTime.GetHour();
	nMinute = oTime.GetMinute();
	nSecond = oTime.GetSecond();
	CString strTime,strHour,strMinute,strSecond;
	strHour.Format("%d",nHour);
	if (nHour <10)
	{
		strHour.Format("0%d",nHour);
	}
	strMinute.Format("%d",nMinute);
	if (nMinute <10)
	{
		strMinute.Format("0%d",nMinute);
	}
	strSecond.Format("%d",nSecond);
	if (nSecond <10)
	{
		strSecond.Format("0%d",nSecond);
	}
	strTime.Format("%s : %s : %s",strHour,strMinute,strSecond);
	pDc->SetTextColor(m_color);
	if(!m_bgColor)
	{
		int nBKMode = pDc->SetBkMode(TRANSPARENT);
		pDc->TextOut(m_X,m_Y,strTime);
		pDc->SetBkMode(nBKMode);
	}
	else
	{
		pDc->TextOut(m_X,m_Y,strTime);
	}
}
void CClockNum::SetPosition(CRect rectClient)
{
	CPoint ptMiddle;
	ptMiddle.x = rectClient.Width()/2;    
	ptMiddle.y = rectClient.Height()/2 - 15;
	int nRidius  = min(ptMiddle.x,ptMiddle.y);

	if(m_position == 0)	
	{	// 内部
		switch(m_inType)
		{
		case 0:				// 上
			m_X = ptMiddle.x - 35;
			m_Y = ptMiddle.y - nRidius * 0.7;
			break;
		case 1:				// 下
			m_X = ptMiddle.x - 35;
			m_Y = ptMiddle.y + nRidius * 0.7;
			break;
		case 2:				// 左
			m_X = ptMiddle.x - nRidius * 0.8 + 25;
			m_Y = ptMiddle.y ;
			break;
		case 3:				// 右
			m_X = ptMiddle.x + nRidius * 0.8 - 95;
			m_Y = ptMiddle.y ;
			break;
		}
	}
	else if(m_position == 1)
	{	// 外部
		switch(m_outType)
		{
		case 0:				// 左上角
			m_X = 22;
			m_Y = 10;
			break;
		case 1:				// 右上角
			m_X = rectClient.right - 100;
			m_Y = 10;
			break;
		case 2:				// 左下角
			m_X = 22;
			m_Y = rectClient.bottom - 30 ;
			break;
		case 3:				// 右下角
			m_X = rectClient.right - 96;
			m_Y = rectClient.bottom - 30;
			break;
		case 4:				// 上侧居中
			m_X = ptMiddle.x - 33;
			m_Y = 2;
			break;
		case 5:				// 下侧居中
			m_X = ptMiddle.x - 33;
			m_Y = rectClient.bottom - 30;
			break;
		case 6:				// 左侧居中
			m_X = 10;
			m_Y = ptMiddle.y ;
			break;
		case 7:				// 右侧居中
			m_X = rectClient.right - 86;
			m_Y = ptMiddle.y ;
			break;
		}
	}
}