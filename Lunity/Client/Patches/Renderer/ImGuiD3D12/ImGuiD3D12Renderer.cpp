#include "ImGuiD3D12Renderer.h"

ImGuiD3D12Renderer* currentRenderer = nullptr;

long __fastcall _Present(IDXGISwapChain3* SwapChainPtr,
                         unsigned int SyncInterval,
                         unsigned int Flags) {
    if (currentRenderer) return currentRenderer->_Present(SwapChainPtr, SyncInterval, Flags);
    if (!ImGuiD3D12Renderer::D3D12Present) throw std::exception("ImGuiD3D12Renderer::D3D12Present was null.");
    return ImGuiD3D12Renderer::D3D12Present(SwapChainPtr, SyncInterval, Flags);
}

long __fastcall _ResizeBuffers(IDXGISwapChain3* SwapChainPtr,
                               unsigned int BufferCount,
                               unsigned int Width,
                               unsigned int Height,
                               DXGI_FORMAT NewFormat,
                               unsigned int SwapChainFlags) {
    if (currentRenderer) return currentRenderer->_ResizeBuffers(SwapChainPtr, BufferCount, Width, Height, NewFormat, SwapChainFlags);
    if (!ImGuiD3D12Renderer::D3D12ResizeBuffers) throw std::exception("ImGuiD3D12Renderer::D3D12ResizeBuffers was null.");
    return ImGuiD3D12Renderer::D3D12ResizeBuffers(SwapChainPtr, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

auto ImGuiD3D12Renderer::isHooked() -> bool {
    return hooked;
}

auto ImGuiD3D12Renderer::hookUnsafely() -> void {
    if (hooked) return;

    currentRenderer = this;

    if (kiero::init(kiero::RenderType::D3D12) != kiero::Status::Success)
        throw std::exception("Could not initialize kiero in D3D12Renderer.cpp");

    // TODO: set initializeOnNextCall to true

    kiero::bind(140, (void**)&D3D12Present, _Present);
    kiero::bind(145, (void**)&D3D12ResizeBuffers, _ResizeBuffers); // 13

    hooked = true;
}

auto ImGuiD3D12Renderer::hook() -> void {
    if (hooked) return;
    if (isAlreadyHooked) throw std::exception("A hook has already been initialized.");

    hookUnsafely();

    isAlreadyHooked = true;
}

auto ImGuiD3D12Renderer::unhook() -> void {
    if (!hooked) return;

    if (currentRenderer == this) currentRenderer = nullptr;

    // TODO: D3D12Renderer::unhook

    isAlreadyHooked = false;
    hooked = false;
}

auto ImGuiD3D12Renderer::release() -> void {
    if (!hooked) return;

    // TODO: D3D12Renderer::release

    hooked = false;
}

auto ImGuiD3D12Renderer::reload() -> void {
    unhook();
    hook();
}