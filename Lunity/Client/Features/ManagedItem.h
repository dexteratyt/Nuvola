#ifndef LUNITY_CLIENT_FEATURES_MANAGEDITEM
#define LUNITY_CLIENT_FEATURES_MANAGEDITEM
#include <iostream>
#include <string>

class ManagedItem {
protected:
    std::string name;
public:
    explicit ManagedItem(std::string name);
    virtual std::string getName();
    virtual bool isManager();
};

#endif /* LUNITY_CLIENT_FEATURES_MANAGEDITEM */
