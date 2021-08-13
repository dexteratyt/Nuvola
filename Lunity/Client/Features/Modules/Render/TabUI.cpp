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

#define COL_SELECTION COL_BACKGROUND //Color(.53, 0.16, 0.94, .3)
#define COL_BACKGROUND Color(1.0f, 0.53f, 0.78f, .3f)
#define COL_BRAND Color()
#define COL_CAT_SELECT Color(0.97f, 1.0f, 0.97f)
#define COL_CAT COL_CAT_SELECT //Color(0.02,0.03,0.05)
#define COL_CHOSEN Color(89, 44, 68)

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

		if(thisMod->IsEnabled()) {
			if(tabLocX < BASE_PADDING) {
				tabLocX += renderer->GetDeltaTime() * (ANIM_SPEED*5);
			} else {
				tabLocX = BASE_PADDING;
			}
		} else {
			if(tabLocX > -100) {
				tabLocX -= renderer->GetDeltaTime() * (ANIM_SPEED*5);
			} else {
				tabLocX = -100;
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

		Module* mod = dynamic_cast<Module*>(toRender);
		bool isHighlighted = toRender == highlightedCat || toRender == highlightedMod;
		bool isSelected = toRender == selectedCat || (mod != nullptr ? mod->IsEnabled() : false);
		Color bgColor = COL_BACKGROUND;
		Color textColor = Color();
		if(isHighlighted) {
			bgColor = COL_SELECTION;
		}
		if(isSelected) {
			bgColor = COL_CHOSEN;
		}
		if(isHighlighted && isSelected) {
			bgColor = Color();
			textColor = Color(0,0,0);
		}
		if(isHighlighted || isSelected) {
			renderer->Fill(RectangleArea(location.x, location.y, bgAnimWidthX, size.y), bgColor);
		}
		renderer->DrawString(toRender->getName(), location, textColor);
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
		Manager<ManagedItem>* moduleMgr = (Manager<ManagedItem>*)ModuleMgr::getInstance();
		if(highlightedCat == nullptr) {
			highlightedCat = moduleMgr->getItem(0);
		}
		renderMgr(e->GetRenderWrapper(), moduleMgr, categoriesLoc, Vector2<float>(maxBgAnimWidthX, TEXT_HEIGHT) * CATEGORY_SCALE);
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
						if(selectedCat == nullptr) {
							selectedCat = highlightedCat;
							currentSelection = 0;
						} else {
							Category* cat = ((Category*)selectedCat);
							if(cat->getItems()->size() < 1) {
								break;
							}
							Module* mod = cat->getItem(currentSelection);
							if(mod != nullptr) {
								mod->Toggle();
							}
						}
						break;
					case VK_DOWN:
						currentSelection++;
						resetAnim();
						break;
				}
			}
		}
		sanitizeSelection();
	}
}
TabUI::TabUI() : Module("TabUI", VK_TAB) {
	this->SetEnabled(true);
	//Register this event here, it will never be unregistered
	//If this goes in on enable, since its never unregistered, it will register again, causing it to draw multiple times/frame
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, TabUI_Locals::onRender);
}

void TabUI::OnEnable() {
	//Enable code
	EventHandler::GetInstance()->ListenFor(EVENT_ID::KEYPRESS_EVENT, TabUI_Locals::onKey);
}

void TabUI::OnDisable() {
	//Disable code
	EventHandler::GetInstance()->UnlistenFor(EVENT_ID::KEYPRESS_EVENT, TabUI_Locals::onKey);
	TabUI_Locals::highlightedCat = ModuleMgr::getInstance()->getItem(0);
	TabUI_Locals::selectedCat = nullptr;
	TabUI_Locals::currentSelection = 0;
}