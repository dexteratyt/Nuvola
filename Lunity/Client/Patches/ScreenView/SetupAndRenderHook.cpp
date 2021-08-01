#include "SetupAndRenderHook.h"

#include <string>

#include "../../Bridge/MinecraftUIRenderContext.h"
#include "../../Bridge/ScreenContext.h"
#include "../../Bridge/Tessellator.h"
#include "../../Bridge/MeshHelpers.h"

#include "../../../Utils/Math.h"

void __fastcall SetupAndRenderHook::setupAndRenderCallback_1_17_10_4(class ScreenView* screenView, class MinecraftUIRenderContext* renderContext) {
	PLH::FnCast(setupAndRenderOriginal, setupAndRenderCallback_1_17_10_4)(screenView, renderContext);

	Vector4<float> rect(0, 0, 100, 100);
	Vector4<float> color(1, 1, 1, 0);
	renderContext->fillRectangle((class RectangleArea*)&rect, (class Color*)&color, 0);

	/*Tessellator* tess = renderContext->screenContext->tessellator;
	//Utils::DebugF("Grabbed tess: "+std::to_string((uintptr_t)tess));
	if(!Utils::GetUIMaterialPtr()) {
		return;
	}
	Utils::DebugF("Got mat*: " + std::to_string((uintptr_t)Utils::GetUIMaterialPtr()));
	Utils::DebugF("Starting render");
	tess->begin(1, 3);
	Utils::DebugF("Began");
	tess->vertex(0,0,0);
	Utils::DebugF("Vert #1");
	tess->vertex(0,100,0);
	Utils::DebugF("Vert #2");
	tess->vertex(100,100,0);
	Utils::DebugF("Vert #3");
	MeshHelpers::renderMeshImmediately(renderContext->screenContext, tess, Utils::GetUIMaterialPtr());
	Utils::DebugF("Rendered mesh");*/
}

SetupAndRenderHook::SetupAndRenderHook() : IPatch::IPatch("ScreenView::setupAndRender") {
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 4C 8B ?? ?? 89 ?? ?? ?? 4C"), 0));
}

auto SetupAndRenderHook::Apply() -> bool {
	return this->AutoPatch(setupAndRenderCallback_1_17_10_4, &setupAndRenderOriginal);
}