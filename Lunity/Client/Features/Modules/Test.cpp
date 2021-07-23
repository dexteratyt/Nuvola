#include "Test.h"

#include "../../Events/LocalPlayer/UpdateHeadYEvent.h"

void CallbackFunc(EventData* event) {
	//Using "as" properly
	LocalPlayer* player = event->as<UpdateHeadYEvent>()->GetLocalPlayer();
	if(player) {
		player->YHeadRot(0);
	}
}

Test::Test() : Module("Test") {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::LOCALPLAYER_UPDATE_HEAD_Y, CallbackFunc);
}

void Test::onEnable() {
	//Enable code

}

void Test::onDisable() {
	//Disable code
}

bool init = true;
void Test::onTick() {
	//Tick code
	// ClientInstance* client = Utils::GetClientInstance();
	// LocalPlayer* lPlayer = client->GetLocalPlayer();
	// if(lPlayer)
	// 	if(lPlayer->GetAddress() != 0)
	// 		lPlayer->SetOnGround(true);
}