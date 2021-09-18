#ifndef NUVOLA_CLIENT_FEATURES_MODULES_MOTION_JETPACK
#define NUVOLA_CLIENT_FEATURES_MODULES_MOTION_JETPACK

#include "../../Module.h"

class Jetpack : public Module {
public:
	Jetpack();
	void OnEnable() override;
	void OnDisable() override;
	void OnTick() override;

	void onHotkeyCheckEvent(KeyEvent& event) override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_MOTION_JETPACK */
