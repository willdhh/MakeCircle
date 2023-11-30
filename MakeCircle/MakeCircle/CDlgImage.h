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

	int nLeft=0;
	int nTop=0;
	int nRight=50;
	int nBottom=50;
	int nCenterX=25;
	int nCenterY=25;

	int nInnerDiam = 5;

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
