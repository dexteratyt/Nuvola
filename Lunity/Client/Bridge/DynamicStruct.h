#ifndef LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
#define LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
/*
A rewrite of my DynamicStruct code.
Hopefully this will be nicer to use & update

This iteration will use preprocessor macros to
simplify everything. Unfortunately, because of this,
versionless code won't be possible.
*/

#include "../../Utils/Utils.h"
#include "../../Utils/Math.h"
#include "../../Mem/Mem.h"
#include <polyhook2/Detour/ADetour.hpp> //Included for PLH::FnCast

#define DYN_FIELD(NAME, OFFSET, TYPE) auto NAME() -> TYPE { \
		void* addr = this+OFFSET; \
		return *(TYPE*)addr; \
	} \
	auto NAME(TYPE newVal) -> void { \
		void* addr = this+OFFSET; \
		*(TYPE*)addr = newVal; \
	}

#define DYN_FUNC(NAME, SIGNATURE, SIG_OFFSET, TYPE, PARAMS, PARAM_NAMES) static uintptr_t NAME##_signatureResult; \
	auto NAME(PARAMS) -> TYPE { \
		if(!NAME##_signatureResult) { \
			NAME##_signatureResult = Mem::FindSig(SIGNATURE); \
			if(!NAME##_signatureResult) { \
				Utils::DebugF("FATAL: Bad signature \"" #SIGNATURE "\" on call " #NAME); \
			} \
			NAME##_signatureResult+(SIG_OFFSET); \
		} \
		return PLH::FnCast(NAME##_signatureResult, NAME)(PARAM_NAMES); \
	} \
/*
TODO:
	- DYN_FIELD (Done)
	- DYN_FUNC
	- DYN_VIRT
*/

#endif /* LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT */
