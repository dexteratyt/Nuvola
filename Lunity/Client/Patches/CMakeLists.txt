target_sources(Lunity PRIVATE
	"IPatch.cpp"
	"PatchManager.cpp"
)
add_subdirectory(ClientInstance)
add_subdirectory(Dx11)
add_subdirectory(Actor)
add_subdirectory(LocalPlayer)
add_subdirectory(ScreenView)
