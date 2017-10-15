// ClockDate.h: interface for the CClockDate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKDATE_H__A94346B3_419B_417F_AF13_E8B8A2EF179E__INCLUDED_)
#define AFX_CLOCKDATE_H__A94346B3_419B_417F_AF13_E8B8A2EF179E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClockDate  
{
public:
	CClockDate();
	virtual ~CClockDate();

public:
	void SetPosition(CRect rectClient);
	void DrawDate(CDC *pDc, CRect rectClient,CTime oTime);
public:
	CString weekDay(CTime oTime);
	int m_inType;
	int m_outType;
	int m_position;

	bool m_bUp;
	int m_DX;
	int m_DY;

	int m_WX;
	int m_WY;
	COLORREF m_dColor;
	COLORREF m_wColor;
};

#endif // !defined(AFX_CLOCKDATE_H__A94346B3_419B_417F_AF13_E8B8A2EF179E__INCLUDED_)
