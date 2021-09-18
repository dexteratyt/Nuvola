#ifndef NUVOLA_CLIENT_FEATURES_COMMANDS_TOGGLECOMMAND
#define NUVOLA_CLIENT_FEATURES_COMMANDS_TOGGLECOMMAND

#include "../Command.h"

class ToggleCommand : public Command {
public:
	ToggleCommand();
	auto Execute(std::vector<std::string> params) -> bool override;
	auto GetDescription() -> std::string override;
	auto GetAliases() -> std::vector<std::string> override;
};

#endif /* NUVOLA_CLIENT_FEATURES_COMMANDS_TOGGLECOMMAND */
