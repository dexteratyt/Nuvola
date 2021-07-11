#include "ImGuiD3D12Renderer.h"

ImGuiD3D12Renderer* currentRenderer = nullptr;

long __fastcall _Present(IDXGISwapChain3* SwapChainPtr,
                         unsigned int SyncInterval,
                         unsigned int Flags) {
    // TODO: currentRenderer.D3D12Present

    return D3D12Present(SwapChainPtr, SyncInterval, Flags);
}

long __fastcall _ResizeBuffers(IDXGISwapChain3* SwapChainPtr,
                               unsigned int BufferCount,
                               unsigned int Width,
                               unsigned int Height,
                               DXGI_FORMAT NewFormat,
                               unsigned int SwapChainFlags) {
    // TODO: currentRenderer._ResizeBuffers

    return D3D12ResizeBuffers(SwapChainPtr, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

auto ImGuiD3D12Renderer::isHooked() -> bool {
    return hooked;
}

auto ImGuiD3D12Renderer::hookUnsafely() -> void {
    if (hooked) return;

    // TODO: D3D12Renderer::hookUnsafely

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