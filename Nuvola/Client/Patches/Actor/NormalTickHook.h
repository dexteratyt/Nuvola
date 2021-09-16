#ifndef NUVOLA_CLIENT_PATCHES_ACTOR_NORMALTICKHOOK
#define NUVOLA_CLIENT_PATCHES_ACTOR_NORMALTICKHOOK

#include "../IPatch.h"
#include "../../Bridge/Actor.h"

class NormalTickHook : public IPatch {
	static void __fastcall NormalTickHookCallback_1_17_11_1(Actor* actor);
public:
	static inline uintptr_t funcOriginal = 0;
	NormalTickHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_ACTOR_NORMALTICKHOOK */
