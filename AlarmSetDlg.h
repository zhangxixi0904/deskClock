#if !defined(AFX_ALARMSETDLG_H__13591888_40B2_44EB_86FB_6AD899F04C4E__INCLUDED_)
#define AFX_ALARMSETDLG_H__13591888_40B2_44EB_86FB_6AD899F04C4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AlarmSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AlarmSetDlg dialog

class AlarmSetDlg : public CDialog
{
// Construction
public:
	AlarmSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AlarmSetDlg)
	enum { IDD = IDD_SET_ALARM };
	int		m_hour;
	int		m_minute;
	int		m_second;
	BOOL	m_bSound;
	int		m_bMusic;
	CString	m_strAlarmMusic;
	CTime	m_pickerTime;
	//}}AFX_DATA

public:
	void SetEnable();
	int m_typeBeep;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AlarmSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AlarmSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnMusic();
	afx_msg void OnBeep();
	afx_msg void OnBmusic();
	afx_msg void OnSelectMusic();
	afx_msg void OnSelectBeep();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALARMSETDLG_H__13591888_40B2_44EB_86FB_6AD899F04C4E__INCLUDED_)
