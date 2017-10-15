#if !defined(AFX_SYSTEMTIMESETDLG_H__3E31E6FA_823E_41F2_99DF_86989BCCA774__INCLUDED_)
#define AFX_SYSTEMTIMESETDLG_H__3E31E6FA_823E_41F2_99DF_86989BCCA774__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SystemTimeSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SystemTimeSetDlg dialog

class SystemTimeSetDlg : public CDialog
{
// Construction
public:
	SystemTimeSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SystemTimeSetDlg)
	enum { IDD = IDD_SET_TIME };
	int		m_hour;
	int		m_minute;
	int		m_second;
	CTime	m_pickerTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SystemTimeSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SystemTimeSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSetfocusSe();
	afx_msg void OnKillfocusSe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMTIMESETDLG_H__3E31E6FA_823E_41F2_99DF_86989BCCA774__INCLUDED_)
