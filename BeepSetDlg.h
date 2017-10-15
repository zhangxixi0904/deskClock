#if !defined(AFX_BEEPSETDLG_H__2275231F_DCF0_4710_A742_698ED99019FB__INCLUDED_)
#define AFX_BEEPSETDLG_H__2275231F_DCF0_4710_A742_698ED99019FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BeepSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BeepSetDlg dialog

class BeepSetDlg : public CDialog
{
// Construction
public:
	void ClockBeep();
	int m_times;
	BeepSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BeepSetDlg)
	enum { IDD = IDD_SET_BEEP };
	int		m_typeBeep;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BeepSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BeepSetDlg)
	afx_msg void OnXiaoJiuWo();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnC1();
	afx_msg void OnC2();
	afx_msg void OnC3();
	afx_msg void OnC4();
	afx_msg void OnC5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BEEPSETDLG_H__2275231F_DCF0_4710_A742_698ED99019FB__INCLUDED_)
