#ifndef LUNITY_CLIENT_PATCHES_CLIENTINSTANCE_UPDATEHOOK
#define LUNITY_CLIENT_PATCHES_CLIENTINSTANCE_UPDATEHOOK
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

class UpdateHook : public IPatch {
	static auto clientInstanceCallback_1_17_2_1(uintptr_t theInstance, char param_2) -> int;
public:
	static inline uintptr_t funcOriginal = 0;
	UpdateHook();
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_CLIENTINSTANCE_UPDATEHOOK */
