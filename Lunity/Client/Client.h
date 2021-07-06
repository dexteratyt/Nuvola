#ifndef LUNITY_CLIENT_CLIENT
#define LUNITY_CLIENT_CLIENT
#include <string>
#include <vector>

#include "../Mem/Mem.h"
#include "../Utils/Utils.h"

#include "Features/Module.h"
#include "Features/ModuleMgr.h"

class Client {
public:
    std::string name;

    Client(std::string name){
        this->name = name;
        Utils::DebugF(std::string("Initialized " + std::string(this->name)));

		//Get Module Manager instance;
		ModuleMgr* moduleManager = ModuleMgr::getInstance();
		//Get all modules
		std::vector<Module*>* allMods = moduleManager->getAllModules();

		//Loop through
		for(auto module : *allMods) {
			Utils::DebugF(module->getName());
		}
    };
};


#endif /* LUNITY_CLIENT_CLIENT */
