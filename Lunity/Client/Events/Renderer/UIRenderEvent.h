#ifndef LUNITY_CLIENT_EVENTS_RENDERER_UIRENDEREVENT
#define LUNITY_CLIENT_EVENTS_RENDERER_UIRENDEREVENT

#include "../EventData.h"
#include "../../Bridge/MinecraftUIRenderContext.h"
#include "../../../Utils/MinecraftRenderer.h"

class UIRenderEvent : public EventData {
	MinecraftUIRenderContext* renderContext;
	MinecraftRenderer* renderWrapper;
public:
	UIRenderEvent(MinecraftUIRenderContext* renderContext, MinecraftRenderer* renderWrapper) : EventData() {
		this->renderContext = renderContext;
		this->renderWrapper = renderWrapper;
	};

	auto GetRenderContext() -> MinecraftUIRenderContext* {
		return this->renderContext;
	}
	auto GetRenderWrapper() -> MinecraftRenderer* {
		return this->renderWrapper;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_RENDERER_UIRENDEREVENT */
