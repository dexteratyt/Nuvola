#ifndef LUNITY_CLIENT_BRIDGE_CLIENTINSTANCE
#define LUNITY_CLIENT_BRIDGE_CLIENTINSTANCE
#include "DynamicStruct.h"
#include "LocalPlayer.h"
#include "GuiData.h"
#include "../../Utils/VersionUtils.h"

struct ClientInstance : DynamicStruct {
    GuiData* guiData = nullptr;
    LocalPlayer* localPlayer = nullptr;

    ClientInstance(uintptr_t address) : DynamicStruct("ClientInstance", 0) {
        this->setAddress(address);
        this->addVirtual(new DynamicMethod("getLocalPlayer", 25));
        this->addVirtual(new DynamicMethod("getGuiData", 198));
    };

    auto getLocalPlayer() -> LocalPlayer* {
        DynamicMethod* getLP = (DynamicMethod*)this->get("getLocalPlayer");
        uintptr_t(__fastcall** theFn)(uintptr_t) = (uintptr_t(__fastcall**)(uintptr_t))getLP->asVoid();
        if(!localPlayer)
            localPlayer = new LocalPlayer();
        localPlayer->setAddress((*theFn)(this->getAddress()));
        return localPlayer;
    }
    auto getGuiData() -> GuiData* {
        DynamicMethod* getGD = (DynamicMethod*)this->get("getGuiData");
        uintptr_t(__fastcall** theFn)(uintptr_t) = (uintptr_t(__fastcall**)(uintptr_t))getGD->asVoid();
        if(!guiData)
            guiData = new GuiData();
        guiData->setAddress((*theFn)(this->getAddress()));
        return guiData;
    }
};

#endif /* LUNITY_CLIENT_BRIDGE_CLIENTINSTANCE */
