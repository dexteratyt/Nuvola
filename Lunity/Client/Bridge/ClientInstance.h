#ifndef LUNITY_CLIENT_BRIDGE_CLIENTINSTANCE
#define LUNITY_CLIENT_BRIDGE_CLIENTINSTANCE
#include "DynamicStruct.h"
#include "Actor.h"
//#include "GuiData.h"
#include "../../Utils/VersionUtils.h"

struct ClientInstance {

	DYN_FIELD(LocalPlayer, 0x140, Actor*);

/*
    ClientInstance(uintptr_t address) : DynamicStruct("ClientInstance", 0) {
        this->SetAddress(address);
		this->AddField("LocalPlayer", 0x140);
        // this->AddVirtual(new DynamicMethod("GetLocalPlayer", 25));
        // this->AddVirtual(new DynamicMethod("GetGuiData", 198));
    };

    auto GetLocalPlayer() -> LocalPlayer {
        LocalPlayer lp;
		lp.SetAddress(this->GetField("LocalPlayer"));
        return lp;
    }
*/
    // auto GetGuiData() -> GuiData* {
    //     DynamicMethod* getGD = (DynamicMethod*)this->Get("GetGuiData");
    //     uintptr_t(__fastcall** theFn)(uintptr_t) = (uintptr_t(__fastcall**)(uintptr_t))getGD->AsVoid();
    //     if(!guiData)
    //         guiData = new GuiData();
    //     guiData->SetAddress((*theFn)(this->GetAddress()));
    //     return guiData;
    // }
};

#endif /* LUNITY_CLIENT_BRIDGE_CLIENTINSTANCE */
