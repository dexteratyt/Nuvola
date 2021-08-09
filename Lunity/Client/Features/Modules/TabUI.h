#ifndef LUNITY_CLIENT_FEATURES_MODULES_TABUI
#define LUNITY_CLIENT_FEATURES_MODULES_TABUI

#include "../Module.h"

class TabUI : public Module {
public:
	TabUI();
	void onEnable() override;
	void onDisable() override;
};

#endif /* LUNITY_CLIENT_FEATURES_MODULES_TABUI */
