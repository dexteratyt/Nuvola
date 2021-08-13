#include "PatchManager.h"
#include "IPatch.h"
#include <iostream>

#include "Global/KeyPressHook.h"
#include "ClientInstance/UpdateHook.h"
#include "LocalPlayer/SetYHeadRotHook.h"
#include "Actor/SetRotHook.h"
#include "ScreenView/SetupAndRenderHook.h"
#include "MeshHelpers/RenderMeshHook.h"

void PatchManager::ApplyAll()
{
	/* Input hooking */
	PatchManager::ApplyPatch(new KeyPressHook());

	/* ClientInstance reference receiver hook */
	PatchManager::ApplyPatch(new UpdateHook());

	/* Graphics hooking */
	PatchManager::ApplyPatch(new SetupAndRenderHook());

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

auto PatchManager::RemoveAll() -> bool {
	for(auto patch : *PatchManager::patches) {
		PatchManager::RemovePatch(patch);
	}
	Utils::DebugF("PATCHMANAGER 47");
	return true;
}
auto PatchManager::RemovePatch(class IPatch* toRemove) -> bool {
	delete toRemove;
	Utils::DebugF("PATCHMANAGER 51");
	return true;
}