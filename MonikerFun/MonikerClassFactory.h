#pragma once

class ATL_NO_VTABLE CMonikerClassFactory : 
	public ATL::CComObjectRootEx<ATL::CComMultiThreadModel>,
	public IParseDisplayName {
public:
	BEGIN_COM_MAP(CMonikerClassFactory)
		COM_INTERFACE_ENTRY(IParseDisplayName)
	END_COM_MAP()

	// Inherited via IParseDisplayName
	HRESULT __stdcall ParseDisplayName(IBindCtx* pbc, LPOLESTR pszDisplayName, ULONG* pchEaten, IMoniker** ppmkOut) override;
};

