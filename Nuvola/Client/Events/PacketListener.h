#ifndef NUVOLA_CLIENT_EVENTS_PACKETLISTENER
#define NUVOLA_CLIENT_EVENTS_PACKETLISTENER

#include "PacketEvent.h"
#include "PlayerAuthInputPacketEvent.h"

enum class PACKET_IDS {
	PlayerAuthInputPacket = 0x90
};

class PacketListener {
public:
	virtual void onPacket(PacketEvent& event) {};
	virtual void onPlayerAuthInputPacket(PlayerAuthInputPacketEvent& event) {};
};

#endif /* NUVOLA_CLIENT_EVENTS_PACKETLISTENER */
