#ifndef GUARD_IntOption
#define GUARD_IntOption
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "../../Utils/Nuv.h"
#include "Option.h"
struct IntOption : public Option {
	/* Fields */
	char padding_16[16];
	int maximum;
	char padding_24[4];
	int value;
	char padding_32[4];
	int minimum;
	/* Virtuals */
	/* Functions */
};
#endif