#ifndef GUARD_Packet
#define GUARD_Packet
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
struct Packet {
	/* Fields */
	/* Virtuals */
	virtual void virt_pad_0() {};
	virtual auto getId() -> int {};
	virtual auto getName() -> nuv::string {};
	/* Functions */
};
#endif