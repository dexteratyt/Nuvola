#include "Test.h"

#include "../../Events/LocalPlayer/UpdateHeadYEvent.h"
#include "../../Events/Mob/UpdateRot.h"

void Head_Y_Callback(EventData* event) {
	//Using "as" properly
	LocalPlayer* player = event->as<UpdateHeadYEvent>()->GetLocalPlayer();
	if(player) {
		player->YHeadRot(0);
	}
}

void Rot_Callback(EventData* event) {
	//Get the client instance & local player
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* localPlayer = client->ClientPlayer();

	//Get data from event
	Mob* mob = event->as<UpdateRot>()->GetMob();
	Vector2<float>* newVec = event->as<UpdateRot>()->GetNewVector();

	//If the mob is the local player
	if(mob == localPlayer) {
		//Control the vector
		newVec->x = 0;
		localPlayer->LookingVec(*newVec);
	}
}

Test::Test() : Module("Test") {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::LOCALPLAYER_UPDATE_HEAD_Y, Head_Y_Callback);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::MOB_UPDATE_ROT, Rot_Callback);
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