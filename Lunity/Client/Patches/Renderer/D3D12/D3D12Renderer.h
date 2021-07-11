#ifndef LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H
#define LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H

#include <exception>
#include <Windows.h>
#include <dxgi.h>
#include <d3d12.h>

// kiero
#include "../../../../Lib/kiero/kiero.h"
#define KIERO_INCLUDE_D3D12  1 // 1 if you need D3D12 hook
#define KIERO_USE_MINHOOK    1 // 1 if you will use kiero::bind function
// kiero end

#include "../../../../Utils/Event.h"
#include "../Renderer.h"

struct D3D12InitializingEventArgs
{
    bool handled;
    bool cancel;
};

struct D3D12RenderEventArgs
{
    bool handled;
};

class D3D12Renderer : Renderer
{
private:
    bool isInitialized = false;
    bool hooked = false;
    static bool isAlreadyHooked = false;

public:
    // Typedefs
    typedef long(__fastcall* D3D12PresentFunc) (IDXGISwapChain3* SwapChainPtr, uint SyncInterval, uint Flags);
    typedef HRESULT(__fastcall* D3D12ResizeBuffersFunc)(IDXGISwapChain* SwapChainPtr, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
    typedef void(*D3D12ExecuteCommandListsFunc)(ID3D12CommandQueue* CommandQueuePtr, uint CommandListsCount, ID3D12CommandList* CommandListPtr);
    typedef long(*D3D12SignalFunc)(ID3D12CommandQueue* commandQueuePtr, ID3D12Fence* fence, uint64 value);
    typedef long(__fastcall* D3D12ResizeRenderTargetsFunc)(IDXGISwapChain3* SwapChainPtr, const DXGI_MODE_DESC* newTargetParametersPtr);
    typedef void(__fastcall* D3D12DrawInstancedFunc)(ID3D12GraphicsCommandList* CommandListPtr, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation);
    typedef void(__fastcall* D3D12DrawIndexedInstancedFunc)(ID3D12GraphicsCommandList* CommandListPtr, UINT IndexCount, UINT InstanceCount, UINT StartIndex, INT BaseVertex);

    // Resources
    IDXGISwapChain3* D3D12SpawChain3Ptr = nullptr;
    ID3D12Device* D3D12DevicePtr = nullptr;
    ID3D12DescriptorHeap* D3D12DescriptorHeapBackBuffersPtr = nullptr;
    ID3D12DescriptorHeap* D3D12DescriptorHeapImGuiRenderPtr = nullptr;
    ID3D12GraphicsCommandList* D3D12CommandListPtr = nullptr;
    ID3D12CommandQueue* D3D12CommandQueuePtr = nullptr;
    ID3D12Fence* D3D12FencePtr = nullptr;
    UInt64 D3D12FenceValue = 0;
    FrameContext* FrameContextPtr = nullptr;
    UInt ReservedBufferCount = 0;
    UInt BufferCount = 0;

    // Original Functions
    D3D12PresentFunc D3D12Present = nullptr;
    D3D12ResizeBuffersFunc D3D12ResizeBuffers = nullptr;
    D3D12ExecuteCommandListsFunc D3D12ExecuteCommandLists = nullptr;
    D3D12SignalFunc D3D12Signal = nullptr;
    D3D12ResizeRenderTargetsFunc D3D12ResizeRenderTargets = nullptr;
    D3D12DrawInstancedFunc D3D12DrawInstanced = nullptr;
    D3D12DrawIndexedInstancedFunc D3D12DrawIndexedInstanced = nullptr;

private:
    bool InitializeOnNextCall = true;
    bool ReleaseOnNextCall = false;
    bool DisposeOnNextCall = false;
    unsigned int bufferWidth = 0;
    unsigned int bufferHeight = 0;

public:
    HWND WindowHandle = 0;

public:
    D3D12Renderer() : Renderer("Renderer::D3D12") { }
    ~D3D12Renderer() { }
    auto isHooked() -> bool;
    auto hookUnsafely() -> void;
    auto hook() -> void;
    auto unhook() -> void;
    auto reload() -> void;
    auto release() -> void;

public:
    // TODO: Add EventArgs
    Event<void(D3D12InitializingEventArgs&)> initializing; // Is being invoked before the hook initializes all its resources
    Event<void(D3D12RenderEventArgs&)> render; // Is being invoked when everything is being rendered
};


#endif //LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H
