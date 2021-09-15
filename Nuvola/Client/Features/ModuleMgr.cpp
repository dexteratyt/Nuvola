#include "ModuleMgr.h"

#define 

//Combat
#include "Modules/Combat/Killaura.h"
//Render
#include "Modules/Render/ModList.h"
#include "Modules/Render/TabUI.h"
#include "Modules/Render/ClickGui.h"
//Motion
#include "Modules/Motion/Airjump.h"
#include "Modules/Motion/TestFly.h"
//Player
#include "Modules/Player/NoSwing.h"
//Misc
#include "Modules/Misc/Uninject.h"

//Events
#include "../Events/EventHandler.h"

void ModuleMgr::onKeyEvent(KeyEvent& event) {
	if(event.GetAction() == KeyAction::PRESSED) {
		ModuleMgr* mgr = ModuleMgr::getInstance();
		for(auto mod : *mgr->getAllModules()) {
			if(mod->GetHotkey() == event.GetKey()) {
				mod->Toggle();
			}
		}
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
	render->addItem(new ModList());
	render->addItem(new TabUI());
	render->addItem(new ClickGui());
    //Motion
	motion->addItem(new Airjump());
	//motion->addItem(new TestFly());
    //Player
	player->addItem(new NoSwing());
    //Misc
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

Module* ModuleMgr::findModule(std::string name) {
	std::vector<Module*>* allModules = this->getAllModules();
	for(auto mod : *allModules) {
		if(mod->getName() == name) {
			return mod;
		}
	}
	return nullptr;
}