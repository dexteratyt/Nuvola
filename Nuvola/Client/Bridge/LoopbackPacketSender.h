#ifndef GUARD_LoopbackPacketSender
#define GUARD_LoopbackPacketSender
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
struct LoopbackPacketSender {
	/* Fields */
	/* Virtuals */
	virtual void virt_pad_0() {};
	virtual auto send(void* packet) -> void {};
	/* Functions */
};
#endif