#ifndef LUNITY_CLIENT_EVENTS_LOCALPLAYER_HEADROTYEVENT
#define LUNITY_CLIENT_EVENTS_LOCALPLAYER_HEADROTYEVENT

#include "../Event.h"
#include "../../Bridge/LocalPlayer.h"

class HeadRotYEvent : public Event {
	LocalPlayer* thePlayer;
	Actor* cameraEntity;
public:
	HeadRotYEvent(LocalPlayer* thePlayer, Actor* cameraEntity);
	auto GetPlayer() -> LocalPlayer*;
	auto GetCameraEntity() -> Actor*;
	virtual auto Identifier() -> EVENT_ID override;
};

#endif /* LUNITY_CLIENT_EVENTS_LOCALPLAYER_HEADROTYEVENT */
