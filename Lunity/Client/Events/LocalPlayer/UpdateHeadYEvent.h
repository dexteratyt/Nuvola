#ifndef LUNITY_CLIENT_EVENTS_LOCALPLAYER_UPDATEHEADYEVENT
#define LUNITY_CLIENT_EVENTS_LOCALPLAYER_UPDATEHEADYEVENT

#include "../EventData.h"
#include "../../Bridge/LocalPlayer.h"

class UpdateHeadYEvent : public EventData {
	LocalPlayer* localActor;
	Actor* cameraActor;
public:
	UpdateHeadYEvent(LocalPlayer* localActor, Actor* cameraActor) : EventData() {
		this->localActor = localActor;
		this->cameraActor = cameraActor;
	};

	auto GetLocalPlayer() -> LocalPlayer* {
		return this->localActor;
	}
	auto GetCameraActor() -> Actor* {
		return this->cameraActor;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_LOCALPLAYER_UPDATEHEADYEVENT */
