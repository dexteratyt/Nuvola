#include "Airjump.h"

#include "../../../Bridge/LocalPlayer.h"

Airjump::Airjump() : Module("Airjump") {

}
void Airjump::OnEnable() {
}
void Airjump::OnDisable() {
}
void Airjump::OnTick() {
	ClientInstance* client = Utils::GetClientInstance();
	if(client) {
		LocalPlayer* player = client->clientPlayer;
		if(player) {
			player->OnGround = true;
		}
	}
}