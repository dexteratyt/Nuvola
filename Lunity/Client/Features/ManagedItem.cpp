#include "ManagedItem.h"

std::string ManagedItem::getName() {
    return name;
}

ManagedItem::ManagedItem(std::string name) {
    this->name = name;
}

bool ManagedItem::isManager() {
    return false;
}