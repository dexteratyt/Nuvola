#include  "SetRotHook.h"

#include <vector>

#include "../../Bridge/Actor.h"
#include "../../Events/ActorRotateEvent.h"
#include "../../Events/EventHandler.h"

void __fastcall SetRotHook::SetRotCallback_1_17_11_1(Actor* actor, Vector2<float>* vector) {
	ActorRotateEvent event(actor, *vector);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onActorRotateEvent(event);
	}
	if(event.IsCancelled()) {
		return;
	}
	PLH::FnCast(funcOriginal, &SetRotCallback_1_17_11_1)(event.GetActor(), vector);
}

SetRotHook::SetRotHook() : IPatch::IPatch("Actor::SetRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 83 ?? ?? 8B ?? ?? 48 8B ?? 48 81"), -1));
}

auto SetRotHook::Apply() -> bool {
	return this->AutoPatch(&SetRotCallback_1_17_11_1, &funcOriginal);
}