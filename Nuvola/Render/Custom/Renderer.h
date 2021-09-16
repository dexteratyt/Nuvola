#ifndef NUVOLA_RENDER_CUSTOM_RENDERER
#define NUVOLA_RENDER_CUSTOM_RENDERER

// This renderer is meant to behave like OpenGL
// in the sense of using Vertexes after a Begin command
// to define the aspects of what is being drawn.
// Another renderer class (Like SimpleRenderer) should
// be provided as an alternative for drawing basic shapes
// simply and efficiently using this renderer as a base

#include "../../Utils/Math.h"
#include <vector>

class Renderer {
	static inline int vertCount = 0;
	static inline std::vector<Vector2<float>> vectors;
public:
	static void Setup(class MinecraftUIRenderContext* renderContext);

	//TODO: Implement!!!
	//Begin & End
	static void Begin();
	static void End();

	//How the shape should look
	static void SetLineWidth(float width);
	
	static void SetColor(Vector3<float>);
	static void SetColor(float r, float g, float b);
	static void SetColor(Vector4<float>);
	static void SetColor(float r, float g, float b, float a);

	//The way to set a vertex
	static void Vertex2D(float x, float y);
	static void Vertex2D(Vector2<float>);
};

#endif /* NUVOLA_RENDER_CUSTOM_RENDERER */
