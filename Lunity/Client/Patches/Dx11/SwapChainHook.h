#ifndef LUNITY_CLIENT_PATCHES_DX11_SWAPCHAINHOOK
#define LUNITY_CLIENT_PATCHES_DX11_SWAPCHAINHOOK
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

#include <d3d11.h>
#include <d2d1_1.h>
#include <dwrite_1.h>

#define KIERO_INCLUDE_D3D11 1
#include <kiero.h>

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"

class SwapChainHook : public IPatch {
    static inline uint64_t presentOriginal = 0;
	static auto hookPresent(IDXGISwapChain* pChain, UINT syncInterval, UINT flags) -> long;
public:
	SwapChainHook();
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_DX11_SWAPCHAINHOOK */
