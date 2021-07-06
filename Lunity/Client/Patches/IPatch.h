#ifndef LUNITY_CLIENT_PATCHES_IPATCH
#define LUNITY_CLIENT_PATCHES_IPATCH

#include <string>
#include <polyhook2/Detour/x86Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>

#pragma comment(lib,"asmjit.lib")
#pragma comment(lib,"capstone.lib")
#pragma comment(lib,"PolyHook_2.lib")
#pragma comment(lib,"Zydis.lib")
#pragma comment(lib,"Zycore.lib")

class IPatch
{
	static inline PLH::CapstoneDisassembler* dis = new PLH::CapstoneDisassembler(PLH::Mode::x86);
	std::string name;
public:
	IPatch(std::string name);
	auto GetName() -> std::string;
	auto GetDis() -> PLH::CapstoneDisassembler&;
	virtual auto Apply() -> bool;
};

#endif /* LUNITY_CLIENT_PATCHES_IPATCH */
