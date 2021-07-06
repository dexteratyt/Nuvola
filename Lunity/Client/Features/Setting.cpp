#include "Setting.h"

Setting::Setting(std::string name, SettingType type, void* defaultValue, void* minimumValue, void* maximumValue) : ManagedItem(name) {
    this->type         = type;
    this->maximumValue = maximumValue;
    this->minimumValue = minimumValue;
    this->value        = defaultValue;
}

void *Setting::getValue() {
    return this->value;
}

void *Setting::getMinimum() {
    return this->minimumValue;
}

void *Setting::getMaximum() {
    return this->maximumValue;
}