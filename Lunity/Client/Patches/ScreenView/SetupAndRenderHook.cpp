#include "SetupAndRenderHook.h"

#include <string>

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

struct TextMeasureData {
    float scale;

    TextMeasureData() {
        this->scale = 1.0f;
    }
    TextMeasureData(float scale) {
        this->scale = scale;
    }
};

struct CaretMeasureData {
    int a;
    bool b;

    CaretMeasureData() {
        CaretMeasureData(0xFFFFFFFF, false);
    };
    CaretMeasureData(int param_1, bool param_2) {
        this->a = param_1;
        this->b = param_2;
    };
};



#include "../../Bridge/MinecraftUIRenderContext.h"
#include <string>
#include "../../Bridge/MinecraftGame.h"
#include "../../Bridge/ScreenContext.h"
#include "../../Bridge/Tessellator.h"
#include "../../Bridge/MeshHelpers.h"

#include "../../../Utils/Math.h"

struct RectangleArea {
    float x;
    float w;
    float y;
    float h;

    RectangleArea(){
        this->x = 0;
        this->y = 0;
        this->w = 100;
        this->h = 100;
    };
    RectangleArea(float x, float y){
        this->x = x;
        this->y = y;
        this->w = this->x + 100;
        this->h = this->y + 100;
    };
    RectangleArea(Vector2<float> vec2){
        this->x = vec2.x;
        this->y = vec2.y;
        this->w = this->x + 100;
        this->h = this->y + 100;
    };
    RectangleArea(float x, float y, float w, float h){
        this->x = x;
        this->y = y;
        this->w = this->x + w;
        this->h = this->y + h;
    };
};

void __fastcall SetupAndRenderHook::setupAndRenderCallback_1_17_10_4(class ScreenView* screenView, class MinecraftUIRenderContext* renderContext) {
	PLH::FnCast(setupAndRenderOriginal, setupAndRenderCallback_1_17_10_4)(screenView, renderContext);


	Vector4<float> rect = Vector4<float>(0, 100, 0, 100);
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
	renderContext->fillRectangle((float*)&rect, (float*)&color, .5);
	size_t mcGameAddr = (size_t)renderContext->clientInstance->minecraftGame;
	float one = 1.0f;
	RectangleArea area = RectangleArea(0,0);
	TextMeasureData measureData = TextMeasureData(1.0f);
	CaretMeasureData caretData = CaretMeasureData();
	std::string text = "Lunity";
	class BitmapFont* font = renderContext->clientInstance->minecraftGame->possibleFont;
	renderContext->drawText(font, &area, &text, &color, 1.0f, nullptr, &measureData, &caretData);
	Utils::DebugF("Drawn text");
	renderContext->flushText(0);
	Utils::DebugF("Flushed");

/*
	ScreenContext* screenCtx = renderContext->screenContext;
	Tessellator* tess = screenCtx->tessellator;
	Utils::DebugF("Grabbed tess: "+std::to_string((uintptr_t)tess));
	class MaterialPtr* mat = (class MaterialPtr*)Utils::GetUIMaterialPtr();
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
	tess->begin(3, 3);
	Utils::DebugF("Began");
	tess->vertex(0,0,0);
	Utils::DebugF("Vert #1");
	tess->vertex(0, 100, 0);
	Utils::DebugF("Vert #2");
	tess->vertex(100, 100, 0);
	Utils::DebugF("Vert #3");
	MeshHelpers::renderMeshImmediately(screenCtx, tess, mat);
	Utils::DebugF("Rendered mesh");
	*/
/*
	float x = 0;
	float y = 1000;
	float z = 0;
	float w = 1000;
	ScreenContext* screenCtx = renderContext->screenContext;
	screenCtx->shaderColor->r = 1;
	screenCtx->shaderColor->g = 1;
	screenCtx->shaderColor->b = 1;
	screenCtx->shaderColor->a = 1;
	Tessellator* tessellator = screenCtx->tessellator;
	tessellator->begin(4,0); 			//Tessellator::begin(tessellator,4,0);
	tessellator->vertex(x, w, 0.0); 	//Tessellator::vertex(tessellator,x,w,0.0);
	tessellator->vertex(z, w, 0.0); 	//Tessellator::vertex(tessellator,z,w,0.0);
	tessellator->vertex(z, y, 0.0); 	//Tessellator::vertex(tessellator,z,y,0.0);
	tessellator->vertex(x, y, 0.0); 	//Tessellator::vertex(tessellator,x,y,0.0);
	MeshHelpers::renderMeshImmediately(screenCtx, tessellator, Utils::GetUIMaterialPtr());
	*/
}

SetupAndRenderHook::SetupAndRenderHook() : IPatch::IPatch("ScreenView::setupAndRender") {
	this->AddSignature(new SigInfo(new std::string("48 8B ?? ?? 89 ?? ?? 55 56 57 41 ?? 41 ?? 41 ?? 41 ?? 48 ?? ?? ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? ?? 29 ?? ?? ?? 29 ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? ?? ?? ?? 4C 8B ?? ?? 89 ?? ?? ?? 4C"), 0));
}

auto SetupAndRenderHook::Apply() -> bool {
	return this->AutoPatch(setupAndRenderCallback_1_17_10_4, &setupAndRenderOriginal);
}