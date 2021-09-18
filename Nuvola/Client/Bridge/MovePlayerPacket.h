#ifndef GUARD_MovePlayerPacket
#define GUARD_MovePlayerPacket
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
#include "Packet.h"
struct MovePlayerPacket : public Packet {
	/* Fields */
	char padding_48[48];
	size_t actorRuntimeID;
	Vector3<float> pos;
	Vector2<float> lookingVec;
	char padding_81[5];
	bool onGround;
	/* Virtuals */
	/* Functions */
};
#endif