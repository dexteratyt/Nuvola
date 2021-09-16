#ifndef NUVOLA_CLIENT_EVENTS_PLAYERTICKEVENT
#define NUVOLA_CLIENT_EVENTS_PLAYERTICKEVENT

#include "PlayerEvent.h"
#include "../Bridge/SurvivalMode.h"

class PlayerTickEvent : public PlayerEvent {
	GameMode* gameMode;
	bool isLocalPlayer;
public:
	PlayerTickEvent(class GameMode* gameMode, Player* player, bool isLocalPlayer) : PlayerEvent(player) {
		this->gameMode = gameMode;
		this->isLocalPlayer = isLocalPlayer;
	};

	auto GetGameMode() -> GameMode* {
		return this->gameMode;
	}
	auto IsLocalPlayer() -> bool {
		return this->isLocalPlayer;
	}
};

#endif /* NUVOLA_CLIENT_EVENTS_PLAYERTICKEVENT */
