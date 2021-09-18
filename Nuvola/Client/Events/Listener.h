#ifndef NUVOLA_CLIENT_EVENTS_LISTENER
#define NUVOLA_CLIENT_EVENTS_LISTENER

#include "PacketListener.h"

#include "Event.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include "NormalTickEvent.h"
#include "PlayerTickEvent.h"
#include "RenderEvent.h"
#include "ActorRotateEvent.h"
#include "ChatEvent.h"
#include "MobSwingEvent.h"

class Listener : public PacketListener {
public:
	virtual void onEvent(Event& event) {};
	virtual void onKeyEvent(KeyEvent& event) {};
	virtual void onMouseEvent(MouseEvent& event) {};
	virtual void onNormalTickEvent(NormalTickEvent& event) {};
	virtual void onPlayerTickWorldEvent(PlayerTickEvent& event) {};
	virtual void onRenderEvent(RenderEvent& event) {};
	virtual void onActorRotateEvent(ActorRotateEvent& event) {};
	virtual void onChatEvent(ChatEvent& event) {};
	virtual void onMobSwingEvent(MobSwingEvent& event) {};
};

#endif /* NUVOLA_CLIENT_EVENTS_LISTENER */
