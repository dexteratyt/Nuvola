# Poor code was never used since Jirachi dead.
# I wrote this code so I hope it aint an issue if
# its going here

target_sources(Nuvola PRIVATE
	"Category.cpp"
	"Command.cpp"
	"CommandMgr.cpp"
	"ManagedItem.cpp"
	"Module.cpp"
	"ModuleMgr.cpp"
)

add_subdirectory(Commands)
add_subdirectory(Modules)