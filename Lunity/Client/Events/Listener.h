#ifndef LUNITY_CLIENT_EVENTS_LISTENER
#define LUNITY_CLIENT_EVENTS_LISTENER

#include "Event.h"
#include "KeyPressEvent.h"
#include "MouseEvent.h"
#include "PlayerTickEvent.h"
#include "RenderEvent.h"
#include "ActorRotateEvent.h"

class Listener {
public:
	virtual void onEvent(Event& event) {};
	virtual void onKeyEvent(KeyPressEvent& event) {};
	virtual void onMouseEvent(MouseEvent& event) {};
	virtual void onPlayerTickEvent(PlayerTickEvent& event) {};
	virtual void onRenderEvent(RenderEvent& event) {};
	virtual void onActorRotateEvent(ActorRotateEvent& event) {};
};

#endif /* LUNITY_CLIENT_EVENTS_LISTENER */
