
// MakeCircle.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMakeCircleApp:
// See MakeCircle.cpp for the implementation of this class
//

class CMakeCircleApp : public CWinApp
{
public:
	CMakeCircleApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMakeCircleApp theApp;
