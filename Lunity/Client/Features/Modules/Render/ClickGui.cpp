#include "ClickGui.h"

#include "../../../Bridge/MinecraftUIRenderContext.h"
#include "../../../Bridge/ScreenContext.h"
#include "../../../Bridge/MeshHelpers.h"
#include "../../../Bridge/Tessellator.h"
#include "../../../Bridge/ClientInstance.h"
#include "../../../Bridge/LocalPlayer.h"
#include <sstream>
#include "../../../Bridge/Level.h"

std::vector<void*> testVec;

std::string to_hex_string( size_t i ) {
	std::stringstream s;
	s << "0x" << std::hex << i;
	return s.str();
}

void ClickGui::onRenderEvent(RenderEvent& event) {
	MinecraftUIRenderContext* context = event.GetRenderContext();
	MinecraftRenderer* wrapper = event.GetRenderWrapper();

	ClientInstance* client = event.GetRenderContext()->clientInstance;
	LocalPlayer* player = client->clientPlayer;
	if(player) {
		Level* level = player->level;
		if(level) {
			size_t player_count = level->players.size();
			size_t actor_count = level->actors.size();
			wrapper->DrawString(std::to_string(player_count), Vector2<float>(0,0));
			wrapper->DrawString(std::to_string(actor_count), Vector2<float>(0,10));
			wrapper->DrawString(to_hex_string((size_t)&testVec), Vector2<float>(0,20));
		}
	}
}

ClickGui::ClickGui() : Module("ClickGui") {
	testVec.push_back(&testVec);
}
void ClickGui::OnEnable() {
	EventHandler::registerListener(this);
}
void ClickGui::OnDisable() {
	EventHandler::unregisterListener(this);
}