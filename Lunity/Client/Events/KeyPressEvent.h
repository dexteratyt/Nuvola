#ifndef LUNITY_CLIENT_EVENTS_KEYPRESSEVENT
#define LUNITY_CLIENT_EVENTS_KEYPRESSEVENT

#include "Event.h"
#include "Cancellable.h"

enum class KeyAction {
	PRESSED,
	RELEASED
};

class KeyPressEvent : public Event, public Cancellable {
	int key;
	KeyAction action;
public:
	KeyPressEvent(int key, int action) : Event() {
		this->key = key;
		this->action = (KeyAction)action;
	};

	auto GetKey() -> int {
		return this->key;
	}
	void SetKey(int key) {
		this->key = key;
	}
	auto GetAction() -> KeyAction {
		return this->action;
	}
	void SetAction(KeyAction action) {
		this->action = action;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_KEYPRESSEVENT */
