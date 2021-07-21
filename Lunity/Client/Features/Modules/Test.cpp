#include "Test.h"

#include "../../Events/LocalPlayer/HeadRotYEvent.h"

void CallbackFunc(Event* e) {
	HeadRotYEvent* event = (HeadRotYEvent*)e;
	LocalPlayer* player = event->GetPlayer();
	if(player) {
		player->YHeadRot(0);
	}
}

void Test::onEnable() {
	//Enable code

	EventRegistry::GetInstance()->AddSubscriber(CallbackFunc, LP_HEAD_ROT_Y_EVENT);
}

void Test::onDisable() {
	//Disable code
}

void Test::onTick() {
	//Tick code
	// ClientInstance* client = Utils::GetClientInstance();
	// LocalPlayer* lPlayer = client->GetLocalPlayer();
	// if(lPlayer)
	// 	if(lPlayer->GetAddress() != 0)
	// 		lPlayer->SetOnGround(true);
}