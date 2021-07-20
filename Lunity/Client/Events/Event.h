#ifndef LUNITY_CLIENT_EVENTS_EVENT
#define LUNITY_CLIENT_EVENTS_EVENT

#include "EventRegistry.h"

class Event {
	static inline EVENT_ID id = EVENT_BASE;
public:
	Event();
	virtual auto Identifier() -> EVENT_ID;
	static auto GetEventID() -> EVENT_ID;
};

#endif /* LUNITY_CLIENT_EVENTS_EVENT */
