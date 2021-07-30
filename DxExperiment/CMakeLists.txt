if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

add_executable(DxExperiment)

target_sources(DxExperiment PRIVATE 
	"main.cpp"
	"Renderer.cpp"
)