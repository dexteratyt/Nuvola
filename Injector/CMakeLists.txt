add_executable(Injector)

# Set the C# language version to 9
set_target_properties(Injector PROPERTIES VS_GLOBAL_LangVersion "9.0")

# Set project properties
set_property(TARGET Injector PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.8")
set_property(TARGET Injector PROPERTY WIN32_EXECUTABLE FALSE)
set_property(TARGET Injector PROPERTY VS_CONFIGURATION_TYPE Console)
set_property(TARGET Injector PROPERTY VS_DOTNET_REFERENCES_COPY_LOCAL ON)

# Add references
set_property(TARGET Injector PROPERTY VS_DOTNET_REFERENCES "System")
set_property(TARGET Injector PROPERTY VS_PACKAGE_REFERENCES
	"ConsoleGUI_1.4.0"
)

# Add sources
target_sources(Injector PRIVATE
	"App.cs"
	"Injector.cs"
	"Win32.cs"
)

message("${CMAKE_CURRENT_LIST_DIR}")
message("${CMAKE_SOURCE_DIR}")


file(DOWNLOAD "https://dist.nuget.org/win-x86-commandline/v5.10.0/nuget.exe" "nuget.exe")
add_custom_command(TARGET Injector
    PRE_BUILD
    COMMAND nuget.exe restore Lunity.sln
)