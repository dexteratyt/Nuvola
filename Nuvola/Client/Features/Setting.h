#ifndef NUVOLA_CLIENT_FEATURES_SETTING
#define NUVOLA_CLIENT_FEATURES_SETTING
#include "ManagedItem.h"
#include "ISetting.h"

enum class SettingType{
    TOGGLE,
	SLIDER
};


template <class T> class Setting : public ISetting, public ManagedItem {
    T minimumValue;
    T maximumValue;
    SettingType type;
public:
    T* value;
    explicit Setting(std::string name, SettingType type, T* defaultValue, T minimumValue, T maximumValue) : ManagedItem(name), ISetting() {
		this->type         = type;
		this->maximumValue = maximumValue;
		this->minimumValue = minimumValue;
		this->value        = value;
	}
	void* getValue() override {
		return this->value;
	}
	void setValue(T value) {
		*this->value = value;
	}
    T getMinimum() {
		return this->minimumValue;
	}
    T getMaximum() {
		return this->maximumValue;
	}
};

#endif /* NUVOLA_CLIENT_FEATURES_SETTING */
