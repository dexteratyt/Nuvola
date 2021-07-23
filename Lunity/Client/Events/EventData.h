#ifndef LUNITY_CLIENT_EVENTS_EVENTDATA
#define LUNITY_CLIENT_EVENTS_EVENTDATA

#include "EventHandler.h"

//Default / base event
//Events should base themselves off this class.
class EventData {
public:
	EventData() {};
	virtual EVENT_ID GetIdentifier() {
		return EVENT_ID::DEFAULT_EVENT;
	};
};

#endif /* LUNITY_CLIENT_EVENTS_EVENTDATA */
