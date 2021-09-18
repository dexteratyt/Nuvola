#ifndef NUVOLA_CLIENT_FEATURES_MODULES_MISC_NOPACKET
#define NUVOLA_CLIENT_FEATURES_MODULES_MISC_NOPACKET

#include "../../../Utils/Utils.h"
#include "../../Module.h"

class NoPacket : public Module {
public:
	NoPacket();
	void OnEnable() override;
	void OnDisable() override;
	void onPacketEvent(PacketEvent& event) override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_MISC_NOPACKET */
