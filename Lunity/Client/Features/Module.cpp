#include "Module.h"

Module::Module(std::string name)  : Module(name, 0) {};
Module::Module(std::string name, int key) : Manager<Setting>(name) {
	this->wasEnabled = false;
	this->SetEnabled(false);
	this->SetHotkey(key);
}

void Module::OnEnable() {

}

void Module::OnDisable() {

}

void Module::OnLunityTick() {
	if(enabled) {
		if(!wasEnabled) {
			this->OnEnable();
		}
	} else {
		if(wasEnabled) {
			this->OnDisable();
		}
	}
	wasEnabled = enabled;
}

auto Module::IsEnabled() -> bool {
	return this->enabled;
}

void Module::SetEnabled(bool enabled) {
	this->enabled = enabled;
}

void Module::Toggle() {
	this->SetEnabled(!this->enabled);
}

auto Module::GetHotkey() -> int {
	return this->hotkey;
};
void Module::SetHotkey(int key) {
	this->hotkey = key;
};