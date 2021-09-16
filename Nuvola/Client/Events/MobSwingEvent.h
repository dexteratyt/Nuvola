#ifndef NUVOLA_CLIENT_EVENTS_MOBSWINGEVENT
#define NUVOLA_CLIENT_EVENTS_MOBSWINGEVENT

#include "MobEvent.h"
#include "Cancellable.h"

class MobSwingEvent : public MobEvent, public Cancellable {
public:
	MobSwingEvent(Mob* mob) : MobEvent(mob), Cancellable() {}
};

#endif /* NUVOLA_CLIENT_EVENTS_MOBSWINGEVENT */
