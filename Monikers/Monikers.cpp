// Monikers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <shobjidl.h>

void DisplayWindows(IShellWindows* pShell) {
	long count = 0;
	pShell->get_Count(&count);
	for (long i = 0; i < count; i++) {
		CComPtr<IDispatch> spDisp;
		pShell->Item(CComVariant(i), &spDisp);
		CComQIPtr<IWebBrowserApp> spWin(spDisp);
		if (spWin) {
			CComBSTR name;
			spWin->get_LocationName(&name);
			printf("Name: %ws\n", name.m_str);
		}
	}
}

int main() {
	::CoInitialize(nullptr);

	{
		//
		// normal CoCreateInstance
		//
		CComPtr<IShellWindows> spShell;
		auto hr = spShell.CoCreateInstance(__uuidof(ShellWindows));
		if (spShell) {
			DisplayWindows(spShell);
		}
	}

	{
		//
		// normal CoCreateInstance
		//
		CComPtr<IShellWindows> spShell;
		auto hr = ::CoCreateInstance(__uuidof(ShellWindows), nullptr,
			CLSCTX_ALL, __uuidof(IShellWindows),
			reinterpret_cast<void**>(&spShell));
		if (spShell) {
			DisplayWindows(spShell);
		}
	}

	{
		CComPtr<IClassFactory> spCF;
		auto hr = ::CoGetClassObject(__uuidof(ShellWindows),
			CLSCTX_ALL, nullptr, __uuidof(IClassFactory),
			reinterpret_cast<void**>(&spCF));
		if (SUCCEEDED(hr)) {
			CComPtr<IShellWindows> spShell;
			hr = spCF->CreateInstance(nullptr, __uuidof(IShellWindows), reinterpret_cast<void**>(&spShell));
			if (SUCCEEDED(hr)) {
				// use spShell
			}
		}
	}
	{
		//
		// use class moniker
		//
		CComPtr<IMoniker> spClsMoniker;
		CComPtr<IBindCtx> spBindCtx;
		::CreateBindCtx(0, &spBindCtx);
		ULONG eaten;
		CComPtr<IClassFactory> spCF;
		auto hr = ::MkParseDisplayName(
			spBindCtx,
			L"clsid:9BA05972-F6A8-11CF-A442-00A0C90A8F39",
			&eaten, &spClsMoniker);
		if (SUCCEEDED(hr)) {
			spClsMoniker->BindToObject(spBindCtx, nullptr,
				__uuidof(IClassFactory), reinterpret_cast<void**>(&spCF));
			if (SUCCEEDED(hr)) {
				CComPtr<IShellWindows> spShell;
				hr = spCF->CreateInstance(nullptr, __uuidof(IShellWindows), reinterpret_cast<void**>(&spShell));
				if (SUCCEEDED(hr)) {
					DisplayWindows(spShell);
				}
			}
		}
	}
	{
		//
		// use class moniker
		//
		CComPtr<IClassFactory> spCF;
		BIND_OPTS opts{ sizeof(opts) };
		auto hr = ::CoGetObject(L"clsid:9BA05972-F6A8-11CF-A442-00A0C90A8F39",
			&opts, __uuidof(IClassFactory),
			reinterpret_cast<void**>(&spCF));
		if (SUCCEEDED(hr)) {
			CComPtr<IShellWindows> spShell;
			hr = spCF->CreateInstance(nullptr, __uuidof(IShellWindows), reinterpret_cast<void**>(&spShell));
			if (SUCCEEDED(hr)) {
				DisplayWindows(spShell);
			}
		}
	}
}

