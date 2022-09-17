// ProcessMoniker.cpp : Implementation of CProcessMoniker

#include "pch.h"
#include "ProcessMoniker.h"
#include "WinProcess.h"

// CProcessMoniker

HRESULT __stdcall CProcessMoniker::GetClassID(CLSID* pClassID) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::IsDirty(void) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::Load(IStream* pStm) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::Save(IStream* pStm, BOOL fClearDirty) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::GetSizeMax(ULARGE_INTEGER* pcbSize) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::BindToObject(IBindCtx* pbc, IMoniker* pmkToLeft, REFIID riidResult, void** ppvResult) {
	auto pid = std::stoul(m_DisplayName);
	auto hProcess = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
	if (!hProcess)
	    return HRESULT_FROM_WIN32(::GetLastError());

	CComObject<CWinProcess>* pProcess;
	auto hr = pProcess->CreateInstance(&pProcess);
	pProcess->SetHandle(hProcess);
	pProcess->AddRef();
	
	hr = pProcess->QueryInterface(riidResult, ppvResult);
	pProcess->Release();
	return hr;
}

HRESULT __stdcall CProcessMoniker::BindToStorage(IBindCtx* pbc, IMoniker* pmkToLeft, REFIID riid, void** ppvObj) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::Reduce(IBindCtx* pbc, DWORD dwReduceHowFar, IMoniker** ppmkToLeft, IMoniker** ppmkReduced) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::ComposeWith(IMoniker* pmkRight, BOOL fOnlyIfNotGeneric, IMoniker** ppmkComposite) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::Enum(BOOL fForward, IEnumMoniker** ppenumMoniker) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::IsEqual(IMoniker* pmkOtherMoniker) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::Hash(DWORD* pdwHash) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::IsRunning(IBindCtx* pbc, IMoniker* pmkToLeft, IMoniker* pmkNewlyRunning) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::GetTimeOfLastChange(IBindCtx* pbc, IMoniker* pmkToLeft, FILETIME* pFileTime) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::Inverse(IMoniker** ppmk) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::CommonPrefixWith(IMoniker* pmkOther, IMoniker** ppmkPrefix) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::RelativePathTo(IMoniker* pmkOther, IMoniker** ppmkRelPath) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::GetDisplayName(IBindCtx* pbc, IMoniker* pmkToLeft, LPOLESTR* ppszDisplayName) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::ParseDisplayName(IBindCtx* pbc, IMoniker* pmkToLeft, LPOLESTR pszDisplayName, ULONG* pchEaten, IMoniker** ppmkOut) {
	return E_NOTIMPL;
}

HRESULT __stdcall CProcessMoniker::IsSystemMoniker(DWORD* pdwMksys) {
	*pdwMksys = FALSE;
	return S_OK;
}
