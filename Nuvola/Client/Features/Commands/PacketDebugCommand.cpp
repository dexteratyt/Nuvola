#include "PacketDebugCommand.h"

#include "../../../Utils/Utils.h"
#include "../../Bridge/LocalPlayer.h"
#include "../../Bridge/GuiData.h"

#include "../../Events/EventHandler.h"

PacketDebugCommand::PacketDebugCommand() : Command("packetdebugger") {
	EventHandler::registerListener(this);
}

template< typename T >
std::string int_to_hex( T i )
{
  std::stringstream stream;
  stream << "0x" << std::hex << i;
  return stream.str();
}

bool resolveNext = false;
int packetID;
void PacketDebugCommand::onPacketEvent(PacketEvent& event) {
	//If theres no task, don't do anything!
	//if(currentTask == Task::NONE) { return; }

	if(resolveNext) {
		if(event.GetPacket()->getId() == packetID) {
			resolveNext = false;
			DisplayMessage("Resolved packet with ID (" + std::to_string(packetID) + ") as \"" + event.GetPacket()->getName().getString() + "\" associated VTable is "+int_to_hex(*(void**)event.GetPacket()));
		}
	}
}

auto PacketDebugCommand::Execute(std::vector<std::string> params) -> bool {

	if(params[0] == "resolve") {
		if(params.size() > 1) {
			resolveNext = true;
			packetID = std::stoi(params[1]);
			DisplayMessage("Waiting for next resolve for packet "+std::to_string(packetID));
		} else {
			return false;
		}
	}

	return true;
};

auto PacketDebugCommand::GetDescription() -> std::string {
	return "A packet 'debugger' (its really a dumping/interception tool)";
}

auto PacketDebugCommand::GetAliases() -> std::vector<std::string> {
	std::vector<std::string> aliases;
	aliases.push_back("pdbg");
	return aliases;
}