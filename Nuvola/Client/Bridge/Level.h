#ifndef GUARD_Level
#define GUARD_Level
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
struct Level {
	/* Fields */
	char padding_112[112];
	nuv::vector<Player*> players;
	char padding_9952[9816];
	nuv::vector<Actor*> actors;
	/* Virtuals */
	/* Functions */
};
#endif