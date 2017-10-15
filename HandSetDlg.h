#if !defined(AFX_HANDSETDLG_H__7E2EAD39_DB56_425B_A3E7_16C32BF6C61A__INCLUDED_)
#define AFX_HANDSETDLG_H__7E2EAD39_DB56_425B_A3E7_16C32BF6C61A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HandSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HandSetDlg dialog

class HandSetDlg : public CDialog
{
// Construction
public:
	HandSetDlg(CWnd* pParent = NULL);   // standard constructor

	COLORREF m_HbordColor;
	COLORREF m_HColor;

	COLORREF m_MbordColor;
	COLORREF m_MColor;

	COLORREF m_SbordColor;
// Dialog Data
	//{{AFX_DATA(HandSetDlg)
	enum { IDD = IDD_SET_HAND };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HandSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(HandSetDlg)
	afx_msg void OnPaint();
	afx_msg void OnHbcolor();
	afx_msg void OnHcolor();
	afx_msg void OnMbcolor();
	afx_msg void OnMcolor();
	afx_msg void OnSbcolor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANDSETDLG_H__7E2EAD39_DB56_425B_A3E7_16C32BF6C61A__INCLUDED_)
