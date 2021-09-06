#ifndef LUNITY_CLIENT_FEATURES_SETTING
#define LUNITY_CLIENT_FEATURES_SETTING
#include "ManagedItem.h"
#include "ISetting.h"

enum class SettingType{
    TOGGLE,
	SLIDER
};


template <class T>
class Setting : public ISetting, public ManagedItem {
    T minimumValue;
    T maximumValue;
    SettingType type;
public:
    T* value;
    Setting(std::string name, SettingType type, T* defaultValue, T minimumValue, T maximumValue);
	void* getValue() override;
	void setValue(T value);
    T getMinimum();
    T getMaximum();
};

#endif /* LUNITY_CLIENT_FEATURES_SETTING */
