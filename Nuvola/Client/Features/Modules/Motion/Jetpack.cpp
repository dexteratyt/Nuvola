#include "Jetpack.h"

#include <Windows.h>

#include "../../../Bridge/LocalPlayer.h"

float jetpackSpeed = 1.0f;

Jetpack::Jetpack() : Module("Jetpack", 'F') {

}

void Jetpack::onHotkeyCheckEvent(KeyEvent& event) {
	if(event.GetKey() == this->GetHotkey()) {
		if(event.GetAction() == KeyAction::RELEASED) {
			this->SetEnabled(false);
		}
		if(event.GetAction() == KeyAction::PRESSED) {
			this->SetEnabled(true);
		}
	}
}

void Jetpack::OnEnable() {
}
void Jetpack::OnDisable() {
}
void Jetpack::OnTick() {
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;
	//If player is invalid, dont touch it
	if(player == nullptr) { return; }

	Vector2<float> lookingVec = player->lookingVec;
	//Thanks for the math in old Lunity, echo!
	player->velocity.x = cos((lookingVec.y + 90.0f) * (PI / 180.0f)) * jetpackSpeed;
	player->velocity.y = sin((lookingVec.x) * -(PI / 180.0f)) * jetpackSpeed;
	player->velocity.z = sin((lookingVec.y + 90.0f) * (PI / 180.0f)) * jetpackSpeed;
}