// WinProcess.h : Declaration of the CWinProcess

#pragma once
#include "resource.h"       // main symbols
#include "MonikerFun_i.h"

using namespace ATL;
// CWinProcess

class ATL_NO_VTABLE CWinProcess :
	public CComObjectRootEx<CComMultiThreadModel>,
	public IDispatchImpl<IWinProcess> {
public:
	CWinProcess() {
	}

	DECLARE_NO_REGISTRY()

	BEGIN_COM_MAP(CWinProcess)
		COM_INTERFACE_ENTRY(IWinProcess)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct() {
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease() {
		m_pUnkMarshaler.Release();
		if (m_hProcess)
			::CloseHandle(m_hProcess);
	}

	void SetHandle(HANDLE hProcess);

private:
	HANDLE m_hProcess{ nullptr };
	CComPtr<IUnknown> m_pUnkMarshaler;

	// Inherited via IWinProcess
	HRESULT get_Id(DWORD* pId);
	HRESULT get_ImagePath(BSTR* path);
	HRESULT Terminate(DWORD exitCode);

};

//OBJECT_ENTRY_AUTO(__uuidof(WinProcess), CWinProcess)
