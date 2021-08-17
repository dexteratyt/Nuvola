#include "MouseActionHook.h"

#include "../../Events/Global/MouseEvent.h"

void MouseActionHook::mouseActionHookCallback_1_17_11_1(void* param_1,char button, char action, short mouseX, short mouseY, short movementX, short movementY, char param_8) {
	MouseEvent event(button, action, mouseX, mouseY, movementX, movementY);
	EventHandler::GetInstance()->DispatchEvent(EVENT_ID::MOUSE_INPUT_EVENT, &event);
	if(!event.IsCancelled()) {
		PLH::FnCast(funcOriginal, mouseActionHookCallback_1_17_11_1)(param_1, button, action, mouseX, mouseY, movementX, movementY, param_8);
	}
}

MouseActionHook::MouseActionHook() : IPatch("Global::MouseAction") {
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? ?? 89 ?? ?? ?? 89 ?? ?? 57 41 ?? 41 ?? 41 ?? 41 ?? 48 83 ?? ?? 44 ?? ?? ?? ?? ?? ?? ?? ?? 48"), 0));
}

auto MouseActionHook::Apply() -> bool {
	return this->AutoPatch(mouseActionHookCallback_1_17_11_1, &funcOriginal);
}