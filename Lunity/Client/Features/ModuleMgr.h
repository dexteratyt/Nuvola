#ifndef LUNITY_CLIENT_FEATURES_MODULEMGR
#define LUNITY_CLIENT_FEATURES_MODULEMGR
#include <iostream>
#include <vector>
#include "Category.h"
#include "Module.h"

class ModuleMgr : public Manager<Category> {
    static ModuleMgr * instance;
public:
    ModuleMgr();
    static ModuleMgr * getInstance();
    std::vector<Module*>* getAllModules();
	Module* findModule(std::string name);
};

#endif /* LUNITY_CLIENT_FEATURES_MODULEMGR */
