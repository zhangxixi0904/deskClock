#if !defined(AFX_SCALESETDLG_H__04D11E96_3309_4232_BB12_2796694402C3__INCLUDED_)
#define AFX_SCALESETDLG_H__04D11E96_3309_4232_BB12_2796694402C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScaleSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ScaleSetDlg dialog

class ScaleSetDlg : public CDialog
{
// Construction
public:
	COLORREF m_color;
	ScaleSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ScaleSetDlg)
	enum { IDD = IDD_SET_SCALE };
	int		m_type;
	int		m_logColor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ScaleSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ScaleSetDlg)
	afx_msg void OnOther();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCALESETDLG_H__04D11E96_3309_4232_BB12_2796694402C3__INCLUDED_)
