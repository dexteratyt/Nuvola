#ifndef LUNITY_CLIENT_BRIDGE_MOB
#define LUNITY_CLIENT_BRIDGE_MOB
#include "Actor.h"

struct Mob : Actor {
    Mob() : Actor("Mob") {

    };
    Mob(std::string structName) : Actor(structName) {

    };
};

#endif /* LUNITY_CLIENT_BRIDGE_MOB */
