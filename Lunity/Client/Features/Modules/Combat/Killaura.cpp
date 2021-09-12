#include "Killaura.h"
#include "../../../Patches/PatchManager.h"
#include "../../../Bridge/ClientInstance.h"
#include "../../../Bridge/Level.h"

float reachVal = 12;
float minimumReach = 0;
float maximumReach = 8;

//Interval in ticks
int interval = 1;
int minimumInterval = 0; //(run every tick)
int maximumInterval = 20; //Once/second

bool noSwing = false;

bool targetPlayers = true;
bool targetNeutrals = false;
bool targetMobs = true;
bool targetAnimals = false;
bool targetActors = false;

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
/*
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
*/

//Returns in RADIANS
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
#pragma region EntityDefs
std::string monsters[] = {
	"blaze",
	"cave_spider",
	"creeper",
	"drowned",
	"elder_guardian",
	"elder_guardian_ghost",
	"ender_dragon",
	"enderman",
	"endermite",
	"evocation_illager",
	"ghast",
	"guardian",
	"hoglin",
	"husk",
	"magma_cube",
	"phantom",
	"piglin_brute",
	"pillager",
	"ravager",
	"shulker",
	"spider",
	"stray",
	"vex",
	"vindicator",
	"witch",
	"wither",
	"wither_skeleton",
	"zoglin",
	"zombie"
};
std::string animals[] = {
	"axolotl",
	"bat",
	"bee",
	"cat",
	"chicken",
	"cod",
	"cow",
	"dolphin",
	"donkey",
	"fox",
	"glow_squid",
	"goat",
	"horse",
	"llama",
	"mooshroom",
	"mule"
	"ocelot",
	"panda",
	"parrot",
	"pig",
	"polar_bear",
	"pufferfish",
	"rabbit",
	"salmon",
	"sheep",
	"squid",
	"tropicalfish",
	"turtle",
	"wolf"
};
#pragma endregion

void __declspec(dllexport) Killaura::onPlayerTickWorldEvent(PlayerTickEvent& event) {
	if(!this->IsEnabled()) {return;}
	if(!event.IsLocalPlayer()) {return;}

	GameMode* gm = event.GetGameMode();
	Player* player = event.GetPlayer();

	//Set the target
	theTarget = findTarget(player);

	if(gm != nullptr) {
		if(theTarget != nullptr) {
			if(distance < reachVal) {
				if(!noSwing)
					player->swing();
				gm->attack(theTarget);
			}
		}
	}
}

auto Killaura::findTarget(Actor* sourceActor) -> Actor* {
	//Get the level
	Level* level = sourceActor->level;
	//Get the actors & players
	std::vector<Actor*> allActors = level->actors;
	std::vector<Player*> allPlayers = level->players;
	//Merge the vectors to get a complete list to iterate
	allActors.insert(allActors.end(), allPlayers.begin(), allPlayers.end());

	//Remove the source actor from the list. We can't attack ourselves!
	allActors.erase(std::find(allActors.begin(), allActors.end(), sourceActor), allActors.end());

	//Remove non-qualifying actors
	allActors.erase(std::remove_if(allActors.begin(), allActors.end(),
		[sourceActor]
		(Actor* ent) {

			if(!ent->isAlive()) {
				return true;
			}

			//Get the distance to the possible target
			float distance = getDistance(sourceActor, ent);
			if(distance > reachVal) {
				//The entity is out of reach
				return true;
			}

			//If the actor is a player & we want to target it:
			if(targetPlayers && ent->entityTypeId.type.key == "player") {
				//Dont remove it
				return false;
			}

			if(targetMobs) {
				for(auto monster : monsters) {
					if(ent->entityTypeId.type.key == monster) {
						//Dont remove it
						return false;
					}
				}
			}

			if(targetAnimals) {
				for(auto animal : animals) {
					if(ent->entityTypeId.type.key == animal) {
						return false;
					}
				}
			}

			//Doesn't meet any criteria, we don't have enough info on this target. Remove it.
			return true;
		}
	), allActors.end());

	return getClosestActorFromVector(sourceActor, allActors);
}

/*
static_assert(sizeof(AABB)==28, "AABB isnt 28 bytes");
static_assert(offsetof(Player, gameMode)==0x12E8, "gameMode is misaligned at {0}");
static_assert(offsetof(Mob, yHeadRot)==0x728, "yHeadRot is misaligned at {0}");
static_assert(offsetof(Actor, velocity)==0x50C, "velocity is misaligned at {0}");
*/


void Killaura::onActorRotateEvent(ActorRotateEvent& event) {
	//if(event.GetRotationType() == RotationType::CORPSE) { return; }
	
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* player = client->clientPlayer;
	Actor* rotatingActor = event.GetActor();
	if(rotatingActor != player) {return;}; //If the actor isnt the player, don't do anything.
	//Check if player is actually valid
	if(player) {
		//Check if the target is valid
		if(theTarget != nullptr) {
			//Get the positions
			Vector3<float> enemyPos = *theTarget->getPos();
			//enemyPos.y += theTarget->size.y / 2.0f;
			Vector3<float> playerPos = *player->getPos();
			
			//Get the desired view angles (Where the player has to face)
			//this is basically just aimbot math
			Vector2<float> anglesRad = CalcAngle(playerPos, enemyPos); //180/PI gives degrees
			Vector2<float> anglesDeg = anglesRad * (180.0/3.141592653589793238463); //180/PI gives degrees

			//rotate the player to face the desired angles
			event.SetRotation(anglesDeg);
		}
	}
}

#include <sstream>
template< typename T >
std::string int_to_hex( T i )
{
  std::stringstream stream;
  stream << std::hex << i;
  return stream.str();
}

void Killaura::onRenderEvent(RenderEvent& event) {
	MinecraftRenderer* wrapper = event.GetRenderWrapper();
	
	wrapper->DrawString(std::to_string(distance), Vector2<float>(0,0));
	wrapper->DrawString(int_to_hex((uintptr_t)theTarget), Vector2<float>(0,10));
}

Killaura::Killaura() : Module("Killaura") {
	this->addItem(new Setting("Interval", SettingType::SLIDER, &interval, minimumInterval, maximumInterval));
	this->addItem(new Setting("Reach", SettingType::SLIDER, &reachVal, minimumReach, maximumReach));
	this->addItem(new Setting("NoSwing", SettingType::TOGGLE, &noSwing, false, true));

	this->addItem(new Setting("Target Players", SettingType::TOGGLE, &targetPlayers, false, true));
	this->addItem(new Setting("Target Mobs", SettingType::TOGGLE, &targetMobs, false, true));
	this->addItem(new Setting("Target Animals", SettingType::TOGGLE, &targetAnimals, false, true));
	this->addItem(new Setting("Target Actors", SettingType::TOGGLE, &targetActors, false, true));
    
};

void Killaura::OnEnable() {
	EventHandler::registerListener(this);
};

void Killaura::OnDisable() {
	theTarget = nullptr;
	distance = 0;
	EventHandler::unregisterListener(this);
};