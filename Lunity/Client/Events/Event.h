#ifndef LUNITY_CLIENT_EVENTS_EVENT
#define LUNITY_CLIENT_EVENTS_EVENT

#include "EventRegistry.h"

class Event {
public:
	Event();
	virtual auto Identifier() -> EVENT_ID;
};

#endif /* LUNITY_CLIENT_EVENTS_EVENT */
