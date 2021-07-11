#include "ImGuiD3D12Renderer.h"

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