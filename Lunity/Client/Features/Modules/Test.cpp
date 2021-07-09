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
	if(!client)
		return;
	if(client->getAddress() != 0)
		return;
	LocalPlayer* lPlayer = client->getLocalPlayer();
	if(lPlayer)
		if(lPlayer->getAddress() != 0)
			lPlayer->setOnGround(true);
}