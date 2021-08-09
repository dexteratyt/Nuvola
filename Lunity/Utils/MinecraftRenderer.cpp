#include "MinecraftRenderer.h"
#include "../Client/Bridge/MinecraftGame.h"

MinecraftRenderer::MinecraftRenderer(MinecraftUIRenderContext* renderContext) {
	this->renderContext = renderContext;
}

/* Animation wrappers */
auto MinecraftRenderer::GetDeltaTime() -> float {
	return IAnimWrapper::GetDeltaTime();
}

/* Draw Text wrappers */
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

/* Fill wrappers */
void MinecraftRenderer::Fill(float x, float y, float width, float height, Color color) {
	MinecraftRenderer::Fill(Vector2<float>(x, y), Vector2<float>(width, height), color);
}
void MinecraftRenderer::Fill(float x, float y, Vector2<float> size, Color color) {
	MinecraftRenderer::Fill(Vector2<float>(x, y), size, color);
}
void MinecraftRenderer::Fill(Vector2<float> position, float width, float height, Color color) {
	MinecraftRenderer::Fill(position, Vector2<float>(width, height), color);
}
void MinecraftRenderer::Fill(Vector2<float> position, Vector2<float> size, Color color) {
	MinecraftRenderer::Fill(RectangleArea(position, size), color);
}
void MinecraftRenderer::Fill(RectangleArea rectangle, Color color) {
	this->renderContext->fillRectangle((float*)&rectangle, (float*)&color, color.w);
}