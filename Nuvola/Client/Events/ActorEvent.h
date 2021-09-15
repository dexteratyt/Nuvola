#ifndef LUNITY_CLIENT_EVENTS_ACTOREVENT
#define LUNITY_CLIENT_EVENTS_ACTOREVENT

#include "Event.h"
#include "../Bridge/Actor.h"

class ActorEvent : public Event {
	Actor* actor;
public:
	ActorEvent(Actor* actor) : Event() {
		this->actor = actor;
	};

	auto GetActor() -> Actor* {
		return this->actor;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_ACTOREVENT */
