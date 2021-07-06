#ifndef LUNITY_CLIENT_FEATURES_MODULE
#define LUNITY_CLIENT_FEATURES_MODULE
#include <iostream>
#include <string>
#include <utility>
#include "Manager.h"
#include "Setting.h"

class Module : public Manager<Setting> {
public:
    explicit Module(std::string name);

    virtual void onTick();
    virtual void onGmTick(class GameMode* gm);
    virtual void onEnable();
    virtual void onDisable();
    virtual void onKey(int key, bool isPressed);
    virtual void onMouseButton(char button, bool isPressed);
    virtual void onMouseMove();
    virtual void onRender(class Renderer*);
};


#endif /* LUNITY_CLIENT_FEATURES_MODULE */
