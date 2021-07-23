#include  "SnapLookingVecHook.h"

#include "../../Events/Mob/UpdateRot.h"

void __fastcall SnapLookingVecHook::SnapLookingVecHook_1_17_10_4(Mob* mob, Vector2<float>* vector) {
	UpdateRot event(mob, vector);
	EventHandler::GetInstance()->DispatchEvent(EVENT_ID::MOB_UPDATE_ROT, &event);
	if(event.IsCancelled()) {
		return;
	}
	PLH::FnCast(funcOriginal, &SnapLookingVecHook_1_17_10_4)(event.GetMob(), event.GetNewVector());
	// ClientInstance* client = Utils::GetClientInstance();
	// LocalPlayer* lPlayer = client->ClientPlayer();
	// if(lPlayer) {
	// 	Vector2<float> lookVec = lPlayer->LookingVec();
	// 	lookVec.x = 0;
	// 	lPlayer->LookingVec(lookVec);
	// }
}

SnapLookingVecHook::SnapLookingVecHook() : IPatch::IPatch("LocalPlayer::SetYHeadRot") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? 57 48 83 ?? ?? 8B ?? ?? 48 8B ?? 48 81"), -1));
}

auto SnapLookingVecHook::Apply() -> bool {
	return this->AutoPatch(&SnapLookingVecHook_1_17_10_4, &funcOriginal);
}