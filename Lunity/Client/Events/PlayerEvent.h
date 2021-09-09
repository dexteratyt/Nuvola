#ifndef LUNITY_CLIENT_EVENTS_PLAYEREVENT
#define LUNITY_CLIENT_EVENTS_PLAYEREVENT

#include "Event.h"
#include "../Bridge/Player.h"

class PlayerEvent : public Event {
	Player* player;
public:
	PlayerEvent(Player* player) : Event() {
		this->player = player;
	};

	auto GetPlayer() -> Player* {
		return this->player;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_PLAYEREVENT */