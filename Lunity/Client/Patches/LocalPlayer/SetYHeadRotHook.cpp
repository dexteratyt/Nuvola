#include  "SetYHeadRotHook.h"

void __fastcall SetYHeadRotHook::SetYHeadRotHookCallback_1_17_10_4(uintptr_t localPlayer, uintptr_t camera) {
	PLH::FnCast(funcOriginal, &SetYHeadRotHookCallback_1_17_10_4)(localPlayer, camera);
	ClientInstance* client = Utils::GetClientInstance();
	if(!client) {
		return;
	}
	if(client->GetAddress() == 0) {
		return;
	}
	Utils::DebugF("Got client");
	LocalPlayer* lPlayer = client->GetLocalPlayer();
	if(lPlayer) {
		Utils::DebugF("Got DynamicLPlayer");
		if(lPlayer->GetAddress() != 0) {
			Utils::DebugF("Got Player");
			lPlayer->SetYHeadRot(0);
			Utils::DebugF("Set rotation");
		}
	}
}

SetYHeadRotHook::SetYHeadRotHook() : IPatch::IPatch("LocalPlayer::SetYHeadRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? ?? ?? BA"), -1));
}

auto SetYHeadRotHook::Apply() -> bool {
	return this->AutoPatch(&SetYHeadRotHookCallback_1_17_10_4, &funcOriginal);
}