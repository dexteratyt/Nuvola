#ifndef GUARD_LocalPlayer
#define GUARD_LocalPlayer
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "Player.h"
struct LocalPlayer : public Player {
	/* Fields */
	/* Virtuals */
	/* Functions */
	static inline uintptr_t holder_swing;
	auto __thiscall swing() -> void {
		if(holder_swing == 0) {
			holder_swing = Mem::FindSig("40 ?? 48 83 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? 48 8B ?? ?? B9 ?? ?? ?? ?? ?? 74 ?? E8");
		}
		if(holder_swing == 0){
			Utils::DebugF("FATAL: Sig failure for swing");
		}
		holder_swing += -0;
		return ((void(__thiscall*)(LocalPlayer*))holder_swing)(this);
	};
};
#endif