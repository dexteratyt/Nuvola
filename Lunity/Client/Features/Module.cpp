#include "Module.h"

Module::Module(std::string name) : Manager<Setting>(name) {

}

void Module::onEnable() {

}

void Module::onDisable() {

}

bool Module::isEnabled() {
	return this->enabled;
}

void Module::setEnabled(bool enabled) {
	this->enabled = enabled;
}

void Module::toggle() {
	this->enabled = !this->enabled;
}