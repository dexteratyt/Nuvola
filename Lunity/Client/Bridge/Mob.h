#ifndef LUNITY_CLIENT_BRIDGE_MOB
#define LUNITY_CLIENT_BRIDGE_MOB
#include "Actor.h"

#include "../../Utils/Math.h"

struct Mob : Actor {
    Mob() : Actor("Mob") {};
    Mob(std::string structName) : Actor(structName) {
        this->AddVirtual(new DynamicMethod("getYHeadRot", 221)); // getYHeadRot should be exempt from naming conventions as it is the internal name from Minecraft
        this->AddField(new DynamicField("YHeadRot", 0x728));
    };

	auto GetYHeadRot() -> float {
        DynamicMethod* getRotFunc = (DynamicMethod*)this->Get("getYHeadRot");
        float(__fastcall* theFn)(uintptr_t) = (float(__fastcall*)(uintptr_t))getRotFunc->AsVoid();
        return theFn(this->GetAddress());
    }

	void SetYHeadRot(float newVal) {
		DynamicField* theField = (DynamicField*)this->Get("YHeadRot");
		float* theVal = (float*)theField->AsVoid();
		*theVal = newVal;
	}
};

#endif /* LUNITY_CLIENT_BRIDGE_MOB */
