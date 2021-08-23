#include "Killaura.h"
#include "../../../Patches/PatchManager.h"
#include "../../../Events/LocalPlayer/UpdateHeadYEvent.h"
#include "../../../Events/Renderer/UIRenderEvent.h"
#include "../../../Bridge/ClientInstance.h"
#include "../../../Bridge/Level.h"

float reachVal = 3;
float minimumReach = 0;
float maximumReach = 8;

auto getDistance(Actor* first, Actor* second) -> float {
	return first->getPos()->DistanceTo(*second->getPos());
}
auto getClosestActorFromVector(Actor* first, std::vector<Actor*> actors) -> Actor* {
	Actor* closest = nullptr;

	for(auto actor : actors) {
		//If the actor is the actor we are looking for, we don't want it
		if(actor == first) {
			continue;
		}
		//If closest isnt set, make it the first
		if(closest == nullptr) {
			closest = actor;
			continue;
		}
		//Calculate the distances
		float distCurrent = getDistance(first, actor);
		float distClosest = getDistance(first, closest);

		//If this actor is closer, make it the closest
		if(distCurrent < distClosest) {
			closest = actor;
		}
	}

	return closest;
}
auto getClosestActor(Actor* first) -> Actor* {
	Actor* closest = nullptr;
	Level* level = first->level;
	std::vector<Actor*> actors = level->actors;
	
	return getClosestActorFromVector(first, actors);
}
auto getClosestPlayer(Actor* first) -> Player* {
	Actor* closest = nullptr;
	Level* level = first->level;
	std::vector<Player*> players = level->players;
	
	return (Player*)getClosestActorFromVector(first, *(std::vector<Actor*>*)&players);
}

void headUpdateY(EventData* event) {
	UpdateHeadYEvent* e = event->as<UpdateHeadYEvent>();
}

void onRender(EventData* event) {
	UIRenderEvent* e = event->as<UIRenderEvent>();
	MinecraftRenderer* wrapper = e->GetRenderWrapper();
	ClientInstance* client = e->GetRenderContext()->clientInstance;
	LocalPlayer* player = client->clientPlayer;
	if(player) {
		Actor* closestActor = getClosestActor(player);
		Player* closestPlayer = getClosestPlayer(player);
		
		float distanceActor = 0;
		float distancePlayer = 0;
		float distance = 0;
		if(closestActor != nullptr) {
			distance = getDistance(player, closestActor);
		}
		if(closestPlayer != nullptr) {
			distance = getDistance(player, closestActor);
		}
		if(closestPlayer != nullptr && closestActor != nullptr) {
			distance = (distanceActor < distancePlayer ? distanceActor : distancePlayer);
		}

		wrapper->DrawString(std::to_string(distance), Vector2<float>(0,0));
	}
}

Killaura::Killaura() : Module("Killaura") {
	this->addItem(new Setting("Reach", SettingType::SLIDER, &reachVal, &minimumReach, &maximumReach));
};

void Killaura::OnEnable() {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, onRender);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::LOCALPLAYER_UPDATE_HEAD_Y, headUpdateY);
};

void Killaura::OnDisable() {
	EventHandler::GetInstance()->UnlistenFor(EVENT_ID::RENDER_EVENT, onRender);
	EventHandler::GetInstance()->UnlistenFor(EVENT_ID::LOCALPLAYER_UPDATE_HEAD_Y, headUpdateY);
};