#include "SwapChainHook.h"

#include <d3d12.h>
#include <gl/GL.h>

auto SwapChainHook::hookPresent(IDXGISwapChain3* pChain, UINT syncInterval, UINT flags) -> long {
	HRESULT res = pChain->GetDevice(__uuidof(ID3D12Device), (void**)&pDevice);

	if(res != S_OK) {
		Utils::DebugF("Shit went horribly wrong!");
		Utils::DebugF("Error: "+std::to_string(res));
		Sleep(2000);
		goto returnPoint;
	}

	//pDevice->CreateCommandQueue(D3D12CommandQueue(), __uuidof(ID3D12CommandQueue), (void**)&pCommandQueue)

returnPoint:
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