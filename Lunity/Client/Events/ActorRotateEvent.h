#ifndef LUNITY_CLIENT_EVENTS_ACTORROTATEEVENT
#define LUNITY_CLIENT_EVENTS_ACTORROTATEEVENT

#include "Event.h"
#include "Cancellable.h"
#include "../Bridge/Actor.h"

class ActorRotateEvent : public Event, public Cancellable {
	Actor* actor;
	Vector2<float> rotation;
public:
	ActorRotateEvent(Actor* actor, Vector2<float> rotation) : Event() {
		this->actor = actor;
	};

	auto GetActor() -> Actor* {
		return this->actor;
	}

	auto GetRotation() -> Vector2<float> {
		return this->rotation;
	}
	void SetRotation(Vector2<float> rotation) {
		this->rotation = rotation;
	}

	auto GetYaw() -> float {
		return this->rotation.x;
	}
	void SetYaw(float yaw) {
		this->rotation.x = yaw;
	}

	auto GetPitch() -> float {
		return this->rotation.x;
	}
	void SetPitch(float pitch) {
		this->rotation.y = pitch;
	}
};

#endif /* LUNITY_CLIENT_EVENTS_ACTORROTATEEVENT */
