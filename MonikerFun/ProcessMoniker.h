// ProcessMoniker.h : Declaration of the CProcessMoniker

#pragma once
#include "resource.h"       // main symbols
#include "MonikerFun_i.h"
#include "MonikerClassFactory.h"

using namespace ATL;

// CProcessMoniker

class ATL_NO_VTABLE CProcessMoniker :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CProcessMoniker, &CLSID_ProcessMoniker>,
	public IMoniker {
public:
	CProcessMoniker() {
	}

	DECLARE_REGISTRY_RESOURCEID(106)

	DECLARE_CLASSFACTORY_EX(CMonikerClassFactory)

	BEGIN_COM_MAP(CProcessMoniker)
		COM_INTERFACE_ENTRY(IMoniker)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct() {
		return S_OK;
	}

	void FinalRelease() {
	}

public:
	// Inherited via IMoniker
	HRESULT __stdcall GetClassID(CLSID* pClassID) override;
	HRESULT __stdcall IsDirty(void) override;
	HRESULT __stdcall Load(IStream* pStm) override;
	HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) override;
	HRESULT __stdcall GetSizeMax(ULARGE_INTEGER* pcbSize) override;
	HRESULT __stdcall BindToObject(IBindCtx* pbc, IMoniker* pmkToLeft, REFIID riidResult, void** ppvResult) override;
	HRESULT __stdcall BindToStorage(IBindCtx* pbc, IMoniker* pmkToLeft, REFIID riid, void** ppvObj) override;
	HRESULT __stdcall Reduce(IBindCtx* pbc, DWORD dwReduceHowFar, IMoniker** ppmkToLeft, IMoniker** ppmkReduced) override;
	HRESULT __stdcall ComposeWith(IMoniker* pmkRight, BOOL fOnlyIfNotGeneric, IMoniker** ppmkComposite) override;
	HRESULT __stdcall Enum(BOOL fForward, IEnumMoniker** ppenumMoniker) override;
	HRESULT __stdcall IsEqual(IMoniker* pmkOtherMoniker) override;
	HRESULT __stdcall Hash(DWORD* pdwHash) override;
	HRESULT __stdcall IsRunning(IBindCtx* pbc, IMoniker* pmkToLeft, IMoniker* pmkNewlyRunning) override;
	HRESULT __stdcall GetTimeOfLastChange(IBindCtx* pbc, IMoniker* pmkToLeft, FILETIME* pFileTime) override;
	HRESULT __stdcall Inverse(IMoniker** ppmk) override;
	HRESULT __stdcall CommonPrefixWith(IMoniker* pmkOther, IMoniker** ppmkPrefix) override;
	HRESULT __stdcall RelativePathTo(IMoniker* pmkOther, IMoniker** ppmkRelPath) override;
	HRESULT __stdcall GetDisplayName(IBindCtx* pbc, IMoniker* pmkToLeft, LPOLESTR* ppszDisplayName) override;
	HRESULT __stdcall ParseDisplayName(IBindCtx* pbc, IMoniker* pmkToLeft, LPOLESTR pszDisplayName, ULONG* pchEaten, IMoniker** ppmkOut) override;
	HRESULT __stdcall IsSystemMoniker(DWORD* pdwMksys) override;

	std::wstring m_DisplayName;
};

OBJECT_ENTRY_AUTO(__uuidof(ProcessMoniker), CProcessMoniker)
