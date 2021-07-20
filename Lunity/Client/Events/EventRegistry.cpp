#include "EventRegistry.h"

Listener::Listener(EVENT_ID id, std::function<void(Event*)> callback) {
	this->id;
	this->callback = callback;
}

EventRegistry::EventRegistry() {
	listeners = new std::vector<std::function<void(Event*)>>();
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