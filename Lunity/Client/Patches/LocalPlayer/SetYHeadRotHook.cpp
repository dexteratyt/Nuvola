#include  "SetYHeadRotHook.h"

//#include "../../Events/UpdateHeadYEvent.h"
#include "../../Events/EventHandler.h"

void __fastcall SetYHeadRotHook::SetYHeadRotHookCallback_1_17_10_4(LocalPlayer* localPlayer, Actor* camera) {
	PLH::FnCast(funcOriginal, &SetYHeadRotHookCallback_1_17_10_4)(localPlayer, camera);
	//UpdateHeadYEvent event(localPlayer, camera);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		//listener->onHeadRotateEvent(event);
	}
}

SetYHeadRotHook::SetYHeadRotHook() : IPatch::IPatch("LocalPlayer::SetYHeadRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? ?? ?? BA"), -1));
}

auto SetYHeadRotHook::Apply() -> bool {
	return this->AutoPatch(&SetYHeadRotHookCallback_1_17_10_4, &funcOriginal);
}