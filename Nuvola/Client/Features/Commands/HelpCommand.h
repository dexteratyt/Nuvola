#ifndef NUVOLA_CLIENT_FEATURES_COMMANDS_HELPCOMMAND
#define NUVOLA_CLIENT_FEATURES_COMMANDS_HELPCOMMAND

#include "../Command.h"

class HelpCommand : public Command {
public:
	HelpCommand();
	auto Execute(std::vector<std::string> params) -> bool override;
	auto GetDescription() -> std::string override;
	auto GetAliases() -> std::vector<std::string> override;
};

#endif /* NUVOLA_CLIENT_FEATURES_COMMANDS_HELPCOMMAND */
