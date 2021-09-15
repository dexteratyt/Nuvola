target_sources(Nuvola PRIVATE
	"IPatch.cpp"
	"PatchManager.cpp"
)
add_subdirectory(Actor)
add_subdirectory(ClientInstance)
add_subdirectory(ClientInstanceScreenModel)
add_subdirectory(Global)
add_subdirectory(LocalPlayer)
add_subdirectory(MeshHelpers)
add_subdirectory(Mob)
add_subdirectory(Player)
add_subdirectory(ScreenView)
# add_subdirectory(SurvivalMode)