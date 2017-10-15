#if !defined(AFX_DATESETDLG_H__40B780C5_F6FF_4FD1_AEAC_B34AE03A9EDF__INCLUDED_)
#define AFX_DATESETDLG_H__40B780C5_F6FF_4FD1_AEAC_B34AE03A9EDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DateSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DateSetDlg dialog

class DateSetDlg : public CDialog
{
// Construction
public:
	DateSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DateSetDlg)
	enum { IDD = IDD_SET_DATE };
	CComboBox	m_comOut;
	CComboBox	m_comIn;
	int		m_up;
	int		m_in;
	int		m_show;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DateSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	void SetPositionEnable();
	COLORREF m_dColor;		// 日期颜色
	COLORREF m_wColor;		// 星期颜色

	int m_inType;
	int m_outType;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DateSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnLeft();
	afx_msg void OnIn();
	afx_msg void OnOut();
	afx_msg void OnPaint();
	afx_msg void OnDatecolor();
	afx_msg void OnWeekcolor();
	afx_msg void OnSelchangeComIn();
	afx_msg void OnSelchangeComOut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATESETDLG_H__40B780C5_F6FF_4FD1_AEAC_B34AE03A9EDF__INCLUDED_)
