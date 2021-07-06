#ifndef LUNITY_CLIENT_CLIENT
#define LUNITY_CLIENT_CLIENT
#include <string>
#include <vector>

#include "Mem/Mem.h"
#include "Utils/Utils.h"

#include "Client/Modules/Module.h"

class Client {
public:
    std::string name;
    std::vector<Module*> modules;

    Client(std::string name){
        this->name = name;
        Utils::DebugF(std::string("Initialized " + std::string(this->name)));
    };
};


#endif /* LUNITY_CLIENT_CLIENT */
