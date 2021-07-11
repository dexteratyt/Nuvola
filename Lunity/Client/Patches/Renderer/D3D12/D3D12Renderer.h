#ifndef LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H
#define LUNITY_CLIENT_RENDERER_D3D12_D3D12RENDERER_H

#include <exception>
#include <dxgi.h>
#include <d3d12.h>

// kiero.h
#include "../../../../Lib/kiero/kiero.h"
#define KIERO_INCLUDE_D3D12  1 // 1 if you need D3D12 hook
#define KIERO_USE_MINHOOK    1 // 1 if you will use kiero::bind function
// kiero.h end

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
    D3D12Renderer() : Renderer("Renderer::D3D11") { }
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
