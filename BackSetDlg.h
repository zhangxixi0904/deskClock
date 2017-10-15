#if !defined(AFX_BACKSETDLG_H__5C546437_9AAB_46B6_AC58_029194D90B28__INCLUDED_)
#define AFX_BACKSETDLG_H__5C546437_9AAB_46B6_AC58_029194D90B28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BackSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BackSetDlg dialog

class BackSetDlg : public CDialog
{
// Construction
public:
	void SetEnable();
	BackSetDlg(CWnd* pParent = NULL);   // standard constructor
	
	COLORREF m_colorBk;
// Dialog Data
	//{{AFX_DATA(BackSetDlg)
	enum { IDD = IDD_SET_BACK };
	int		m_bPicture;
	CString	m_strBk;
	int		m_bBkStre;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BackSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BackSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnColor();
	afx_msg void OnRadio2();
	afx_msg void OnPaint();
	afx_msg void OnBkcolor();
	afx_msg void OnBkpicture();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKSETDLG_H__5C546437_9AAB_46B6_AC58_029194D90B28__INCLUDED_)
