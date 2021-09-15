#ifndef GUARD_FontRepository
#define GUARD_FontRepository
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct FontRepository {
	/* Fields */
	char padding_16[16];
	class FontList* fontList;
	/* Virtuals */
	/* Functions */
};
#endif