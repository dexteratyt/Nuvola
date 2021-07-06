#ifndef LUNITY_CLIENT_FEATURES_Setting
#define LUNITY_CLIENT_FEATURES_Setting
#include "ManagedItem.h"

enum class SettingType{
    TOGGLE
};

class Setting : ManagedItem {
    void* minimumValue;
    void* maximumValue;
    SettingType type;
public:
    void* value;
    Setting(std::string name, SettingType type, void* defaultValue, void* minimumValue, void* maximumValue);
    void* getValue();
    void* getMinimum();
    void* getMaximum();
};

#endif /* LUNITY_CLIENT_FEATURES_Setting */
