# Microsoft Developer Studio Project File - Name="deskClock" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=deskClock - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "deskClock.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "deskClock.mak" CFG="deskClock - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "deskClock - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "deskClock - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "deskClock - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "deskClock - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "deskClock - Win32 Release"
# Name "deskClock - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AlarmSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BackSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BeepSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ClockDate.cpp
# End Source File
# Begin Source File

SOURCE=.\ClockHand.cpp
# End Source File
# Begin Source File

SOURCE=.\ClockNum.cpp
# End Source File
# Begin Source File

SOURCE=.\ClockScale.cpp
# End Source File
# Begin Source File

SOURCE=.\DateSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\deskClock.cpp
# End Source File
# Begin Source File

SOURCE=.\deskClock.rc
# End Source File
# Begin Source File

SOURCE=.\deskClockDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HandSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NumTimeSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ScaleSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SystemTimeSetDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AlarmSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\BackSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\BeepSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\ClockDate.h
# End Source File
# Begin Source File

SOURCE=.\ClockHand.h
# End Source File
# Begin Source File

SOURCE=.\ClockNum.h
# End Source File
# Begin Source File

SOURCE=.\ClockScale.h
# End Source File
# Begin Source File

SOURCE=.\DateSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\deskClock.h
# End Source File
# Begin Source File

SOURCE=.\deskClockDlg.h
# End Source File
# Begin Source File

SOURCE=.\HandSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\NumTimeSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ScaleSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SystemTimeSetDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=".\res\da98262e7cb2487c4ec22665¸±±¾.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\deskClock.ico
# End Source File
# Begin Source File

SOURCE=.\res\deskClock.rc2
# End Source File
# Begin Source File

SOURCE=.\log.bmp
# End Source File
# Begin Source File

SOURCE=".\±³¾°.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
