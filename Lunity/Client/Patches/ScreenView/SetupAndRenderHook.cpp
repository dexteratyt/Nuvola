#include "SetupAndRenderHook.h"

#include <string>

#include "../../Bridge/MinecraftUIRenderContext.h"
#include "../../Bridge/ScreenContext.h"
#include "../../Bridge/Tessellator.h"
#include "../../Bridge/MeshHelpers.h"

#include "../../../Utils/Math.h"


struct Color {
	union {
		struct {
			float r;
			float g;
			float b;
			float a;
		};
		float arr[4];
	};
	bool test;

	Color(float r, float g, float b, float a, bool test) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
		this->test = test;
	}
};

void __fastcall SetupAndRenderHook::setupAndRenderCallback_1_17_10_4(class ScreenView* screenView, class MinecraftUIRenderContext* renderContext) {
	PLH::FnCast(setupAndRenderOriginal, setupAndRenderCallback_1_17_10_4)(screenView, renderContext);

/*
	Vector4<float> rect = Vector4<float>(0, 0, 1000, 1000);
	float test[4];
	test[0] = rect.x;
	test[1] = rect.z;
	test[2] = rect.y;
	test[3] = rect.z;
	Color color = Color(1, 1, 1, .5, false);
	float col[4];
	col[0] = color.r;
	col[1] = color.g;
	col[2] = color.b;
	col[3] = color.a;
	renderContext->fillRectangle((float*)test, (float*)col, .5);
*/

	ScreenContext* screenCtx = renderContext->screenContext;
	Tessellator* tess = screenCtx->tessellator;
	Utils::DebugF("Grabbed tess: "+std::to_string((uintptr_t)tess));
	class MaterialPtr* mat = Utils::GetUIMaterialPtr();
	if(!mat) {
		Utils::DebugF("Failed to get material");
		return;
	}
	//class MaterialPtr* matPtr = (class MaterialPtr*)(((size_t)Utils::GetUIMaterialPtr())+0x10);
	screenCtx->shaderColor->r = 1;
	screenCtx->shaderColor->g = 1;
	screenCtx->shaderColor->b = 1;
	screenCtx->shaderColor->a = 1;
	Utils::DebugF("Got mat*: " + std::to_string((uintptr_t)mat));
	Utils::DebugF("Starting render");
	tess->begin(3, 3, true);
	Utils::DebugF("Began");
	tess->vertex(0,0,0);
	Utils::DebugF("Vert #1");
	tess->vertex(0, 100, 0);
	Utils::DebugF("Vert #2");
	tess->vertex(100, 100, 0);
	Utils::DebugF("Vert #3");
	MeshHelpers::renderMeshImmediately(screenCtx, tess, mat);
	Utils::DebugF("Rendered mesh");
}

SetupAndRenderHook::SetupAndRenderHook() : IPatch::IPatch("ScreenView::setupAndRender") {
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 4C 8B ?? ?? 89 ?? ?? ?? 4C"), 0));
}

auto SetupAndRenderHook::Apply() -> bool {
	return this->AutoPatch(setupAndRenderCallback_1_17_10_4, &setupAndRenderOriginal);
}