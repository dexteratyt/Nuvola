#ifndef LUNITY_CLIENT_EVENTS_ACTOR_SETROTEVENT
#define LUNITY_CLIENT_EVENTS_ACTOR_SETROTEVENT

#include "../EventData.h"
#include "../Cancellable.h"
#include "../../Bridge/Mob.h"

class SetRotEvent : public EventData, public Cancellable {
	Actor* actor;
	Vector2<float>* vector;
public:
	SetRotEvent(Actor* actor, Vector2<float>* vector) : EventData() {
		this->actor = actor;
		this->vector = vector;
	};

	auto GetActor() -> Actor* {
		return this->actor;
	}
	auto GetNewVector() -> Vector2<float>* {
		return this->vector;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_ACTOR_SETROTEVENT */
