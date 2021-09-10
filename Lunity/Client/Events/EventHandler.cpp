#include "EventHandler.h"

void EventHandler::registerListener(Listener* listener) {
	listeners.push_back(listener);
}
void EventHandler::unregisterListener(Listener* listener) {
	listeners.erase(std::find(listeners.begin(), listeners.end(), listener), listeners.end());
}
auto EventHandler::getListeners() -> std::vector<Listener*> {
	return listeners;
}