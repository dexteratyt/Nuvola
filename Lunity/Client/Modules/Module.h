#ifndef LUNITY_CLIENT_MODULES_MODULE
#define LUNITY_CLIENT_MODULES_MODULE
#include <string>

class Module {
public:
    std::string name;

    bool isEnabled, wasEnabled;

    Module(std::string name){
        this->name = name;
    };

    void setState(bool, bool);
};


#endif /* LUNITY_CLIENT_MODULES_MODULE */
