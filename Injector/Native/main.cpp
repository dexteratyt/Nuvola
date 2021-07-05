#include <Windows.h>
#include <tlhelp32.h>
#include <string>
#include <codecvt>
#include <iostream>

using namespace std;

enum class ArgState {
	NONE,
	INJECT,
	UNINJECT
};

auto getProcId(const char* ProcName) -> int {
	PROCESSENTRY32 pe32;
	HANDLE hSnapshot = nullptr;

	pe32.dwSize = sizeof(PROCESSENTRY32);
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if(Process32First(hSnapshot, &pe32)) {
		do {
			//Goo goo ga ga wstring to string bad waaa
			//Bitch idgaf suck my balls
			using convert_type = std::codecvt_utf8<wchar_t>;
			std::wstring_convert<convert_type, wchar_t> converter;
			wstring wideName((WCHAR*)pe32.szExeFile);
			string thinName = converter.to_bytes(wideName);
			if(strcmp(thinName.c_str(), ProcName) == 0) {
				break;
			}
		}
		while(Process32Next(hSnapshot, &pe32));
	}

	if( hSnapshot != INVALID_HANDLE_VALUE )
		CloseHandle( hSnapshot );

	return pe32.th32ProcessID;
}

auto procIdFromName(string procName) -> int {
	return getProcId(procName.c_str());
}

auto openProc(int procId) -> void* {
	HANDLE procHandle = OpenProcess(0x1F0FFF, true, procId);
	return procHandle;
}
auto openProc(string procName) -> void* {
	return openProc(procIdFromName(procName));
}


auto injectDll() -> int {
	return 0;
}

auto main(int argc, char** argv) -> int {
	auto currentState = ArgState::NONE;
	for(int i = 0; i < argc; i++) {
		string argStr = string(argv[i]);
		//If theres no state, we are expecting one. If one isnt provided, keep going until one is.
		if(currentState == ArgState::NONE) {
			if(argStr == "-i") {
				currentState = ArgState::INJECT;
			}
			if(argStr == "-u") {
				currentState = ArgState::UNINJECT;
			}
		}
		//If there is a Inject state, we are expecting a file name to inject.
		if(currentState == ArgState::INJECT) {
			string path = argStr;
			//TODO: Inject dll
			cout << "Injecting dll at " << path << endl;
		}
		//If there is an Uninject state, we want the module to uninject
		if(currentState == ArgState::UNINJECT) {
			string moduleName = argStr;
			//TODO: Uninject dll
			cout << "Uninjecting module named " << moduleName << endl;
		}
		currentState = ArgState::NONE;
	}
	return 0;
};