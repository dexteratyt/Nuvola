#ifndef LUNITY_CLIENT_BRIDGE_ACTOR
#define LUNITY_CLIENT_BRIDGE_ACTOR
#include "DynamicStruct.h"

struct Actor : DynamicStruct {
    Actor() : Actor("Actor") {};
    Actor(std::string structName) : DynamicStruct(structName, 0) {
        this->AddField(new DynamicField("OnGround", 0x1E0));
    };

	auto IsOnGround() -> bool {
		DynamicField* theField = (DynamicField*)this->Get("OnGround");
		bool* theVal = (bool*)theField->AsVoid();
		return *theVal;
	}
	void SetOnGround(bool onGround) {
		DynamicField* theField = (DynamicField*)this->Get("OnGround");
		bool* theVal = (bool*)theField->AsVoid();
		*theVal = onGround;
	}
};

#endif /* LUNITY_CLIENT_BRIDGE_ACTOR */
