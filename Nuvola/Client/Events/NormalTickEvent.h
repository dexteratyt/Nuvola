#ifndef LUNITY_CLIENT_EVENTS_NORMALTICKEVENT
#define LUNITY_CLIENT_EVENTS_NORMALTICKEVENT

#include "ActorEvent.h"

class NormalTickEvent : public ActorEvent {
public:
	NormalTickEvent(Actor* tickingActor) : ActorEvent(tickingActor) {};
};

#endif /* LUNITY_CLIENT_EVENTS_NORMALTICKEVENT */
