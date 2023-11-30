
// MakeCircleDlg.h : header file
//

#pragma once
#include "CDlgImage.h"


// CMakeCircleDlg dialog
class CMakeCircleDlg : public CDialogEx
{
// Construction
public:
	CMakeCircleDlg(CWnd* pParent = nullptr);	// standard constructor

	CDlgImage* m_pDlgImage;
	int nDiam = 50;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAKECIRCLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnCircle();

	void init();
	void configDlgItems(CWnd* wnd, int left, int top, int width, int height);
};
