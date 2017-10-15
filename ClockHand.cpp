// ClockHand.cpp: implementation of the CClockHand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "deskClock.h"
#include "ClockHand.h"
#include "ClockScale.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClockHand::CClockHand()
{
	m_HbordColor =  RGB(255,255,255);
	m_HColor = RGB(128,128,0);

	m_MbordColor = RGB(255,255,255);
	m_MColor = RGB(0,128,128);

	m_SbordColor = RGB(255,128,128);
}

CClockHand::~CClockHand()
{

}

void CClockHand::DrawHand(CDC *pDC, int nValue,HANDTYPE typeHand,CPoint &ptMiddle,CTime oTime)
{
	m_ptMiddle.x = ptMiddle.x;
	m_ptMiddle.y = ptMiddle.y;
	m_nRidius  = min(m_ptMiddle.x,m_ptMiddle.y);
	m_nPointWidth = (int)m_nRidius/20;

	CPoint ptHand[4];
	//得到指针的位置
	GetHandPoints(nValue,typeHand,ptHand, oTime);

	CBrush brHandH(m_HColor);
	CPen penHandH(PS_SOLID,1,m_HbordColor);

	CBrush brHandM(m_MColor);
	CPen penHandM(PS_SOLID,1,m_MbordColor);

	CPen penrgb(PS_SOLID,1,m_SbordColor);
	switch(typeHand)
	{
	case HOUR_HAND:
		//设置画刷、画笔
		pDC->SelectObject(&brHandH);
		pDC->SelectObject(&penHandH);

		//绘制一个四边形
		pDC->Polygon(ptHand,4);
		break;
	case MINUTE_HAND:
		//设置画刷、画笔
		
		pDC->SelectObject(&brHandM);
		pDC->SelectObject(&penHandM);

		//绘制一个四边形
		pDC->Polygon(ptHand,4);
		break;
	case SECOND_HAND:
		pDC->SelectObject(&penrgb);
		pDC->MoveTo(ptHand[0]);
		pDC->LineTo(ptHand[1]);
		break;
	}
}

void CClockHand::GetHandPoints(int nValue, HANDTYPE typeHand, CPoint *pptHand,CTime oTime)
{
	UINT nMinute = oTime.GetMinute();
	CClockScale Scale;
	Scale.m_ptMiddle.x = m_ptMiddle.x;
	Scale.m_ptMiddle.y = m_ptMiddle.y;
	int nLength = 0;
	//根据指针的类型区分
	switch(typeHand)
	{
	case HOUR_HAND:
		//时针长为钟面半径的一半
		nLength = MulDiv(m_nRidius, 50, 100);
		//因为绘制时针按照分针进行，故需要一些变换
		nValue *= 5;
		nValue += (nMinute/12);
		break;
	case MINUTE_HAND:
		nLength = MulDiv(m_nRidius, 70, 100);
		break;
	case SECOND_HAND:
		nLength = MulDiv(m_nRidius, 80, 100);
		break;
	default:
		ASSERT(false);
	}

	//得到时针和分针外形的四个点
	if (typeHand == HOUR_HAND || typeHand == MINUTE_HAND)
	{
		pptHand[0] = Scale.ComputerFacePoint(nValue+30,m_nPointWidth*2);
		pptHand[1] = Scale.ComputerFacePoint(nValue+15,m_nPointWidth);
		pptHand[2] = Scale.ComputerFacePoint(nValue,nLength);
		pptHand[3] = Scale.ComputerFacePoint(nValue-15,m_nPointWidth);
	}
	//得到秒针的两个端点
	else
	{
		pptHand[0] = m_ptMiddle;
		pptHand[1] = Scale.ComputerFacePoint(nValue,nLength);
	}
}

void CClockHand::SetHandColor(COLORREF hBColor, COLORREF hColor, COLORREF mBColor, COLORREF mColor, COLORREF sColor)
{
	m_HbordColor =  hBColor;
	m_HColor = hColor;

	m_MbordColor = mBColor;
	m_MColor = mColor;

	m_SbordColor = sColor;
}

void CClockHand::GetHandColor(COLORREF &hBColor, COLORREF &hColor, COLORREF &mBColor, COLORREF &mColor, COLORREF &sColor)
{
	hBColor = m_HbordColor;
	hColor = m_HColor;

	mBColor = m_MbordColor;
	mColor = m_MColor;

	sColor = m_SbordColor;
}
