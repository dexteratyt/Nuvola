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

	nuv::string* nuvStr = new nuv::string("Hello!");
	nuv::string* nuvLongStr = new nuv::string("This string is quite long, so reallocation is needed!");

	DisplayMessage("NuvStr-Addr: "+int_to_hex(nuvStr));
	DisplayMessage("NuvStr-Addr: "+int_to_hex(nuvLongStr));

	return true;
};