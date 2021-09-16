#ifndef NUVOLA_CLIENT_FEATURES_MODULES_MOTION_TESTFLY
#define NUVOLA_CLIENT_FEATURES_MODULES_MOTION_TESTFLY

#include "../../Module.h"

class TestFly : public Module {
public:
	TestFly();
	void OnEnable() override;
	void OnDisable() override;
	void OnTick() override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_MOTION_TESTFLY */
