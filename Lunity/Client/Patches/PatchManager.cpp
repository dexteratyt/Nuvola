#include "PatchManager.h"
#include "IPatch.h"
#include <iostream>

#include "ClientInstance/UpdateHook.h"
#include "LocalPlayer/SetYHeadRotHook.h"
#include "Actor/SetRotHook.h"

void PatchManager::ApplyAll()
{
	PatchManager::ApplyPatch(new UpdateHook());

	/* Both patches are needed for changing where LP is facing */
	PatchManager::ApplyPatch(new SetYHeadRotHook()); // This func has head & camera math
	PatchManager::ApplyPatch(new SetRotHook()); // This has for up & down rotation which is shared across the whole body, however only the head moves.
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