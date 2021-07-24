#ifndef LUNITY_CLIENT_PATCHES_ACTOR_SETROTHOOK
#define LUNITY_CLIENT_PATCHES_ACTOR_SETROTHOOK

#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Bridge/Mob.h"

class SetRotHook : public IPatch {
	static void __fastcall SetRotCallback_1_17_10_4(Actor* actor, Vector2<float>* vector);
public:
	static inline uintptr_t funcOriginal = 0;
	SetRotHook();
	auto Apply() -> bool override;
};



#endif /* LUNITY_CLIENT_PATCHES_ACTOR_SETROTHOOK */
