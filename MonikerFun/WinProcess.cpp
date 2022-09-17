// WinProcess.cpp : Implementation of CWinProcess

#include "pch.h"
#include "WinProcess.h"


// CWinProcess

void CWinProcess::SetHandle(HANDLE hProcess) {
	m_hProcess = hProcess;
}

HRESULT CWinProcess::get_Id(DWORD* pId) {
	ATLASSERT(m_hProcess);
	return *pId = ::GetProcessId(m_hProcess), S_OK;
}

HRESULT CWinProcess::get_ImagePath(BSTR* pPath) {
	WCHAR path[MAX_PATH];
	DWORD size = _countof(path);
	if (::QueryFullProcessImageName(m_hProcess, 0, path, &size))
		return CComBSTR(path).CopyTo(pPath);

	return HRESULT_FROM_WIN32(::GetLastError());
}

HRESULT CWinProcess::Terminate(DWORD exitCode) {
	HANDLE hKill;
	if (::DuplicateHandle(::GetCurrentProcess(), m_hProcess, 
		::GetCurrentProcess(), &hKill, PROCESS_TERMINATE, FALSE, 0)) {
		auto success = ::TerminateProcess(hKill, exitCode);
		auto error = ::GetLastError();
		::CloseHandle(hKill);
		return success ? S_OK : HRESULT_FROM_WIN32(error);
	}
	return HRESULT_FROM_WIN32(::GetLastError());
}

