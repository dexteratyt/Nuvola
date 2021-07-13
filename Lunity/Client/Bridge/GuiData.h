#ifndef LUNITY_CLIENT_BRIDGE_GUIDATA
#define LUNITY_CLIENT_BRIDGE_GUIDATA
#include "DynamicStruct.h"
#include "../../Utils/Math.h"

struct GuiData : DynamicStruct {
    GuiData() : DynamicStruct("GuiData", 0) {
        this->AddField(new DynamicField("Resolution", 0x18));
        this->AddField(new DynamicField("ScaledResolution", 0x28));
        this->AddField(new DynamicField("GuiSize", 0x30));
        this->AddField(new DynamicField("GuiScale", 0x38));
        this->AddField(new DynamicField("MouseX", 0x52));
        this->AddField(new DynamicField("MouseY", 0x54));
        this->AddField(new DynamicField("IsWorldLoaded", 0x56));
        this->AddField(new DynamicField("HeldItemSlot", 0x58));
        this->AddField(new DynamicField("HeldItemName", 0x94));
    };

    auto GetResolution() -> Vector2<float> {
        DynamicField* theField = (DynamicField*)this->Get("Resolution");
        Vector2<float>* theVec = (Vector2<float>*)theField->AsVoid();
        return *theVec;
    };
    auto GetScaledResolution() -> Vector2<float> {
        DynamicField* theField = (DynamicField*)this->Get("ScaledResolution");
        Vector2<float> theVec = *((Vector2<float>*)theField->AsVoid());
        return theVec;
    };
	auto GetGuiSize() -> double {
        DynamicField* theField = (DynamicField*)this->Get("GuiSize");
        double* theVal = (double*)theField->AsVoid();
        return *theVal;
    };
    auto GetGuiScale() -> float {
        DynamicField* theField = (DynamicField*)this->Get("GuiScale");
        float* theVal = (float*)theField->AsVoid();
        return *theVal;
    };
	auto GetMouseX() -> short {
		DynamicField* theField = (DynamicField*)this->Get("MouseX");
        short* theVal = (short*)theField->AsVoid();
        return *theVal;
	}
	auto GetMouseY() -> short {
		DynamicField* theField = (DynamicField*)this->Get("MouseY");
        short* theVal = (short*)theField->AsVoid();
        return *theVal;
	}
	auto GetMouseLoc() -> Vector2<short> {
		return Vector2<short>(this->GetMouseX(), this->GetMouseY());
	}
};

#endif /* LUNITY_CLIENT_BRIDGE_GUIDATA */
