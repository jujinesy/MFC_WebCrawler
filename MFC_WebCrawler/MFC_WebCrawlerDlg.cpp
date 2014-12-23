
// MFC_WebCrawlerDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFC_WebCrawler.h"
#include "MFC_WebCrawlerDlg.h"
#include "afxdialogex.h"
#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_WebCrawlerDlg 대화 상자



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


// CMFC_WebCrawlerDlg 메시지 처리기

BOOL CMFC_WebCrawlerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_hAccelTable = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));
	m_WordList.InsertColumn(0, L"검색단어 결과", LVCFMT_LEFT, 250);
	//m_WordList.InsertColumn(1, L"ㄴㄴㄴ", LVCFMT_LEFT, 70);

	CMFC_WebCrawlerDlg::ReadVanWords();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFC_WebCrawlerDlg::OnPaint()
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
HCURSOR CMFC_WebCrawlerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_WebCrawlerDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetClipboard();
	ShowWindow(false);
	
	ShellExecute(NULL, _T("open"), _T("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"), NULL, NULL, 0);
	Sleep(2000);
	CString pi;
	
	//검색위치
	//SetCursorPos(623, 409);
	//Sleep(100);
	//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);
	//Sleep(100);
	//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, NULL);
	
	//클립보드 있는거 붙여넣기
	Sleep(500);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('V', 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('V', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(100);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

	//검색 엔터
	Sleep(500);
	keybd_event(VK_RETURN, 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

	//관련검색어 클릭
	SetCursorPos(161, 277);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, NULL);

	//클립보드 있는거 붙여넣기
	Sleep(500);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('A', 0, KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event('A', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(100);
	keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

	//클립보드 있는거 붙여넣기
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString pi;
	POINT point;
	GetCursorPos(&point);
	pi.Format(_T("X : %d\nY : %d"), point.x, point.y);
	AfxMessageBox(pi);
}


BOOL CMFC_WebCrawlerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_hAccelTable != NULL)
	{
		if (TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg))
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CMFC_WebCrawlerDlg::OnTest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Clipboard2CString();
}


void CMFC_WebCrawlerDlg::SetClipboard()
{
	CString save_str;
	// 클립보드에 저장할 문자열을 얻는다.
	GetDlgItemText(IDC_EDIT1, save_str);

	HANDLE h_data;         // 클립보드에 사용할 메모리 핸들
	char *p_data = NULL;   // 클립보드에 사용할 메모리 주소

	// 문자열 길이만큼 전역 메모리를 할당한다.
	if (!(h_data = ::GlobalAlloc(GMEM_DDESHARE | GMEM_MOVEABLE, save_str.GetLength()*2 + 2))) return;

	// 할당된 메모리 핸들로부터 실제로 사용 가능한 주소를 얻는다.
	if (!(p_data = (char *)::GlobalLock(h_data))){
		// 주소를 얻는데 실패하면 메모리를 할당해제한다.
		::GlobalFree(h_data);
		return;
	}
	// 할당된 메모리 영역에 삽입할 문자열을 복사한다.
	strcpy_s(p_data, save_str.GetLength()*2 + 2, ATL::CW2AEX<1024>(save_str.GetBuffer(0)));
	if (::OpenClipboard(m_hWnd)){        // 클립보드를 연다.
		::EmptyClipboard();          // 존재하는 데이터를 삭제한다.
		// 클립보드로 데이터를 전달한다.
		::SetClipboardData(CF_TEXT, h_data);
		::CloseClipboard(); // 클립보드를 닫는다.
	}
	// 할당된 메모리 핸들로부터 얻은 사용 가능한 주소를 반환한다.
	::GlobalUnlock(h_data);

	SetDlgItemText(IDC_EDIT1, _T(""));
}

void CMFC_WebCrawlerDlg::Clipboard2CString()
{
	//if (OpenClipboard() == false){
	//	return; // 클립보드를 열지 못했다. 더이상 작업을 진행할 수 없다. 
	//}

	///// 클립 보드 내용을 얻어 가는 부분..
	//// 클립보드의 메모리 공간을 텍스트로 접근 설정.
	//HGLOBAL hglobal = GetClipboardData(CF_TEXT);
	//// 메모리를 잠가 놓고, 
	//LPTSTR lptstr = (LPTSTR)GlobalLock(hglobal);
	//// CString 형 변수를 메모리로부터 만들고, 
	//CString str(lptstr);

	//// begin of program specific jobs 
	//// --- 적당한 작업을 해준다. (여기선 텍스트에 약간의 변형을 줌.
	////str.Replace(L":", L"..");
	////str.Replace(L"\n", L" ");
	////str.Replace(L"\r", L" ");
	////str.Replace(L"  ", L" ");
	////str.Replace(L"/", L"_");
	////str += "\0";
	//// end of program specific jobs.

	//// 변형된 내용을 다시 클립보드로 복사해 넣는 부분의 시작.
	//int length = str.GetLength() + 1;
	//// 메모리 주소를 얻어서, 
	//HGLOBAL hNewTitle = GlobalAlloc(GMEM_MOVEABLE, length);
	//// string 으로 casting 해서 잡아 놓고, 
	//LPTSTR lptstrNewTitle = (LPTSTR)GlobalLock(hNewTitle);
	//// 위에서 수정한 것을 복사해 놓고,
	//CopyMemory(lptstrNewTitle, str.operator LPCTSTR(), length);
	//// 잡았던 메모리를 풀어 준다.
	//GlobalUnlock(hNewTitle);

	//// 클립보드의 기존 데이터를 없애고,
	//EmptyClipboard();
	//// 새로 설정해 놓은 메모리를 클립보들에 밀어 넣는다.
	//SetClipboardData(CF_TEXT, hNewTitle);
	//// 변형된 내용을 다시 클립보드로 복사해 넣는 부분의 끝.


	//// 잡아 놓았던 메모리를 풀어 놓고, 
	//GlobalUnlock(hglobal);
	//// 클립보드를 닫는다.
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

	// 클립보드에 사용가능한 문자열형식의 데이터가 있는지 확인한다.
	if (::IsClipboardFormatAvailable(CF_TEXT) != FALSE){
		// 클립보드를 연다.
		if (OpenClipboard()){
			// 문자열 데이터 핸들을 얻는다.
			h_data = GetClipboardData(CF_TEXT);

			if (h_data != NULL) {
				// 데이터 핸들로부터 사용 가능한 주소를 얻는다.
				p_data = (LPSTR)::GlobalLock(h_data);

				// 클립보드에 있는 문자열을 에디트 박스에 출력한다.
				//SetDlgItemText(IDC_EDIT1, (CString)p_data);

				// 할당된 메모리 핸들로부터 얻은 사용 가능한 주소를 반환한다.
				::GlobalUnlock(h_data);
			}
			// 클립보드를 닫는다.
			CloseClipboard();
		}
	}

	data_str = (CString)p_data;
	data_str.Replace(L"\n", L" ");
	data_str.Replace(L"\r", L" ");

	data_str=data_str.Mid(data_str.Find(L"관련검색:")+6);
	

	LinePos = 0;
	while ((temp = data_str.Tokenize(_T(" "), LinePos)) != "") // 각 구분자로 구분하여 데이터 내용을 가져와 temp에 저장. 
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT1, m_WordList.GetItemText(pNMItemActivate->iItem, 0));
	OnBnClickedButton1();
	*pResult = 0;
}


void CMFC_WebCrawlerDlg::OnNMRClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
	if (file.Open(_T("VanWords.txt"), CFile::modeRead | CFile::typeText)) // 현재 폴더의 test.txt 파일의 내용을 가져온다.
	{
		while (file.ReadString(data_str)) // 파일의 내용을 한 줄씩 읽어서 data_str 에 저장한다.
		{
			LinePos = 0;
			while ((temp = data_str.Tokenize(_T("\n"), LinePos)) != "") // 각 구분자로 구분하여 데이터 내용을 가져와 temp에 저장. 
			{
				VanWords.insert({ temp, 0 });
			}
		}
		file.Close(); // 모든 파일의 내용을 가져왔으면 파일을 닫는다.
	}
	else
	{
		CMFC_WebCrawlerDlg::WriteVanWords();
		MessageBoxW(_T("VanWords.txt 파일이 없습니다.\n기본 파일이 생성되었습니다."));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	MessageBoxW(_T("Resulte.txt로 저장되었습니다."));
}
