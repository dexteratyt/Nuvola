#include "TabUI.h"
#include "../../Events/Renderer/UIRenderEvent.h"
#include "../../Events/Global/KeyPressEvent.h"

void onRender(EventData* event) {
	MinecraftRenderer* renderer = event->as<UIRenderEvent>()->GetRenderWrapper();
	if(lastKey)
		renderer->DrawString(std::to_string(*lastKeyPtr), Vector2<float>(10, 10));
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