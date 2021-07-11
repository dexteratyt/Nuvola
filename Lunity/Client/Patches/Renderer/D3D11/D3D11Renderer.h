#ifndef LUNITY_CLIENT_RENDERER_D3D11_D3D11RENDERER_H
#define LUNITY_CLIENT_RENDERER_D3D11_D3D11RENDERER_H

#include <exception>
#include <dxgi.h>
#include <d3d11.h>

// kiero.h
#include "../../../../Lib/kiero/kiero.h"
#define KIERO_INCLUDE_D3D11  1 // 1 if you need D3D11 hook
#define KIERO_USE_MINHOOK    1 // 1 if you will use kiero::bind function
// kiero.h end

#include "../../../../Utils/Event.h"
#include "../Renderer.h"

struct D3D11InitializingEventArgs
{
    bool handled;
    bool cancel;
};

struct D3D11RenderEventArgs
{
    bool handled;
};

class D3D11Renderer : Renderer
{
private:
    bool isInitialized = false;
    bool hooked = false;
    static bool isAlreadyHooked = false;
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
    Event<void(D3D11InitializingEventArgs&)> initializing; // Is being invoked before the hook initializes all its resources
    Event<void(D3D11RenderEventArgs&)> render; // Is being invoked when everything is being rendered
};


#endif //LUNITY_CLIENT_RENDERER_D3D12_D3D11RENDERER_H
