
// MFC_WebCrawler.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFC_WebCrawlerApp:
// �� Ŭ������ ������ ���ؼ��� MFC_WebCrawler.cpp�� �����Ͻʽÿ�.
//

class CMFC_WebCrawlerApp : public CWinApp
{
public:
	CMFC_WebCrawlerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFC_WebCrawlerApp theApp;