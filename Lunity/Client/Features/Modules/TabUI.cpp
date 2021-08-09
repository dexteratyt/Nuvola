#include "TabUI.h"
#include "../../Events/Renderer/UIRenderEvent.h"

TabUI::TabUI() : Module("TabUI") {
	this->onEnable();
}

void onRender(EventData* event) {
	MinecraftRenderer* renderer = event->as<UIRenderEvent>()->GetRenderWrapper();
	renderer->DrawString("Lunity", Vector2<float>(10, 10));
}

void TabUI::onEnable() {
	//Enable code
	EventHandler::GetInstance()->ListenFor(EVENT_ID::RENDER_EVENT, onRender);
}

void TabUI::onDisable() {
	//Disable code
}