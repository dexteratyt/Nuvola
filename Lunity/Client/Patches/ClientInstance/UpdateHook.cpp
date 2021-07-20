#include "UpdateHook.h"

auto __fastcall UpdateHook::clientInstanceCallback_1_17_2_1(uintptr_t theInstance, char param_2) -> int {
    Utils::SetClientInstance(theInstance);

	std::vector<Module*>* modules = ModuleMgr::getInstance()->getAllModules();
	for(auto module : *modules) {
		module->onTick();
	}

    return PLH::FnCast(funcOriginal, &clientInstanceCallback_1_17_2_1)(theInstance, param_2);
}

UpdateHook::UpdateHook() : IPatch::IPatch("ClientInstance::Update") {
	//Ok I get it, this system is heap hell.
	//I just dont want objects getting destroyed
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? ?? 89 ?? ?? ?? ?? 89 ?? ?? ?? 55 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 44 0F ?? ?? 48 8B ?? 45"), -1));
}

auto UpdateHook::Apply() -> bool {
	return this->AutoPatch(clientInstanceCallback_1_17_2_1, &funcOriginal);
}