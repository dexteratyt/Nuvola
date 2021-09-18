#include "NoPacket.h"
#include "../../../Events/EventHandler.h"

NoPacket::NoPacket() : Module("NoPacket") {};

void NoPacket::onPacket(PacketEvent& event) {
	event.Cancel();
}

void NoPacket::OnEnable() {
	EventHandler::registerListener(this);
};

void NoPacket::OnDisable() {
	EventHandler::unregisterListener(this);
}