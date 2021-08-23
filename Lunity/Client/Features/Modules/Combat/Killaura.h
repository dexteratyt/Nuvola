#ifndef LUNITY_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA
#define LUNITY_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA

#include "../../Module.h"

class Killaura : public Module {
public:
	Killaura();
	void OnEnable() override;
	void OnDisable() override;
};



#endif /* LUNITY_CLIENT_FEATURES_MODULES_COMBAT_KILLAURA */
