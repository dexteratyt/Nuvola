#include "Disabler.h"
#include "../../../Events/EventHandler.h"

#include "../../../Bridge/MovePlayerPacket.h"
#include "../../../Bridge/LocalPlayer.h"
#include "../../../Bridge/Level.h"

Disabler::Disabler() : Module("Disabler") {};

void Disabler::onPacketEvent(PacketEvent& event) {
	Packet* uncastedPacket = event.GetPacket();

	//If MovePlayerPacket
	if(uncastedPacket->getId() == 0x13) {
		//TODO: The actual disabler part
	}
}

void Disabler::OnEnable() {
	EventHandler::registerListener(this);
};

void Disabler::OnDisable() {
	EventHandler::unregisterListener(this);
}