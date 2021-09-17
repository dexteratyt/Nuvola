#include "VersionCommand.h"

#include "../../../Utils/Utils.h"
#include "../../Bridge/LocalPlayer.h"
#include "../../Bridge/GuiData.h"

VersionCommand::VersionCommand() : Command("version") {

}

auto VersionCommand::Execute(std::vector<std::string> params) -> bool {
	
	DisplayMessage("&7Currently running &aNuvola &b" STRING(NUVOLA_BUILD_TAG) " &a" STRING(NUVOLA_BUILD_VERSION));

	return true;
};

auto VersionCommand::GetDescription() -> std::string {
	return "Shows the current Nuvola build version and any other versioning information";
}

auto VersionCommand::GetAliases() -> std::vector<std::string> {
	std::vector<std::string> aliases;
	aliases.push_back("ver");
	return aliases;
}