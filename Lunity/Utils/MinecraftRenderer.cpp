#include "MinecraftRenderer.h"
#include "../Client/Bridge/MinecraftGame.h"

MinecraftRenderer::MinecraftRenderer(MinecraftUIRenderContext* renderContext) {
	this->renderContext = renderContext;
}

void MinecraftRenderer::DrawString(std::string text, Vector2<float> position) {
	MinecraftRenderer::DrawString(text, Color(), position);
}
void MinecraftRenderer::DrawString(std::string text, Color color, Vector2<float> position) {
	MinecraftRenderer::DrawString(text, color, 1.0f, position);
}
void MinecraftRenderer::DrawString(std::string text, Color color, float scale, Vector2<float> position) {
	class BitmapFont* font = this->renderContext->clientInstance->minecraftGame->mcFontA;
	RectangleArea rect = RectangleArea(position);
	TextMeasureData measureData = TextMeasureData(scale);
	CaretMeasureData caretData = CaretMeasureData();
	this->renderContext->drawText(font, &rect, &text, &color, 1.0f, nullptr, &measureData, &caretData);
	this->renderContext->flushText(0);
}