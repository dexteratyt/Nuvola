#ifndef NUVOLA_CLIENT_FEATURES_MODULES_RENDER_FREELOOK
#define NUVOLA_CLIENT_FEATURES_MODULES_RENDER_FREELOOK

#include "../../Module.h"

class Freelook : public Module {
public:
	Freelook();
	void OnEnable() override;
	void OnDisable() override;

	void onActorRotateEvent(ActorRotateEvent& event) override;
	void onKeyEvent(KeyEvent& event) override;
};

#endif /* NUVOLA_CLIENT_FEATURES_MODULES_RENDER_FREELOOK */
