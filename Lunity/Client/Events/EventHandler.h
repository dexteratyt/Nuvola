#ifndef LUNITY_CLIENT_EVENTS_EVENTHANDLER
#define LUNITY_CLIENT_EVENTS_EVENTHANDLER

#include <functional>
#include <vector>

typedef std::function<void(class EventData*)> EventCallback;

//Events are defined here.
//3rd party events can just cast themselves or something, enums are just ints after all.
#define EVENT_COUNT 1
enum class EVENT_ID {
	DEFAULT_EVENT
};

class EventHandler {
	static inline EventHandler* instance;
	EventHandler();
	//First layer vector is selected with the EVENT_ID. They correspond.
	//Second layer vector is the actual callback function to invoke.
	std::vector<std::vector<EventCallback>*>* callbacks;
	auto GetCallbackVector(EVENT_ID event) -> std::vector<EventCallback>*;
public:
	static EventHandler* GetInstance();
	void ListenFor(EVENT_ID event, EventCallback callback);
	void DispatchEvent(EVENT_ID event, class EventData* data);
};

#endif /* LUNITY_CLIENT_EVENTS_EVENTHANDLER */
