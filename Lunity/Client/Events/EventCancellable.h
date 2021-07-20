#ifndef LUNITY_CLIENT_EVENTS_EVENTCANCELLABLE
#define LUNITY_CLIENT_EVENTS_EVENTCANCELLABLE

#include "Event.h"

class EventCancellable : public Event {
	bool cancelled;
public:
	EventCancellable();
	auto IsCancelled() -> bool;
	void SetCancelled(bool cancelled);
	void Cancel();
};

#endif /* LUNITY_CLIENT_EVENTS_EVENTCANCELLABLE */
