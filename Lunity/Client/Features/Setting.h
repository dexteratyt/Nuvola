#ifndef LUNITY_CLIENT_FEATURES_SETTING
#define LUNITY_CLIENT_FEATURES_SETTING
#include "ManagedItem.h"

enum class SettingType{
    TOGGLE,
	SLIDER
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

#endif /* LUNITY_CLIENT_FEATURES_SETTING */
