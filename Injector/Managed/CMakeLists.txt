if(MSVC)
add_compile_options(
		$<$<CONFIG:>:/MT> #---------|
		$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
		$<$<CONFIG:Release>:/MT> #--|
)
endif()

add_executable(Injector)

# Set the C# language version to 9
set_target_properties(Injector PROPERTIES VS_GLOBAL_LangVersion "9.0")

# Set project properties
set_property(TARGET Injector PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.8")
set_property(TARGET Injector PROPERTY WIN32_EXECUTABLE TRUE)
set_property(TARGET Injector PROPERTY VS_CONFIGURATION_TYPE Console)
set_property(TARGET Injector PROPERTY VS_DOTNET_REFERENCES_COPY_LOCAL OFF)

# Add sources
target_sources(Injector PRIVATE 
	"Injector.cs"
)

message("${CMAKE_CURRENT_LIST_DIR}")