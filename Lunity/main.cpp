#include <httplib.h>
#include <iostream>
#include <Windows.h>
#include <string>

auto initialize() -> int {

	// HTTP server (no ssl)
	httplib::Server svr;

	svr.Get("/", [](const httplib::Request &, httplib::Response &res) {
		res.set_content("Hello World!", "text/plain");
	});

	svr.listen("localhost", 420);

	if (!svr.is_valid()) {
		return -1;
	}

    return 0;
}

extern "C" __declspec(dllexport) bool __stdcall DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
            initialize();
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}