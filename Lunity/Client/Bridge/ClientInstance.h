#ifndef GUARD_ClientInstance
#define GUARD_ClientInstance
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct ClientInstance {
	/* Fields */
	char padding_320[320];
	class LocalPlayer* clientPlayer;
	/* Virtuals */
	/* Functions */
};
#endif