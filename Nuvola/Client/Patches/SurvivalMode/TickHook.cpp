#include "TickHook.h"

#include "../../Events/TickEvent.h"

void __fastcall TickHook::tickCallback_1_17_11_1(SurvivalMode* gameMode) {
	PLH::FnCast(tickOriginal, tickCallback_1_17_11_1);

	if(gameMode->player != nullptr) {
		bool isLocal = gameMode->player == Utils::GetClientInstance()->clientPlayer;
		TickEvent event(gameMode, gameMode->player, isLocal);
		EventHandler::GetInstance()->DispatchEvent(EVENT_ID::INTERACTION_TICK_EVENT, &event);
	}
}


TickHook::TickHook() : IPatch("SurvivalMode::Tick") {
	this->AddSignature(new SigInfo(new std::string("89 ?? ?? ?? ?? 89 ?? ?? ?? ?? 89 ?? ?? ?? 55 48 ?? ?? ?? ?? 48 81 ?? ?? ?? ?? ?? 48 8B ?? ?? ?? ?? ?? 48 33 ?? ?? 89 ?? ?? 48 8B ?? 48 ?? ?? ?? ?? ?? ?? 48 ?? ?? ?? ?? ?? 8B"), -1));
};
auto TickHook::Apply() -> bool {
	return this->AutoPatch(tickCallback_1_17_11_1, &tickOriginal);
};