#ifndef NUVOLA_CLIENT_EVENTS_ACTORROTATEEVENT
#define NUVOLA_CLIENT_EVENTS_ACTORROTATEEVENT

#include "ActorEvent.h"
#include "Cancellable.h"
#include "../Bridge/Actor.h"

enum class RotationType {
	HEAD,
	CORPSE
};

class ActorRotateEvent : public ActorEvent, public Cancellable {
	Actor* actor;
	Vector2<float>* rotation;
	RotationType rotationType;
public:
	ActorRotateEvent(Actor* actor, Vector2<float>* rotation, RotationType rotationType) : ActorEvent(actor) {
		this->rotation = rotation;
		this->rotationType = rotationType;
	};

	auto GetRotationType() -> RotationType {
		return this->rotationType;
	}

	auto GetRotation() -> Vector2<float> {
		return *this->rotation;
	}
	void SetRotation(Vector2<float> rotation) {
		*this->rotation = rotation;
	}

	auto GetYaw() -> float {
		return this->rotation->x;
	}
	void SetYaw(float yaw) {
		this->rotation->x = yaw;
	}

	auto GetPitch() -> float {
		return this->rotation->x;
	}
	void SetPitch(float pitch) {
		this->rotation->y = pitch;
	}
};

#endif /* NUVOLA_CLIENT_EVENTS_ACTORROTATEEVENT */
