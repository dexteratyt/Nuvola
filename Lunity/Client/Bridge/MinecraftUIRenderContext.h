#ifndef GUARD_MinecraftUIRenderContext
#define GUARD_MinecraftUIRenderContext
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct MinecraftUIRenderContext {
	/* Fields */
	char padding_8[8];
	class ClientInstance* clientInstance;
	class ScreenContext* screenContext;
	char padding_40[16];
	float textAlpha;
	char padding_240[196];
	class UIScene* uiScene;
	/* Virtuals */
	/* Functions */
};
#endif