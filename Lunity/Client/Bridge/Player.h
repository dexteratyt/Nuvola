#ifndef LUNITY_CLIENT_BRIDGE_PLAYER
#define LUNITY_CLIENT_BRIDGE_PLAYER
#include "Mob.h"

struct Player : Mob {
    Player() : Mob("Player") {

    };
    Player(std::string structName) : Mob(structName) {

    };
};

#endif /* LUNITY_CLIENT_BRIDGE_PLAYER */
