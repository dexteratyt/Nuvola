#ifndef NUVOLA_CLIENT_EVENTS_EVENTHANDLER
#define NUVOLA_CLIENT_EVENTS_EVENTHANDLER

#include <vector>

#include "Listener.h"

class EventHandler {
	static inline std::vector<Listener*> listeners;
public:
	static void registerListener(Listener* listener);
	static void unregisterListener(Listener* listener);
	static auto getListeners() -> std::vector<Listener*>;
};

#endif /* NUVOLA_CLIENT_EVENTS_EVENTHANDLER */
