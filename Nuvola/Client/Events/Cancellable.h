#ifndef NUVOLA_CLIENT_EVENTS_CANCELLABLE
#define NUVOLA_CLIENT_EVENTS_CANCELLABLE

class Cancellable {
	bool cancelled;
public:
	Cancellable() {
		this->cancelled = false;
	}

	auto IsCancelled() -> bool {
		return this->cancelled;
	}
	void SetCancelled(bool cancelled) {
		this->cancelled = cancelled;
	}
	void Cancel() {
		this->cancelled = true;
	}
};

#endif /* NUVOLA_CLIENT_EVENTS_CANCELLABLE */
