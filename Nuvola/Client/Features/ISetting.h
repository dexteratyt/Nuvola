#ifndef NUVOLA_CLIENT_FEATURES_ISETTING
#define NUVOLA_CLIENT_FEATURES_ISETTING

class ISetting {
public:
	virtual void* getValue() {
		return nullptr;
	}
};

#endif /* NUVOLA_CLIENT_FEATURES_ISETTING */
