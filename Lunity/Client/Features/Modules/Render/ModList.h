#ifndef LUNITY_CLIENT_FEATURES_MODULES_RENDER_MODLIST
#define LUNITY_CLIENT_FEATURES_MODULES_RENDER_MODLIST

#include "../../Module.h"

class ModList : public Module {
public:
	ModList();
	void OnEnable() override;
	void OnDisable() override;
	
	void onRenderEvent(RenderEvent& event) override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_RENDER_MODLIST */
