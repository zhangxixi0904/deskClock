// deskClock.h : main header file for the DESKCLOCK application
//

#if !defined(AFX_DESKCLOCK_H__B7522C7C_B987_45C6_BCB3_F7207C078EE3__INCLUDED_)
#define AFX_DESKCLOCK_H__B7522C7C_B987_45C6_BCB3_F7207C078EE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeskClockApp:
// See deskClock.cpp for the implementation of this class
//

class CDeskClockApp : public CWinApp
{
public:
	CDeskClockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeskClockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeskClockApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESKCLOCK_H__B7522C7C_B987_45C6_BCB3_F7207C078EE3__INCLUDED_)
