#ifndef LUNITY_CLIENT_PATCHES_DX11_SWAPCHAINHOOK
#define LUNITY_CLIENT_PATCHES_DX11_SWAPCHAINHOOK
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

#include <d3d11.h>
#include <d3d12.h>
#include <d2d1_1.h>
#include <dwrite_1.h>
#include <dxgi.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <DirectXColors.h>

#include <kiero.h>

class SwapChainHook : public IPatch {
    static inline uint64_t presentOriginal = 0;
	static auto hookPresent(IDXGISwapChain3* pChain, UINT syncInterval, UINT flags) -> long;
	static inline ID3D12Device* pDevice;
	static inline ID3D12CommandQueue* pCommandQueue;
public:
	SwapChainHook();
	~SwapChainHook() override;
	auto ManualCleanup() -> bool override;
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_DX11_SWAPCHAINHOOK */
