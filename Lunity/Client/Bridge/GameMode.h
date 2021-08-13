#ifndef GUARD_GameMode
#define GUARD_GameMode
#include "../../Utils/Math.h"
#include "../../Utils/Utils.h"
#include "../../Mem/Mem.h"
struct GameMode {
	/* Fields */
	class Player* player;
	/* Virtuals */
	virtual void virt_pad_0() {};
	virtual auto startDestroyBlock(class BlockPos* pos, char blockFace, bool param_3) -> bool {};
	virtual auto destroyBlock(class BlockPos* pos, char blockFace) -> bool {};
	virtual auto continueDestroyBlock(class BlockPos* pos, char blockFace, Vector3<float>* param_3, bool param_4) -> bool {};
	virtual auto stopDestroyBlock(class BlockPos* pos) -> void {};
	virtual auto startBuildBlock(class BlockPos* pos, char blockFace) -> void {};
	virtual auto buildBlock(class BlockPos* pos, char blockFacee) -> bool {};
	virtual auto continueBuildBlock(class BlockPos* pos, char blockFace) -> void {};
	virtual auto stopBuildBlock() -> void {};
	virtual auto tick() -> void {};
	virtual auto getPickRange(class InputMode* inputMode, bool param_2) -> float {};
	virtual auto useItem(class ItemStack* itemStack) -> bool {};
	virtual auto useItemOn(class ItemStack* itemStack, class BlockPos* pos, char blockFace, Vector3<float>* param_4, class Block* block) -> bool {};
	virtual auto interact(class Actor* actor, Vector3<float>* pos) -> bool {};
	virtual auto attack(class Actor* actor) -> bool {};
	virtual auto releaseUsingItem() -> void {};
	/* Functions */
};
#endif