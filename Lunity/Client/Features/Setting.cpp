#include "Setting.h"

template <class T>
Setting<T>::Setting(std::string name, SettingType type, T* value, T minimumValue, T maximumValue) : ManagedItem(name) {
    this->type         = type;
    this->maximumValue = maximumValue;
    this->minimumValue = minimumValue;
    this->value        = value;
}

template <class T>
void* Setting<T>::getValue() {
    return this->value;
}

template <class T>
void Setting<T>::setValue(T value) {
	*this->value = value;
}

template <class T>
T Setting<T>::getMinimum() {
    return this->minimumValue;
}

template <class T>
T Setting<T>::getMaximum() {
    return this->maximumValue;
}