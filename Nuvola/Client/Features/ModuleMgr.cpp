#include "ModuleMgr.h"

//Combat
#include "Modules/Combat/Killaura.h"
//Render
#include "Modules/Render/ClickGui.h"
#include "Modules/Render/Freelook.h"
#include "Modules/Render/ModList.h"
#include "Modules/Render/TabUI.h"
//Motion
#include "Modules/Motion/Airjump.h"
#include "Modules/Motion/Jetpack.h"
//Player
#include "Modules/Player/NoSwing.h"
//Misc
#include "Modules/Misc/Disabler.h"
#include "Modules/Misc/NoPacket.h"
#include "Modules/Misc/Uninject.h"

//Events
#include "../Events/EventHandler.h"

void ModuleMgr::onKeyEvent(KeyEvent& event) {
	ModuleMgr* mgr = ModuleMgr::getInstance();
	for(auto mod : *mgr->getAllModules()) {
		mod->onHotkeyCheckEvent(event);
	}
}

ModuleMgr::ModuleMgr() : Manager<Category>("ModuleManager") {
    //Set instance
    instance = this;
    //Create categories
    auto* combat = new Category("Combat");
    auto* render = new Category("Render");
    auto* motion = new Category("Motion");
    auto* player = new Category("Player");
    auto* misc   = new Category("Misc");

    //Combat
	combat->addItem(new Killaura());
    //Render
	render->addItem(new ClickGui());
	render->addItem(new Freelook());
	render->addItem(new ModList());
	render->addItem(new TabUI());
    //Motion
	motion->addItem(new Airjump());
	motion->addItem(new Jetpack());
    //Player
	player->addItem(new NoSwing());
    //Misc
	misc->addItem(new Disabler());
	misc->addItem(new NoPacket());
	misc->addItem(new Uninject());

    //Register categories
    this->addItem(combat);
    this->addItem(render);
    this->addItem(motion);
    this->addItem(player);
    this->addItem(misc);

	EventHandler::registerListener(this);

    //LogFile::log("Created ModuleManager instance!");
}

ModuleMgr *ModuleMgr::instance = nullptr;

ModuleMgr *ModuleMgr::getInstance() {
	if(instance == nullptr) {
		instance = new ModuleMgr();
	}
    return instance;
}

std::vector<Module*>* ModuleMgr::getAllModules() {
    //Create new vector for returning all Modules
    auto* allModules = new std::vector<Module*>();
    //Get all categories
    std::vector<Category*>* categories = getItems();
    //Loop through all categories
    for (auto currentCategory : *categories) {
        //Get all Modules from the Category
        std::vector<Module*>* Modules = currentCategory->getItems();
        //Add the Modules to the allModules vector to be returned
        for (auto Module : *Modules) {
            allModules->push_back(Module);
        }
    }
    //If allModules is empty, return nullptr instead
    if (allModules->empty()) {
        //Delete allModules because its not needed
        delete allModules;
        return nullptr;
    }
    //Return allModules
    return allModules;
}

std::string toLower(std::string in) {
	std::string lower = "";
	for(auto c : in) {
		if(c <= 'Z'&& c >= 'A') {
			lower += (c - ('Z'- 'z'));
			continue;
		}
		lower += c;
	}
	return lower;
}

Module* ModuleMgr::findModule(std::string name) {
	std::vector<Module*>* allModules = this->getAllModules();
	for(auto mod : *allModules) {
		std::string modName = mod->getName();
		if(toLower(modName) == toLower(name)) {
			return mod;
		}
	}
	return nullptr;
}