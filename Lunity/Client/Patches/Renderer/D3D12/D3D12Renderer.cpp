#include "D3D12Renderer.h"

auto D3D12Renderer::isHooked() -> bool {
    return hooked;
}

auto D3D12Renderer::hookUnsafely() -> void {
    if (hooked) return;

    if (kiero::init(kiero::RenderType::D3D12) != kiero::Status::Success)
        throw std::exception("Could not initialize kiero in D3D12Renderer.cpp");

    // TODO: set initializeOnnextCall to true

    //kiero::bind(140, (void**)&D3D12Present, _Present);
    //kiero::bind(145, (void**)&D3D12ResizeBuffers, _ResizeBuffers); // 13

    hooked = true;
}

auto D3D12Renderer::hook() -> void {
    if (hooked) return;
    if (isAlreadyHooked) throw std::exception("A hook has already been initialized.");

    hookUnsafely();

    isAlreadyHooked = true;
}

auto D3D12Renderer::unhook() -> void {
    if (!hooked) return;

    // TODO: set disposeOnNextCall to true

    // TODO: release resources

    isAlreadyHooked = false;
    hooked = false;
}

auto D3D12Renderer::release() -> void {
    if (!hooked) return;

    // TODO: D3D12Renderer::release

    hooked = false;
}

auto D3D12Renderer::reload() -> void {
    unhook();
    hook();
}