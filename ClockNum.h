// ClockNum.h: interface for the CClockNum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKNUM_H__78E69FC1_153B_4BAA_860B_DBE74E28E3A0__INCLUDED_)
#define AFX_CLOCKNUM_H__78E69FC1_153B_4BAA_860B_DBE74E28E3A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClockNum  
{
public:
	
	CClockNum();
	virtual ~CClockNum();
	
	void DrawTime(CDC *pDc,CRect rectClient,CTime oTime);
	void SetPosition(CRect rectClient);
public:
	int m_inType;
	int m_outType;
	int m_position;
	int m_pType;
	int m_X;
	int m_Y;

	COLORREF m_color;
	bool m_bgColor;

};

#endif // !defined(AFX_CLOCKNUM_H__78E69FC1_153B_4BAA_860B_DBE74E28E3A0__INCLUDED_)
