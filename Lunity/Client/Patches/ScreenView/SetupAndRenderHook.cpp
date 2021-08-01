#include "SetupAndRenderHook.h"

#include <string>

#include "../../Bridge/MinecraftUIRenderContext.h"
#include "../../Bridge/ScreenContext.h"
#include "../../Bridge/Tessellator.h"

void __fastcall SetupAndRenderHook::setupAndRenderCallback_1_17_10_4(class ScreenView* screenView, class MinecraftUIRenderContext* renderContext) {
	PLH::FnCast(setupAndRenderOriginal, setupAndRenderCallback_1_17_10_4)(screenView, renderContext);

	Tessellator* tess = renderContext->screenContext->tessellator;
	//Utils::DebugF("Grabbed tess: "+std::to_string((uintptr_t)tess));
	tess->begin(3, true);
	tess->vertex(0,0,0);
	tess->vertex(0,100,0);
	tess->vertex(100,100,0);
}

SetupAndRenderHook::SetupAndRenderHook() : IPatch::IPatch("ScreenView::setupAndRender") {
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 4C 8B ?? ?? 89 ?? ?? ?? 4C"), 0));
}

auto SetupAndRenderHook::Apply() -> bool {
	return this->AutoPatch(setupAndRenderCallback_1_17_10_4, &setupAndRenderOriginal);
}