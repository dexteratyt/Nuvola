#ifndef LUNITY_CLIENT_EVENTS_MOBEVENT
#define LUNITY_CLIENT_EVENTS_MOBEVENT

#include "../Bridge/Mob.h"
#include "Event.h"

class MobEvent : public Event {
	Mob* mob;
public:
	MobEvent(Mob* mob) : Event() {
		this->mob = mob;
	};

	auto GetMob() -> Mob* {
		return this->mob;
	};
};

#endif /* LUNITY_CLIENT_EVENTS_MOBEVENT */
