#include "Freelook.h"

#include <Windows.h>

#include "../../ModuleMgr.h"

#include "../../../Events/EventHandler.h"

#include "../../../Bridge/LocalPlayer.h"
#include "../../../Bridge/Options.h"
#include "../../../Bridge/IntOption.h"

Freelook::Freelook() : Module("Freelook", VK_MENU) {

}

int lastCameraState = 0;
Vector2<float> lookingAngles;
void Freelook::onActorRotateEvent(ActorRotateEvent& event) {
	Actor* actor = event.GetActor();
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;
	if(player == actor) {
		event.SetRotation(lookingAngles);
	}
}
void Freelook::onHotkeyCheckEvent(KeyEvent& event) {
	if(event.GetKey() == this->GetHotkey()) {
		if(event.GetAction() == KeyAction::RELEASED) {
			this->SetEnabled(false);
		}
		if(event.GetAction() == KeyAction::PRESSED) {
			this->SetEnabled(true);
		}
	}
};

void Freelook::OnEnable() {
	EventHandler::registerListener(this);

	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;
	if(player) {
		lookingAngles = player->lookingVec;
	}
	Options* options = client->getOptions();
	IntOption* cameraState = options->cameraState;

	lastCameraState = cameraState->value;
	cameraState->value = 1;
}
void Freelook::OnDisable() {
	EventHandler::unregisterListener(this);

	ClientInstance* client = Utils::GetClientInstance();
	Options* options = client->getOptions();
	IntOption* cameraState = options->cameraState;

	cameraState->value = lastCameraState;
}