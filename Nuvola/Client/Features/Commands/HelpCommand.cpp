#include "HelpCommand.h"

#include "../../../Utils/Utils.h"
#include "../CommandMgr.h"

HelpCommand::HelpCommand() : Command("help") {

}

auto HelpCommand::Execute(std::vector<std::string> params) -> bool {
	
	std::vector<Command*>* commands = CommandMgr::getInstance()->getAllCommands();

	DisplayMessage("&ko&r&bLunity&r&ko&r &8- &eHelp menu");
	for(auto command : *commands) {
		DisplayMessage("&e> &7!&b"+command->getName() + " &8- &7" + command->GetDescription());
	}

	return true;
};