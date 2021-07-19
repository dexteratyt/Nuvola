#include "Test.h"

void Test::onEnable() {
	//Enable code
}

void Test::onDisable() {
	//Disable code
}

void Test::onTick() {
	//Tick code
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer lPlayer = client->GetLocalPlayer();
	if(!lPlayer.IsNull())
		lPlayer.SetOnGround(true);
}