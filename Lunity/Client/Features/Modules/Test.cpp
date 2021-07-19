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
	Actor* lPlayer = client->LocalPlayer();
	if(lPlayer)
		lPlayer->OnGround(true);
}