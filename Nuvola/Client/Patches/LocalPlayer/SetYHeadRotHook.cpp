#include  "SetYHeadRotHook.h"

#include "../../Events/ActorRotateEvent.h"
#include "../../Events/EventHandler.h"

void __fastcall SetYHeadRotHook::SetYHeadRotHookCallback_1_17_10_4(LocalPlayer* localPlayer, Actor* camera) {
	Vector2<float> rotationBuffer(0, localPlayer->yHeadRot); 
	ActorRotateEvent event(localPlayer, &rotationBuffer, RotationType::HEAD);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onActorRotateEvent(event);
	}
	localPlayer->yHeadRot = rotationBuffer.y;
	if(event.IsCancelled()) {
		return;
	}
	PLH::FnCast(funcOriginal, &SetYHeadRotHookCallback_1_17_10_4)(localPlayer, camera);
}

SetYHeadRotHook::SetYHeadRotHook() : IPatch::IPatch("LocalPlayer::SetYHeadRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? ?? ?? BA"), -1));
}

auto SetYHeadRotHook::Apply() -> bool {
	return this->AutoPatch(&SetYHeadRotHookCallback_1_17_10_4, &funcOriginal);
}