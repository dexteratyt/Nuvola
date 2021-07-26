#include "Utils.h"

void Utils::DebugF(const char* out) {
    std::string fPath = std::string("Lunity_Output.txt");
	std::string dirP = getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\" + std::string(fPath));

	CloseHandle(CreateFileA(dirP.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

	std::ofstream fileOutput;
	fileOutput.open(dirP.c_str(), std::ios_base::app);
	fileOutput << out << std::endl;
	fileOutput.close();
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