
// MfcStartDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MfcStart.h"
#include "MfcStartDlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <vector>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#define COLOR_RED RGB(0xff, 0 ,0)
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMfcStartDlg 대화 상자



CMfcStartDlg::CMfcStartDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSTART_DIALOG, pParent)
	, m_nNum(0) //해당 숫자로 초기화
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, m_nNum);
}

BEGIN_MESSAGE_MAP(CMfcStartDlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMfcStartDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_NUM, &CMfcStartDlg::OnEnChangeEditNum)
	ON_BN_CLICKED(IDC_IMG_BTN2, &CMfcStartDlg::OnBnClickedImgBtn2)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CMfcStartDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_LOAD, &CMfcStartDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CMfcStartDlg::OnBnClickedBtnAction)
	ON_EN_CHANGE(IDC_EDIT1, &CMfcStartDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMfcStartDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BTN_RAND, &CMfcStartDlg::OnBnClickedBtnRand)
END_MESSAGE_MAP()


// CMfcStartDlg 메시지 처리기

BOOL CMfcStartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	SetDlgItemText(IDC_STATIC_RESULT, _T("0"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMfcStartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMfcStartDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMfcStartDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcStartDlg::OnBnClickedButton1()
{
	//AfxMessageBox(_T("Hello")); alert 같은거

	//값 99로
	UpdateData(true); // 변수들 저장된 값 가져옴
	m_nNum += 1;
	cout << m_nNum << endl;
	
	UpdateData(false); 


}

void CMfcStartDlg::OnEnChangeEditNum()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMfcStartDlg::OnBnClickedImgBtn2()
{
	InitImage();
	
}

CString g_strFileImage = _T("C:\\image\\save.bmp");
void CMfcStartDlg::OnBnClickedBtnSave()
{
	m_image.Save(g_strFileImage);
}

void CMfcStartDlg::OnBnClickedBtnLoad()
{
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Load(g_strFileImage);
	UpdateDIsplay();
}

void CMfcStartDlg::UpdateDIsplay() 
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0); // 그림의 포지션
}

void CMfcStartDlg::moveRect() {
	static int nSttX = 0;
	static int nSttY = 0; //static이면 이 함수 호출되어도 값을 기억함.
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 20; // 원 크기
	unsigned char* fm = (unsigned char*)m_image.GetBits(); //필드 이미지. 이미지 포인트 줄 때. GetBits() - 첫번째 포인터값 가져옴

	//memset(fm, 0xff, nWidth * nHeight); //그린 기록 지워줌

	drawCircle(fm, nSttX, nSttY, nRadius, 0xff); //그린 기록 지워줌 0xff가 화이트라서.
	drawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray); //원하는 포인터(fm)에 그림. Stt는 스타트.

	//for (int j = nSttY; j < nSttY+48; j++) {
	//	for (int i = nSttX; i < nSttX+64; i++) {
			
			//if(validImgPos(i,j))
			//	fm[j * nPitch + i] = nGray;
	//	}
	//}
	//nSttX++;
	//nSttY++;
	UpdateDIsplay();
	CString strFile;
	strFile.Format(_T("C:\\image\\image%d.jpg"), nSttX);
	m_image.Save(strFile);

}
void CMfcStartDlg::OnBnClickedBtnAction()
{
	for (int i = 0; i < 400; i++) {
		moveRect();
	}
		
}

BOOL CMfcStartDlg::validImgPos(int x, int y) { // img 사각형 안에 들가는지
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight); //MFC 영역에 대한정보

	return rect.PtInRect(CPoint(x, y)); // POINT가 그 안에 들어가냐?  CPOINT는 Point로 바꿔줌

	//if (x > 0 && x <= nWidth) {
	//	bRet = true;
	//}
	//if (y > 0 && y <= nHeight) {
	//	bRet = true;
	//}
	//return bRet;
}

void CMfcStartDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray) {
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if(isInCircle(i, j, nCenterX, nCenterY, nRadius))//원 그릴지 
				fm[j * nPitch + i] = nGray;
		}
	}
}

bool CMfcStartDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius) {
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}

void CMfcStartDlg::InitImage() {
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits(); //필드 이미지. 이미지 포인트 줄 때. GetBits() - 첫번째 포인터값 가져옴

	//아래 반복문 1개와 같음
	memset(fm, 0xff, nWidth * nHeight);


	//for(int j=0;j<nHeight ; j++){
	//	for (int i = 0; i < nWidth; i++) {
	//		//fm[j * nPitch * i] = 255; //하얀색 코드
	//		fm[j * nPitch + i] = j % 255;
	//	}
	//}

	//fm[12 * nPitch + 16] = 0;
	//fm[0 * nPitch + 0] = 255;
	//fm[0 * nPitch + 1] = 255;
	//fm[1 * nPitch + 1] = 255;

	UpdateDIsplay();
}
void CMfcStartDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMfcStartDlg::OnBnClickedButton2()
{
	Invalidate();
	UpdateWindow();
	InitImage();
	static int nSttX = 0;
	static int nSttY = 0; //static이면 이 함수 호출되어도 값을 기억함.
	vector<CPoint> clickPoints; //클릭된 점 저장하는곳
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 20; // 원 크기
	unsigned char* fm = (unsigned char*)m_image.GetBits(); //필드 이미지. 이미지 포인트 줄 때. GetBits() - 첫번째 포인터값 가져옴

	srand(time(0));  // 랜덤 시드 값 설정 (프로그램 시작 시마다 다르게 랜덤 생성)
	for (int i = 0; i < 3; i++) {
		int randomX = rand() % 200 + 100; // 0 ~ 
		int randomY = rand() % 200 + 100; // 0 ~ 
		CPoint point(randomX, randomY);
		clickPoints.push_back(point);
		drawCircle(fm, point.x - nRadius, point.y - nRadius, nRadius, nGray);
		UpdateDIsplay();
	}

	// 세 점을 통해 원의 중심과 반지름을 계산
	CPoint center;
	double radius;
	CalculateCircle(clickPoints[0], clickPoints[1], clickPoints[2], center, radius);

	// CClientDC 객체 생성 (클라이언트 영역에 그리기)
	CClientDC dc(this);

	// 계산된 중심과 반지름으로 원 그리기
	dc.Ellipse(center.x - radius, center.y - radius, center.x + radius, center.y + radius);

	drawCircle(fm, clickPoints[0].x - nRadius, clickPoints[0].y - nRadius, nRadius, nGray);
}

// 마우스 클릭 이벤트 처리
void CMfcStartDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	static int nSttX = 0;
	static int nSttY = 0; //static이면 이 함수 호출되어도 값을 기억함.
	static vector<CPoint> clickPoints; //클릭된 점 저장하는곳
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = 20; // 원 크기
	unsigned char* fm = (unsigned char*)m_image.GetBits(); //필드 이미지. 이미지 포인트 줄 때. GetBits() - 첫번째 포인터값 가져옴

	if (clickPoints.size() == 2) {
		drawCircle(fm, point.x - nRadius, point.y - nRadius, nRadius, nGray);
		UpdateDIsplay();
	}

	clickPoints.push_back(point);

	if (clickPoints.size() == 3) { //점 3개면 정원 그림
		// 세 점을 통해 원의 중심과 반지름을 계산
		CPoint center;
		double radius;
		CalculateCircle(clickPoints[0], clickPoints[1], clickPoints[2], center, radius);

		// CClientDC 객체 생성 (클라이언트 영역에 그리기)
		CClientDC dc(this);

		// 계산된 중심과 반지름으로 원 그리기
		dc.Ellipse(center.x - radius, center.y - radius, center.x + radius, center.y + radius);

		//drawCircle(fm, clickPoints[0].x - nRadius, clickPoints[0].y - nRadius, nRadius, nGray);
	}
	else if(clickPoints.size() < 3) {
		drawCircle(fm, point.x - nRadius, point.y - nRadius, nRadius, nGray);
		UpdateDIsplay();
	}

	CDialogEx::OnLButtonDown(nFlags, point); // 기본 처리 호출

}

void CMfcStartDlg::CalculateCircle(CPoint p1, CPoint p2, CPoint p3, CPoint& center, double& radius)
{
	double x1 = p1.x, y1 = p1.y;
	double x2 = p2.x, y2 = p2.y;
	double x3 = p3.x, y3 = p3.y;

	// 세 점을 지나가는 원의 중심 계산
	double d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
	double ux = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / d;
	double uy = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / d;

	// 원의 중심을 구함
	center.x = static_cast<int>(ux);
	center.y = static_cast<int>(uy);

	// 원의 반지름 계산 (중심과 한 점 사이의 거리)
	radius = sqrt((center.x - x1) * (center.x - x1) + (center.y - y1) * (center.y - y1));
}

void CMfcStartDlg::OnBnClickedBtnRand()
{

}
