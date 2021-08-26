#include "EventHandler.h"

void EventHandler::registerListener(Listener* listener) {
	listeners.push_back(listener);
}
void EventHandler::unregisterListener(Listener* listener) {
	for(int i = 0; i < listeners.size(); i++) {
		Listener* current = listeners.at(i);
		if(current == listener) {
			listeners.erase(std::find(listeners.begin(), listeners.end(), i));
			return;
		}
	}
}
auto EventHandler::getListeners() -> std::vector<Listener*> {
	return listeners;
}