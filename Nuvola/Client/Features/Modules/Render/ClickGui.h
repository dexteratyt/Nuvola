#ifndef LUNITY_CLIENT_FEATURES_MODULES_RENDER_CLICKGUI
#define LUNITY_CLIENT_FEATURES_MODULES_RENDER_CLICKGUI

#include "../../Module.h"
#include "../../../Events/Listener.h"
#include "../../../Events/EventHandler.h"

class ClickGui : public Module {
public:
	ClickGui();
	void OnEnable() override;
	void OnDisable() override;

	void onRenderEvent(RenderEvent& event) override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_RENDER_CLICKGUI */
