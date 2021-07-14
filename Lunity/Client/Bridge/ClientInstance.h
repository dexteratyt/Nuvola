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
        this->SetAddress(address);
        this->AddVirtual(new DynamicMethod("GetLocalPlayer", 25));
        this->AddVirtual(new DynamicMethod("GetGuiData", 198));
    };

    auto GetLocalPlayer() -> LocalPlayer* {
        DynamicMethod* getLP = (DynamicMethod*)this->Get("GetLocalPlayer");
        uintptr_t(__fastcall** theFn)(uintptr_t) = (uintptr_t(__fastcall**)(uintptr_t))getLP->AsVoid();
        if(!localPlayer)
            localPlayer = new LocalPlayer();
        localPlayer->SetAddress((*theFn)(this->GetAddress()));
        return localPlayer;
    }
    auto GetGuiData() -> GuiData* {
        DynamicMethod* getGD = (DynamicMethod*)this->Get("GetGuiData");
        uintptr_t(__fastcall** theFn)(uintptr_t) = (uintptr_t(__fastcall**)(uintptr_t))getGD->AsVoid();
        if(!guiData)
            guiData = new GuiData();
        guiData->SetAddress((*theFn)(this->GetAddress()));
        return guiData;
    }
};

#endif /* LUNITY_CLIENT_BRIDGE_CLIENTINSTANCE */
