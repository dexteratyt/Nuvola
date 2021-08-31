#ifndef GUARD_ClientInstance
#define GUARD_ClientInstance
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct ClientInstance {
	/* Fields */
	char pad_0000[168]; //0x0000
	class MinecraftGame* minecraftGame; //0x00A8
	char pad_00B0[32]; //0x00B0
	class LoopbackPacketSender* loopbackPacketSender; //0x00D0
	char pad_00D8[104]; //0x00D8
	class LocalPlayer *clientPlayer; //0x0140
	char pad_0148[912]; //0x0148
	class GuiData* guiData; //0x04D8
	/* Virtuals */
	/* Functions */
};
#endif