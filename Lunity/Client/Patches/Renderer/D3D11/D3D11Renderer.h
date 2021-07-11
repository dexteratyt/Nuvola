#ifndef LUNITY_CLIENT_RENDERER_D3D11_D3D11RENDERER_H
#define LUNITY_CLIENT_RENDERER_D3D11_D3D11RENDERER_H

#include <exception>
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
