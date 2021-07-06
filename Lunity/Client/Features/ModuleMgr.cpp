#include "ModuleMgr.h"

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
    //Render
    //render->addItem(new hud());
    //Motion
    //Player
    //Misc
    //misc->addItem(new unload());

    //Register categories
    this->addItem(combat);
    this->addItem(render);
    this->addItem(motion);
    this->addItem(player);
    this->addItem(misc);

    //LogFile::log("Created ModuleManager instance!");
}

ModuleMgr *ModuleMgr::instance = nullptr;

ModuleMgr *ModuleMgr::getInstance() {
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