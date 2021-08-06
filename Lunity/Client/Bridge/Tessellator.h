#ifndef GUARD_Tessellator
#define GUARD_Tessellator
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct Tessellator {
	/* Fields */
	/* Virtuals */
	/* Functions */
	static inline uintptr_t holder_begin;
	auto __thiscall begin(int primitiveMode, int vertCount, bool param_3) -> void {
		if(holder_begin == 0) {
			holder_begin = Mem::FindSig("89 ?? ?? ?? 55 48 83 ?? ?? ?? B9 ?? ?? ?? ?? ?? 45");
		}
		if(holder_begin == 0){
			Utils::DebugF("FATAL: Sig failure for begin");
		}
		holder_begin += -1;
		return ((void(__thiscall*)(Tessellator*, int primitiveMode, int vertCount, bool param_3))holder_begin)(this, primitiveMode, vertCount, param_3);
	};
	static inline uintptr_t holder_vertex;
	auto __thiscall vertex(float vertX, float vertY, float vertZ) -> void {
		if(holder_vertex == 0) {
			holder_vertex = Mem::FindSig("40 ?? 48 83 ?? ?? ?? 29 ?? ?? ?? ?? 29 ?? ?? ?? ?? 0F");
		}
		if(holder_vertex == 0){
			Utils::DebugF("FATAL: Sig failure for vertex");
		}
		holder_vertex += -0;
		return ((void(__thiscall*)(Tessellator*, float vertX, float vertY, float vertZ))holder_vertex)(this, vertX, vertY, vertZ);
	};
};
#endif