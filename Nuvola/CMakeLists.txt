if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

link_directories("${CMAKE_CURRENT_LIST_DIR}/Lib/PolyHook_2_0/_install/lib/")

add_library(Nuvola SHARED)

target_sources(Nuvola PRIVATE 
	"main.cpp"
)

add_subdirectory(Client)
add_subdirectory(Render)
add_subdirectory(Utils)
add_subdirectory(Mem)
add_subdirectory(Lib)

target_include_directories(Nuvola PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Lib/PolyHook_2_0/_install/include/")
target_include_directories(Nuvola PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Lib/cpp-httplib/")
target_include_directories(Nuvola PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Lib/HTTPRequest/include/")
target_include_directories(Nuvola PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Lib/GSL/include/")

message("${CMAKE_CURRENT_LIST_DIR}")

target_link_libraries(Nuvola PRIVATE PolyHook_2 capstone version)
