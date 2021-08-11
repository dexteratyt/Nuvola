#ifndef LUNITY_CLIENT_FEATURES_MODULE
#define LUNITY_CLIENT_FEATURES_MODULE
#include <iostream>
#include <string>
#include <utility>
#include "Manager.h"
#include "Setting.h"
#include "../Events/EventHandler.h"

class Module : public Manager<Setting> {
	bool enabled;
public:
    explicit Module(std::string name);

    virtual void onEnable();
    virtual void onDisable();
	bool isEnabled();
	void setEnabled(bool enabled);
	void toggle();
};


#endif /* LUNITY_CLIENT_FEATURES_MODULE */
