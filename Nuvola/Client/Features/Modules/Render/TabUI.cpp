#include "TabUI.h"
#include "../../ModuleMgr.h"
#include <Windows.h>

#include <gsl/gsl>
#include <unordered_set>
#include "../../../Bridge/LocalPlayer.h"
#include "../../../Bridge/ClientInstance.h"
#include "../../../Bridge/GuiData.h"
#include "../../../Bridge/Level.h"

/* Tab GUI constants*/
#define BRAND std::string("Nuvola")

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

//#define MOUSE_SUPPORT

//I made a namespace here because I don't want to deal with conflicting names in the future
namespace TabUI_Locals {

	float bgAnimWidthX = 0;
	float maxBgAnimWidthX = 0;
	float brandWidth = 0;

	Vector2<short> mousePos;
	bool clickBuff = false;

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

	void renderItem(MinecraftRenderer* renderer, ManagedItem* toRender, Vector2<float> location, Vector2<float> size, bool isModule) {
		renderer->Fill(RectangleArea(location, size), COL_BACKGROUND);

/*
		GuiData* guiData = Utils::GetClientInstance()->guiData;

		Vector2<short> mousePosScaled = Vector2<short>(mousePos.x * guiData->scale, mousePos.y * guiData->scale);
		bool mouseOver = location.x < mousePosScaled.x && location.y < mousePosScaled.y && size.x+location.x > mousePosScaled.x && size.y+location.y > mousePosScaled.y;

		
		if(mouseOver) {
			if(selectedCat) {
				highlightedMod = toRender;
			} else {
				highlightedCat = toRender;
			}
		}
		//if the click input buffer is waiting and this is highlighted
		if(clickBuff && mouseOver) {
			if(selectedCat && isModule) {
				((Module*)toRender)->Toggle();
			}
			else {
				selectedCat = toRender;
			}
			clickBuff = false;
		}
*/

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

	void renderMgr(MinecraftRenderer* renderer, Manager<ManagedItem>* toRender, Vector2<float> location, Vector2<float> size, bool isModule) {
		for(auto item : *toRender->getItems()) {
			renderItem(renderer, item, location, size, isModule);
			location.y += TEXT_HEIGHT;
		}
	}

	auto renderBranding(MinecraftRenderer* renderer, Vector2<float> location) -> float {
		brandWidth = renderer->MeasureText(BRAND);
		renderer->Fill(RectangleArea(location/2, Vector2<float>(brandWidth, TEXT_HEIGHT)), COL_BACKGROUND);
		renderer->DrawString(BRAND, location/2, COL_BRAND);
		return brandWidth;
	}

	void onRender(RenderEvent* e) {
		e->GetRenderWrapper()->SetScale(BRAND_SCALE);
		float width = renderBranding(e->GetRenderWrapper(), Vector2<float>(getTabLocX(), BASE_PADDING));

		e->GetRenderWrapper()->SetScale(CATEGORY_SCALE);
		Vector2<float> categoriesLoc = Vector2<float>(getTabLocX(), (BASE_PADDING * BRAND_SCALE) + (CATEGORY_SCALE * TEXT_HEIGHT));
		maxBgAnimWidthX = width * BRAND_SCALE;
		Manager<ManagedItem>* moduleMgr = (Manager<ManagedItem>*)ModuleMgr::getInstance();
		if(highlightedCat == nullptr) {
			highlightedCat = moduleMgr->getItem(0);
		}
		renderMgr(e->GetRenderWrapper(), moduleMgr, categoriesLoc, Vector2<float>(maxBgAnimWidthX, TEXT_HEIGHT) * CATEGORY_SCALE, false);
		if(selectedCat != nullptr) {
			Vector2<float> modulesLoc = categoriesLoc;
			modulesLoc.x += maxBgAnimWidthX;
			renderMgr(e->GetRenderWrapper(), (Manager<ManagedItem>*)selectedCat, modulesLoc, Vector2<float>(maxBgAnimWidthX, TEXT_HEIGHT) * CATEGORY_SCALE, true);
		}

/*
		std::string error = "";
		int entityCount = 0;
		ClientInstance* client = Utils::GetClientInstance();
		if(client) {
			LocalPlayer* player = client->clientPlayer;
			if(player) {
				Level* level = player->level;
				if(level) {
					std::unordered_set<gsl::not_null<Actor*>>* entities = level->getGlobalEntities();
					if(entities) {
						entityCount = entities->size();
					} else {
						error = "Cant reach entities";
					}
				}
				else {
					error = "Cant reach level";
				}
			}
			else {
				error = "Cant reach player";
			}
		}
		else {
			error = "Cant reach client";
		}
		
		e->GetRenderWrapper()->DrawString(error + std::to_string(entityCount), Vector2<float>(0,0));
*/
#ifdef MOUSE_SUPPORT
		GuiData* guiData = Utils::GetClientInstance()->guiData;
		Vector2<short> mousePosScaled = Vector2<short>(mousePos.x * guiData->scale, mousePos.y * guiData->scale);
		e->GetRenderWrapper()->DrawString(std::to_string(mousePos.x) + std::string(", ") + std::to_string(mousePos.y), Vector2<float>(0,0));
		e->GetRenderWrapper()->DrawString(std::to_string(mousePosScaled.x) + std::string(", ") + std::to_string(mousePosScaled.y), Vector2<float>(0,10));
		e->GetRenderWrapper()->DrawString(std::to_string(guiData->scale), Vector2<float>(0,20));
#endif
		updateAnimVars(e->GetRenderWrapper());
	}

	void onKey(KeyEvent* e) {
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
#ifdef MOUSE_SUPPORT
	void onMouse(EventData* event) {
		MouseEvent* e = event->as<MouseEvent>();
		mousePos = e->GetMousePos();
		GuiData* guiData = Utils::GetClientInstance()->guiData;

		Vector2<float> uiLoc = Vector2<float>(BASE_PADDING, BASE_PADDING);
		Vector2<float> uiSize = Vector2<float>(brandWidth/guiData->scale + (selectedCat != nullptr ? brandWidth/guiData->scale : 0), (BASE_PADDING * BRAND_SCALE) + (CATEGORY_SCALE * TEXT_HEIGHT) + ((CATEGORY_SCALE * TEXT_HEIGHT) * ModuleMgr::getInstance()->getAllModules()->size()));

		Vector2<short> mousePosScaled = Vector2<short>(mousePos.x * guiData->scale, mousePos.y * guiData->scale);
		bool mouseOver = uiLoc.x < mousePosScaled.x && uiLoc.y < mousePosScaled.y && uiSize.x+uiLoc.x > mousePosScaled.x && uiSize.y+uiLoc.y > mousePosScaled.y;
		if(mouseOver) {
			if(e->GetAction() == MouseAction::PRESS && e->GetButton() == MouseButton::LEFT) {
				if(selectedCat == nullptr) {
					selectedCat = highlightedCat;
					currentSelection = 0;
				} else {
					//If is category section
					if(mousePosScaled.x < uiLoc.x + (uiSize.x-(brandWidth/guiData->scale))) {
						//treat as deselect
						selectedCat = nullptr;
						return;
					}
					Category* cat = ((Category*)selectedCat);
					if(cat->getItems()->size() < 1) {
						return;
					}
					Module* mod = cat->getItem(currentSelection);
					if(mod != nullptr) {
						mod->Toggle();
					}
				}
			}
			currentSelection = floor(((mousePosScaled.y+1) - (BASE_PADDING * BRAND_SCALE))/10)-1;
			sanitizeSelection();
		}
	}
#endif
}

void TabUI::onRenderEvent(RenderEvent& event) {
	TabUI_Locals::onRender(&event);
};
void TabUI::onMouseEvent(MouseEvent& event) {
#ifdef MOUSE_SUPPORT
	if(this->IsEnabled()) {
		TabUI_Locals::onMouseEvent(&event);
	}
#endif
}
void TabUI::onKeyEvent(KeyEvent& event) {
	if(this->IsEnabled()) {
		TabUI_Locals::onKey(&event);
	}
}

TabUI::TabUI() : Module("TabUI", VK_TAB) {
	this->SetEnabled(true);
	//Register this event here, it will never be unregistered
	//If this goes in on enable, since its never unregistered, it will register again, causing it to draw multiple times/frame
	EventHandler::registerListener(this);
}

void TabUI::OnEnable() {
}

void TabUI::OnDisable() {
	TabUI_Locals::highlightedCat = ModuleMgr::getInstance()->getItem(0);
	TabUI_Locals::selectedCat = nullptr;
	TabUI_Locals::currentSelection = 0;
}