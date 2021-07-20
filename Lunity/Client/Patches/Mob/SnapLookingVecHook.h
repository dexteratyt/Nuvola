#ifndef LUNITY_CLIENT_PATCHES_MOB_SNAPHOOKINGVECHOOK
#define LUNITY_CLIENT_PATCHES_MOB_SNAPHOOKINGVECHOOK

#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Bridge/Mob.h"

class SnapLookingVecHook : public IPatch {
	static void __fastcall SnapLookingVecHook_1_17_10_4(Mob* mob, Vector2<float>* vector);
public:
	static inline uintptr_t funcOriginal = 0;
	SnapLookingVecHook();
	auto Apply() -> bool override;
};



#endif /* LUNITY_CLIENT_PATCHES_MOB_SNAPHOOKINGVECHOOK */
