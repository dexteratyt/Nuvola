#include  "SetYHeadRotHook.h"

void __fastcall SetYHeadRotHook::SetYHeadRotHookCallback_1_17_10_4(LocalPlayer* localPlayer, struct RendererCamera* camera) {
	PLH::FnCast(setYHeadRotHookOriginal, &SetYHeadRotHookCallback_1_17_10_4)(localPlayer, camera);
	localPlayer->SetYHeadRot(0);
}

SetYHeadRotHook::SetYHeadRotHook() : IPatch::IPatch("LocalPlayer::SetYHeadRot") {
	Utils::DebugF("Start SetYHeadRotHook");
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? ?? ?? BA"), -1));
	Utils::DebugF("Sig added");
}

auto SetYHeadRotHook::Apply() -> bool {
	Utils::DebugF("Start apply");
	PLH::CapstoneDisassembler dis = this->GetDis();
	Utils::DebugF("Got dis");

	uintptr_t setYHeadRotHookHookAddr = this->ScanSigs();
	Utils::DebugF("Found addr");
	Utils::DebugF(std::to_string(setYHeadRotHookHookAddr));

	if(setYHeadRotHookHookAddr == 0) {
		Utils::DebugF("Bad addr!");
		return false;
	}

	PLH::x64Detour* detourHook = new PLH::x64Detour((char*)setYHeadRotHookHookAddr, (char*)SetYHeadRotHookCallback_1_17_10_4, &setYHeadRotHookOriginal, dis);
	Utils::DebugF("Created detour");

	if(!detourHook->hook()) {
		Utils::DebugF("Hook fail!");
		return false;
	}

	Utils::DebugF("Hook yes!");
	return true;
}