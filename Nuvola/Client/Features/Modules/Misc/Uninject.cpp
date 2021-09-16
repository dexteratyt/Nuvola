#include "Uninject.h"
#include "../../../Patches/PatchManager.h"

Uninject::Uninject() : Module("Uninject") {};

void Uninject::OnEnable() {
	//Uninject here

#ifdef LOG_CONSOLE
	//Free console window if in use
	FreeConsole();
#endif
	
	//Clean up hooks
	PatchManager::RemoveAll();

	//Free library
	FreeLibraryAndExitThread(Mem::GetThisModule(), 0);

	//If this code is reach, uninjection failed!
	//We should re apply the patches and let the user know
	PatchManager::ApplyAll();

	//TODO: let user know uninjection failed!
};

void Uninject::OnDisable() {
	//This code is unreachable
	//The library and its memory would have been
	//freed and execution would have stopped.
}