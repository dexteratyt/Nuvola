#ifndef LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK
#define LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

#include <d3d12.h>
#include <dxgi.h>
#include <Kiero.h>

class SwapChainHook : public IPatch {
public:
	SwapChainHook();
	auto Apply() -> bool override;

	ID3D12Device* d3d12Device = nullptr;
	ID3D12DescriptorHeap* d3d12DescriptorHeapBackBuffers = nullptr;
	ID3D12DescriptorHeap* d3d12DescriptorHeapImGuiRender = nullptr;
	ID3D12GraphicsCommandList* d3d12CommandList = nullptr;
	ID3D12Fence* d3d12Fence = nullptr;
	UINT64 d3d12FenceValue = 0;
	ID3D12CommandQueue* d3d12CommandQueue = nullptr;
};

#endif /* LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK */
