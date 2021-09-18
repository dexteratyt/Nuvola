#include  "SendToServerHook.h"

#include "../../Events/PacketEvent.h"
#include "../../Events/EventHandler.h"

void __fastcall SendToServerHook::SendToServerHookCallback_1_17_10_4(LoopbackPacketSender* packetSender, Packet* packet) {

	PacketEvent event(packet);
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onPacketEvent(event);
	}
	if(event.IsCancelled()) {
		return;
	}

	PLH::FnCast(funcOriginal, &SendToServerHookCallback_1_17_10_4)(packetSender, packet);
}

SendToServerHook::SendToServerHook() : IPatch::IPatch("LoopbackPacketSender::SendToServer") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 81 ?? ?? ?? ?? ?? 0F ?? ?? ?? 48"), -1));
}

auto SendToServerHook::Apply() -> bool {
	return this->AutoPatch(&SendToServerHookCallback_1_17_10_4, &funcOriginal);
}