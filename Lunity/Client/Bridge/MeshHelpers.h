#ifndef GUARD_MeshHelpers
#define GUARD_MeshHelpers
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct MeshHelpers {
	/* Fields */
	/* Virtuals */
	/* Functions */
	static inline uintptr_t holder_renderMeshImmediately;
	static auto __fastcall renderMeshImmediately(class ScreenContext* screenContext, class Tessellator* tessellator, class MaterialPtr* material) -> void {
		if(holder_renderMeshImmediately == 0) {
			holder_renderMeshImmediately = Mem::FindSig("40 ?? 56 57 48 81 ?? ?? ?? ?? ?? 49 8B ?? 48 8B ?? 48 8B ?? ?? BA");
		}
		if(holder_renderMeshImmediately == 0){
			Utils::DebugF("FATAL: Sig failure for renderMeshImmediately");
		}
		holder_renderMeshImmediately += -0;
		return ((void(__fastcall*)(class ScreenContext* screenContext, class Tessellator* tessellator, class MaterialPtr* material))holder_renderMeshImmediately)(screenContext, tessellator, material);
	};
};
#endif