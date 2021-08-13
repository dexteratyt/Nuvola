#ifndef LUNITY_MEM_MEM
#define LUNITY_MEM_MEM
#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include <string>

//Polyhook defines these macros, but its a different definition.
//To solve this, we'll undef polyhooks, then redef at the end.
#ifdef getBits
#define PLH_INCLUDED
#undef INRANGE
#undef getBits
#undef getByte
#endif

#define INRANGE(x,a,b)	(x >= a && x <= b)
#define getBits( x )	(INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )	(getBits(x[0]) << 4 | getBits(x[1]))

#define PI 3.14159265359

class Mem {
public:
    static uintptr_t FindMLvlPtr(uintptr_t, std::vector<unsigned int>);
    static auto FindSig(const char* pattern) -> uintptr_t;
	static auto FindSig(long long rangeStart, long long rangeEnd, const char* pattern) -> uintptr_t;
	static auto getModuleBase() -> long long;
    static auto getModuleBaseHandle() -> HMODULE;
    static auto getBaseModuleSize() -> long long;
    static auto getBaseModuleEnd() -> long long;
	static auto GetThisModule() -> HMODULE;
};

//Re use PLH macros if needed
#ifdef PLH_INCLUDED
#undef INRANGE
#undef getBits
#undef getByte
#include <polyhook2/Misc.hpp>
#endif

#endif /* LUNITY_MEM_MEM */
