#include "TestFly.h"

#include "../../../Bridge/LocalPlayer.h"
#include <unordered_set>
#include "../../../Bridge/Level.h"

TestFly::TestFly() : Module("TestFly") {

}
void TestFly::OnEnable() {
	
}
void TestFly::OnDisable() {
}
void TestFly::OnTick() {
	ClientInstance* client = Utils::GetClientInstance();
	if(client) {
		LocalPlayer* player = client->clientPlayer;
		if(player) {
			player->getPos()->y -= 0.00001f;
		}
	}
}