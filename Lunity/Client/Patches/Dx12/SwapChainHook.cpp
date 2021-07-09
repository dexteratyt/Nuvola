#include "SwapChainHook.h"
#include "Kiero.h"

SwapChainHook::SwapChainHook()  : IPatch::IPatch("SwapChainHook::Update") {
	//
}

long __fastcall hookPresentD3D12(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags){
	//
}

void __fastcall hookkDrawInstancedD3D12(ID3D12GraphicsCommandList* dCommandList, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation) {
	return oDrawInstancedD3D12(dCommandList, VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
}

void __fastcall hookDrawIndexedInstancedD3D12(ID3D12GraphicsCommandList* dCommandList, UINT IndexCount, UINT InstanceCount, UINT StartIndex, INT BaseVertex) {
	return oDrawIndexedInstancedD3D12(dCommandList, IndexCount, InstanceCount, StartIndex, BaseVertex);
}

void hookExecuteCommandListsD3D12(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists) {
	//

	oExecuteCommandListsD3D12(queue, NumCommandLists, ppCommandLists);
}

HRESULT hookSignalD3D12(ID3D12CommandQueue* queue, ID3D12Fence* fence, UINT64 value) {
	//

	return oSignalD3D12(queue, fence, value);
}

auto SwapChainHook::Apply() -> bool {
	PLH::CapstoneDisassembler dis = this->GetDis();

	if (kiero::init(kiero::RenderType::D3D12) == kiero::Status::Success){
		kiero::bind(54, (void**)&oExecuteCommandListsD3D12, hookExecuteCommandListsD3D12);
		kiero::bind(58, (void**)&oSignalD3D12, hookSignalD3D12);
		kiero::bind(140, (void**)&oPresentD3D12, hookPresentD3D12);
		kiero::bind(84, (void**)&oDrawInstancedD3D12, hookkDrawInstancedD3D12);
		kiero::bind(85, (void**)&oDrawIndexedInstancedD3D12, hookDrawIndexedInstancedD3D12);

	}

	Utils::DebugF("Done with Kiero shit?");

	return true;
}