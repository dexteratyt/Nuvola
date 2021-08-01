#ifndef GUARD_Actor
#define GUARD_Actor
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct Actor {
	/* Fields */
	char padding_320[320];
	Vector2<float> LookingVec;
	char padding_480[152];
	bool OnGround;
	char padding_872[391];
	class BlockSource* WorldSource;
	/* Virtuals */
	void virt_pad_0() {};
	void virt_pad_1() {};
	void virt_pad_2() {};
	void virt_pad_3() {};
	void virt_pad_4() {};
	void virt_pad_5() {};
	void virt_pad_6() {};
	void virt_pad_7() {};
	void virt_pad_8() {};
	void virt_pad_9() {};
	void virt_pad_10() {};
	void virt_pad_11() {};
	void virt_pad_12() {};
	void virt_pad_13() {};
	void virt_pad_14() {};
	auto getPos() -> Vector3<float>* {};
	/* Functions */
};
#endif