#include "SwapChainHook.h"

auto SwapChainHook::hookPresent(IDXGISwapChain3* pChain, UINT syncInterval, UINT flags) -> long {
	HRESULT res = pChain->GetDevice(__uuidof(ID3D12Device), (void**)&pDevice);

	if(res != S_OK) {
		Utils::DebugF("Shit went horribly wrong!");
		Utils::DebugF("Error: " + std::to_string(res));
		Sleep(2000);
		goto returnPoint;
	}

returnPoint:
	return PLH::FnCast(presentOriginal, &hookPresent)(pChain, syncInterval, flags);
}

SwapChainHook::SwapChainHook()  : IPatch::IPatch("Dx12::Present") {}
SwapChainHook::~SwapChainHook() {
	kiero::unbind(140);
}
auto SwapChainHook::ManualCleanup() -> bool {
	return true;
}

auto SwapChainHook::Apply() -> bool {
	if (kiero::init(kiero::RenderType::D3D12) == kiero::Status::Success) {
		Utils::DebugF("Kiero setup for d3d12");

		if(kiero::bind(140, (void**)&presentOriginal, hookPresent) == kiero::Status::Success) {
			return true;
		}
	}

	return false;
}