// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__13D6CB71_AC16_4269_8C67_7678D160E3A3__INCLUDED_)
#define AFX_STDAFX_H__13D6CB71_AC16_4269_8C67_7678D160E3A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

enum MAJORTYPE{TYPE_ELLIPSE = 0 ,TYPE_RECT = 1 ,TYPE_RHOMBUS = 2,TYPE_TRIANGLE = 3};
enum HANDTYPE{HOUR_HAND,MINUTE_HAND,SECOND_HAND};

enum fy{
	d1=262,
	d1_=277,
	d2=294,
	d2_=311,
	d3=330,
	d4=349,
	d5=392,
	d5_=415,
	d6=440,
	d6_=466,
	d7=494,
	z1=523,
	z1_=554,
	z2=578,
	z2_=622,
	z3=659,
	z4=698,
	z4_=740,
	z5=784,
	z5_=831,
	z6=880,
	z6_932,
	z7=988,
	g1=1046,
	g1_=1109,
	g2=1175,
	g2_=1245,
	g3=1318,
	g4=1397,
	g4_=1480,
	g5=1568,
	g5_=1661,
	g6=1760,
	g6_=1865,
	g7=1976,
	yaya=0
};
typedef struct yf
{
enum fy s;
int t;
}yf;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__13D6CB71_AC16_4269_8C67_7678D160E3A3__INCLUDED_)
