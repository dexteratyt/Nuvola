#include "ModList.h"

#include "../../ModuleMgr.h"

#include "../../../Events/EventHandler.h"

#include "../../../Bridge/GuiData.h"

ModList::ModList() : Module("ModList") {

}

void ModList::onRenderEvent(RenderEvent& event) {
	//Get the wrapper & vars we need
	MinecraftRenderer* wrapper = event.GetRenderWrapper();
	GuiData* data = event.GetRenderContext()->clientInstance->guiData;
	Vector2<float> scaledRes = data->scaledResolution;
	
	//Loop all mods
	int i = 0;
	for(auto mod : *ModuleMgr::getInstance()->getAllModules()) {
		//Check if theyre enabled
		if(mod->IsEnabled()) {
			//Render it if its enabled
			//TODO: Super fancy animations
			std::string name = mod->getName();
			float width = wrapper->MeasureText(name);

			wrapper->DrawString(name, Vector2<float>(scaledRes.x - width, i*12));
			i++;
		}
	}
}

void ModList::OnEnable() {
	EventHandler::registerListener(this);
}
void ModList::OnDisable() {
	EventHandler::unregisterListener(this);
}