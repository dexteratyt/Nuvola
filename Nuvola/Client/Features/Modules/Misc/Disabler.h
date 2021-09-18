#ifndef NUVOLA_CLIENT_FEATURES_MODULES_MISC_DISABLER
#define NUVOLA_CLIENT_FEATURES_MODULES_MISC_DISABLER

#include "../../../Utils/Utils.h"
#include "../../Module.h"

class Disabler : public Module {
public:
	Disabler();
	void OnEnable() override;
	void OnDisable() override;
	void onPacketEvent(PacketEvent& event) override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_MISC_DISABLER */
