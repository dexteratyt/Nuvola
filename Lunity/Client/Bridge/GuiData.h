#ifndef GUARD_GuiData
#define GUARD_GuiData
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct GuiData {
	/* Fields */
	char padding_24[24];
	Vector2<float> resolution;
	char padding_40[8];
	Vector2<float> scaledResolution;
	char padding_56[8];
	float scale;
	char padding_82[22];
	Vector2<short> mousePos;
	/* Virtuals */
	/* Functions */
};
#endif