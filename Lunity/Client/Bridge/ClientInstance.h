#ifndef GUARD_ClientInstance
#define GUARD_ClientInstance
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct ClientInstance {
	/* Fields */
	char padding_168[168];
	class MinecraftGame* minecraftGame;
	char padding_320[144];
	class LocalPlayer* clientPlayer;
	/* Virtuals */
	/* Functions */
};
#endif