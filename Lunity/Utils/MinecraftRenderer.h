#ifndef LUNITY_UTILS_MINECRAFTRENDERER
#define LUNITY_UTILS_MINECRAFTRENDERER

#include "Math.h"
#include "../Client/Bridge/MinecraftUIRenderContext.h"
#include <string>
#include "IAnimWrapper.h"

//A MinecraftUIRenderContext wrapper
class MinecraftRenderer {
	MinecraftUIRenderContext* renderContext;
public:
	MinecraftRenderer(MinecraftUIRenderContext* renderContext);

	/* Animation helpers */
	auto GetDeltaTime() -> float;

	/* Text drawing wrappers */
	void DrawString(std::string text, Vector2<float> position);
	void DrawString(std::string text, Vector2<float> position, Color color);
	void DrawString(std::string text, Vector2<float> position, Color color, float scale);

	/* Fill wrappers */
	void Fill(float x, float y, float width, float height, Color color);
	void Fill(float x, float y, Vector2<float> size, Color color);
	void Fill(Vector2<float> position, float width, float height, Color color);
	void Fill(Vector2<float> position, Vector2<float> size, Color color);
	void Fill(RectangleArea rectangle, Color color);
};

#endif /* LUNITY_UTILS_MINECRAFTRENDERER */
