#include "EventRegistry.h"

#include "Event.h"

Listener::Listener(EVENT_ID id, std::function<void(Event*)> callback) {
	this->id = id;
	this->callback = callback;
}

EventRegistry::EventRegistry() {
	listeners = new std::vector<Listener>();
}

auto EventRegistry::GetInstance() -> EventRegistry* {
	if(instance == nullptr) {
		instance = new EventRegistry();
	}
	return instance;
}

void EventRegistry::AddSubscriber(std::function<void(Event*)> callback, EVENT_ID listenId) {
	Listener listener(listenId, callback);
	listeners->push_back(listener);
}

void EventRegistry::DispatchEvent(Event* event) {
	for(auto listener : *listeners) {
		if(listener.id == event->GetEventID()) {
			listener.callback(event);
		}
	}
}