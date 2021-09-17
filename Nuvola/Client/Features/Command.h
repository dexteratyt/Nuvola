#ifndef NUVOLA_CLIENT_FEATURES_COMMAND
#define NUVOLA_CLIENT_FEATURES_COMMAND

#include "ManagedItem.h"
#include <vector>
#include <string>
#include <ostream>

#include "../Bridge/GuiData.h"

class Command : public ManagedItem {
	auto GetGuiData() -> GuiData*;
public:
	Command(std::string name);

	//Command execution method
	virtual auto Execute(std::vector<std::string> params) -> bool;
	//The command description
	virtual auto GetDescription() -> std::string;
	//Possible aliases (ex. version can shorten to ver)
	virtual auto GetAliases() -> std::vector<std::string>;
	//Check the name & alias. If name == command.name OR if name is an alias, return true
	auto MatchName(std::string toMatch) -> bool;
	//Helper function for output. Parses any formatting
	void DisplayMessage(std::string message);
	//an std::cout-like output method if this is prefered
	auto GetOut() -> lun::ostream&;
};

#endif /* NUVOLA_CLIENT_FEATURES_COMMAND */
