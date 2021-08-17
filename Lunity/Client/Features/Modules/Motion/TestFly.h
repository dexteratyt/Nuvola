#ifndef LUNITY_CLIENT_FEATURES_MODULES_MOTION_TESTFLY
#define LUNITY_CLIENT_FEATURES_MODULES_MOTION_TESTFLY

#include "../../Module.h"

class TestFly : public Module {
public:
	TestFly();
	void OnEnable() override;
	void OnDisable() override;
	void OnTick() override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_MOTION_TESTFLY */
