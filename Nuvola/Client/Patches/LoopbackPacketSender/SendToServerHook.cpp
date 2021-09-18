#include  "SendToServerHook.h"

#include "../../Events/PacketEvent.h"
#include "../../Events/EventHandler.h"

void __fastcall SendToServerHook::SendToServerHookCallback_1_17_10_4(LoopbackPacketSender* packetSender, Packet* packet) {

	PacketEvent event(packet);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onPacket(event);
	}
	if(event.IsCancelled()) {
		return;
	}

	switch(packet->getId()) {
		case (int)PACKET_IDS::PlayerAuthInputPacket:
			PlayerAuthInputPacketEvent event((PlayerAuthInputPacket*)packet);
			for(auto listener : listeners) {
				listener->onPlayerAuthInputPacket(event);
			}
			break;
	}

	PLH::FnCast(funcOriginal, &SendToServerHookCallback_1_17_10_4)(packetSender, packet);
}

SendToServerHook::SendToServerHook() : IPatch::IPatch("LoopbackPacketSender::SendToServer") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 81 ?? ?? ?? ?? ?? 0F ?? ?? ?? 48"), -1));
}

auto SendToServerHook::Apply() -> bool {
	return this->AutoPatch(&SendToServerHookCallback_1_17_10_4, &funcOriginal);
}