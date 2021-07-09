#include "SwapChainHook.h"

auto SwapChainHook::presentCallback(IDXGISwapChain* pChain, UINT syncInterval, UINT flags) -> int {
    //

	/*std::vector<Module*>* modules = ModuleMgr::getInstance()->getAllModules();
	for(auto module : *modules) {
		//module->onRender();
	}*/

    return PLH::FnCast(presentOriginal, &presentCallback)(pChain, syncInterval, flags);
}

SwapChainHook::SwapChainHook()  : IPatch::IPatch("Dx12::SwapChain") {
	//
}

auto SwapChainHook::Apply() -> bool {
	PLH::CapstoneDisassembler dis = this->GetDis();

    WNDCLASSEX wc{};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = DefWindowProc;
    wc.lpszClassName = TEXT("TemporaryWindow");
	//This call is related to crash!!!
	//TODO: READ THIS SHIT MF
    RegisterClassEx(&wc);

    HWND hWnd = CreateWindow(wc.lpszClassName, TEXT(""), WS_DISABLED, 0, 0, 0, 0, nullptr, nullptr, nullptr, nullptr);

    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
    DXGI_SWAP_CHAIN_DESC sd;
    {
        memset((&sd), 0, (sizeof(sd)));
        sd.BufferCount = 1;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        sd.OutputWindow = hWnd;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    }

    HRESULT hrD3D11CreateDeviceAndSwapChain = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, &featureLevel, 1, D3D11_SDK_VERSION, &sd, &pSwapChain, &pDevice, nullptr, &pContext);

    if (FAILED(hrD3D11CreateDeviceAndSwapChain)) {
        DestroyWindow(sd.OutputWindow);
        UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
        return false;
    }

    pSwapChainVTable = *reinterpret_cast<uintptr_t***>(pSwapChain);

    std::ostringstream o;
    o << std::hex << pSwapChainVTable[8] << std::endl;
    Utils::DebugF(o.str().c_str());

	PLH::x64Detour* detourHook = new PLH::x64Detour((char*)pSwapChainVTable[8], (char*)presentCallback, &presentOriginal, dis);

	Utils::DebugF("CREATED DETOUR INSTANCE");

	if(!detourHook->hook()) {
		Utils::DebugF("FAILED HOOK DETOUR INSTANCE");
		return false;
	}

	Utils::DebugF("YES CREATED DETOUR INSTANCE");

    pDevice->Release();
    pContext->Release();
    pSwapChain->Release();

	Utils::DebugF("RELEASED");

    DestroyWindow(sd.OutputWindow);
    UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
	
	Utils::DebugF("DESTROY & UNREGISTER");


	return true;
}