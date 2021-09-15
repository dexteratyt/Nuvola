#ifndef LUNITY_CLIENT_FEATURES_COMMANDS_SWINGCOMMAND
#define LUNITY_CLIENT_FEATURES_COMMANDS_SWINGCOMMAND

#include "../Command.h"

class SwingCommand : public Command {
public:
	SwingCommand();
	auto Execute(std::vector<std::string> params) -> bool override;
};

#endif /* LUNITY_CLIENT_FEATURES_COMMANDS_SWINGCOMMAND */
