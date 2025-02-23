#ifndef NUVOLA_CLIENT_PATCHES_GLOBAL_KEYPRESSHOOK
#define NUVOLA_CLIENT_PATCHES_GLOBAL_KEYPRESSHOOK

#include "../IPatch.h"

class KeyPressHook : public IPatch {
	static auto keyPressCallback_1_17_10_4(int key, int action) -> void;
public:
	static inline uintptr_t funcOriginal = 0;
	KeyPressHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_GLOBAL_KEYPRESSHOOK */
