#ifndef GUARD_Actor
#define GUARD_Actor
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
#include "NamespacedKey.h"
struct Actor {
	/* Fields */
	char padding_320[312];
	Vector2<float> lookingVec;
	char padding_480[152];
	bool onGround;
	char padding_872[391];
	class BlockSource* blockSource;
	class Dimension* dimension;
	class Level* level;
	char padding_1008[112];
	NamespacedKey type;
	/* Virtuals */
	virtual void virt_pad_0() {};
	virtual void virt_pad_1() {};
	virtual void virt_pad_2() {};
	virtual void virt_pad_3() {};
	virtual void virt_pad_4() {};
	virtual void virt_pad_5() {};
	virtual void virt_pad_6() {};
	virtual void virt_pad_7() {};
	virtual void virt_pad_8() {};
	virtual void virt_pad_9() {};
	virtual void virt_pad_10() {};
	virtual void virt_pad_11() {};
	virtual void virt_pad_12() {};
	virtual void virt_pad_13() {};
	virtual void virt_pad_14() {};
	virtual auto getPos() -> Vector3<float>* {};
	/* Functions */
};
#endif