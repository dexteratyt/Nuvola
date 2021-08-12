#include "TabUI.h"
#include "../../../Events/Renderer/UIRenderEvent.h"
#include "../../../Events/Global/KeyPressEvent.h"
#include "../../ModuleMgr.h"
#include <Windows.h>

/* Tab GUI constants*/
#define BRAND std::string("Lunity")

#define BASE_PADDING 10
#define BRAND_SCALE 2
#define CATEGORY_SCALE 1
#define ANIM_SPEED 100

#define COL_SELECTION Color(.53, 0.16, 0.94, .3)
#define COL_BACKGROUND Color(1, 0.53, 0.78, .3)
#define COL_BRAND Color()
#define COL_CAT_SELECT Color(0.97, 1, 0.97)
#define COL_CAT COL_CAT_SELECT //Color(0.02,0.03,0.05)
#define COL_CHOSEN Color(0.18, 0.18, 0.18)

//I made a namespace here because I don't want to deal with conflicting names in the future
namespace TabUI_Locals {

	float bgAnimWidthX = 0;
	float maxBgAnimWidthX = 0;

	float tabLocX = 0;
	auto getTabLocX() -> float {
		return floor(tabLocX);
	}

	int currentSelection = 0;

	ManagedItem* highlightedCat = nullptr;
	ManagedItem* selectedCat = nullptr;
	ManagedItem* highlightedMod = nullptr;

	Module* thisMod;

	void resetAnim() {
		bgAnimWidthX = 0;
	}
	void sanitizeSelection() {
		Manager<ManagedItem>* manager;
		int max;
		if(selectedCat) {
			manager = ((Manager<ManagedItem>*)selectedCat);
		} else {
			manager = (Manager<ManagedItem>*)ModuleMgr::getInstance();
		}
		max = manager->getItems()->size();

		if(currentSelection >= max) {
			currentSelection = 0;
		}
		if(currentSelection < 0) {
			currentSelection = max-1;
		}

		if(max > 0) {
			if(selectedCat) {
				highlightedMod = manager->getItem(currentSelection);
			} else {
				highlightedCat = manager->getItem(currentSelection);
			}
		}
	}

	void updateAnimVars(MinecraftRenderer* renderer) {
		if(!thisMod) {
			thisMod = ModuleMgr::getInstance()->findModule("TabUI");
		}

		if(thisMod->isEnabled()) {
			if(tabLocX < BASE_PADDING) {
				tabLocX += renderer->GetDeltaTime() * (ANIM_SPEED*5);
			} else {
				tabLocX = BASE_PADDING;
			}
		} else {
			if(tabLocX > -200) {
				tabLocX -= renderer->GetDeltaTime() * (ANIM_SPEED*5);
			} else {
				tabLocX = -200;
			}
		}

		if(bgAnimWidthX < maxBgAnimWidthX) {
			bgAnimWidthX += renderer->GetDeltaTime() * (ANIM_SPEED*5);
		} else {
			bgAnimWidthX = maxBgAnimWidthX;
		}
	}

	void renderItem(MinecraftRenderer* renderer, ManagedItem* toRender, Vector2<float> location, Vector2<float> size) {
		renderer->Fill(RectangleArea(location, size), COL_BACKGROUND);
		if(toRender == highlightedCat) {
			renderer->Fill(RectangleArea(location.x, location.y, bgAnimWidthX, size.y), COL_SELECTION);
		}
		Module* mod = dynamic_cast<Module*>(toRender);
		if(toRender == selectedCat || (mod != nullptr ? mod->isEnabled() : false)) {
			renderer->Fill(RectangleArea(location.x, location.y, bgAnimWidthX, size.y), COL_CHOSEN);
		}
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
		float width = renderBranding(e->GetRenderWrapper(), Vector2<float>(getTabLocX(), BASE_PADDING));

		e->GetRenderWrapper()->SetScale(CATEGORY_SCALE);
		Vector2<float> categoriesLoc = Vector2<float>(getTabLocX(), (BASE_PADDING * BRAND_SCALE) + (CATEGORY_SCALE * TEXT_HEIGHT));
		maxBgAnimWidthX = width * BRAND_SCALE;
		renderMgr(e->GetRenderWrapper(), (Manager<ManagedItem>*)ModuleMgr::getInstance(), categoriesLoc, Vector2<float>(maxBgAnimWidthX, TEXT_HEIGHT) * CATEGORY_SCALE);
		if(selectedCat != nullptr) {
			Vector2<float> modulesLoc = categoriesLoc;
			modulesLoc.x += maxBgAnimWidthX;
			renderMgr(e->GetRenderWrapper(), (Manager<ManagedItem>*)selectedCat, modulesLoc, Vector2<float>(maxBgAnimWidthX, TEXT_HEIGHT) * CATEGORY_SCALE);
		}

		updateAnimVars(e->GetRenderWrapper());
	}

	void onKey(EventData* event) {
		KeyPressEvent* e = event->as<KeyPressEvent>();

		if(e->GetAction() == KeyAction::PRESSED) {
			if(thisMod) {
				switch(e->GetKey()) {
					case VK_LEFT:
						selectedCat = nullptr;
						break;
					case VK_UP:
						currentSelection--;
						resetAnim();
						break;
					case VK_RIGHT:
						selectedCat = highlightedCat;
						break;
					case VK_DOWN:
						currentSelection++;
						resetAnim();
						break;
					case VK_TAB:
						thisMod->toggle();
						break;
				}
			}
		}
		sanitizeSelection();
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