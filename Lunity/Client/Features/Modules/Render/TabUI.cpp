#include "TabUI.h"
#include "../../../Events/Renderer/UIRenderEvent.h"
#include "../../../Events/Global/KeyPressEvent.h"
#include "../../ModuleMgr.h"
#include <Windows.h>

/* Tab GUI */
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
namespace TabUIVars {
	int highlightedIndex = 0;
	Category* highlightedCategory = nullptr;
	Category* chosenCategory = nullptr;
	Module* highlightedModule = nullptr;
	float selectedCatX = 0; //X offset for the selected cat. This is for the animation.
	float selectedCatBgX = 0;
	float tabUiPosX = 9;
	bool tabUIShow = true;

	void resetAnim() {
		TabUIVars::selectedCatX = 0.0f;
		TabUIVars::selectedCatBgX = 0.0f;
	}
}

void renderMgr(MinecraftRenderer* renderer, Manager<ManagedItem>* toRender, Vector2<float> location, float textYOff, float bgInteractWidth) {
	std::vector<ManagedItem*>* items = toRender->getItems();
	for(int i = 0; i < items->size(); i++) {
		ManagedItem* item = items->at(i);
		Module* mod = dynamic_cast<Module*>(item);
		std::string catText = item->getName();
		bool isSelected = TabUIVars::highlightedCategory == item || TabUIVars::highlightedModule == item;
		bool isChosen = TabUIVars::chosenCategory == item || (mod != nullptr ? mod->isEnabled() : false);
		Vector2<float> catTextLoc = Vector2<float>(
			(isSelected ? floor(TabUIVars::selectedCatX) : 0) + (floor(location.x)+1), //Push to the right selectedCatX if the selected category is this one. 
																	//selectedCatX is floored because text doesnt render properly on decimals for some reason.
			textYOff + (i * (CATEGORY_SCALE * DRAWN_TEXT_HEIGHT)) //Multiply the category scale with text height, then multiply that by the current category and add the offset
		);
		
		if(isSelected) {
			renderer->Fill(location.x, location.y + (i * (CATEGORY_SCALE * TEXT_HEIGHT)), bgInteractWidth, TEXT_HEIGHT, COL_SELECTION);
		}
		if(isChosen) {
			renderer->Fill(location.x, location.y+(i*(CATEGORY_SCALE * TEXT_HEIGHT)), bgInteractWidth, TEXT_HEIGHT, COL_CHOSEN);
		}
		renderer->DrawString(catText, catTextLoc, isSelected ? COL_CAT_SELECT : COL_CAT, CATEGORY_SCALE);
	}
}

void onRender(EventData* event) {
	MinecraftRenderer* renderer = event->as<UIRenderEvent>()->GetRenderWrapper();
	float delta = renderer->GetDeltaTime();

	auto allCategories = ModuleMgr::getInstance()->getItems();
	if(TabUIVars::highlightedCategory == nullptr) {
		TabUIVars::highlightedCategory = allCategories->at(0);
	}
	float yOff = (BRAND_SCALE * DRAWN_TEXT_HEIGHT)+6.5;
	float yOffGeo = (BRAND_SCALE * TEXT_HEIGHT)+10;

	//Draw background
	float brandWidth = renderer->MeasureText("Lunity", BRAND_SCALE);
	float bgHeight = yOff + (allCategories->size() * (CATEGORY_SCALE * DRAWN_TEXT_HEIGHT)) + (BRAND_SCALE * DRAWN_TEXT_HEIGHT) + 1; //You can figure out this math for yourself
	
	renderer->Fill(TabUIVars::tabUiPosX, 10, brandWidth, bgHeight+2, COL_BACKGROUND);

	//Draw branding
	renderer->DrawString("Lunity", Vector2<float>(floor(TabUIVars::tabUiPosX)+1, 5), COL_BRAND, BRAND_SCALE);

	renderMgr(renderer, (Manager<ManagedItem>*)ModuleMgr::getInstance(), Vector2<float>(TabUIVars::tabUiPosX, yOffGeo), yOff, TabUIVars::selectedCatBgX);

	if(TabUIVars::chosenCategory != nullptr) {
		float categoryWidth = brandWidth;
		float categoryHeight = 0.0f;
		for(auto category : *TabUIVars::chosenCategory->getItems()) {
			std::string catName = category->getName();
			float catWidth = renderer->MeasureText(catName, CATEGORY_SCALE);
			if(catWidth > categoryWidth) {
				categoryWidth = catWidth;
			}
			categoryHeight += CATEGORY_SCALE * TEXT_HEIGHT;
		}
		renderer->Fill(TabUIVars::tabUiPosX+brandWidth, yOffGeo, categoryWidth, categoryHeight, COL_BACKGROUND);
		renderMgr(renderer, (Manager<ManagedItem>*)TabUIVars::chosenCategory, Vector2<float>(TabUIVars::tabUiPosX+brandWidth, yOffGeo), yOff, categoryWidth);
	}


	/*
	int currentCategory = 0;
	for(auto category : *allCategories) {
		std::string catText = category->getName();
		bool isSelected = TabUIVars::selectedCategory == currentCategory;
		bool isChosen = TabUIVars::chosenCategory == category;
		Vector2<float> catTextLoc = Vector2<float>(
			(isSelected ? floor(TabUIVars::selectedCatX) : 0) + (floor(TabUIVars::tabUiPosX)+1), //Push to the right selectedCatX if the selected category is this one. 
																	//selectedCatX is floored because text doesnt render properly on decimals for some reason.
			yOff + (currentCategory*(CATEGORY_SCALE * DRAWN_TEXT_HEIGHT)) //Multiply the category scale with text height, then multiply that by the current category and add the offset
		);

		if(isSelected) {
			renderer->Fill(TabUIVars::tabUiPosX, yOffGeo+(currentCategory*(CATEGORY_SCALE * TEXT_HEIGHT)), TabUIVars::selectedCatBgX, TEXT_HEIGHT, COL_SELECTION);
		}
		if(isChosen) {
			renderer->Fill(TabUIVars::tabUiPosX, yOffGeo+(currentCategory*(CATEGORY_SCALE * TEXT_HEIGHT)), TabUIVars::selectedCatBgX, TEXT_HEIGHT, COL_CHOSEN);
		}
		renderer->DrawString(catText, catTextLoc, isSelected ? COL_CAT_SELECT : COL_CAT, CATEGORY_SCALE);

		currentCategory++;
	}
	*/


	//If the selected cat x offset is less than 10, add to it based on time.
	if(TabUIVars::selectedCatX < 10.0f) {
		TabUIVars::selectedCatX += delta * ANIM_SPEED;
	} else {
		TabUIVars::selectedCatX = 10.0f;
	}
	if(TabUIVars::selectedCatBgX < brandWidth) {
		TabUIVars::selectedCatBgX += delta * (ANIM_SPEED*6);
	} else {
		TabUIVars::selectedCatBgX = brandWidth;
	}
	if(ModuleMgr::getInstance()->findModule("TabUI")->isEnabled()) {
		if(TabUIVars::tabUiPosX < 10) {
			TabUIVars::tabUiPosX += delta * (ANIM_SPEED*8);
		} else {
			TabUIVars::tabUiPosX = 10;
		}
	} else {
		if(TabUIVars::tabUiPosX > -100) {
			TabUIVars::tabUiPosX -= delta * (ANIM_SPEED*8);
		} else {
			TabUIVars::tabUiPosX = -100;
		}
	}
}



void onKey(EventData* event) {
	auto allCategories = ModuleMgr::getInstance()->getItems();
	int key = event->as<KeyPressEvent>()->GetKey();
	KeyAction action = event->as<KeyPressEvent>()->GetAction();

	if(action == KeyAction::PRESSED) {
		switch(key) {
			case VK_RIGHT:
				if(TabUIVars::chosenCategory == nullptr) {
					TabUIVars::chosenCategory = allCategories->at(TabUIVars::highlightedIndex);
					TabUIVars::highlightedIndex = 0;
				}
				else if(TabUIVars::highlightedModule != nullptr) {
					TabUIVars::highlightedModule = TabUIVars::chosenCategory->getItems()->at(TabUIVars::highlightedIndex);
				}
				break;
			case VK_LEFT:
				TabUIVars::chosenCategory = nullptr;
				break;
			case VK_DOWN:
				TabUIVars::highlightedIndex++;
				if(TabUIVars::chosenCategory == nullptr) {
					TabUIVars::resetAnim();
				}
				break;
			case VK_UP:
				TabUIVars::highlightedIndex--;
				if(TabUIVars::chosenCategory == nullptr) {
					TabUIVars::resetAnim();
				}
				break;
			case VK_TAB:
				ModuleMgr::getInstance()->findModule("TabUI")->toggle();
				break;
		}
	}

	if(TabUIVars::highlightedIndex < 0) {
		TabUIVars::highlightedIndex = allCategories->size()-1;
	}
	if(TabUIVars::highlightedIndex >= allCategories->size()) {
		TabUIVars::highlightedIndex = 0;
	}
	TabUIVars::highlightedCategory = allCategories->at(TabUIVars::highlightedIndex);
}

TabUI::TabUI() : Module("TabUI") {
	this->onEnable();
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, onRender);
	EventHandler::GetInstance()->ListenFor(EVENT_ID::KEYPRESS_EVENT, onKey);
}

void TabUI::onEnable() {
	//Enable code
}

void TabUI::onDisable() {
	//Disable code
}