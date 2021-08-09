#ifndef LUNITY_CLIENT_EVENTS_GLOBAL_KEYPRESSEVENT
#define LUNITY_CLIENT_EVENTS_GLOBAL_KEYPRESSEVENT

#include "../EventData.h"
#include "../Cancellable.h"

enum class KeyAction {
	PRESSED,
	RELEASED
};

class KeyPressEvent : public EventData, public Cancellable {
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

#endif /* LUNITY_CLIENT_EVENTS_GLOBAL_KEYPRESSEVENT */
