

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for MonikerFun.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MonikerFun_i_h__
#define __MonikerFun_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IWinProcess_FWD_DEFINED__
#define __IWinProcess_FWD_DEFINED__
typedef interface IWinProcess IWinProcess;

#endif 	/* __IWinProcess_FWD_DEFINED__ */


#ifndef __ProcessMoniker_FWD_DEFINED__
#define __ProcessMoniker_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProcessMoniker ProcessMoniker;
#else
typedef struct ProcessMoniker ProcessMoniker;
#endif /* __cplusplus */

#endif 	/* __ProcessMoniker_FWD_DEFINED__ */


#ifndef __IWinProcess_FWD_DEFINED__
#define __IWinProcess_FWD_DEFINED__
typedef interface IWinProcess IWinProcess;

#endif 	/* __IWinProcess_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IWinProcess_INTERFACE_DEFINED__
#define __IWinProcess_INTERFACE_DEFINED__

/* interface IWinProcess */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWinProcess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3ab0471f-2635-429d-95e9-f2baede2859e")
    IWinProcess : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ DWORD *pId) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ImagePath( 
            /* [retval][out] */ BSTR *path) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Terminate( 
            /* [in] */ DWORD exitCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWinProcessVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWinProcess * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWinProcess * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWinProcess * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWinProcess * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWinProcess * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWinProcess * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWinProcess * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IWinProcess, get_Id)
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Id )( 
            IWinProcess * This,
            /* [retval][out] */ DWORD *pId);
        
        DECLSPEC_XFGVIRT(IWinProcess, get_ImagePath)
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ImagePath )( 
            IWinProcess * This,
            /* [retval][out] */ BSTR *path);
        
        DECLSPEC_XFGVIRT(IWinProcess, Terminate)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IWinProcess * This,
            /* [in] */ DWORD exitCode);
        
        END_INTERFACE
    } IWinProcessVtbl;

    interface IWinProcess
    {
        CONST_VTBL struct IWinProcessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWinProcess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWinProcess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWinProcess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWinProcess_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWinProcess_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWinProcess_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWinProcess_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWinProcess_get_Id(This,pId)	\
    ( (This)->lpVtbl -> get_Id(This,pId) ) 

#define IWinProcess_get_ImagePath(This,path)	\
    ( (This)->lpVtbl -> get_ImagePath(This,path) ) 

#define IWinProcess_Terminate(This,exitCode)	\
    ( (This)->lpVtbl -> Terminate(This,exitCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWinProcess_INTERFACE_DEFINED__ */



#ifndef __MonikerFunLib_LIBRARY_DEFINED__
#define __MonikerFunLib_LIBRARY_DEFINED__

/* library MonikerFunLib */
/* [version][uuid] */ 



EXTERN_C const IID LIBID_MonikerFunLib;

EXTERN_C const CLSID CLSID_ProcessMoniker;

#ifdef __cplusplus

class DECLSPEC_UUID("6ea3a80e-2936-43be-8725-2e95896da9a4")
ProcessMoniker;
#endif
#endif /* __MonikerFunLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


