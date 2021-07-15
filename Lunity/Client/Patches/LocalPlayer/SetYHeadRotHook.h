#ifndef LUNITY_CLIENT_PATCHES_LOCALPLAYER_SETYHEADROTHOOK
#define LUNITY_CLIENT_PATCHES_LOCALPLAYER_SETYHEADROTHOOK

#include "../IPatch.h"
#include "../../../Utils/Utils.h"

#include "../../Bridge/LocalPlayer.h"

class SetYHeadRotHook : public IPatch {
    static inline uint64_t setYHeadRotHookOriginal = 0;
	static void __fastcall SetYHeadRotHookCallback_1_17_10_4(LocalPlayer* localPlayer, struct RendererCamera* camera);
public:
	SetYHeadRotHook();
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_LOCALPLAYER_SETYHEADROTHOOK */
