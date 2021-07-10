#include "D3D11Renderer.h"

auto D3D11Renderer::isHooked() -> bool {
    return hooked;
}

auto D3D11Renderer::hookUnsafely() -> void {
    if (hooked) return;

    // TODO: D3D12Renderer::hookUnsafely

    hooked = true;
}

auto D3D11Renderer::hook() -> void {
    if (hooked) return;
    if (isAlreadyHooked) throw std::exception("A hook has already been initialized.");

    hookUnsafely();

    isAlreadyHooked = true;
}

auto D3D11Renderer::unhook() -> void {
    if (!hooked) return;

    // TODO: D3D12Renderer::unhook

    isAlreadyHooked = false;
    hooked = false;
}

auto D3D11Renderer::release() -> void {
    if (!hooked) return;

    // TODO: D3D12Renderer::release

    hooked = false;
}

auto D3D11Renderer::reload() -> void {
    unhook();
    hook();
}