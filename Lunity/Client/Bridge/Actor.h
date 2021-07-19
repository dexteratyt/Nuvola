#ifndef LUNITY_CLIENT_BRIDGE_ACTOR
#define LUNITY_CLIENT_BRIDGE_ACTOR
#include "DynamicStruct.h"

struct Actor {
	DYN_FIELD(OnGround, 0x1E0, bool);

/*
	auto Get_OnGround() -> bool {
		void* addr = this+0x1E0;
		return *(bool*)addr;
	}
	auto Set_OnGround(bool newVal) -> void {
		void* addr = this+0x1E0;
		*(bool*)addr = newVal;
	}
*/

    // Actor() : Actor("Actor") {};
    // Actor(std::string structName) : DynamicStruct(structName, 0) {
    //     this->AddField("OnGround", 0x1E0);
    // };

	// auto IsOnGround() -> bool {
	// 	bool* theVal = (bool*)this->GetField("OnGround");
	// 	return *theVal;
	// }
	// void SetOnGround(bool onGround) {
	// 	bool* theVal = (bool*)this->GetField("OnGround");
	// 	*theVal = onGround;
	// }
};

#endif /* LUNITY_CLIENT_BRIDGE_ACTOR */
