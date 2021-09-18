#ifndef NUVOLA_CLIENT_EVENTS_DXPRESENTEVENT
#define NUVOLA_CLIENT_EVENTS_DXPRESENTEVENT

#include "Event.h"
#include "Cancellable.h"

class DXPresentEvent : public Event, public Cancellable {
public:
	DXPresentEvent() : Event() {};
};

#endif /* NUVOLA_CLIENT_EVENTS_DXPRESENTEVENT */
