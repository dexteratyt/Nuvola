#include "SwapChainHook.h"

auto SwapChainHook::hookPresent(IDXGISwapChain* pChain, UINT syncInterval, UINT flags) -> long {

	//Simple fps throttle to show it works
	Sleep(1000/10); // Should limit game to 10 fps
	
    return PLH::FnCast(presentOriginal, &hookPresent)(pChain, syncInterval, flags);
}

SwapChainHook::SwapChainHook()  : IPatch::IPatch("Dx11::Present") {
	
}

auto SwapChainHook::Apply() -> bool {
	if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
		Utils::DebugF("Kiero setup for d3d11");

		if(kiero::bind(8, (void**)&presentOriginal, hookPresent) == kiero::Status::Success) {
			return true;
		}
	}

	return false;
}