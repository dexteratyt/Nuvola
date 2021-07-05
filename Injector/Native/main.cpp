#include <Windows.h>
#include <tlhelp32.h>
#include <string>
#include <codecvt>
#include <iostream>

using namespace std;



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
	cout << "ProcID: " << procId << endl;
	HANDLE procHandle = OpenProcess(0x1F0FFF, true, procId);
	return procHandle;
}
auto openProc(string procName) -> void* {
	return openProc(procIdFromName(procName));
}


auto injectDll(string procName, string dllPath) -> int {

	size_t* bytesout = new size_t();

	//Open the process safely
	void* procHandle = openProc(procName);
	if(procHandle == nullptr) {
		procHandle = openProc(procName+".exe");
	}
	if(procHandle == nullptr) {
		cout << "Failed to find process: \"" << procName << "\"" << endl;
		return -1;
	}

	int lenWrite = procName.length() + 1;
    void* allocMem = VirtualAllocEx(procHandle, nullptr, lenWrite, 0x00001000 | 0x00002000, 0x04);

	const char* strBuffer = procName.c_str();
	WriteProcessMemory(procHandle, allocMem, strBuffer, lenWrite, bytesout);
	HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    FARPROC injector = GetProcAddress(kernel32, "LoadLibraryA");

	if (injector == nullptr) {
        return -1;
	}

	void* hThread = CreateRemoteThread(procHandle, nullptr, 0, (LPTHREAD_START_ROUTINE)injector, allocMem, 0, (LPDWORD)bytesout);
	if(hThread == nullptr) {
		return -1;
	}

	int result = WaitForSingleObject(hThread, 10 * 1000);
	if (result == 0x00000080L || result == 0x00000102L) {
		if (hThread != nullptr) {
			CloseHandle(hThread);
		}
		return 0;
	}
	VirtualFreeEx(procHandle, allocMem, 0, 0x8000);

	if (hThread != nullptr) {
		CloseHandle(hThread);
	}

	return 0;
}

enum class ArgState {
	NONE,
	INJECT,
	UNINJECT,
	PROCNAME
};
enum class Task {
	INJECT,
	UNINJECT
};

auto main(int argc, char** argv) -> int {
	auto currentState = ArgState::NONE;

	string procName = "";
	string moduleName = ""; //Doubles as module path for injecton
	Task task; //What we need to do

	//Parse the params
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
			if(argStr == "-n") {
				currentState = ArgState::PROCNAME;
			}
			continue;
		}
		//Specify the process name
		if(currentState == ArgState::PROCNAME) {
			procName = argStr;
		}
		//If there is a Inject state, we are expecting a file name to inject.
		if(currentState == ArgState::INJECT || currentState == ArgState::UNINJECT) {
			moduleName = argStr;
		}
		if(currentState == ArgState::INJECT) {
			task = Task::INJECT;
		}
		//If there is an Uninject state, we want the module to uninject
		if(currentState == ArgState::UNINJECT) {
			task = Task::UNINJECT;
		}
		currentState = ArgState::NONE;
	}

	//We parsed the args, time to inject
	if(task == Task::INJECT) {
		injectDll(procName, moduleName);
	}
	if(task == Task::UNINJECT) {
		//TODO: Uninject
	}

	return 0;
};