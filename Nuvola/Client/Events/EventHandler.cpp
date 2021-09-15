#include "EventHandler.h"

void EventHandler::registerListener(Listener* listener) {
	listeners.push_back(listener);
}
void EventHandler::unregisterListener(Listener* listener) {
	for(int i = 0; i < listeners.size(); i++) {
		if(listeners[i] == listener) {
			listeners.erase(listeners.begin()+i);
			return;
		}
	}
	//listeners.erase(std::find(listeners.begin(), listeners.end(), listener), listeners.end());
}
auto EventHandler::getListeners() -> std::vector<Listener*> {
	return listeners;
}