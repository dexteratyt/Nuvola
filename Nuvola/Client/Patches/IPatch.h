#ifndef NUVOLA_CLIENT_PATCHES_IPATCH
#define NUVOLA_CLIENT_PATCHES_IPATCH

#include <string>
#include <polyhook2/Detour/x64Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>

#include "../../Mem/SigInfo.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"

class IPatch
{
	//The main disasembler
	static inline PLH::CapstoneDisassembler* dis = new PLH::CapstoneDisassembler(PLH::Mode::x64);

	//Patch metadata
	std::string name;
	std::vector<SigInfo*>* signatures;

	//PLH
	PLH::x64Detour* detourHook;
public:
	IPatch(std::string name);
	virtual ~IPatch();
	//Not using AutoPatch? You'll have to clean up
	//your mess alone! Here's a func to let IPatch know
	//you've got it alone.
	virtual auto ManualCleanup() -> bool;
	//When adding sigs, the first added have priority.
	//Order matters, older version sigs might work on new versions
	//but result in the wrong func or bad memory
	void AddSignature(SigInfo* sigInfo);
	//Scans all sigs in the order
	auto ScanSigs() -> uintptr_t;
	//The patches name
	auto GetName() -> std::string;
	//Returns the polyhook disassembler. You might not need this.
	auto GetDis() -> PLH::CapstoneDisassembler;
	//Actually apply the hook
	virtual auto Apply() -> bool;
	//Use polyhook to hook the function
	auto AutoPatch(void* callback, uintptr_t* original) -> bool;
};

#endif /* NUVOLA_CLIENT_PATCHES_IPATCH */
