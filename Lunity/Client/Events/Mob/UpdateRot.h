#ifndef LUNITY_CLIENT_EVENTS_MOB_UPDATEROT
#define LUNITY_CLIENT_EVENTS_MOB_UPDATEROT

#include "../EventData.h"
#include "../Cancellable.h"
#include "../../Bridge/Mob.h"

class UpdateRot : public EventData, public Cancellable {
	Mob* mob;
	Vector2<float>* vector;
public:
	UpdateRot(Mob* mob, Vector2<float>* vector) : EventData() {
		this->mob = mob;
		this->vector = vector;
	};

	auto GetMob() -> Mob* {
		return this->mob;
	}
	auto GetNewVector() -> Vector2<float>* {
		return this->vector;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_MOB_UPDATEROT */
