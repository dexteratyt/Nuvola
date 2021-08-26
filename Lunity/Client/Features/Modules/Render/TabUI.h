#ifndef LUNITY_CLIENT_FEATURES_MODULES_TABUI
#define LUNITY_CLIENT_FEATURES_MODULES_TABUI

#include "../../Module.h"
#include "../../../Events/EventHandler.h"

class TabUI : public Module {
public:
	TabUI();
	void OnEnable() override;
	void OnDisable() override;

	void onRenderEvent(RenderEvent& event) override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_TABUI */
