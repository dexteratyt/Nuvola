#ifndef LUNITY_CLIENT_EVENTS_GLOBAL_MOUSEEVENT
#define LUNITY_CLIENT_EVENTS_GLOBAL_MOUSEEVENT

#include "../../Utils/Math.h"
#include "Event.h"
#include "Cancellable.h"

enum class MouseButton {
	NONE = 0,
	LEFT = 1,
	RIGHT = 2,
	MMB = 3,
	SCROLL = 4
};
enum class MouseAction {
	PRESS,
	RELEASE,
	SCROLL_UP,
	SCROLL_DOWN
};

class MouseEvent : public Event, public Cancellable {
	MouseButton button;
	MouseAction action;
	short mouseX;
	short mouseY;
	short movementX;
	short movementY;
public:
	MouseEvent(char button, char action, short mouseX, short mouseY, short movementX, short movementY) : Event() {
		this->button = (MouseButton)button;
		this->SetActionFromChar(action);
		this->mouseX = mouseX;
		this->mouseY = mouseY;
		this->movementX = movementX;
		this->movementY = movementY;
	};

	auto GetButton() -> MouseButton {
		return this->button;
	}
	void SetButton(MouseButton button) {
		this->button = button;
	}
	auto GetAction() -> MouseAction {
		return this->action;
	}
	auto GetActionAsChar() -> char {
		switch(this->action) {
			case MouseAction::RELEASE: return 0;
			case MouseAction::PRESS: return 1;
			case MouseAction::SCROLL_UP: return 0x78;
			case MouseAction::SCROLL_DOWN: return 0x80;
			default: return (char)this->action;
		}
	}
	void SetAction(MouseAction action) {
		this->action = action;
	}
	void SetActionFromChar(char action) {
		switch(action) {
			case 0: this->action = MouseAction::RELEASE; break;
			case 1: this->action = MouseAction::PRESS; break;
			case 0x78: this->action = MouseAction::SCROLL_UP; break;
			case 0x7F: this->action = MouseAction::SCROLL_UP; break;
			case 0x80: this->action = MouseAction::SCROLL_DOWN; break;
			case 0x88: this->action = MouseAction::SCROLL_DOWN; break;
			default: this->action = (MouseAction)action; break;
		}
	}
	
	auto GetMouseX() -> short {
		return this->mouseX;
	}
	void SetMouseX(short mouseX) {
		this->mouseX = mouseX;
	}
	auto GetMouseY() -> short {
		return this->mouseY;
	}
	void SetMouseY(short mouseY) {
		this->mouseY = mouseY;
	}
	auto GetMousePos() -> Vector2<short> {
		Vector2<short> pos = Vector2<short>(this->GetMouseX(), this->GetMouseY());
		return pos;
	}
	auto GetMousePosF() -> Vector2<float> {
		Vector2<float> posF = Vector2<float>((float)this->GetMouseX(), (float)this->GetMouseY());
		return posF;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_GLOBAL_MOUSEEVENT */
