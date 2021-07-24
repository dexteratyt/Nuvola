#ifndef LUNITY_CLIENT_BRIDGE_ACTOR
#define LUNITY_CLIENT_BRIDGE_ACTOR

#include "DynamicStruct.h"
#include "BlockSource.h"
#include "Dimension.h"

struct Actor {
	DYN_FIELD(OnGround, 0x1E0, bool);
	DYN_FIELD(WorldSource, 0x368, BlockSource*);
	DYN_FIELD(Dim, 0x368, Dimension*);

	DYN_FUNC(setRot, "89 ?? ?? ?? 57 48 83 ?? ?? 8B ?? ?? 48 8B ?? 48 81", -1, void, Vector2<float> pos, pos);

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
