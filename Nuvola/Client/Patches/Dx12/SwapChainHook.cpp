#include "SwapChainHook.h"

#include "../../Events/Listener.h"
#include "../../Events/EventHandler.h"

#include "../../../Lib/Kiero/kiero.h"

void SwapChainHook::presentCallback(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags) {
	Sleep(30);
	DXPresentEvent event;
	std::vector<Listener*> listeners = EventHandler::getListeners();
	for(auto listener : listeners) {
		listener->onDXPresentEvent(event);
	}
	if(!event.IsCancelled()) {
		PLH::FnCast(funcOriginal, presentCallback)(pSwapChain, SyncInterval, Flags);
	}
}

bool kieroReady = false;
SwapChainHook::SwapChainHook() : IPatch("DX12::SwapChain::Present") {
	kieroReady = (kiero::init(kiero::RenderType::D3D12) == kiero::Status::Success);
}

auto SwapChainHook::Apply() -> bool {
	PLH::CapstoneDisassembler dis = this->GetDis();

	auto hookAddr = kiero::getMethodsTable()[140];

	if(hookAddr == 0) {
		return false;
	}

	theDetour = new PLH::x64Detour((char*)hookAddr, (char*)presentCallback, (uint64_t*)funcOriginal, dis);

	if(!theDetour->hook()) {
		return false;
	}

	return true;
}

auto SwapChainHook::ManualCleanup() -> bool {
	theDetour->unHook();
	delete theDetour;
	return true;
}