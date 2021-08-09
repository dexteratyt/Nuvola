#ifndef LUNITY_CLIENT_EVENTS_GLOBAL_KEYPRESSEVENT
#define LUNITY_CLIENT_EVENTS_GLOBAL_KEYPRESSEVENT

#include "../EventData.h"

enum class KeyAction {
	PRESSED,
	RELEASED
};

class KeyPressEvent : public EventData {
	int key;
	KeyAction action;
public:
	KeyPressEvent(int key, int action) : EventData() {
		this->key = key;
		this->action = (KeyAction)action;
	};

	auto GetKey() -> int {
		return this->key;
	}
	auto GetAction() -> KeyAction {
		return this->action;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_GLOBAL_KEYPRESSEVENT */
