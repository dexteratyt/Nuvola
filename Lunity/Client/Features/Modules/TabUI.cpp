#include "TabUI.h"
#include "../../Events/Renderer/UIRenderEvent.h"
#include "../../Events/Global/KeyPressEvent.h"
#include "../ModuleMgr.h"

float currentX = 0.0f;
void onRender(EventData* event) {
	MinecraftRenderer* renderer = event->as<UIRenderEvent>()->GetRenderWrapper();

	float delta = renderer->GetDeltaTime();
	if(delta > .0001) {
		renderer->DrawString(std::string("DeltaTime: ")+std::to_string(delta), Vector2<float>(10, 10));
		renderer->DrawString(std::string("FPS: ") + std::to_string(1000/(delta*1000)), Vector2<float>(10, 20));
	}
	
	renderer->Fill(currentX, 0, 10, 10, Color());

	currentX += delta*50;
	if(currentX > 1000) {
		currentX = 0;
	}



/*
	auto allCategories = ModuleMgr::getInstance()->getItems();
	for(auto category : *allCategories) {

	}
*/
}

void onKey(EventData* event) {
	
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