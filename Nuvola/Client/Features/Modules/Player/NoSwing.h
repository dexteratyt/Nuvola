#ifndef NUVOLA_CLIENT_FEATURES_MODULES_PLAYER_NOSWING
#define NUVOLA_CLIENT_FEATURES_MODULES_PLAYER_NOSWING

#include "../../Module.h"
#include "../../../Events/Listener.h"
#include "../../../Events/EventHandler.h"

class NoSwing : public Module {
public:
	NoSwing();
	void OnEnable() override;
	void OnDisable() override;
	void OnTick() override;

	void onMobSwingEvent(MobSwingEvent& event) override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_PLAYER_NOSWING */
