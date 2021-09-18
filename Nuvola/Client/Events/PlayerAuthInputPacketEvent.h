#ifndef NUVOLA_CLIENT_EVENTS_PLAYERAUTHINPUTPACKETEVENT
#define NUVOLA_CLIENT_EVENTS_PLAYERAUTHINPUTPACKETEVENT

#include "PacketEvent.h"
#include "../bridge/PlayerAuthInputPacket.h"

class PlayerAuthInputPacketEvent : public PacketEvent {
public:
	PlayerAuthInputPacketEvent(PlayerAuthInputPacket* packet) : PacketEvent(packet) {}

	auto GetPacket() -> PlayerAuthInputPacket* {
		return (PlayerAuthInputPacket*)PacketEvent::GetPacket();
	}
};

#endif /* NUVOLA_CLIENT_EVENTS_PLAYERAUTHINPUTPACKETEVENT */
