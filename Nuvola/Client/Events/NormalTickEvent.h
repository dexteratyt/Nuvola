#ifndef NUVOLA_CLIENT_EVENTS_NORMALTICKEVENT
#define NUVOLA_CLIENT_EVENTS_NORMALTICKEVENT

#include "ActorEvent.h"

class NormalTickEvent : public ActorEvent {
public:
	NormalTickEvent(Actor* tickingActor) : ActorEvent(tickingActor) {};
};

#endif /* NUVOLA_CLIENT_EVENTS_NORMALTICKEVENT */
