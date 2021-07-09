#include "SwapChainHook.h"

SwapChainHook::SwapChainHook()  : IPatch::IPatch("Dx12::SwapChainHook") {
	//
}

uintptr_t oPresentD3D12 = 0;
long __fastcall hookPresentD3D12(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags){
	//
	return PLH::FnCast(oPresentD3D12, hookPresentD3D12)(pSwapChain, SyncInterval, Flags);
}

uintptr_t oDrawInstancedD3D12 = 0;
void __fastcall hookDrawInstancedD3D12(ID3D12GraphicsCommandList* dCommandList, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation) {
	PLH::FnCast(oDrawInstancedD3D12, hookDrawInstancedD3D12)(dCommandList, VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
}

uintptr_t oDrawIndexedInstancedD3D12 = 0;
void __fastcall hookDrawIndexedInstancedD3D12(ID3D12GraphicsCommandList* dCommandList, UINT IndexCount, UINT InstanceCount, UINT StartIndex, INT BaseVertex) {
	PLH::FnCast(oPresentD3D12, hookDrawIndexedInstancedD3D12)(dCommandList, IndexCount, InstanceCount, StartIndex, BaseVertex);
}

uintptr_t oExecuteCommandListsD3D12 = 0;
void hookExecuteCommandListsD3D12(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists) {
	//

	PLH::FnCast(oExecuteCommandListsD3D12, hookExecuteCommandListsD3D12)(queue, NumCommandLists, ppCommandLists);
}

uintptr_t oSignalD3D12 = 0;
HRESULT hookSignalD3D12(ID3D12CommandQueue* queue, ID3D12Fence* fence, UINT64 value) {
	//

	return PLH::FnCast(oSignalD3D12, hookSignalD3D12)(queue, fence, value);
}

auto SwapChainHook::Apply() -> bool {
	PLH::CapstoneDisassembler dis = this->GetDis();


	if (kiero::init(kiero::RenderType::D3D12) == kiero::Status::Success){
		kiero::bind(54, (void**)oExecuteCommandListsD3D12, hookExecuteCommandListsD3D12);
		kiero::bind(58, (void**)oSignalD3D12, hookSignalD3D12);
		kiero::bind(140, (void**)oPresentD3D12, hookPresentD3D12);
		kiero::bind(84, (void**)oDrawInstancedD3D12, hookDrawInstancedD3D12);
		kiero::bind(85, (void**)oDrawIndexedInstancedD3D12, hookDrawIndexedInstancedD3D12);

	}


	Utils::DebugF("Done with Kiero shit?");

	return true;
}