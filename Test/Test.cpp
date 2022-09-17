// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "..\MonikerFun\MonikerFun_i.h"

void Test1(DWORD pid) {
	//
	// go through the moniker
	//
	CComPtr<IMoniker> spProcMoniker;
	CComPtr<IBindCtx> spBindCtx;
	::CreateBindCtx(0, &spBindCtx);
	ULONG eaten;
	std::wstring displayName(L"process:");
	displayName += std::to_wstring(pid);
	auto hr = ::MkParseDisplayName(spBindCtx, displayName.c_str(), &eaten, &spProcMoniker);
	if (SUCCEEDED(hr)) {
		CComPtr<IWinProcess> spProcess;
		hr = spProcMoniker->BindToObject(spBindCtx, nullptr, __uuidof(IWinProcess), reinterpret_cast<void**>(&spProcess));
		if (SUCCEEDED(hr)) {
			CComBSTR path;
			if (S_OK == spProcess->get_ImagePath(&path)) {
				printf("Image path: %ws\n", path.m_str);
			}
		}
	}
}

void Test2(DWORD pid) {
	//
	// use CoGetObject
	//
	std::wstring displayName(L"process:");
	displayName += std::to_wstring(pid);
	BIND_OPTS opts{ sizeof(opts) };
	CComPtr<IWinProcess> spProcess;
	auto hr = ::CoGetObject(displayName.c_str(), 
		&opts, __uuidof(IWinProcess), 
		reinterpret_cast<void**>(&spProcess));
	if (SUCCEEDED(hr)) {
		CComBSTR path;
		if (S_OK == spProcess->get_ImagePath(&path)) {
			printf("Image path: %ws\n", path.m_str);
		}
	}
}

void Test3(DWORD pid) {
	//
	// use CoGetObject and terminate process
	//
	std::wstring displayName(L"process:");
	displayName += std::to_wstring(pid);
	BIND_OPTS opts{ sizeof(opts) };
	CComPtr<IWinProcess> spProcess;
	auto hr = ::CoGetObject(displayName.c_str(), &opts, 
		__uuidof(IWinProcess), reinterpret_cast<void**>(&spProcess));
	if (SUCCEEDED(hr)) {
		auto hr = spProcess->Terminate(1);
		if (SUCCEEDED(hr))
			printf("Process %u terminated.\n", pid);
		else
			printf("Error terminating process: hr=0x%X\n", hr);
	}
}

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		printf("Usage: Test <pid>\n");
		return 0;
	}
	::CoInitialize(nullptr);

	Test1(atoi(argv[1]));
	Test2(atoi(argv[1]));
	if(argc > 2)
		Test3(atoi(argv[1]));
	
	::CoUninitialize();

	return 0;
}

