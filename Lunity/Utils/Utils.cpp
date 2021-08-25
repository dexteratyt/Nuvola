#include "Utils.h"
#include <iostream>

//#define LOG_FILE
#define LOG_CONSOLE

void Utils::DebugF(const char* out) {
#ifdef LOG_CONSOLE
	std::cout << out << std::endl;
#endif

#ifdef LOG_FILE
    std::string fPath = std::string("Lunity_Output.txt");
	std::string dirP = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + std::string(fPath));

	CloseHandle(CreateFileA(dirP.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

	std::ofstream fileOutput;
	fileOutput.open(dirP.c_str(), std::ios_base::app);
	fileOutput << out << std::endl;
	fileOutput.close();
#endif
};

void Utils::DebugF(std::string out) {
    DebugF(out.c_str());
}

void Utils::SetClientInstance(uintptr_t address) {
	clientInstance = (ClientInstance*)address;
}
auto Utils::GetClientInstance() -> ClientInstance* {
	return clientInstance;
}

uintptr_t uiMatPtr = 0;
auto Utils::GetUIMaterialPtr() -> class MaterialPtr* {
	if(uiMatPtr != 0) {
		return (MaterialPtr*)uiMatPtr;
	}
	uintptr_t fillAddr = 0;
	if(fillAddr == 0) {
		fillAddr = Mem::FindSig("89 ?? ?? ?? 57 48 83 ?? ?? 48 ?? ?? ?? 45 33 ?? 48 ?? ?? ?? ?? ?? ?? ?? 48 8B ?? ?? 29");
	}
	if(fillAddr == 0) {
		Utils::DebugF("UI Mat sig failure!");
	}
	fillAddr-=1;
	int* uiMatOffset = (int*)(fillAddr + 0x9F + 3);
	uintptr_t baseInstruction = (uintptr_t)uiMatOffset;
	uiMatPtr = ((baseInstruction+7)+(*uiMatOffset))-3;
	return (MaterialPtr*)uiMatPtr;
}