#ifndef LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
#define LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
/*
A rewrite of my DynamicStruct code.
Hopefully this will be nicer to use & update

This iteration will use preprocessor macros to
simplify everything. Unfortunately, because of this,
versionless code won't be possible.
*/

#define DYN_FIELD(NAME, OFFSET, TYPE) auto NAME() -> TYPE { \
		void* addr = this+OFFSET; \
		return *(TYPE*)addr; \
	} \
	auto NAME(TYPE newVal) -> void { \
		void* addr = this+OFFSET; \
		*(TYPE*)addr = newVal; \
	}

/*
TODO:
	- DYN_FIELD (Done)
	- DYN_FUNC
	- DYN_VIRT
*/

#endif /* LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT */
