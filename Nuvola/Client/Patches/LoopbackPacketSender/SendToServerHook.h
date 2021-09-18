#ifndef NUVOLA_CLIENT_PATCHES_LOOPBACKPACKETSENDER_SENDTOSERVERHOOK
#define NUVOLA_CLIENT_PATCHES_LOOPBACKPACKETSENDER_SENDTOSERVERHOOK

#include "../IPatch.h"
#include "../../../Utils/Utils.h"

#include "../../Bridge/LoopbackPacketSender.h"

class SendToServerHook : public IPatch {
	static void __fastcall SendToServerHookCallback_1_17_10_4(LoopbackPacketSender* packetSender, void* packet);
public:
	static inline uintptr_t funcOriginal = 0;
	SendToServerHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_LOOPBACKPACKETSENDER_SENDTOSERVERHOOK */
