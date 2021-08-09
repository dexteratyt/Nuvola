#include "KeyPressHook.h"

void KeyPressHook::keyPressCallback_1_17_10_4(int key, int action) {

}

KeyPressHook::KeyPressHook() : IPatch("Global::KeyPress") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 83 ?? ?? 8B 05 ?? ?? ?? ?? 8B"), -1));
}

auto KeyPressHook::Apply() -> bool {
	return this->AutoPatch(keyPressCallback_1_17_10_4, &funcOriginal);
}