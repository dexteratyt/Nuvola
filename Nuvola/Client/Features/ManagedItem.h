#ifndef NUVOLA_CLIENT_FEATURES_MANAGEDITEM
#define NUVOLA_CLIENT_FEATURES_MANAGEDITEM
#include <iostream>
#include <string>

#include "../../Utils/Utils.h"

class ManagedItem {
protected:
    std::string name;
public:
    explicit ManagedItem(std::string name);
    virtual std::string getName();
    virtual bool isManager();
};

#endif /* NUVOLA_CLIENT_FEATURES_MANAGEDITEM */
