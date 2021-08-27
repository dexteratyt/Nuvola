#include <thread>
#include <string>
#include <vector>
#include <iostream>

#include "Mem/Mem.h"
#include "Utils/Utils.h"

#include "Client/Features/Module.h"
#include "Client/Features/ModuleMgr.h"

#include "Client/Patches/PatchManager.h"

#include "Client/Bridge/Actor.h"

void init() {
#ifdef LOG_CONSOLE
	AllocConsole();
	FILE *fDummy;
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
#endif

	Utils::DebugF(std::string("Initialized Lunity"));

	//Apply all patches
	PatchManager::ApplyAll();

	//Get Module Manager instance;
	ModuleMgr* moduleManager = ModuleMgr::getInstance();
	//Get all modules
	std::vector<Module*>* allMods = moduleManager->getAllModules();

	//Loop through
	for(auto mod : *allMods) {
		Utils::DebugF(mod->getName());
	}

	//Web panel gui
	//Doesnt work & idk why
	//WebPanel::getInstance()->start(420);

	//Lunity tick caller
	while(true) {
		for(auto mod : *allMods) {
			mod->OnLunityTick();
		}
	}
}

auto __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) -> bool {
	if(fdwReason == DLL_PROCESS_ATTACH) {
		Mem::SetThisModule(hinstDLL);
		std::thread(init).detach();
	}
    return true;  // Successful DLL_PROCESS_ATTACH
}