#ifndef GUARD_ClientInstance
#define GUARD_ClientInstance
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
struct ClientInstance {
	/* Fields */
	char padding_168[168];
	class MinecraftGame* minecraftGame;
	char padding_208[32];
	class LoopbackPacketSender* loopbackPacketSender;
	char padding_320[104];
	class LocalPlayer* clientPlayer;
	char padding_1240[912];
	class GuiData* guiData;
	/* Virtuals */
	/* Functions */
};
#endif