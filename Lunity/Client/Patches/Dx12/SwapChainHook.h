#ifndef LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK
#define LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

#include <d3d11.h>

class SwapChainHook : public IPatch {
    static inline uintptr_t presentOriginal = NULL;
	static auto presentCallback(IDXGISwapChain* pChain, UINT syncInterval, UINT flags) -> int;

	IDXGISwapChain* pSwapChain = nullptr;
	ID3D11Device* pDevice = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* renderTargetView = nullptr;

	uintptr_t** pSwapChainVTable = nullptr;
public:
	SwapChainHook();
	auto Apply() -> bool override;
};


#endif /* LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK */
