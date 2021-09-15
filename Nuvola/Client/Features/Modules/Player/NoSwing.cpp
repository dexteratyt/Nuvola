#include "NoSwing.h"

#include "../../../Bridge/LocalPlayer.h"

NoSwing::NoSwing() : Module("NoSwing") {

}
void NoSwing::OnEnable() {
	EventHandler::registerListener(this);
}
void NoSwing::OnDisable() {
	EventHandler::unregisterListener(this);
}
void NoSwing::OnTick() {
}

void NoSwing::onMobSwingEvent(MobSwingEvent& event) {
	Mob* mob = event.GetMob();
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;
	//Only cancel if we are the once swinging
	if(mob!=player) { return; }

	//Cancel if this module is enabled
	if(this->IsEnabled()) {
		event.SetCancelled(true);
	}
}