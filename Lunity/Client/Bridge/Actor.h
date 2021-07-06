#ifndef LUNITY_CLIENT_BRIDGE_ACTOR
#define LUNITY_CLIENT_BRIDGE_ACTOR
#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor() : DynamicStruct("Actor", 0) {

    };
    Actor(std::string structName) : DynamicStruct(structName, 0) {
        
    };
};

#endif /* LUNITY_CLIENT_BRIDGE_ACTOR */
