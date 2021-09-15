#ifndef LUNITY_CLIENT_FEATURES_ISETTING
#define LUNITY_CLIENT_FEATURES_ISETTING

class ISetting {
public:
	virtual void* getValue() {
		return nullptr;
	}
};

#endif /* LUNITY_CLIENT_FEATURES_ISETTING */
