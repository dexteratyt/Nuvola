#ifndef LUNITY_CLIENT_PATCHES_PLAYER_NORMALTICKHOOK
#define LUNITY_CLIENT_PATCHES_PLAYER_NORMALTICKHOOK

#include "../IPatch.h"
#include "../../Bridge/Player.h"

class NormalTickHook : public IPatch {
	static void __fastcall NormalTickHookCallback_1_17_11_1(Player* localPlayer);
public:
	static inline uintptr_t funcOriginal = 0;
	NormalTickHook();
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_PLAYER_NORMALTICKHOOK */
