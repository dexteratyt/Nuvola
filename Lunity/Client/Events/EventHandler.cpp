#include "EventHandler.h"
#include "EventData.h"

EventHandler::EventHandler() {
	instance = this;
	this->callbacks = new std::vector<std::vector<EventCallback>*>();
	for(int i = 0; i < EVENT_COUNT; i++){
		this->callbacks->push_back(new std::vector<EventCallback>());
	}
}

auto EventHandler::GetCallbackVector(EVENT_ID event) -> std::vector<EventCallback>* {
	//Get all callbacks
	std::vector<std::vector<EventCallback>*>* callbacks = this->callbacks;
	//Get callbacks for this event specifically
	std::vector<EventCallback>* eventCallbacks = callbacks->at((size_t)event);
	return eventCallbacks;
}

auto EventHandler::GetInstance() -> EventHandler* {
	if(instance == nullptr) {
		instance = new EventHandler();
	}
	return instance;
}

void EventHandler::ListenFor(EVENT_ID event, EventCallback callback) {
	std::vector<EventCallback>* eventCallbacks = this->GetCallbackVector(event);
	eventCallbacks->push_back(callback);
}

void EventHandler::UnlistenFor(EVENT_ID event, EventCallback callback) {
	std::vector<EventCallback>* eventCallbacks = this->GetCallbackVector(event);
	for(int i = 0; i < eventCallbacks->size(); i++) {
		if(eventCallbacks->at(i) == callback) {
			eventCallbacks->erase(eventCallbacks->begin() + i);
			return;
		}
	}
}

void EventHandler::DispatchEvent(EVENT_ID event, EventData* data) {
	std::vector<EventCallback>* eventCallbacks = this->GetCallbackVector(event);
	//Call the callbacks
	for(auto callback : *eventCallbacks) {
		callback(data);
	}
}

