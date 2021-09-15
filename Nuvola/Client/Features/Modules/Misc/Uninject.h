#ifndef NUVOLA_CLIENT_FEATURES_MODULES_MISC_UNINJECT
#define NUVOLA_CLIENT_FEATURES_MODULES_MISC_UNINJECT

#include "../../../Utils/Utils.h"
#include "../../Module.h"

class Uninject : public Module {
public:
	Uninject();
	void OnEnable() override;
	void OnDisable() override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_MISC_UNINJECT */
