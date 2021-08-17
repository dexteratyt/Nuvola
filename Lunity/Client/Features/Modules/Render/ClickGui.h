#ifndef LUNITY_CLIENT_FEATURES_MODULES_RENDER_CLICKGUI
#define LUNITY_CLIENT_FEATURES_MODULES_RENDER_CLICKGUI

#include "../../Module.h"

class ClickGui : public Module {
public:
	ClickGui();
	void OnEnable() override;
	void OnDisable() override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_RENDER_CLICKGUI */
