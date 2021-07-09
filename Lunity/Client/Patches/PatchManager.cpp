#include "PatchManager.h"
#include "IPatch.h"
#include <iostream>

#include "ClientInstance/UpdateHook.h"
#include "Dx12/SwapChainHook.h"

void PatchManager::ApplyAll()
{
	PatchManager::ApplyPatch(new UpdateHook());
    PatchManager::ApplyPatch(new SwapChainHook());
}

void PatchManager::ApplyPatch(IPatch* toAdd)
{
    if(toAdd->Apply())
    {
		Utils::DebugF("PRE PUSH BACK");
        PatchManager::patches->push_back(toAdd);
		Utils::DebugF("POST PUSH BACK");
        Utils::DebugF("Successfully applied \'" + toAdd->GetName() + "\' patch!");
    }
    else
    {
        Utils::DebugF("Failed to apply patch: " + toAdd->GetName());
    }
}