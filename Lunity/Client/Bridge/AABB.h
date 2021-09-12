#ifndef GUARD_AABB
#define GUARD_AABB
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct AABB {
	/* Fields */
	Vector3<float> firstCorner;
	Vector3<float> secondCorner;
	bool allZero;
	/* Virtuals */
	/* Functions */
};
#endif