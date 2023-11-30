
// MakeCircleDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MakeCircle.h"
#include "MakeCircleDlg.h"
#include "afxdialogex.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

using namespace std;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMakeCircleDlg dialog



CMakeCircleDlg::CMakeCircleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAKECIRCLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMakeCircleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RAD, nDiam);
}

BEGIN_MESSAGE_MAP(CMakeCircleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(ID_BTN_CIRCLE, &CMakeCircleDlg::OnBnClickedBtnCircle)
END_MESSAGE_MAP()


// CMakeCircleDlg message handlers

BOOL CMakeCircleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	init();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMakeCircleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMakeCircleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMakeCircleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMakeCircleDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	if (m_pDlgImage)
		delete m_pDlgImage;

}

void CMakeCircleDlg::init(){
	CRect rectClient;

	CWnd* rad = GetDlgItem(IDC_TEXT_RAD);

	int nBorderPadding = 20;
	int nWindowWidth = 1024;
	int nWindowHeight = 1024;

	MoveWindow(0, 0, nWindowWidth, nWindowHeight);
	this->GetClientRect(&rectClient);

	int nClientWidth = rectClient.Width() - 2 * nBorderPadding;
	int nClientHeight = rectClient.Height() - 2 * nBorderPadding;

	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_CDlgImage, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(nBorderPadding, nBorderPadding, nClientWidth, nClientHeight * 0.8);


	configDlgItems(
		GetDlgItem(ID_BTN_CIRCLE),
		nBorderPadding,
		nClientHeight * 0.9 + nBorderPadding,
		nClientWidth,
		nClientHeight * 0.1);

	//configDlgItems(
	//	GetDlgItem(IDC_EDIT_RAD),
	//	nBorderPadding,
	//	nClientHeight * 0.80 + 2 * nBorderPadding,
	//	nClientWidth * 0.2,
	//	nClientHeight * 0.1 - 2 * nBorderPadding);

	configDlgItems(
		GetDlgItem(IDC_EDIT_RAD),
		nBorderPadding,
		nClientHeight * 0.80 + 2 * nBorderPadding + (0.1 * nClientHeight - 2 * nBorderPadding - 20) / 2,
		nClientWidth * 0.2,
		20);


	configDlgItems(
		GetDlgItem(IDC_TEXT_CENTERX),
		nBorderPadding + nClientWidth * 0.25,
		nClientHeight * 0.80 + 2 * nBorderPadding,
		nClientWidth * 0.25,
		nClientHeight * 0.1 - 2 * nBorderPadding);

	configDlgItems(
		GetDlgItem(IDC_TEXT_CENTERY),
		nBorderPadding + nClientWidth * 0.5,
		nClientHeight * 0.80 + 2 * nBorderPadding,
		nClientWidth * 0.25,
		nClientHeight * 0.1 - 2 * nBorderPadding);

	configDlgItems(
		GetDlgItem(IDC_TEXT_RAD),
		nBorderPadding + nClientWidth * 0.75,
		nClientHeight * 0.80 + 2 * nBorderPadding,
		nClientWidth * 0.25,
		nClientHeight * 0.1 - 2 * nBorderPadding);
}

void CMakeCircleDlg::OnBnClickedBtnCircle()
{
	UpdateData();

	CRect rect;
	m_pDlgImage->GetWindowRect(&rect);

	CString strRad;
	CString strCenterX;
	CString strCenterY;

	int left;
	int top;

	if ((rect.Width() - nDiam) == 0) {
		left = 0;
	} else {
		left = rand() % (rect.Width() - nDiam);
	}
	if ((rect.Height() - nDiam) == 0) {
		top = 0;
	}
	else {
		top = rand() % (rect.Height() - nDiam);
	}

	int right = left + nDiam;
	int bottom = top + nDiam;
	int CenterX = nDiam / 2 + left;
	int CenterY = nDiam / 2 + top;

	m_pDlgImage->bDrawCircle = TRUE;
	m_pDlgImage->nLeft = left;
	m_pDlgImage->nRight = right;
	m_pDlgImage->nTop = top;
	m_pDlgImage->nBottom = bottom;
	m_pDlgImage->nCenterX = CenterX;
	m_pDlgImage->nCenterY = CenterY;

	m_pDlgImage->Invalidate();
	
	strCenterX.Format(_T("Center X: %d"), CenterX);
	strCenterY.Format(_T("Center Y: %d"), CenterY);
	strRad.Format(_T("Diameter: %d"), nDiam);

	SetDlgItemText(IDC_TEXT_CENTERX, strCenterX);
	SetDlgItemText(IDC_TEXT_CENTERY, strCenterY);
	SetDlgItemText(IDC_TEXT_RAD, strRad);
}

void CMakeCircleDlg::configDlgItems(CWnd* wnd, int left, int top, int width, int height) {
	wnd->MoveWindow(
		left,
		top,
		width,
		height);
}