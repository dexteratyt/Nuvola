#ifndef LUNITY_MEM_MEM
#define LUNITY_MEM_MEM
#include <Windows.h>
#include <Psapi.h>
#include <vector>

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

#define PI 3.14159265359

class Mem {
public:
    static uintptr_t FindMLvlPtr(uintptr_t, std::vector<unsigned int>);
    static uintptr_t FindSig(const char*);
};


#endif /* LUNITY_MEM_MEM */
