#if !defined(AFX_NUMTIMESETDLG_H__B3B38189_C618_477D_AF44_7AA881D08938__INCLUDED_)
#define AFX_NUMTIMESETDLG_H__B3B38189_C618_477D_AF44_7AA881D08938__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NumTimeSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NumTimeSetDlg dialog

class NumTimeSetDlg : public CDialog
{
// Construction
public:
	void SetPositionEnable();
	NumTimeSetDlg(CWnd* pParent = NULL);   // standard constructor

	int m_inType;
	int m_outType;
	COLORREF m_color;
// Dialog Data
	//{{AFX_DATA(NumTimeSetDlg)
	enum { IDD = IDD_SET_NUMTIME };
	CComboBox	m_comOut;
	CComboBox	m_comIn;
	int		m_position;
	int		m_x;
	int		m_y;
	BOOL	m_bgColor;
	int		m_show;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NumTimeSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(NumTimeSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnIn();
	afx_msg void OnOut();
	afx_msg void OnUser();
	afx_msg void OnShow();
	afx_msg void OnHide();
	afx_msg void OnSelchangeComin();
	afx_msg void OnSelchangeComout();
	afx_msg void OnPaint();
	afx_msg void OnColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMTIMESETDLG_H__B3B38189_C618_477D_AF44_7AA881D08938__INCLUDED_)
