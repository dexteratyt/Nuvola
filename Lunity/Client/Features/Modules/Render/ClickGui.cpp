#include "ClickGui.h"

#include "../../../Events/Renderer/UIRenderEvent.h"
#include "../../../Bridge/MinecraftUIRenderContext.h"
#include "../../../Bridge/ScreenContext.h"
#include "../../../Bridge/MeshHelpers.h"
#include "../../../Bridge/Tessellator.h"
#include "../../../Bridge/ClientInstance.h"
#include "../../../Bridge/LocalPlayer.h"
#include <vector>
#include <sstream>
#include "../../../Bridge/Level.h"

namespace ClickGui_Globals {

	std::vector<void*> testVec;

	std::string to_hex_string( size_t i ) {
		std::stringstream s;
		s << "0x" << std::hex << i;
		return s.str();
	}

	void onRender(EventData* event) {
		UIRenderEvent* e = event->as<UIRenderEvent>();
		MinecraftUIRenderContext* context = e->GetRenderContext();
		MinecraftRenderer* wrapper = e->GetRenderWrapper();
		// Tessellator* tess = context->screenContext->tessellator;
		// tess->begin(1, 4, 0);
		// tess->vertex(0, 0, 0);
		// tess->vertex(0, 100, 0);
		// tess->vertex(100, 100, 0);
		// tess->vertex(100, 0, 0);
		// MeshHelpers::renderMeshImmediately(context->screenContext, tess, Utils::GetUIMaterialPtr());


		ClientInstance* client = e->GetRenderContext()->clientInstance;
		LocalPlayer* player = client->clientPlayer;
		if(player) {
			Level* level = player->level;
			if(level) {
				size_t count = level->actors.size();
				wrapper->DrawString(std::to_string(count), Vector2<float>(0,0));
				wrapper->DrawString(to_hex_string((size_t)&testVec), Vector2<float>(0,10));
			}
		}
	}
}

ClickGui::ClickGui() : Module("ClickGui") {
	ClickGui_Globals::testVec.push_back(&ClickGui_Globals::testVec);
}
void ClickGui::OnEnable() {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, ClickGui_Globals::onRender);
}
void ClickGui::OnDisable() {
	EventHandler::GetInstance()->UnlistenFor(EVENT_ID::RENDER_EVENT, ClickGui_Globals::onRender);
}