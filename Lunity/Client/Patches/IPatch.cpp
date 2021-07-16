#include "IPatch.h"

IPatch::IPatch(std::string name)
{
    this->name = name;
	this->signatures = new std::vector<SigInfo*>();
}
void IPatch::AddSignature(SigInfo* sigInfo)
{
	this->signatures->push_back(sigInfo);
}
auto IPatch::ScanSigs() -> uintptr_t {
	uintptr_t reqAddr = 0;
	int sigIndex = 0;
	while(reqAddr == 0) {
		if(sigIndex >= this->signatures->size()) {
			Utils::DebugF("Failed to find signature for Patch \""+name+"\"!");
			//Remember to handle this!
			return 0;
		};

		SigInfo* info = signatures->at(sigIndex);
		std::string* sig = info->signature;
		int offset = info->offset;

		reqAddr = Mem::FindSig(sig->c_str());
		//We need to do this, because adding the offset might cause it to not be 0.
		//This is bad because it will break the loop and have a bad memory address returned, resulting in a crash.
		if(reqAddr != 0) {
			reqAddr += offset;
		}
		sigIndex++;
	};

	return reqAddr;
}
auto IPatch::GetName() -> std::string
{
    return this->name;
}
auto IPatch::GetDis() -> PLH::CapstoneDisassembler
{
    return PLH::CapstoneDisassembler(PLH::Mode::x64);
}
auto IPatch::Apply() -> bool
{
    return false;
}
auto IPatch::AutoPatch(void* callbackPtr, uintptr_t* funcOriginal) -> bool {
	PLH::CapstoneDisassembler dis = this->GetDis();

	uintptr_t hookAddr = this->ScanSigs();

	if(hookAddr == 0) {
		return false;
	}

	PLH::x64Detour* detourHook = new PLH::x64Detour((char*)hookAddr, (char*)callbackPtr, (uint64_t*)funcOriginal, dis);

	if(!detourHook->hook()) {
		return false;
	}

	return true;
}