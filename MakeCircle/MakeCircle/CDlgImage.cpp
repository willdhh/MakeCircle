// CDlgImage.cpp : implementation file
//

#include "pch.h"
#include "MakeCircle.h"
#include "afxdialogex.h"
#include "CDlgImage.h"
#include "iostream"

//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

using namespace std;

// CDlgImage dialog

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage message handlers


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	init();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}
	drawData(&dc);
}

void CDlgImage::init() {

	int nWidth = 4096;
	int nHeight = 4096;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
	
}

#define COLOR_RED RGB(0xff,0x00,0x00)
#define COLOR_GREEN RGB(0x00,0xff,0x00)
#define COLOR_BLUE RGB(0x00,0x00,0xff)
#define COLOR_YELLOW RGB(0xff,0xff,0x00)
void CDlgImage::drawData(CDC* pDC) {

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);
	
	CRect rectOutCirc;

	CPen redPen;
	redPen.CreatePen(PS_SOLID, 2, COLOR_RED);
	CPen* pRedPen = pDC->SelectObject(&redPen);


	if (bDrawCircle) {
	
		rectOutCirc.SetRect(nLeft, nTop, nRight, nBottom);

		pDC->Ellipse(rectOutCirc);

		drawInnerCircle(pDC);	
	}
		pDC->SelectObject(pRedPen);

}

void CDlgImage::drawInnerCircle(CDC* pDC) {

	CPen bluePen;
	bluePen.CreatePen(PS_SOLID, 2, COLOR_YELLOW);
	CPen* pBluePen = pDC->SelectObject(&bluePen);

	CRect rectCent;
	rectCent.SetRect(nCenterX - (nInnerDiam*2), nCenterY - (nInnerDiam * 2), nCenterX + (nInnerDiam * 2)0, nCenterY + (nInnerDiam * 2));
	pDC->Ellipse(rectCent);
	for (int j = -nInnerDiam; nInnerDiam <= 5; j++) {

		pDC->SetPixel(nCenterX, nCenterY + j, 0);
		pDC->SetPixel(nCenterX + j, nCenterY, 0);

		//pDC->MoveTo(CenterX-5, CenterY);
		//pDC->LineTo(CenterX+4, CenterY);
		//pDC->MoveTo(CenterX, CenterY-5);
		//pDC->LineTo(CenterX, CenterY+4);	

	}
	//cout << "CenterX: \t" << CenterX << endl;
	//cout << "CenterY: \t" <<CenterY << endl;
	pDC->SelectObject(pBluePen);
}