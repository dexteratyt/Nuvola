#ifndef NUVOLA_CLIENT_EVENTS_RENDEREVENT
#define NUVOLA_CLIENT_EVENTS_RENDEREVENT

#include "Event.h"
#include "../Bridge/MinecraftUIRenderContext.h"
#include "../../Render/RenderContext/MinecraftRenderer.h"

class RenderEvent : public Event {
	MinecraftUIRenderContext* renderContext;
	MinecraftRenderer* renderWrapper;
public:
	RenderEvent(MinecraftUIRenderContext* renderContext, MinecraftRenderer* renderWrapper) : Event() {
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

#endif /* NUVOLA_CLIENT_EVENTS_RENDEREVENT */
