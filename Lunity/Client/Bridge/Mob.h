#ifndef LUNITY_CLIENT_BRIDGE_MOB
#define LUNITY_CLIENT_BRIDGE_MOB
#include "Actor.h"

#include "../../Utils/Math.h"

struct Mob : Actor {
	DYN_FIELD(YHeadRot, 0x728, float);
};

#endif /* LUNITY_CLIENT_BRIDGE_MOB */
