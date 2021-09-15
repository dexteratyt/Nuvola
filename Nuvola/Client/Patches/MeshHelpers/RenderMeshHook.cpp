#include "RenderMeshHook.h"

auto __fastcall RenderMeshHook::renderMeshImmediatelyCallback_1_17_10_4(class ScreenContext* screenContext, class Tessellator* tessellator, class MaterialPtr* material) -> void {
	return PLH::FnCast(funcOriginal, &renderMeshImmediatelyCallback_1_17_10_4)(screenContext, tessellator, material);
}

RenderMeshHook::RenderMeshHook() : IPatch::IPatch("MeshHelpers::renderMeshImmediately") {
	//Ok I get it, this system is heap hell.
	//I just dont want objects getting destroyed
	this->AddSignature(new SigInfo(new std::string("40 ?? 56 57 48 81 ?? ?? ?? ?? ?? 49 8B ?? 48 8B ?? 48 8B ?? ?? BA"), 0));
}

auto RenderMeshHook::Apply() -> bool {
	return this->AutoPatch(renderMeshImmediatelyCallback_1_17_10_4, &funcOriginal);
}