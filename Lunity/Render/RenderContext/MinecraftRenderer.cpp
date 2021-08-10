#include "MinecraftRenderer.h"

/* Private helper functions */
auto MinecraftRenderer::getFont() -> class BitmapFont* {
	return this->renderContext->clientInstance->minecraftGame->mcFontA;
}

/* Wrapper API below */
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
	class BitmapFont* font = MinecraftRenderer::getFont();
	RectangleArea rect = RectangleArea(position);
	TextMeasureData measureData = TextMeasureData(scale);
	CaretMeasureData caretData = CaretMeasureData();
	this->renderContext->drawText(font, &rect, &text, &color, 1.0f, nullptr, &measureData, &caretData);
	this->renderContext->flushText(0);
}

/* Text measure wrappers */
auto MinecraftRenderer::MeasureText(std::string text) -> float {
	return MinecraftRenderer::MeasureText(text, 1.0f);
}
auto MinecraftRenderer::MeasureText(std::string text, float scale) -> float {
	class BitmapFont* font = MinecraftRenderer::getFont();
	return this->renderContext->getLineLength(font, &text, scale);
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