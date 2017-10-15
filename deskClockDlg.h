// deskClockDlg.h : header file
//

#if !defined(AFX_DESKCLOCKDLG_H__7C076637_A447_4716_B0B6_3C141F141C6D__INCLUDED_)
#define AFX_DESKCLOCKDLG_H__7C076637_A447_4716_B0B6_3C141F141C6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDeskClockDlg dialog
#include "ClockScale.h"
#include "ClockHand.h"
#include "ClockNum.h"
#include "ClockDate.h"
typedef struct alarm
{
	SYSTEMTIME	m_oTime;
	bool		m_bSound;
	bool		m_bMusic;
	int			m_typeBeep;
	CString		m_strAlarmMusic;
}ALAEM;

class CDeskClockDlg : public CDialog
{
// Construction
public:
	LRESULT OnShowDeskClock(WPARAM wParam, LPARAM lParam);
	static UINT BeepThread(LPVOID pParam);
	void Alarm();
	bool IsAlarmTime();
	WINDOWPLACEMENT m_OldWndPlacement; //用来保存原窗口位置
	bool m_bFullScreen;//全屏显示标志
	CRect m_FullScreenRect;//表示全屏显示时的窗口位置

	bool m_dateShow;
	bool m_numShow;
	bool m_bPicture;
	bool m_bBkStre;
	CString m_strBk;
	COLORREF m_colorBk;
	ALAEM	m_alarm;
	UINT	m_alarmTimes;
	void DrawTime(CDC *pDc,CRect rectClient);

//	void GetHandPoints(int nValue, HANDTYPE typeHand, CPoint *pptHand);

	int m_nHour, m_nMinute, m_nSecond;

	CPoint m_ptMiddle;
	double m_nPointWidth;
	double m_nRidius;
	SYSTEMTIME m_oTime;
	CDeskClockDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDeskClockDlg)
	enum { IDD = IDD_DESKCLOCK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeskClockDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CClockScale m_ClockScale;
	CClockHand  m_ClockHand;
	CClockNum	m_ClockNum;
	CClockDate	m_ClockDate;
	// Generated message map functions
	//{{AFX_MSG(CDeskClockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetScale();
	afx_msg void OnSetHand();
	afx_msg void OnSetNumtime();
	afx_msg void OnSetDate();
	afx_msg void OnSetBack();
	afx_msg void OnFull();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnTimeTime();
	afx_msg void OnTimeAlarm();
	virtual void OnOK();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnExit();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKCLOCKDLG_H__7C076637_A447_4716_B0B6_3C141F141C6D__INCLUDED_)
