#ifndef LUNITY_CLIENT_EVENTS_PLAYERTICKEVENT
#define LUNITY_CLIENT_EVENTS_PLAYERTICKEVENT

#include "Event.h"
#include "../Bridge/LocalPlayer.h"
#include "../Bridge/SurvivalMode.h"

class PlayerTickEvent : public Event {
	GameMode* gameMode;
	Player* player;
	bool isLocalPlayer;
public:
	PlayerTickEvent(class GameMode* gameMode, Player* player, bool isLocalPlayer) : Event() {
		this->gameMode = gameMode;
		this->player = player;
		this->isLocalPlayer = isLocalPlayer;
	};

	auto GetGameMode() -> GameMode* {
		return this->gameMode;
	}
	auto GetPlayer() -> Player* {
		return this->player;
	}
	auto IsLocalPlayer() -> bool {
		return this->isLocalPlayer;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_PLAYERTICKEVENT */
