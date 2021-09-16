#ifndef NUVOLA_CLIENT_EVENTS_KEYEVENT
#define NUVOLA_CLIENT_EVENTS_KEYEVENT

#include "Event.h"
#include "Cancellable.h"

enum class KeyAction {
	PRESSED,
	RELEASED
};

class KeyEvent : public Event, public Cancellable {
	int key;
	KeyAction action;
public:
	KeyEvent(int key, int action) : Event() {
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

#endif /* NUVOLA_CLIENT_EVENTS_KEYEVENT */
