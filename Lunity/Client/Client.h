#ifndef LUNITY_CLIENT_CLIENT
#define LUNITY_CLIENT_CLIENT
//#include "Panel/WebPanel.h"

#include <string>
#include <vector>

#include "../Mem/Mem.h"
#include "../Utils/Utils.h"

#include "Features/Module.h"
#include "Features/ModuleMgr.h"

#include "Patches/PatchManager.h"

class Client {
public:
    std::string name;

    Client(std::string name){
        this->name = name;
        Utils::DebugF(std::string("Initialized " + std::string(this->name)));

		//Apply all patches
		PatchManager::ApplyAll();

		//Get Module Manager instance;
		ModuleMgr* moduleManager = ModuleMgr::getInstance();
		//Get all modules
		std::vector<Module*>* allMods = moduleManager->getAllModules();

		//Loop through
		for(auto module : *allMods) {
			Utils::DebugF(module->getName());
		}

		//Web panel gui
		//Doesnt work & idk why
		//WebPanel::getInstance()->start(420);
    };
};

#endif /* LUNITY_CLIENT_CLIENT */