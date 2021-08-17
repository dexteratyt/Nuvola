#ifndef LUNITY_CLIENT_EVENTS_GLOBAL_MOUSEEVENT
#define LUNITY_CLIENT_EVENTS_GLOBAL_MOUSEEVENT

#include "../EventData.h"
#include "../Cancellable.h"

enum class MouseButton {
	NONE,
	LEFT,
	RIGHT,
	MMB,
	SCROLL
};
enum class MouseAction {
	PRESS,
	RELEASE,
	SCROLL_UP,
	SCROLL_DOWN
};

class MouseEvent : public EventData, public Cancellable {
	MouseButton button;
	MouseAction action;
	short mouseX;
	short mouseY;
	short movementX;
	short movementY;
public:
	MouseEvent(char button, char action, short mouseX, short mouseY, short movementX, short movementY) : EventData() {
		switch(button) {
			case 0: this->button = MouseButton::NONE; break;
			case 1: this->button = MouseButton::LEFT; break;
			case 2:	this->button = MouseButton::RIGHT; break;
			case 3: this->button = MouseButton::MMB; break;
			case 4: this->button = MouseButton::SCROLL; break;
			default: this->button = (MouseButton)button; break;
		}
		switch(action) {
			case 0: this->action = MouseAction::RELEASE; break;
			case 1: this->action = MouseAction::PRESS; break;
			case 0x78: this->action = MouseAction::SCROLL_UP; break;
			case 0x7F: this->action = MouseAction::SCROLL_UP; break;
			case 0x80: this->action = MouseAction::SCROLL_DOWN; break;
			case 0x88: this->action = MouseAction::SCROLL_DOWN; break;
			default: this->action = (MouseAction)action; break;
		}
		this->mouseX = mouseX;
		this->mouseY = mouseY;
		this->movementX = movementX;
		this->movementY = movementY;
	};
};

#endif /* LUNITY_CLIENT_EVENTS_GLOBAL_MOUSEEVENT */
