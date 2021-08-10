#include "TabUI.h"
#include "../../Events/Renderer/UIRenderEvent.h"
#include "../../Events/Global/KeyPressEvent.h"
#include "../ModuleMgr.h"
#include <Windows.h>

//#define ANIM_TIMING_DISPLAY
#ifdef ANIM_TIMING_DISPLAY
float currentX = 0.0f;
#endif

//I made a namespace here because I don't want to deal with conflicting names in the future
namespace TabUIVars {
	int selectedCategory = 0;
	float selectedCatX = 0; //X offset for the selected cat. This is for the animation.

	void resetAnim() {
		TabUIVars::selectedCatX = 0.0f;
	}
}

void onRender(EventData* event) {
	MinecraftRenderer* renderer = event->as<UIRenderEvent>()->GetRenderWrapper();
	float delta = renderer->GetDeltaTime();

/* Animation timing testing (Ignore! this part is not compiled without the macro definition!) */
#ifdef ANIM_TIMING_DISPLAY
	if(delta > .0001) {
		renderer->DrawString(std::string("DeltaTime: ")+std::to_string(delta), Vector2<float>(10, 10));
		renderer->DrawString(std::string("FPS: ") + std::to_string(1000/(delta*1000)), Vector2<float>(10, 20));
	}
	
	renderer->Fill(currentX, 0, 10, 10, Color());

	currentX += delta*50;
	if(currentX > 1000) {
		currentX = 0;
	}
#endif

/* Tab GUI */
#define BRAND_SCALE 2
#define CATEGORY_SCALE 1
#define ANIM_SPEED 70
	auto allCategories = ModuleMgr::getInstance()->getItems();
	float yOff = (BRAND_SCALE * TEXT_HEIGHT)+5;

	//Draw background
	float brandWidth = renderer->MeasureText("Lunity", BRAND_SCALE);
	float bgHeight = yOff + (allCategories->size() * (CATEGORY_SCALE * TEXT_HEIGHT)) + (BRAND_SCALE * TEXT_HEIGHT); //You can figure out this math for yourself
	renderer->Fill(9, 10, brandWidth, bgHeight+2, Color(1,1,1,.5));

	//Draw branding
	renderer->DrawString("Lunity", Vector2<float>(10, 5), Color(0,0,0), BRAND_SCALE);


	int currentCategory = 0;
	for(auto category : *allCategories) {
		std::string catText = category->getName();
		Vector2<float> catTextLoc = Vector2<float>(
			(TabUIVars::selectedCategory == currentCategory ? floor(TabUIVars::selectedCatX) : 0) + 10, //Push to the right selectedCatX if the selected category is this one. 
																										//selectedCatX is floored because text doesnt render properly on decimals for some reason.
			yOff + (currentCategory*(CATEGORY_SCALE * TEXT_HEIGHT)) //Multiply the category scale with text height, then multiply that by the current category and add the offset
		);

		renderer->DrawString(catText, catTextLoc, Color(0,0,0), CATEGORY_SCALE);

		currentCategory++;
	}

	//If the selected cat x offset is less than 10, add to it based on time.
	if(TabUIVars::selectedCatX < 10.0f) {
		TabUIVars::selectedCatX += delta * ANIM_SPEED;
	} else {
		TabUIVars::selectedCatX = 10.0f;
	}
}



void onKey(EventData* event) {
	int key = event->as<KeyPressEvent>()->GetKey();
	KeyAction action = event->as<KeyPressEvent>()->GetAction();

	if(action == KeyAction::PRESSED) {
		switch(key) {
			case VK_DOWN:
				TabUIVars::selectedCategory++;
				TabUIVars::resetAnim();
				break;
			case VK_UP:
				TabUIVars::selectedCategory--;
				TabUIVars::resetAnim();
				break;
		}
	}
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