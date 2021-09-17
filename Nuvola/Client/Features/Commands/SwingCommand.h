#ifndef NUVOLA_CLIENT_FEATURES_COMMANDS_SWINGCOMMAND
#define NUVOLA_CLIENT_FEATURES_COMMANDS_SWINGCOMMAND

#include "../Command.h"

class SwingCommand : public Command {
public:
	SwingCommand();
	auto Execute(std::vector<std::string> params) -> bool override;
	auto GetDescription() -> std::string override;
};

#endif /* NUVOLA_CLIENT_FEATURES_COMMANDS_SWINGCOMMAND */
