#ifndef LUNITY_CLIENT_PATCHES_PLAYER_TICKWORLDHOOK
#define LUNITY_CLIENT_PATCHES_PLAYER_TICKWORLDHOOK

#include "../IPatch.h"
#include "../../Bridge/LocalPlayer.h"

class TickWorldHook : public IPatch {
	static void* __fastcall TickWorldHookCallback_1_17_11_1(Player* player, class Tick* tick);
public:
	static inline uintptr_t funcOriginal = 0;
	TickWorldHook();
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_PLAYER_TICKWORLDHOOK */
