#ifndef LUNITY_CLIENT_FEATURES_MODULES_RENDER_MODLIST
#define LUNITY_CLIENT_FEATURES_MODULES_RENDER_MODLIST

#include "../../Module.h"

class ModList : public Module {
public:
	ModList();
	void onEnable() override;
	void onDisable() override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_RENDER_MODLIST */
