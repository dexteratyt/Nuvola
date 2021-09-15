#include "SwingHook.h"

#include "../../Events/Listener.h"
#include "../../Events/EventHandler.h"

void __fastcall SwingHook::SwingHookCallback_1_17_11_1(Mob* mob) {
	MobSwingEvent event(mob);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onMobSwingEvent(event);
	}
	if(event.IsCancelled()) {
		return;
	}
	PLH::FnCast(funcOriginal, &SwingHookCallback_1_17_11_1)(mob);
}

SwingHook::SwingHook() : IPatch::IPatch("Mob::Swing") {
	this->AddSignature(new SigInfo(new std::string("40 ?? 48 83 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? 48 8B ?? ?? B9 ?? ?? ?? ?? ?? 74 ?? E8"), 0));
}

auto SwingHook::Apply() -> bool {
	return this->AutoPatch(&SwingHookCallback_1_17_11_1, &funcOriginal);
}