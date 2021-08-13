#ifndef LUNITY_CLIENT_PATCHES_PATCHMANAGER
#define LUNITY_CLIENT_PATCHES_PATCHMANAGER
#include <vector>

class PatchManager
{
	static inline std::vector<class IPatch*>* patches = new std::vector<class IPatch*>();
public:
	static void ApplyAll();
	static void ApplyPatch(class IPatch* toAdd);
	static auto RemoveAll() -> bool;
	static auto RemovePatch(class IPatch* toRemove) -> bool;
};

#endif /* LUNITY_CLIENT_PATCHES_PATCHMANAGER */
