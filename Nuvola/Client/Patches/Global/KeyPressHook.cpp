#include "KeyPressHook.h"

#include "../../Events/KeyEvent.h"
#include "../../Events/EventHandler.h"

void KeyPressHook::keyPressCallback_1_17_10_4(int key, int action) {
	KeyEvent event(key, action);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onKeyEvent(event);
	}
	if(!event.IsCancelled()) {
		PLH::FnCast(funcOriginal, keyPressCallback_1_17_10_4)(event.GetKey(), (int)event.GetAction());
	}
}

KeyPressHook::KeyPressHook() : IPatch("Global::KeyPress") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 83 ?? ?? 8B 05 ?? ?? ?? ?? 8B"), -1));
}

auto KeyPressHook::Apply() -> bool {
	return this->AutoPatch(keyPressCallback_1_17_10_4, &funcOriginal);
}