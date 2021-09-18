#ifndef NUVOLA_CLIENT_FEATURES_COMMANDS_PACKETDEBUGCOMMAND
#define NUVOLA_CLIENT_FEATURES_COMMANDS_PACKETDEBUGCOMMAND

#include "../Command.h"
#include "../../Events/Listener.h"

class PacketDebugCommand : public Command, public Listener {
public:
	PacketDebugCommand();
	auto Execute(std::vector<std::string> params) -> bool override;
	auto GetDescription() -> std::string override;
	auto GetAliases() -> std::vector<std::string> override;
	void onPacket(PacketEvent& event) override;
};

#endif /* NUVOLA_CLIENT_FEATURES_COMMANDS_PACKETDEBUGCOMMAND */
