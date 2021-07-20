#include "EventRegistry.h"

EventRegistry::EventRegistry() {
	
}

auto EventRegistry::GetInstance() -> EventRegistry* {
	if(instance == nullptr) {
		instance = new EventRegistry();
	}
	return instance;
}