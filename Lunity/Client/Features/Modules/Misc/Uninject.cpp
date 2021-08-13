#include "Uninject.h"
#include "../../../Patches/PatchManager.h"

Uninject::Uninject() : Module("Uninject") {};

void Uninject::OnEnable() {
	//Uninject here

	//Clean up hooks
	PatchManager::RemoveAll();

	//Sleep for 1 second to ensure the hooks are
	//safely removed before we kill our own code
	//Sleep(1000);

	//Free library
	FreeLibraryAndExitThread(Mem::GetThisModule(), 0);
};

void Uninject::OnDisable() {
	//This code is unreachable
	//The library and its memory would have been
	//freed and execution would have stopped.
}