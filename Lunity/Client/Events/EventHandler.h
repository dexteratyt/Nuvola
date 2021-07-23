#ifndef LUNITY_CLIENT_EVENTS_EVENTHANDLER
#define LUNITY_CLIENT_EVENTS_EVENTHANDLER

#include <functional>
#include <vector>

class EventData;

typedef void(*EventCallback)(EventData*);

//Events are defined here.
//3rd party events can just cast themselves or something, enums are just ints after all.
/*
ATTENTION:
	IF THE EVENT_COUNT MACRO IS NOT UPDATED PROPERLY, BAD SHIT WILL HAPPEN!!!
*/
#define EVENT_COUNT 3
enum class EVENT_ID {
	DEFAULT_EVENT, //Responsible caller: NONE, this event should never be used.
	LOCALPLAYER_UPDATE_HEAD_Y, //Responsible caller: "Patches/LocalPlayer/SetYHeadRotHook.cpp"
	MOB_UPDATE_ROT //Responsible caller: "Patches/Mob/SnapLookingVecHook.cpp"

	//ATTENTION: REMEMBER TO UPDATE THE MACRO!
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
	void DispatchEvent(EVENT_ID event, EventData* data);
};

#endif /* LUNITY_CLIENT_EVENTS_EVENTHANDLER */
