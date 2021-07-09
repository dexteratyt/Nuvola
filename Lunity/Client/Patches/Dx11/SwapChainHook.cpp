#include "SwapChainHook.h"
//extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

void InitImGui()
{
	//ImGui::CreateContext();
	//ImGuiIO& io = ImGui::GetIO();
	//io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	//ImGui_ImplWin32_Init(window);
	//ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	/*if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;*/

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

auto SwapChainHook::hookPresent(IDXGISwapChain* pChain, UINT syncInterval, UINT flags) -> long {	

	return PLH::FnCast(presentOriginal, &hookPresent)(pChain, syncInterval, flags);
}

SwapChainHook::SwapChainHook()  : IPatch::IPatch("Dx11::Present") {
	
}

auto SwapChainHook::Apply() -> bool {
	if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
		Utils::DebugF("Kiero setup for d3d11");

		if(kiero::bind(8, (void**)&presentOriginal, hookPresent) == kiero::Status::Success) {
			return true;
		}
	}

	return false;
}