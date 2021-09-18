#ifndef NUVOLA_CLIENT_EVENTS_PACKETEVENT
#define NUVOLA_CLIENT_EVENTS_PACKETEVENT

#include "Event.h"
#include "Cancellable.h"
#include "../Bridge/Packet.h"

class PacketEvent : public Event, public Cancellable {
	Packet* packet;
public:
	PacketEvent(Packet* packet) : Event() {
		this->packet = packet;
	};

	auto GetPacket() -> Packet* {
		return this->packet;
	}
};

#endif /* NUVOLA_CLIENT_EVENTS_PACKETEVENT */
