#ifndef NUVOLA_RENDER_RENDERCONTEXT_MINECRAFTRENDERER
#define NUVOLA_RENDER_RENDERCONTEXT_MINECRAFTRENDERER

#include "Math.h"
#include "../../Client/Bridge/MinecraftUIRenderContext.h"
#include "../../Client/Bridge/MinecraftGame.h"
#include "../../Client/Bridge/FontRepository.h"
#include "../../Client/Bridge/FontList.h"
#include "../../Client/Bridge/FontEntry.h"
#include <string>
#include "../IAnimWrapper.h"

#define TEXT_HEIGHT 10

//A MinecraftUIRenderContext wrapper
class MinecraftRenderer {
	MinecraftUIRenderContext* renderContext;
	auto getFont() -> class BitmapFont*;
	float scale;
public:
	MinecraftRenderer(MinecraftUIRenderContext* renderContext);

	/* Animation helpers */
	auto GetDeltaTime() -> float;

	/* Sizing wrappers */
	void SetScale(float scale);
	auto GetScale() -> float;

	/* Text drawing wrappers */
	void DrawString(std::string text, Vector2<float> position);
	void DrawString(std::string text, Vector2<float> position, Color color);

	/* Text measure wrappers */
	auto MeasureText(std::string text) -> float;
	auto MeasureText(std::string text, float scale) -> float;

	/* Fill wrappers */
	void Fill(float x, float y, float width, float height, Color color);
	void Fill(float x, float y, Vector2<float> size, Color color);
	void Fill(Vector2<float> position, float width, float height, Color color);
	void Fill(Vector2<float> position, Vector2<float> size, Color color);
	void Fill(RectangleArea rectangle, Color color);
};

#endif /* NUVOLA_RENDER_RENDERCONTEXT_MINECRAFTRENDERER */
