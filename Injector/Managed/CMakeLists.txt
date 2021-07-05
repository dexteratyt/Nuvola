if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

add_executable(Injector)

target_sources(Injector PRIVATE 
	"Injector.cs"
)

message("${CMAKE_CURRENT_LIST_DIR}")