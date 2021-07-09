#ifndef LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK
#define LUNITY_CLIENT_PATCHES_DX12_SWAPCHAINHOOK
#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

#include <d3d12.h>
#include <dxgi.h>

typedef long(__fastcall* PresentD3D12) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
extern PresentD3D12 oPresentD3D12;

typedef void(__fastcall* DrawInstancedD3D12)(ID3D12GraphicsCommandList* dCommandList, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation);
extern DrawInstancedD3D12 oDrawInstancedD3D12;

typedef void(__fastcall* DrawIndexedInstancedD3D12)(ID3D12GraphicsCommandList* dCommandList, UINT IndexCount, UINT InstanceCount, UINT StartIndex, INT BaseVertex);
extern DrawIndexedInstancedD3D12 oDrawIndexedInstancedD3D12;

extern void(*oExecuteCommandListsD3D12)(ID3D12CommandQueue*, UINT, ID3D12CommandList*);
extern HRESULT(*oSignalD3D12)(ID3D12CommandQueue*, ID3D12Fence*, UINT64);


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
