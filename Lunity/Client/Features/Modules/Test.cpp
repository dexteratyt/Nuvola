#include "Test.h"

#include "../../Events/Event.h"

void CallbackFunc(Event* event) {
	ClientInstance* instance = Utils::GetClientInstance();
	LocalPlayer* player = instance->ClientPlayer();
	if(player) {
		player->YHeadRot(0);
	}
}

void Test::onEnable() {
	//Enable code

	EventRegistry::GetInstance()->AddSubscriber(CallbackFunc, EVENT_BASE);
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