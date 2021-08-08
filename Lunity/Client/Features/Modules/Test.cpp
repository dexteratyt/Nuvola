#include "Test.h"

#include "../../Events/LocalPlayer/UpdateHeadYEvent.h"
#include "../../Events/Actor/SetRotEvent.h"
#include "../../Events/Renderer/UIRenderEvent.h"

void Head_Y_Callback(EventData* event) {
	//Using "as" properly
	LocalPlayer* player = event->as<UpdateHeadYEvent>()->GetLocalPlayer();
	if(player) {
		player->YHeadRot = 0;
	}
}

void Rot_Callback(EventData* event) {
	//Get the client instance & local player
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* localPlayer = client->clientPlayer;

	//Get data from event
	Actor* actor = event->as<SetRotEvent>()->GetActor();
	Vector2<float>* newVec = event->as<SetRotEvent>()->GetNewVector();
}

void Render_Callback(EventData* event) {
	MinecraftRenderer* renderer = event->as<UIRenderEvent>()->GetRenderWrapper();
	renderer->DrawString("Test!", Vector2<float>(0, 20));
}

Test::Test() : Module("Test") {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::LOCALPLAYER_UPDATE_HEAD_Y, Head_Y_Callback);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::ACTOR_SET_ROT, Rot_Callback);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, Render_Callback);
}

void Test::onEnable() {
	//Enable code

}

void Test::onDisable() {
	//Disable code
}

bool init = true;
void Test::onTick() {
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* lPlayer = client->clientPlayer;
	if(lPlayer)
		lPlayer->swing();
	//Tick code
	// ClientInstance* client = Utils::GetClientInstance();
	// LocalPlayer* lPlayer = client->GetLocalPlayer();
	// if(lPlayer)
	// 	if(lPlayer->GetAddress() != 0)
	// 		lPlayer->SetOnGround(true);
}