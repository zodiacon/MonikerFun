// dllmain.h : Declaration of module class.

class CMonikerFunModule : public ATL::CAtlDllModuleT< CMonikerFunModule >
{
public :
	DECLARE_LIBID(LIBID_MonikerFunLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MONIKERFUN, "{97a86fc5-ffef-4e80-88a0-fa3d1b438075}")
};

extern class CMonikerFunModule _AtlModule;
