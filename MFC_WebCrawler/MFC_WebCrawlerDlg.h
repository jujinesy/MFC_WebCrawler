
// MFC_WebCrawlerDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include <map>
#include <locale.h>


// CMFC_WebCrawlerDlg 대화 상자
class CMFC_WebCrawlerDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC_WebCrawlerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MFC_WEBCRAWLER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_WordList;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnMouse();
	HACCEL m_hAccelTable;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTest();
	void SetClipboard();
	void Clipboard2CString();
	afx_msg void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	void ReadVanWords();
	void WriteVanWords();

	std::map<CString, int> Words;
	std::map<CString, int> VanWords;
	std::map<CString, int>::iterator itMap;
	afx_msg void OnBnClickedButton2();
};
