#include "Command.h"

Command::Command(std::string name) : ManagedItem(name) {
	
}

auto Command::GetGuiData() -> GuiData* {
	return Utils::GetClientInstance()->guiData;
}

char formatCodes[] = {
	'0', //Black
	'1', //Dark blue
	'2', //Dark green
	'3', //Dark aqua
	'4', //Dark red
	'5', //Dark purple
	'6', //Gold
	'7', //Gray
	'8', //Dark gray
	'9', //Blue
	'a', //Green
	'b', //Aqua
	'c', //Red
	'd', //Light purple
	'e', //Yellow
	'f', //White
	'g', //Minecoin gold
	'k', //Obfuscated
	'l', //Bold
	'm', //Strikethrough
	'n', //Underline
	'o', //Italic
	'r'  //Reset
};
void Command::DisplayMessage(std::string message) {
	std::string newMessage;

	bool checkFormat = false;
	for(auto c : message) {
		if(c == '&') {
			if(checkFormat) {
				newMessage += c;
				goto append;
			}
			checkFormat = true;
			continue;
		}
		if(checkFormat) {
			for(auto formatCode : formatCodes) {
				if(c == formatCode) {
					newMessage += "§";
					checkFormat = false;
					goto append;
					break;
				}
			}
		}
append:
		newMessage += c;
	}

	this->GetGuiData()->displayClientMessage(newMessage);
}

auto Command::GetOut() -> lun::ostream& {
	return Utils::mcout();
}

auto Command::Execute(std::vector<std::string> params) -> bool {
	return false;
}
auto Command::GetDescription() -> std::string {
	return "No description provided";
}
auto Command::GetAliases() -> std::vector<std::string> {
	return std::vector<std::string>();
}
auto Command::MatchName(std::string toMatch) -> bool {
	//If the command name matches, perfect!
	if(toMatch == this->getName()) {
		return true;
	}
	//If not, check for aliases
	std::vector<std::string> aliases = this->GetAliases();
	for(auto alias : aliases) {
		//If an alias matches, thats out command
		if(alias == toMatch) {
			return true;
		}
	}
	//Otherwise this isnt us
	return false;
}