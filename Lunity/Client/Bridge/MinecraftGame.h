#ifndef LUNITY_CLIENT_BRIDGE_MINECRAFTGAME
#define LUNITY_CLIENT_BRIDGE_MINECRAFTGAME
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct MinecraftGame {
	/* Fields */
	char padding_248[248];
	class FontRepository* fontRepository;
	char padding_272[16];
	class BitmapFont* mcFontA;
	char padding_344[64];
	class BitmapFont* mcFontB;
	char padding_416[64];
	class BitmapFont* mcFontC;
	char padding_560[136];
	class BitmapFont* mcFontD;
	/* Virtuals */
	/* Functions */
};
#endif /* LUNITY_CLIENT_BRIDGE_MINECRAFTGAME */
