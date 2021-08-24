#include  "SetRotHook.h"

#include "../../Events/Actor/SetRotEvent.h"

void __fastcall SetRotHook::SetRotCallback_1_17_11_1(Actor* actor, Vector2<float>* vector) {
	SetRotEvent event(actor, vector);
	EventHandler::GetInstance()->DispatchEvent(EVENT_ID::ACTOR_SET_ROT, &event);
	if(event.IsCancelled()) {
		return;
	}
	PLH::FnCast(funcOriginal, &SetRotCallback_1_17_11_1)(event.GetActor(), event.GetNewVector());
}

SetRotHook::SetRotHook() : IPatch::IPatch("Actor::SetRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 83 ?? ?? 8B ?? ?? 48 8B ?? 48 81"), -1));
}

auto SetRotHook::Apply() -> bool {
	return this->AutoPatch(&SetRotCallback_1_17_11_1, &funcOriginal);
}