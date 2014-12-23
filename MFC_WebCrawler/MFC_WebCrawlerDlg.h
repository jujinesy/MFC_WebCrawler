
// MFC_WebCrawlerDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include <map>
#include <locale.h>


// CMFC_WebCrawlerDlg ��ȭ ����
class CMFC_WebCrawlerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFC_WebCrawlerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MFC_WEBCRAWLER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
