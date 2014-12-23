
// MFC_WebCrawlerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFC_WebCrawler.h"
#include "MFC_WebCrawlerDlg.h"
#include "afxdialogex.h"
#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_WebCrawlerDlg ��ȭ ����



CMFC_WebCrawlerDlg::CMFC_WebCrawlerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_WebCrawlerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_WebCrawlerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_WordList);
}

BEGIN_MESSAGE_MAP(CMFC_WebCrawlerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_WebCrawlerDlg::OnBnClickedButton1)
	ON_COMMAND(IDC_MOUSEs, &CMFC_WebCrawlerDlg::OnMouse)
	ON_COMMAND(ID_TEST, &CMFC_WebCrawlerDlg::OnTest)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CMFC_WebCrawlerDlg::OnNMDblclkList2)
	ON_NOTIFY(NM_RCLICK, IDC_LIST2, &CMFC_WebCrawlerDlg::OnNMRClickList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_WebCrawlerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFC_WebCrawlerDlg �޽��� ó����

BOOL CMFC_WebCrawlerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_hAccelTable = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));
	m_WordList.InsertColumn(0, L"�˻��ܾ� ���", LVCFMT_LEFT, 250);
	//m_WordList.InsertColumn(1, L"������", LVCFMT_LEFT, 70);

	CMFC_WebCrawlerDlg::ReadVanWords();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFC_WebCrawlerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFC_WebCrawlerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_WebCrawlerDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetClipboard();
	ShowWindow(false);
	
	ShellExecute(NULL, _T("open"), _T("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"), NULL, NULL, 0);
	Sleep(2000);
	CString pi;
	
	//�˻���ġ
	//SetCursorPos(623, 409);
	//Sleep(100);
	//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);
	//Sleep(100);
	//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, NULL);
	
	//Ŭ������ �ִ°� �ٿ��ֱ�
	Sleep(500);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('V', 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('V', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(100);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

	//�˻� ����
	Sleep(500);
	keybd_event(VK_RETURN, 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

	//���ð˻��� Ŭ��
	SetCursorPos(161, 277);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, NULL);

	//Ŭ������ �ִ°� �ٿ��ֱ�
	Sleep(500);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('A', 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('A', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(100);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

	//Ŭ������ �ִ°� �ٿ��ֱ�
	Sleep(500);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('C', 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('C', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(100);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

	SetCursorPos(161, 277);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, NULL);

	Clipboard2CString();


	ShowWindow(true);
}

void CMFC_WebCrawlerDlg::OnMouse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CString pi;
	POINT point;
	GetCursorPos(&point);
	pi.Format(_T("X : %d\nY : %d"), point.x, point.y);
	AfxMessageBox(pi);
}


BOOL CMFC_WebCrawlerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (m_hAccelTable != NULL)
	{
		if (TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg))
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CMFC_WebCrawlerDlg::OnTest()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	Clipboard2CString();
}


void CMFC_WebCrawlerDlg::SetClipboard()
{
	CString save_str;
	// Ŭ�����忡 ������ ���ڿ��� ��´�.
	GetDlgItemText(IDC_EDIT1, save_str);

	HANDLE h_data;         // Ŭ�����忡 ����� �޸� �ڵ�
	char *p_data = NULL;   // Ŭ�����忡 ����� �޸� �ּ�

	// ���ڿ� ���̸�ŭ ���� �޸𸮸� �Ҵ��Ѵ�.
	if (!(h_data = ::GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE, save_str.GetLength()*2 + 2))) return;

	// �Ҵ�� �޸� �ڵ�κ��� ������ ��� ������ �ּҸ� ��´�.
	if (!(p_data = (char *)::GlobalLock(h_data))){
		// �ּҸ� ��µ� �����ϸ� �޸𸮸� �Ҵ������Ѵ�.
		::GlobalFree(h_data);
		return;
	}
	// �Ҵ�� �޸� ������ ������ ���ڿ��� �����Ѵ�.
	strcpy_s(p_data, save_str.GetLength()*2 + 2, ATL::CW2AEX<1024>(save_str.GetBuffer(0)));
	if (::OpenClipboard(m_hWnd)){        // Ŭ�����带 ����.
		::EmptyClipboard();          // �����ϴ� �����͸� �����Ѵ�.
		// Ŭ������� �����͸� �����Ѵ�.
		::SetClipboardData(CF_TEXT, h_data);
		::CloseClipboard(); // Ŭ�����带 �ݴ´�.
	}
	// �Ҵ�� �޸� �ڵ�κ��� ���� ��� ������ �ּҸ� ��ȯ�Ѵ�.
	::GlobalUnlock(h_data);

	SetDlgItemText(IDC_EDIT1, _T(""));
}

void CMFC_WebCrawlerDlg::Clipboard2CString()
{
	//if (OpenClipboard() == false){
	//	return; // Ŭ�����带 ���� ���ߴ�. ���̻� �۾��� ������ �� ����. 
	//}

	///// Ŭ�� ���� ������ ��� ���� �κ�..
	//// Ŭ�������� �޸� ������ �ؽ�Ʈ�� ���� ����.
	//HGLOBAL hglobal = GetClipboardData(CF_TEXT);
	//// �޸𸮸� �ᰡ ����, 
	//LPTSTR lptstr = (LPTSTR)GlobalLock(hglobal);
	//// CString �� ������ �޸𸮷κ��� �����, 
	//CString str(lptstr);

	//// begin of program specific jobs 
	//// --- ������ �۾��� ���ش�. (���⼱ �ؽ�Ʈ�� �ణ�� ������ ��.
	////str.Replace(L":", L"..");
	////str.Replace(L"\n", L" ");
	////str.Replace(L"\r", L" ");
	////str.Replace(L"  ", L" ");
	////str.Replace(L"/", L"_");
	////str += "\0";
	//// end of program specific jobs.

	//// ������ ������ �ٽ� Ŭ������� ������ �ִ� �κ��� ����.
	//int length = str.GetLength() + 1;
	//// �޸� �ּҸ� ��, 
	//HGLOBAL hNewTitle = GlobalAlloc(GMEM_MOVEABLE, length);
	//// string ���� casting �ؼ� ��� ����, 
	//LPTSTR lptstrNewTitle = (LPTSTR)GlobalLock(hNewTitle);
	//// ������ ������ ���� ������ ����,
	//CopyMemory(lptstrNewTitle, str.operator LPCTSTR(), length);
	//// ��Ҵ� �޸𸮸� Ǯ�� �ش�.
	//GlobalUnlock(hNewTitle);

	//// Ŭ�������� ���� �����͸� ���ְ�,
	//EmptyClipboard();
	//// ���� ������ ���� �޸𸮸� Ŭ�����鿡 �о� �ִ´�.
	//SetClipboardData(CF_TEXT, hNewTitle);
	//// ������ ������ �ٽ� Ŭ������� ������ �ִ� �κ��� ��.


	//// ��� ���Ҵ� �޸𸮸� Ǯ�� ����, 
	//GlobalUnlock(hglobal);
	//// Ŭ�����带 �ݴ´�.
	//CloseClipboard();




	//if (!OpenClipboard())
	//{
	//	AfxMessageBox(_T("Cannot open the Clipboard"));
	//	return;
	//}
	//// Remove the current Clipboard contents
	//if (!EmptyClipboard())
	//{
	//	AfxMessageBox(_T("Cannot empty the Clipboard"));
	//	return;
	//}
	//// Set Data
	//size_t size = (strComp.GetLength() * 2) + 2;
	//HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, size);
	//if (hMem)
	//{
	//	LPSTR pClipData = (LPSTR)GlobalLock(hMem);
	//	pClipData[0] = 0;
	//	strncpy(pClipData, ATL::CW2AEX<1024>(strComp.GetBuffer(0)), size);
	//	if (::SetClipboardData(CF_OEMTEXT, hMem) == NULL)
	//	{
	//		AfxMessageBox(_T("Unable to set Clipboard data"));
	//		GlobalUnlock(hMem);
	//		GlobalFree(hMem);
	//		CloseClipboard();
	//		return;
	//	}
	//	GlobalUnlock(hMem);
	//	GlobalFree(hMem);
	//}
	//CloseClipboard();


	int LinePos = 0, WordPos = 0;
	CString data_str, temp;
	HANDLE h_data;
	LPSTR p_data = NULL;
	LVITEM lvItem;
	int nIndex;

	// Ŭ�����忡 ��밡���� ���ڿ������� �����Ͱ� �ִ��� Ȯ���Ѵ�.
	if (::IsClipboardFormatAvailable(CF_TEXT) != FALSE){
		// Ŭ�����带 ����.
		if (OpenClipboard()){
			// ���ڿ� ������ �ڵ��� ��´�.
			h_data = GetClipboardData(CF_TEXT);

			if (h_data != NULL) {
				// ������ �ڵ�κ��� ��� ������ �ּҸ� ��´�.
				p_data = (LPSTR)::GlobalLock(h_data);

				// Ŭ�����忡 �ִ� ���ڿ��� ����Ʈ �ڽ��� ����Ѵ�.
				//SetDlgItemText(IDC_EDIT1, (CString)p_data);

				// �Ҵ�� �޸� �ڵ�κ��� ���� ��� ������ �ּҸ� ��ȯ�Ѵ�.
				::GlobalUnlock(h_data);
			}
			// Ŭ�����带 �ݴ´�.
			CloseClipboard();
		}
	}

	data_str = (CString)p_data;
	data_str.Replace(L"\n", L" ");
	data_str.Replace(L"\r", L" ");

	data_str=data_str.Mid(data_str.Find(L"���ð˻�:")+6);
	

	LinePos = 0;
	while ((temp = data_str.Tokenize(_T(" "), LinePos)) != "") // �� �����ڷ� �����Ͽ� ������ ������ ������ temp�� ����. 
	{
		for (itMap = VanWords.begin(); itMap != VanWords.end(); itMap++)
		{
			if (!(itMap->first).Compare(temp))
				goto skip;
		}
		Words.insert({ temp, 0 });
	skip:;
	}

	m_WordList.DeleteAllItems();
	for (itMap = Words.begin(); itMap != Words.end(); itMap++)
	{		
		nIndex = m_WordList.GetItemCount();
		ZeroMemory(&lvItem, sizeof(lvItem));
		lvItem.mask = LVIF_TEXT | LVIF_PARAM;
		lvItem.iItem = nIndex;
		lvItem.iSubItem = 0;
		lvItem.pszText = (LPWSTR)(LPCWSTR)(itMap->first);
		m_WordList.InsertItem(&lvItem);
		//m_WordList.SetItemText(nIndex, 1, L"dd");
	}
}

void CMFC_WebCrawlerDlg::OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT1, m_WordList.GetItemText(pNMItemActivate->iItem, 0));
	OnBnClickedButton1();
	*pResult = 0;
}


void CMFC_WebCrawlerDlg::OnNMRClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//map<int, data> mapData;
	//map<int, data>::iterator it;

	itMap = Words.begin();
	while (itMap != Words.end())
	{
		if (!(itMap->first).Compare(m_WordList.GetItemText(pNMItemActivate->iItem, 0)))
			Words.erase(itMap++);
		else
			itMap++;
	}
	VanWords.insert({ m_WordList.GetItemText(pNMItemActivate->iItem, 0), 0 });
	m_WordList.DeleteItem(pNMItemActivate->iItem);
	CMFC_WebCrawlerDlg::WriteVanWords();
	*pResult = 0;
}


void CMFC_WebCrawlerDlg::ReadVanWords()
{
	CStdioFile file;
	CString data_str;
	CString temp;
	CString result;
	int LinePos = 0, WordPos = 0;

	setlocale(LC_ALL, "korean");
	if (file.Open(_T("VanWords.txt"), CFile::modeRead | CFile::typeText)) // ���� ������ test.txt ������ ������ �����´�.
	{
		while (file.ReadString(data_str)) // ������ ������ �� �پ� �о data_str �� �����Ѵ�.
		{
			LinePos = 0;
			while ((temp = data_str.Tokenize(_T("\n"), LinePos)) != "") // �� �����ڷ� �����Ͽ� ������ ������ ������ temp�� ����. 
			{
				VanWords.insert({ temp, 0 });
			}
		}
		file.Close(); // ��� ������ ������ ���������� ������ �ݴ´�.
	}
	else
	{
		CMFC_WebCrawlerDlg::WriteVanWords();
		MessageBoxW(_T("VanWords.txt ������ �����ϴ�.\n�⺻ ������ �����Ǿ����ϴ�."));
	}
}


void CMFC_WebCrawlerDlg::WriteVanWords()
{
	CStdioFile file;
	file.Open(_T("VanWords.txt"), CFile::modeCreate | CFile::modeWrite);

	CString save, temp;
	save.Format(_T(""));
	for (itMap = VanWords.begin(); itMap != VanWords.end(); itMap++)
	{
		temp.Format(_T("%s\n"), itMap->first); save = save + temp;
	}
	file.WriteString(save);
	file.Close();
}


void CMFC_WebCrawlerDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CStdioFile file;
	file.Open(_T("Resulte.txt"), CFile::modeCreate | CFile::modeWrite);

	CString save, temp;
	save.Format(_T(""));
	for (itMap = Words.begin(); itMap != Words.end(); itMap++)
	{
		temp.Format(_T("%s\n"), itMap->first); save = save + temp;
	}
	file.WriteString(save);
	file.Close();
	MessageBoxW(_T("Resulte.txt�� ����Ǿ����ϴ�."));
}
