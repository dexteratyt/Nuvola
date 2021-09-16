#ifndef GUARD_ScreenContext
#define GUARD_ScreenContext
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
struct ScreenContext {
	/* Fields */
	char padding_48[48];
	class Color* shaderColor;
	char padding_176[120];
	class Tessellator* tessellator;
	/* Virtuals */
	/* Functions */
};
#endif