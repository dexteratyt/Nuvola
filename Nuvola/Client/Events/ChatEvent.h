#ifndef NUVOLA_CLIENT_EVENTS_CHATEVENT
#define NUVOLA_CLIENT_EVENTS_CHATEVENT

#include "Event.h"
#include "Cancellable.h"

class ChatEvent : public Event, public Cancellable {
	std::string message;
public:
	ChatEvent(std::string message) : Event() {
		this->message = message;
	};

	auto GetMessage() -> std::string {
		return this->message;
	};
	auto SetMessage(std::string message) {
		this->message = message;
	};
};

#endif /* NUVOLA_CLIENT_EVENTS_CHATEVENT */
