#include "Command.h"

Command::Command(std::string name) : ManagedItem(name) {

}

auto Command::Execute(std::vector<std::string> params) -> bool {
	return false;
}