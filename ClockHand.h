// ClockHand.h: interface for the CClockHand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKHAND_H__D3669552_22AA_44C2_ABCB_3AF38C899FC9__INCLUDED_)
#define AFX_CLOCKHAND_H__D3669552_22AA_44C2_ABCB_3AF38C899FC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClockHand  
{
public:
	void GetHandPoints(int nValue, HANDTYPE typeHand, CPoint *pptHand,CTime oTime);
	void DrawHand(CDC *pDC,int nValue,HANDTYPE typeHand,CPoint &ptMiddle,CTime oTime);
	CClockHand();
	virtual ~CClockHand();
public:
	void GetHandColor(COLORREF &hBColor, COLORREF &hColor, COLORREF &mBColor, COLORREF &mColor, COLORREF &sColor);
	void SetHandColor(COLORREF hBColor, COLORREF hColor, COLORREF mBColor, COLORREF mColor, COLORREF sColor);

	CPoint m_ptMiddle;
	UINT m_nPointWidth;
	double m_nRidius;

	COLORREF m_HbordColor;
	COLORREF m_HColor;

	COLORREF m_MbordColor;
	COLORREF m_MColor;

	COLORREF m_SbordColor;

};

#endif // !defined(AFX_CLOCKHAND_H__D3669552_22AA_44C2_ABCB_3AF38C899FC9__INCLUDED_)
