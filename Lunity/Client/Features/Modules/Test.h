#ifndef LUNITY_CLIENT_FEATURES_MODULES_TEST
#define LUNITY_CLIENT_FEATURES_MODULES_TEST
#include "../Module.h"

class Test : public Module {
public:
	Test() : Module("Test") {};
	void onEnable() override;
	void onDisable() override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_TEST */
