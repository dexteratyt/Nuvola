#ifndef LUNITY_CLIENT_BRIDGE_ACTOR
#define LUNITY_CLIENT_BRIDGE_ACTOR
#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor() : Actor("Actor") {};
    Actor(std::string structName) : DynamicStruct(structName, 0) {
        this->addField(new DynamicField("onGround", 0x1E0));
    };

	auto isOnGround() -> bool {
		DynamicField* theField = (DynamicField*)this->get("onGround");
		bool* theVal = (bool*)theField->asVoid();
		return *theVal;
	}
	void setOnGround(bool onGround) {
		DynamicField* theField = (DynamicField*)this->get("onGround");
		bool* theVal = (bool*)theField->asVoid();
		*theVal = onGround;
	}
};

#endif /* LUNITY_CLIENT_BRIDGE_ACTOR */
