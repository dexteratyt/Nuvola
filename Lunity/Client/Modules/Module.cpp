#include "Module.h"

void Module::setState(bool state, bool cancelOnEvent = false){
    this->isEnabled = state;

    if(cancelOnEvent) this->wasEnabled = state; /* Cancel onEnable event */
}