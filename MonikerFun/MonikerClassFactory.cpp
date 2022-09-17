#include "pch.h"
#include "MonikerClassFactory.h"
#include "ProcessMoniker.h"

HRESULT __stdcall CMonikerClassFactory::ParseDisplayName(IBindCtx* pbc, LPOLESTR pszDisplayName, ULONG* pchEaten, IMoniker** ppmkOut) {
    auto colon = wcschr(pszDisplayName, L':');
    ATLASSERT(colon);
    if (colon == nullptr)
        return E_INVALIDARG;

    //
    // simplistic, assume all display name consumed
    //
    *pchEaten = (ULONG)wcslen(pszDisplayName);

    CComObject<CProcessMoniker>* pMon;
    auto hr = pMon->CreateInstance(&pMon);
    if (FAILED(hr))
        return hr;

    //
    // provide the process ID
    //
    pMon->m_DisplayName = colon + 1;
    pMon->AddRef();
    hr = pMon->QueryInterface(ppmkOut);
    pMon->Release();
    return hr;
}
