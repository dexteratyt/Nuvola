#include  "SetRotHook.h"

void __fastcall SetRotHook::SetRotCallback_1_17_10_4(Mob* mob, Vector2<float>* vector) {
	PLH::FnCast(funcOriginal, &SetRotCallback_1_17_10_4)(mob, vector);
	ClientInstance* client = Utils::GetClientInstance();
	LocalPlayer* lPlayer = client->ClientPlayer();
	if(lPlayer) {
		Vector2<float> lookVec = lPlayer->LookingVec();
		lookVec.x = 0;
		lPlayer->LookingVec(lookVec);
	}
}

SetRotHook::SetRotHook() : IPatch::IPatch("Actor::SetRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 83 ?? ?? 8B ?? ?? 48 8B ?? 48 81"), -1));
}

auto SetRotHook::Apply() -> bool {
	return this->AutoPatch(&SetRotCallback_1_17_10_4, &funcOriginal);
}