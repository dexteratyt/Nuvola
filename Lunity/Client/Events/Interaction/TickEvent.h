#ifndef LUNITY_CLIENT_EVENTS_INTERACTION_TICKEVENT
#define LUNITY_CLIENT_EVENTS_INTERACTION_TICKEVENT

#include "../EventData.h"
#include "../../Bridge/LocalPlayer.h"
#include "../../Bridge/SurvivalMode.h"

class TickEvent : public EventData {
	GameMode* gameMode;
	Player* player;
	bool isLocalPlayer;
public:
	TickEvent(class GameMode* gameMode, Player* player, bool isLocalPlayer) : EventData() {
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

#endif /* LUNITY_CLIENT_EVENTS_INTERACTION_TICKEVENT */
