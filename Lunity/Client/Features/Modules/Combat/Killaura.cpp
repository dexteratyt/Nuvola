#include "Killaura.h"
#include "../../../Patches/PatchManager.h"
#include "../../../Events/LocalPlayer/UpdateHeadYEvent.h"
#include "../../../Events/Actor/SetRotEvent.h"
#include "../../../Events/Renderer/UIRenderEvent.h"
#include "../../../Bridge/ClientInstance.h"
#include "../../../Bridge/Level.h"

float reachVal = 4;
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
	std::vector<Actor*> actors = std::vector<Actor*>();
	for(auto player : players) {
		actors.push_back(player);
	}
	
	return (Player*)getClosestActorFromVector(first, actors);
}

float distance = 0;
Actor* theTarget = nullptr;
void setRotEvent(EventData* event) {
	SetRotEvent* e = event->as<SetRotEvent>();

	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;
	if(player) {
		Actor* closestActor = getClosestActor(player);
		Player* closestPlayer = getClosestPlayer(player);
		
		if(closestActor != nullptr) {
			distance = getDistance(player, closestActor);
			theTarget = closestActor;
		}
		if(closestPlayer != nullptr) {
			float playerDist = getDistance(player, closestPlayer);
			if(distance < playerDist) {
				distance = playerDist;
				theTarget = closestPlayer;
			}
		}
		if(closestActor == nullptr && closestPlayer == nullptr) {
			distance = 0;
			theTarget = nullptr;
		}
		

		if(theTarget != nullptr) {
			if(distance < reachVal) {
				Vector3<float> enemyPos = *theTarget->getPos();
				Vector3<float> playerPos = *player->getPos();
				Vector3<float> targetPos = enemyPos - playerPos;

				float hypo = sqrt(pow(targetPos.x, 2) + pow(targetPos.y, 2) + pow(targetPos.z, 2));

				float newYaw = atan(targetPos.y/targetPos.x);
				float newPitch = acos(targetPos.z/hypo);

				e->SetCancelled(true);
				player->lookingVec.x = newYaw;
				player->lookingVec.y = newPitch;
			}
		}
	}
}

void onRender(EventData* event) {
	UIRenderEvent* e = event->as<UIRenderEvent>();
	MinecraftRenderer* wrapper = e->GetRenderWrapper();
	
	wrapper->DrawString(std::to_string(distance), Vector2<float>(0,0));
	wrapper->DrawString(std::to_string((uintptr_t)theTarget), Vector2<float>(0,10));
}

Killaura::Killaura() : Module("Killaura") {
	this->addItem(new Setting("Reach", SettingType::SLIDER, &reachVal, &minimumReach, &maximumReach));
};

void Killaura::OnEnable() {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, onRender);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::ACTOR_SET_ROT, setRotEvent);
};

void Killaura::OnDisable() {
	EventHandler::GetInstance()->UnlistenFor(EVENT_ID::RENDER_EVENT, onRender);
	EventHandler::GetInstance()->UnlistenFor(EVENT_ID::ACTOR_SET_ROT, setRotEvent);
};