#ifndef NUVOLA_CLIENT_FEATURES_COMMANDS_VERSIONCOMMAND
#define NUVOLA_CLIENT_FEATURES_COMMANDS_VERSIONCOMMAND

#include "../Command.h"

class VersionCommand : public Command {
public:
	VersionCommand();
	auto Execute(std::vector<std::string> params) -> bool override;
	auto GetDescription() -> std::string override;
	auto GetAliases() -> std::vector<std::string> override;
};

#endif /* NUVOLA_CLIENT_FEATURES_COMMANDS_VERSIONCOMMAND */
