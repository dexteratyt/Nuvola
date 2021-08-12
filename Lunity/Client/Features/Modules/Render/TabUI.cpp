#include "TabUI.h"
#include "../../../Events/Renderer/UIRenderEvent.h"
#include "../../../Events/Global/KeyPressEvent.h"
#include "../../ModuleMgr.h"
#include <Windows.h>

/* Tab GUI constants*/
#define BRAND std::string("Lunity")

#define BASE_PADDING 10, 10
#define BRAND_SCALE 2
#define CATEGORY_SCALE 1
#define ANIM_SPEED 70

#define COL_SELECTION Color(.53, 0.16, 0.94, .3)
#define COL_BACKGROUND Color(1, 0.53, 0.78, .3)
#define COL_BRAND Color()
#define COL_CAT_SELECT Color(0.97, 1, 0.97)
#define COL_CAT COL_CAT_SELECT //Color(0.02,0.03,0.05)
#define COL_CHOSEN Color(0.18, 0.18, 0.18)

//I made a namespace here because I don't want to deal with conflicting names in the future
namespace TabUI_Locals {
	void resetAnim() {
	}

	void renderItem(MinecraftRenderer* renderer, ManagedItem* toRender, Vector2<float> location, Vector2<float> size) {
		renderer->Fill(RectangleArea(location, size), COL_BACKGROUND);
		renderer->DrawString(toRender->getName(), location);
	}

	void renderMgr(MinecraftRenderer* renderer, Manager<ManagedItem>* toRender, Vector2<float> location, Vector2<float> size) {
		for(auto item : *toRender->getItems()) {
			renderItem(renderer, item, location, size);
			location.y += TEXT_HEIGHT;
		}
	}

	auto renderBranding(MinecraftRenderer* renderer, Vector2<float> location) -> float {
		float brandWidth = renderer->MeasureText(BRAND);
		renderer->Fill(RectangleArea(location/2, Vector2<float>(brandWidth, TEXT_HEIGHT)), COL_BACKGROUND);
		renderer->DrawString(BRAND, location/2, COL_BRAND);
		return brandWidth;
	}

	void onRender(EventData* event) {
		UIRenderEvent* e = event->as<UIRenderEvent>();
		e->GetRenderWrapper()->SetScale(BRAND_SCALE);
		float width = renderBranding(e->GetRenderWrapper(), Vector2<float>(BASE_PADDING));

		e->GetRenderWrapper()->SetScale(CATEGORY_SCALE);
		Vector2<float> categoriesLoc = Vector2<float>(BASE_PADDING * BRAND_SCALE + (CATEGORY_SCALE * TEXT_HEIGHT));
		renderMgr(e->GetRenderWrapper(), (Manager<ManagedItem>*)ModuleMgr::getInstance(), categoriesLoc, Vector2<float>(width * BRAND_SCALE, TEXT_HEIGHT) * CATEGORY_SCALE);
	}

	void onKey(EventData* event) {
		KeyPressEvent* e = event->as<KeyPressEvent>();
	}
}
TabUI::TabUI() : Module("TabUI") {
	this->onEnable();
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, TabUI_Locals::onRender);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::KEYPRESS_EVENT, TabUI_Locals::onKey);
}

void TabUI::onEnable() {
	//Enable code
}

void TabUI::onDisable() {
	//Disable code
}