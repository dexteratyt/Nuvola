#include "Freelook.h"

#include <Windows.h>

#include "../../ModuleMgr.h"

#include "../../../Events/EventHandler.h"

#include "../../../Bridge/LocalPlayer.h"
#include "../../../Bridge/Options.h"
#include "../../../Bridge/IntOption.h"

Freelook::Freelook() : Module("Freelook") {

}

int lastCameraState = 0;
Vector2<float> lookingAngles;
bool doFreelook = false;
void Freelook::onActorRotateEvent(ActorRotateEvent& event) {
	if(doFreelook) {
		Actor* actor = event.GetActor();
		ClientInstance* client = Utils::GetClientInstance();
		LocalPlayer* player = client->clientPlayer;
		if(player == actor) {
			event.SetRotation(lookingAngles);
		}
	}
}
void Freelook::onKeyEvent(KeyEvent& event) {
	if(event.GetAction() == KeyAction::RELEASED && event.GetKey() == VK_MENU) {
		doFreelook = false;

		ClientInstance* client = Utils::GetClientInstance();
		Options* options = client->getOptions();
		IntOption* cameraState = options->cameraState;

		cameraState->value = lastCameraState;
	} else {
		doFreelook = true;

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
};

void Freelook::OnEnable() {
	EventHandler::registerListener(this);
}
void Freelook::OnDisable() {
	EventHandler::unregisterListener(this);
}