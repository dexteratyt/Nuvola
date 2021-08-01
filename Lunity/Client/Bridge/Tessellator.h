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
	auto __thiscall begin(int vertCount, bool param_2) -> void {
		if(holder_begin == 0) {
			holder_begin = Mem::FindSig("89 ?? ?? ?? 55 48 83 ?? ?? ?? B9 ?? ?? ?? ?? ?? 45");
		}
		if(holder_begin == 0){
			Utils::DebugF("FATAL: Sig failure for begin");
		}
		holder_begin += -1;
		return ((void(__thiscall*)(Tessellator*, int vertCount, bool param_2))holder_begin)(this, vertCount, param_2);
	};
};
#endif