#ifndef NUVOLA_CLIENT_PATCHES_MOB_SWINGHOOK
#define NUVOLA_CLIENT_PATCHES_MOB_SWINGHOOK

#include "../IPatch.h"
#include "../../Bridge/Mob.h"

class SwingHook : public IPatch {
	static void __fastcall SwingHookCallback_1_17_11_1(Mob* mob);
public:
	static inline uintptr_t funcOriginal = 0;
	SwingHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_MOB_SWINGHOOK */
