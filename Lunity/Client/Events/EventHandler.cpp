#include "EventHandler.h"

void EventHandler::registerListener(Listener* listener) {
	listeners.push_back(listener);
}
void EventHandler::unregisterListener(Listener* listener) {
	for(int i = 0; i < getListeners().size(); i++) {
		Listener* current = getListeners().at(i);
		if(current == listener) {
			listeners.erase(listeners.begin()+i);
			return;
		}
	}
}
auto EventHandler::getListeners() -> std::vector<Listener*> {
	return listeners;
}