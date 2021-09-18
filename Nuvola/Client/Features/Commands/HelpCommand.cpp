#include "HelpCommand.h"

#include "../../../Utils/Utils.h"
#include "../CommandMgr.h"

HelpCommand::HelpCommand() : Command("help") {

}

template< typename T >
std::string int_to_hex( T i )
{
  std::stringstream stream;
  stream << "0x" << std::hex << i;
  return stream.str();
}

auto HelpCommand::Execute(std::vector<std::string> params) -> bool {
	
	std::vector<Command*>* commands = CommandMgr::getInstance()->getAllCommands();

	DisplayMessage("&ko&r&bNuvola&r&ko&r &8- &eHelp menu");
	for(auto command : *commands) {
		DisplayMessage("&e> &7!&b"+command->getName() + " &8- &7" + command->GetDescription());
	}

	return true;
};

auto HelpCommand::GetDescription() -> std::string {
	return "Display's all available Nuvola commands, as well as provides a description of what they each do";
}

auto HelpCommand::GetAliases() -> std::vector<std::string> {
	std::vector<std::string> aliases;
	aliases.push_back("h");
	return aliases;
}