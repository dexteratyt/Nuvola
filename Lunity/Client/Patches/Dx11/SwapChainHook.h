#ifndef LUNITY_CLIENT_PATCHES_CLIENTINSTANCE_SwapChainHook
#define LUNITY_CLIENT_PATCHES_CLIENTINSTANCE_SwapChainHook
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

#include <d3d11.h>
#include <d2d1_1.h>
#include <dwrite_1.h>

#include <kiero.h>
#include "d3d11_impl.h"

class SwapChainHook : public IPatch {
    static inline uint64_t presentOriginal = 0;
	static auto hookPresent(IDXGISwapChain* pChain, UINT syncInterval, UINT flags) -> long;
public:
	SwapChainHook();
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_CLIENTINSTANCE_SwapChainHook */
