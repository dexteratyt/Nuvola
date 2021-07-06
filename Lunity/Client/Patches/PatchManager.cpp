#include "PatchManager.h"
#include "IPatch.h"
#include <iostream>

void PatchManager::ApplyAll()
{
	//PatchManager::ApplyPatch(new );
}

void PatchManager::ApplyPatch(IPatch* toAdd)
{
    if(toAdd->Apply())
    {
        PatchManager::patches->push_back(toAdd);
        std::cout << "Successfully applied \'" << toAdd->GetName() << "\' patch!" << std::endl;
    }
    else
    {
        std::cout << "Failed to apply patch: " << toAdd->GetName() << std::endl;
    }
}