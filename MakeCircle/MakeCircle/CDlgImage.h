#pragma once
#include "afxdialogex.h"


// CDlgImage dialog

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgImage();

	CWnd* m_pParent;
	CImage m_image;
	BOOL bDrawCircle = FALSE;

	int left=0;
	int top=0;
	int right=50;
	int bottom=50;
	int CenterX=25;
	int CenterY=25;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgImage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();

	void drawData(CDC* pDC);
	void drawInnerCircle(CDC* pDC);
	void init();
};
