#include "ClickGui.h"

#include "../../../Events/Renderer/UIRenderEvent.h"
#include "../../../Bridge/MinecraftUIRenderContext.h"
#include "../../../Bridge/ScreenContext.h"
#include "../../../Bridge/MeshHelpers.h"
#include "../../../Bridge/Tessellator.h"

namespace ClickGui_Globals {
	void onRender(EventData* event) {
		UIRenderEvent* e = event->as<UIRenderEvent>();
		MinecraftUIRenderContext* context = e->GetRenderContext();
		Tessellator* tess = context->screenContext->tessellator;
		tess->begin(1, 4, 0);
		tess->vertex(0, 0, 0);
		tess->vertex(0, 100, 0);
		tess->vertex(100, 100, 0);
		tess->vertex(100, 0, 0);
		MeshHelpers::renderMeshImmediately(context->screenContext, tess, Utils::GetUIMaterialPtr());
	}
}

ClickGui::ClickGui() : Module("ClickGui") {

}
void ClickGui::OnEnable() {
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, ClickGui_Globals::onRender);
}
void ClickGui::OnDisable() {
	EventHandler::GetInstance()->UnlistenFor(EVENT_ID::RENDER_EVENT, ClickGui_Globals::onRender);
}