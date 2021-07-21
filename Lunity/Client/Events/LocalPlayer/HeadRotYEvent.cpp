#include "HeadRotYEvent.h"

HeadRotYEvent::HeadRotYEvent(LocalPlayer* thePlayer, Actor* cameraEntity) : Event::Event() {

}

auto HeadRotYEvent::GetPlayer() -> LocalPlayer* {
	return this->thePlayer;
}

auto HeadRotYEvent::GetCameraEntity() -> Actor* {
	return this->cameraEntity;
}

auto HeadRotYEvent::Identifier() -> EVENT_ID {
	return LP_HEAD_ROT_Y_EVENT;
}