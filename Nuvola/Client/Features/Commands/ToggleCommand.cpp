#include "ToggleCommand.h"

#include "../../../Utils/Utils.h"
#include "../../Bridge/LocalPlayer.h"
#include "../../Bridge/GuiData.h"

#include "../ModuleMgr.h"

ToggleCommand::ToggleCommand() : Command("toggle") {

}

auto ToggleCommand::Execute(std::vector<std::string> params) -> bool {
	
	if(params.size() < 1) {
		DisplayMessage("&7Usage: &8.toggle <module>");
		return false;
	}

	std::string moduleName = params[0];

	auto mod = ModuleMgr::getInstance()->findModule(moduleName);
	if(mod == nullptr) {
		DisplayMessage("&cUnknown module \""+moduleName+"\"");
		return false;
	}

	mod->Toggle();
	if(mod->IsEnabled())
		DisplayMessage("&aEnabled "+mod->getName());
	else
		DisplayMessage("&cDisabled "+mod->getName());

	return true;
};

auto ToggleCommand::GetDescription() -> std::string {
	return "Shows the current Nuvola build version and any other versioning information";
}

auto ToggleCommand::GetAliases() -> std::vector<std::string> {
	std::vector<std::string> aliases;
	aliases.push_back("t");
	return aliases;
}