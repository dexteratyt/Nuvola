#ifndef LUNITY_CLIENT_PATCHES_CLIENTINSTANCESCREENMODEL_SENDCHATMESSAGE
#define LUNITY_CLIENT_PATCHES_CLIENTINSTANCESCREENMODEL_SENDCHATMESSAGE

#include "../IPatch.h"
#include "../../../Utils/Utils.h"
#include "../../Features/ModuleMgr.h"

class SendChatMessageHook : public IPatch {
	static void clientInstanceCallback_1_17_11_1(class ClientInstanceScreenModel* screenModel, std::string* text);
public:
	static inline uintptr_t funcOriginal = 0;
	SendChatMessageHook();
	auto Apply() -> bool override;
};

#endif /* LUNITY_CLIENT_PATCHES_CLIENTINSTANCESCREENMODEL_SENDCHATMESSAGE */
