
// MfcStartDlg.h: 헤더 파일
//

#pragma once


// CMfcStartDlg 대화 상자
class CMfcStartDlg : public CDialogEx
{
private:
	CImage m_image;
	BOOL validImgPos(int x, int y); // img 사각형 안에 들가는지
// 생성입니다.
public:
	CMfcStartDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSTART_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEditNum();
	int m_nNum;
	afx_msg void OnBnClickedImgBtn2();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	void UpdateDIsplay();
	void moveRect();
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	void InitImage();
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	void OnLButtonDown(UINT nFlags, CPoint point);
	void CalculateCircle(CPoint p1, CPoint p2, CPoint p3, CPoint& center, double& radius);
	afx_msg void OnBnClickedBtnRand();
};
