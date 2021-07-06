#include "Client/Client.h"
#include <thread>

void init() {
    Client* client = new Client("Lunity");
}

auto __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) -> bool {
	if(fdwReason == DLL_PROCESS_ATTACH) {
		std::thread(init).detach();
	}
    return true;  // Successful DLL_PROCESS_ATTACH
}