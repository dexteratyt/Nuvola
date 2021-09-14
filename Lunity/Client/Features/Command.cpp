#include "Command.h"

Command::Command(std::string name) : ManagedItem(name) {
	
}

auto Command::GetGuiData() -> GuiData* {
	return Utils::GetClientInstance()->guiData;
}

std::string formatCodes[] = {
	"0", //Black
	"1", //Dark blue
	"2", //Dark green
	"3", //Dark aqua
	"4", //Dark red
	"5", //Dark purple
	"6", //Gold
	"7", //Gray
	"8", //Dark gray
	"9", //Blue
	"a", //Green
	"b", //Aqua
	"c", //Red
	"d", //Light purple
	"e", //Yellow
	"f", //White
	"g", //Minecoin gold
	"k", //Obfuscated
	"l", //Bold
	"m", //Strikethrough
	"n", //Underline
	"o", //Italic
	"r"  //Reset
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
				if(c == formatCode[0]) {
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