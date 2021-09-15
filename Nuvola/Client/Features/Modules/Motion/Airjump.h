#ifndef LUNITY_CLIENT_FEATURES_MODULES_MOTION_AIRJUMP
#define LUNITY_CLIENT_FEATURES_MODULES_MOTION_AIRJUMP

#include "../../Module.h"

class Airjump : public Module {
public:
	Airjump();
	void OnEnable() override;
	void OnDisable() override;
	void OnTick() override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_MOTION_AIRJUMP */
