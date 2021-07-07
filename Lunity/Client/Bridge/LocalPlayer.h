#ifndef LUNITY_CLIENT_BRIDGE_LOCALPLAYER
#define LUNITY_CLIENT_BRIDGE_LOCALPLAYER
#include "Player.h"

struct LocalPlayer : Player {
    LocalPlayer() : Player("LocalPlayer") {

    };
    LocalPlayer(std::string structName) : Player(structName) {

    };
};

#endif /* LUNITY_CLIENT_BRIDGE_LOCALPLAYER */