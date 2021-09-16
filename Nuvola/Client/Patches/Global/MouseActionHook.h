#ifndef NUVOLA_CLIENT_PATCHES_GLOBAL_MOUSEACTIONHOOK
#define NUVOLA_CLIENT_PATCHES_GLOBAL_MOUSEACTIONHOOK

#include "../IPatch.h"

class MouseActionHook : public IPatch {
	static auto mouseActionHookCallback_1_17_11_1(void* param_1,char button, char action, short mouseX, short mouseY, short movementX, short movementY, char param_8) -> void;
public:
	static inline uintptr_t funcOriginal = 0;
	MouseActionHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_GLOBAL_MOUSEACTIONHOOK */
