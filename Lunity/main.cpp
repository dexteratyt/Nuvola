#include "Client/Client.h"

void init(LPVOID lpParam){
    Client* client = new Client("Lunity");
}

extern "C" __declspec(dllexport) bool __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    switch(fdwReason) {
        case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hinstDLL, 0, 0);
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}