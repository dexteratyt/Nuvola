#include "Test.h"

#include "../../Events/LocalPlayer/UpdateHeadYEvent.h"
#include "../../Events/Actor/SetRotEvent.h"

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
	Actor* actor = event->as<SetRotEvent>()->GetActor();
	Vector2<float>* newVec = event->as<SetRotEvent>()->GetNewVector();

	//If the mob is the local player
	if(actor == localPlayer) {
		//Control the vector
		newVec->X = 0;
		localPlayer->LookingVec(*newVec);
	}
}

Test::Test() : Module("Test") {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::LOCALPLAYER_UPDATE_HEAD_Y, Head_Y_Callback);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::ACTOR_SET_ROT, Rot_Callback);
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