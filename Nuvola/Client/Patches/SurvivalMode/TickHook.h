#ifndef NUVOLA_CLIENT_PATCHES_SURVIVALMODE_TICKHOOK
#define NUVOLA_CLIENT_PATCHES_SURVIVALMODE_TICKHOOK

#include "../IPatch.h"

class TickHook : public IPatch {
    static inline uint64_t tickOriginal = 0;
	static void __fastcall tickCallback_1_17_11_1(class SurvivalMode* gameMode);
public:
	TickHook();
	auto Apply() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_SURVIVALMODE_TICKHOOK */
