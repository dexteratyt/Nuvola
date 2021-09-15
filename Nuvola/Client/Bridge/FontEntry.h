#ifndef GUARD_FontEntry
#define GUARD_FontEntry
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct FontEntry {
	/* Fields */
	char padding_40[40];
	class BitmapFont* font;
	char padding_64[16];
	void* wackyptr;
	/* Virtuals */
	/* Functions */
};
#endif