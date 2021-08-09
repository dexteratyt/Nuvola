#include "MinecraftRenderer.h"
#include "../Client/Bridge/MinecraftGame.h"

MinecraftRenderer::MinecraftRenderer(MinecraftUIRenderContext* renderContext) {
	this->renderContext = renderContext;
}

void MinecraftRenderer::DrawString(std::string text, Vector2<float> position) {
	MinecraftRenderer::DrawString(text, position, Color());
}
void MinecraftRenderer::DrawString(std::string text, Vector2<float> position, Color color) {
	MinecraftRenderer::DrawString(text, position, color, 1.0f);
}
void MinecraftRenderer::DrawString(std::string text, Vector2<float> position, Color color, float scale) {
	class BitmapFont* font = this->renderContext->clientInstance->minecraftGame->mcFontA;
	RectangleArea rect = RectangleArea(position);
	TextMeasureData measureData = TextMeasureData(scale);
	CaretMeasureData caretData = CaretMeasureData();
	this->renderContext->drawText(font, &rect, &text, &color, 1.0f, nullptr, &measureData, &caretData);
	this->renderContext->flushText(0);
}