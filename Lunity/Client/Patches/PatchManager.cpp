#include "PatchManager.h"
#include "IPatch.h"
#include <iostream>

#include "ClientInstance/UpdateHook.h"
#include "Dx11/SwapChainHook.h"

void PatchManager::ApplyAll()
{
	PatchManager::ApplyPatch(new UpdateHook());
	PatchManager::ApplyPatch(new SwapChainHook());
}

void PatchManager::ApplyPatch(IPatch* toAdd)
{
    if(toAdd->Apply())
    {
        PatchManager::patches->push_back(toAdd);
        Utils::DebugF("Successfully applied \'" + toAdd->GetName() + "\' patch!");
    }
    else
    {
        Utils::DebugF("Failed to apply patch: " + toAdd->GetName());
    }
}