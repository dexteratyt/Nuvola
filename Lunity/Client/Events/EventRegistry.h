#ifndef LUNITY_CLIENT_EVENTS_EVENTREGISTRY
#define LUNITY_CLIENT_EVENTS_EVENTREGISTRY

#include "Event.h"
#include <functional>

class EventRegistry {
	static inline EventRegistry* instance;
	EventRegistry();
public:
	static auto GetInstance() -> EventRegistry*;
	//Functions that return 'void' and have 'Event*' as a parameter can have a callback
	//NOTE: Even though events are pointers, THEY SHOULD NOT BE CREATED WITH THE "new" KEYWORD!
	void AddSubscriber(std::function<void(Event*)> callback);
};

#endif /* LUNITY_CLIENT_EVENTS_EVENTREGISTRY */
