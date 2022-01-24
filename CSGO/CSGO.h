// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CSGO_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CSGO_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CSGO_EXPORTS
#define CSGO_API __declspec(dllexport)
#else
#define CSGO_API __declspec(dllimport)
#endif

// This class is exported from the dll
class CSGO_API CCSGO {
public:
	CCSGO(void);
	// TODO: add your methods here.
};

extern CSGO_API int nCSGO;

CSGO_API int fnCSGO(void);
