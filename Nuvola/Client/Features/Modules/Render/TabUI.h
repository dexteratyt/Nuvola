#ifndef NUVOLA_CLIENT_FEATURES_MODULES_RENDER_TABUI
#define NUVOLA_CLIENT_FEATURES_MODULES_RENDER_TABUI

#include "../../Module.h"
#include "../../../Events/EventHandler.h"

class TabUI : public Module {
public:
	TabUI();
	void OnEnable() override;
	void OnDisable() override;

	void onRenderEvent(RenderEvent& event) override;
	void onMouseEvent(MouseEvent& event) override;
	void onKeyEvent(KeyEvent& event) override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_RENDER_TABUI */
