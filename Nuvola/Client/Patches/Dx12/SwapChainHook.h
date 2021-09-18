#ifndef NUVOLA_CLIENT_PATCHES_DX12_SWAPCHAINHOOK
#define NUVOLA_CLIENT_PATCHES_DX12_SWAPCHAINHOOK

#include "../IPatch.h"
#include <dxgi.h>
#include <d3d12.h>
#include <d3d12.h>
#include <dxgi1_4.h>

class SwapChainHook : public IPatch {
	static auto presentCallback(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags) -> void;
public:
	PLH::x64Detour* theDetour;
	static inline uintptr_t funcOriginal = 0;
	SwapChainHook();
	auto Apply() -> bool override;
	auto ManualCleanup() -> bool override;
};

#endif /* NUVOLA_CLIENT_PATCHES_DX12_SWAPCHAINHOOK */
