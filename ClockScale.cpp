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
	//�������������λ��
	m_ptMiddle.x =  ptMiddle.x;
	m_ptMiddle.y =  ptMiddle.y;
	if (m_ptMiddle.y < 0)
	{
		m_ptMiddle.y = 0;
	}

	//��������İ뾶
	UINT nRidius  = min(m_ptMiddle.x,m_ptMiddle.y);
	//���������̶�֮��ľ���
	m_nPointWidth = (int)nRidius/20;

	// ����LOG
	
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
	//��������̶ȵ��λ��
	CPoint ptFace;

	//���ÿ̶ȵ����ɫ
	CBrush brPoint(m_color);
	CBrush* pbrOld = pDc->SelectObject(&brPoint);

	//�̶����ڵ�Բ�뾶Ϊ����뾶��90%
	int nFaceLength = MulDiv(nRidius,9,10);
	//���Ƹ����̶�
	for (int nMin=0; nMin<60; nMin++)
	{
													//bHourΪ�ٱ�ʾ���Ƶ��Ƿ��ӿ̶�
		BOOL bHour = FALSE;
													//����һ���̶ȵ��λ��
		ptFace = ComputerFacePoint(nMin,nFaceLength);

												//����������5�ı���ʱ��bHourΪ���ʾ����Сʱ�̶�
		if (nMin%5==0)
		{
			bHour = true;
		}
													//����һ���̶ȵ�
		DrawFacePoint(pDc,ptFace,bHour);
	}
	pDc->SelectObject(pbrOld);
	return;
}

CPoint CClockScale::ComputerFacePoint(UINT min, int nFaceLength)
{
	CPoint ptCalc;
	//������ת��Ϊ�Ƕ���
	double fDegrees = 180+((15+min)%60)*6;

	//��ת��Ϊ������
	double fAngle = fDegrees/180;

	//����̶ȵ�λ��

	ptCalc.x = m_ptMiddle.x + (int)(cos(fAngle*PI)*nFaceLength);
	ptCalc.y = m_ptMiddle.y + (int)(sin(fAngle*PI)*nFaceLength);

	//���ؿ̶ȵ�λ��
	return(ptCalc);
}

void CClockScale::DrawFacePoint(CDC *pDC, const CPoint &ptFace, BOOL bMajor)
{
	CRect rectPoint(ptFace.x,ptFace.y,ptFace.x,ptFace.y);
	//����Сʱ�̶ȵ�
	if (bMajor)
	{
		//���Ӹ߶ȺͿ�ȣ�ʹ�����ΪС�ľ�����
		rectPoint.InflateRect((m_nPointWidth/2)+2,(m_nPointWidth/2)+2);
		DrawMajor(pDC, m_style,rectPoint);	
	}
	//���Ʒ��ӿ̶ȵ�
	else
	{
		//ֻ�е��̶ȵ�֮��ľ����㹻��ʱ�Ż���
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