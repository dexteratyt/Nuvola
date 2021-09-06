#include "Killaura.h"
#include "../../../Patches/PatchManager.h"
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


Vector2<float> CalcAngle(Vector3<float> localPos, Vector3<float> targetPos)
{
    Vector2<float> vec2;
	float dX = localPos.x - targetPos.x;
	float dY = localPos.y - targetPos.y;
	float dZ = localPos.z - targetPos.z;
	double distance = sqrt(dX * dX + dY * dY + dZ * dZ);
	vec2.x = ((float)atan2(dY, (float)distance) * (float)3.13810205 / (float)3.141592653589793);
	vec2.y = ((float)atan2(dZ, dX) * (float)3.13810205 / (float)3.141592653589793) + (float)1.569051027;
	return vec2;
}

float distance = 0;
Actor* theTarget = nullptr;

void Killaura::onPlayerTickWorldEvent(PlayerTickEvent& event) {
	if(!this->IsEnabled()) {return;}
	if(!event.IsLocalPlayer()) {return;}

	GameMode* gm = event.GetGameMode();
	if(theTarget != nullptr) {
		if(distance < reachVal) {
			gm->attack(theTarget);
		}
	}
}

void Killaura::onActorRotateEvent(ActorRotateEvent& event) {
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;
	Actor* rotatingActor = event.GetActor();
	if(rotatingActor != player) {return;}; //If the actor isnt the player, don't do anything.
	//Check if player is actually valid
	if(player) {
		//Get the closest player and actor
		//They are stored in 2 different lists, so we must check both.
		Actor* closestActor = getClosestActor(player);
		Player* closestPlayer = getClosestPlayer(player);
		
		//Goofy statements to see who is actually closer
		//Check if the closest actor is valid
		if(closestActor != nullptr) {
			//if so, calc that distance
			distance = getDistance(player, closestActor);
			//set it to the target
			theTarget = closestActor;
		}
		//Check if the player is valid
		if(closestPlayer != nullptr) {
			//Get that distance
			float playerDist = getDistance(player, closestPlayer);
			//If the distance is greater than the player dist
			if(distance > playerDist) {
				//target the player
				distance = playerDist;
				theTarget = closestPlayer;
			}
		}
		//If both failed
		if(closestActor == nullptr && closestPlayer == nullptr) {
			//Make the target null and distance 0.
			//We can check these in our attack code later
			distance = 0;
			theTarget = nullptr;
		}
		
		//Check if the target is valid
		if(theTarget != nullptr) {
			//Check if the target is within reach distance
			if(distance < reachVal) {
				//Get the positions
				Vector3<float> enemyPos = *theTarget->getPos();
				Utils::DebugF("Enemy: "+enemyPos.to_string());
				Vector3<float> playerPos = *player->getPos();
				Utils::DebugF("Player: "+playerPos.to_string());
				
				//Get the desired view angles (Where the player has to face)
				//this is basically just aimbot math
				Vector2<float> angles = CalcAngle(playerPos, enemyPos) * (180.0/3.141592653589793238463);

				//Cancel the rotation, we are going to handle that manually
				event.SetCancelled(true);
				//rotate the player to face the desired angles
				player->lookingVec = angles;
				// event.SetYaw(angles.x);
				// event.SetPitch(angles.y);
				Utils::DebugF("Looking: "+player->lookingVec.to_string());
			}
		}
	}
}

void Killaura::onRenderEvent(RenderEvent& event) {
	MinecraftRenderer* wrapper = event.GetRenderWrapper();
	
	wrapper->DrawString(std::to_string(distance), Vector2<float>(0,0));
	wrapper->DrawString(std::to_string((uintptr_t)theTarget), Vector2<float>(0,10));
}

Killaura::Killaura() : Module("Killaura") {
	this->addItem(new Setting("Reach", SettingType::SLIDER, &reachVal, minimumReach, maximumReach));
    //this->addItem(new Setting("Interval", SettingType::SLIDER, &interval, 1, 10));
};

void Killaura::OnEnable() {
	EventHandler::registerListener(this);
};

void Killaura::OnDisable() {
	EventHandler::unregisterListener(this);
};