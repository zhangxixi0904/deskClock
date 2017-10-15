// ClockScale.h: interface for the CClockScale class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKSCALE_H__AEFEB0AD_A9E6_42F2_A063_1F069B1D9521__INCLUDED_)
#define AFX_CLOCKSCALE_H__AEFEB0AD_A9E6_42F2_A063_1F069B1D9521__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClockScale  
{
public:
	CClockScale();
	virtual ~CClockScale();
public:
	void DrawFacePoint(CDC *pDC,const CPoint &ptFace, BOOL bMajor);
	void DrawScale(CDC *pDc,CPoint &ptMiddle);
	void DrawMajor(CDC *PDC,MAJORTYPE type, CRect rectPoint);
	CPoint ComputerFacePoint(UINT min, int nFaceLength);

	MAJORTYPE GetScaleStyle();
	COLORREF GetScaleColor();
	int GetLogColor();
	void SetScaleColor(COLORREF colorref);
	void SetLogColor(int color);
	void SetScaleStyle(MAJORTYPE type);
public:
	COLORREF m_color;
//	UINT m_size;
	int  m_logColor;
	CPoint m_ptMiddle;
	UINT m_nPointWidth;
	MAJORTYPE m_style;

};

#endif // !defined(AFX_CLOCKSCALE_H__AEFEB0AD_A9E6_42F2_A063_1F069B1D9521__INCLUDED_)
