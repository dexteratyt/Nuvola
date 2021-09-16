#ifndef NUVOLA_CLIENT_PATCHES_MESHHELPERS_RENDERMESHHOOK
#define NUVOLA_CLIENT_PATCHES_MESHHELPERS_RENDERMESHHOOK
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

class RenderMeshHook : public IPatch {
	static auto renderMeshImmediatelyCallback_1_17_10_4(class ScreenContext* screenContext, class Tessellator* tessellator, class MaterialPtr* material) -> void;
public:
	static inline uintptr_t funcOriginal = 0;
	RenderMeshHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_MESHHELPERS_RENDERMESHHOOK */
