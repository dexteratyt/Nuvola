#include  "NormalTickHook.h"

#include "../../Events/EventHandler.h"

void __fastcall NormalTickHook::NormalTickHookCallback_1_17_11_1(Actor* actor) {
	NormalTickEvent event(actor);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onNormalTickEvent(event);
	}
	PLH::FnCast(funcOriginal, &NormalTickHookCallback_1_17_11_1)(actor);
}

NormalTickHook::NormalTickHook() : IPatch::IPatch("Actor::NormalTick") {
	//TODO: Find actor normalTick func (its no where to be found tbh, this hook is deprecated anyway so)
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? 55 41 ?? 41 ?? 48 ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? 48 8B ?? 8B 15"), 0));
}

auto NormalTickHook::Apply() -> bool {
	return this->AutoPatch(&NormalTickHookCallback_1_17_11_1, &funcOriginal);
}