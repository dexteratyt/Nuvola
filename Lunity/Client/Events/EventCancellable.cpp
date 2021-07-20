#include "EventCancellable.h"

EventCancellable::EventCancellable() {
	this->cancelled = false;
}

auto EventCancellable::IsCancelled() -> bool {
	return this->cancelled;
}

void EventCancellable::SetCancelled(bool cancelled) {
	this->cancelled = cancelled;
}

void EventCancellable::Cancel() {
	this->cancelled = true;
}