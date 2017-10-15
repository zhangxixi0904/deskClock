// ClockScale.cpp: implementation of the CClockScale class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "deskClock.h"
#include "ClockScale.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define PI 3.1415926
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClockScale::CClockScale()
{
	m_color = 0xFF0000;
	m_style = TYPE_RHOMBUS;
	m_logColor = 0;
}

CClockScale::~CClockScale()
{

}

void CClockScale::DrawScale(CDC *pDc,CPoint &ptMiddle)
{
	//计算钟面的中心位置
	m_ptMiddle.x =  ptMiddle.x;
	m_ptMiddle.y =  ptMiddle.y;
	if (m_ptMiddle.y < 0)
	{
		m_ptMiddle.y = 0;
	}

	//计算钟面的半径
	UINT nRidius  = min(m_ptMiddle.x,m_ptMiddle.y);
	//计算两个刻度之间的距离
	m_nPointWidth = (int)nRidius/20;

	// 绘制LOG
	
	CBitmap maskbmp,logbmp;
	maskbmp.LoadBitmap(IDB_LOGMASK);
	logbmp.LoadBitmap(IDB_LOG);

	CDC MaskDC,memDC;
	MaskDC.CreateCompatibleDC(pDc);
	MaskDC.SelectObject(&maskbmp);
	memDC.CreateCompatibleDC(pDc);
	memDC.SelectObject(&logbmp);
	if(m_nPointWidth > 8)
	{
		if(m_logColor == 0 )
		{
			pDc->BitBlt(m_ptMiddle.x - 25 ,ptMiddle.y - nRidius * 0.7,96,96,&MaskDC,0,0,SRCAND);
			pDc->BitBlt(m_ptMiddle.x - 25,ptMiddle.y - nRidius * 0.7,96,96,&memDC,0,0,MERGEPAINT);
		}
		else if(m_logColor == 1 )
		{
			pDc->BitBlt(m_ptMiddle.x - 25 ,ptMiddle.y - nRidius * 0.7,96,96,&MaskDC,0,0,MERGEPAINT);
			pDc->BitBlt(m_ptMiddle.x - 25,ptMiddle.y - nRidius * 0.7,96,96,&memDC,0,0,SRCAND);
		}
	}

	if (m_nPointWidth < 2)
	{
		m_nPointWidth = 2;
	}
	//保存各个刻度点的位置
	CPoint ptFace;

	//设置刻度点的颜色
	CBrush brPoint(m_color);
	CBrush* pbrOld = pDc->SelectObject(&brPoint);

	//刻度所在的圆半径为钟面半径的90%
	int nFaceLength = MulDiv(nRidius,9,10);
	//绘制各个刻度
	for (int nMin=0; nMin<60; nMin++)
	{
													//bHour为假表示绘制的是分钟刻度
		BOOL bHour = FALSE;
													//计算一个刻度点的位置
		ptFace = ComputerFacePoint(nMin,nFaceLength);

												//当分钟数是5的倍数时，bHour为真表示绘制小时刻度
		if (nMin%5==0)
		{
			bHour = true;
		}
													//绘制一个刻度点
		DrawFacePoint(pDc,ptFace,bHour);
	}
	pDc->SelectObject(pbrOld);
	return;
}

CPoint CClockScale::ComputerFacePoint(UINT min, int nFaceLength)
{
	CPoint ptCalc;
	//将分钟转换为角度数
	double fDegrees = 180+((15+min)%60)*6;

	//再转换为弧度数
	double fAngle = fDegrees/180;

	//计算刻度点位置

	ptCalc.x = m_ptMiddle.x + (int)(cos(fAngle*PI)*nFaceLength);
	ptCalc.y = m_ptMiddle.y + (int)(sin(fAngle*PI)*nFaceLength);

	//返回刻度点位置
	return(ptCalc);
}

void CClockScale::DrawFacePoint(CDC *pDC, const CPoint &ptFace, BOOL bMajor)
{
	CRect rectPoint(ptFace.x,ptFace.y,ptFace.x,ptFace.y);
	//绘制小时刻度点
	if (bMajor)
	{
		//增加高度和宽度，使单点变为小的矩形区
		rectPoint.InflateRect((m_nPointWidth/2)+2,(m_nPointWidth/2)+2);
		DrawMajor(pDC, m_style,rectPoint);	
	}
	//绘制分钟刻度点
	else
	{
		//只有当刻度点之间的距离足够大时才绘制
		if (m_nPointWidth > 2)
		{
			rectPoint.InflateRect(1,1);
			pDC->Draw3dRect(&rectPoint,GetSysColor(COLOR_BTNHIGHLIGHT),GetSysColor(COLOR_BTNSHADOW));
		}
	}
	return;
}

void CClockScale::DrawMajor(CDC *pDC, MAJORTYPE type, CRect rectPoint)
{
	CPen *oldPen;
	CPoint ptRhombus[4] ;
	CPen penBorder(PS_SOLID,1,RGB(255,255,255));
	switch(type)
	{
	case TYPE_ELLIPSE:
		pDC->Ellipse(rectPoint);
		break;
	case TYPE_RECT:	
		pDC->Rectangle(&rectPoint);	
		pDC->Draw3dRect(&rectPoint,GetSysColor(COLOR_BTNHIGHLIGHT),GetSysColor(COLOR_BTNSHADOW));
		break;
	case TYPE_RHOMBUS:
		oldPen = pDC->SelectObject(&penBorder);
		ptRhombus[1].x = rectPoint.left + rectPoint.Width()/2;
		ptRhombus[1].y = rectPoint.top;
		
		ptRhombus[0].x = rectPoint.left;
		ptRhombus[0].y = rectPoint.top + rectPoint.Height()/2;

		ptRhombus[3].x = rectPoint.left + rectPoint.Width()/2;
		ptRhombus[3].y = rectPoint.bottom;

		ptRhombus[2].x = rectPoint.right;
		ptRhombus[2].y = rectPoint.top + rectPoint.Height()/2;

		pDC->Polygon(ptRhombus,4);
		pDC->SelectObject(oldPen);
		break;
	case TYPE_TRIANGLE:
		oldPen = pDC->SelectObject(&penBorder);
		ptRhombus[0].x = rectPoint.left;
		ptRhombus[0].y = rectPoint.top + rectPoint.Height()/2;
		
		ptRhombus[1].x = rectPoint.left + rectPoint.Width()/2;
		ptRhombus[1].y = rectPoint.top;
		
		ptRhombus[2].x = rectPoint.right;
		ptRhombus[2].y = rectPoint.top + rectPoint.Height()/2;

		pDC->Polygon(ptRhombus,3);
		pDC->SelectObject(oldPen);
		break;
	}
}

void CClockScale::SetScaleStyle(MAJORTYPE type)
{
	m_style = type;
}

void CClockScale::SetScaleColor(COLORREF colorref)
{
	m_color = colorref;
}
void CClockScale::SetLogColor(int color)
{
	m_logColor = color;
}
MAJORTYPE CClockScale::GetScaleStyle()
{
	return m_style;
}

COLORREF CClockScale::GetScaleColor()
{
	return m_color;
}
int CClockScale::GetLogColor()
{
	return m_logColor;
}