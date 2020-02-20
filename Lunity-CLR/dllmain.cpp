// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <metahost.h>
#pragma comment(lib, "mscoree.lib")
#include <fstream>

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}
DWORD getAddress(DWORD baseAddress, DWORD offsets[], int offsetCount)
{
    DWORD address; // Where the final address will be stored
    address = *(DWORD*)(baseAddress); // Add the base address to the modules base address.

    // Loop through each offset
    for (int i = 0; i < offsetCount; i++) {
        address = *(DWORD*)(address + offsets[i]);
    }

    return address;
}
DWORD WINAPI startClr(LPVOID lpParam)
{
	ICLRMetaHost* metaHost = NULL; //Declare our CLR Meta Host value as a NULL
	ICLRRuntimeInfo* runtimeInfo = NULL; //Declare our CLR Runtime Info as a Null
	ICLRRuntimeHost* runtimeHost = NULL; //Delcare our CLR HOST as a NULL

    if (CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&metaHost) == S_OK)
    {
        if (metaHost->GetRuntime(L"v4.0.X", IID_ICLRRuntimeInfo, (LPVOID*)&runtimeInfo) == S_OK) //If getting Runtime version is successful
        {
            if (runtimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&runtimeHost) == S_OK) //If getting the interface with the follow parameters is successful
            {
                if (runtimeHost->Start() == S_OK) //Start the CLR (If it is successful)
                {
                    DWORD pReturnValue; //Declare our return value as a DWORD

                    //Invoke our method through CLR host using following parameters
                    std::string lunityPath = std::string(getenv("APPDATA")).c_str() + std::string("\\Lunity\\Lunity-Injectable.dll");
                    *(std::string*)(0x7FF668C41C3C) = lunityPath;
                    runtimeHost->ExecuteInDefaultAppDomain(s2ws(lunityPath).c_str(), L"Lunity_Injectable.EntryClass", L"Main", L"Hello!", &pReturnValue);
                    *(DWORD*)(0x7FF668C41C64) = pReturnValue;
                }
                else {
                    *(std::string*)(0x7FF668C41C64) = "Error starting runtime host!";
                }
            }
            else {
                *(std::string*)(0x7FF668C41C64) = "Error getting interface!";
            }
        }
        else {
            *(std::string*)(0x7FF668C41C64) = "Error getting runtime!";
        }
    }
    else {
        *(std::string*)(0x7FF668C41C64) = "Error creating instance!";
    }
	return 0;
}

BOOL __stdcall DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)startClr, hModule, NULL, NULL);
        DisableThreadLibraryCalls(hModule);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

