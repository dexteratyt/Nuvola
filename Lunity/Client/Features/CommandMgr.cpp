#include "CommandMgr.h"

#include "../Events/EventHandler.h"

CommandMgr::CommandMgr() : Manager<Command>("CommandManager") {
    //Set instance
    instance = this;
    //Initialize commands
	auto* command = new Command("help");

	//Register commands
	this->addItem(command);

	EventHandler::registerListener(this);
}

CommandMgr* CommandMgr::instance = nullptr;

CommandMgr* CommandMgr::getInstance() {
	if(instance == nullptr) {
		instance = new CommandMgr();
	}
    return instance;
}

Command* CommandMgr::findCommand(std::string name) {
	std::vector<Command*>* allCommands = this->getItems();
	for(auto cmd : *allCommands) {
		if(cmd->getName() == name) {
			return cmd;
		}
	}
	return nullptr;
}


//TODO: continue parsing, interpreting & executing

//Message must be at least 1 "word"
void CommandMgr::parseAndInterpret(std::string message) {
	std::vector<std::string> words;
	
	//Split string by space
	std::string newWord = "";
	bool canSplit = true; //When using "" the text between counts as 1 word
	for(auto c : message) {
		if(c == '"') {
			canSplit = !canSplit;
		}
		if(canSplit && c == ' ') {
			words.push_back(newWord);
			newWord = "";
			continue;
		}
		newWord += c;
	}

	std::string cmdStr = words[0];
	words.erase(words.begin());
	
	Command* cmd = this->findCommand(cmdStr);
	if(cmd != nullptr) {
		cmd->Execute(words);
	}
}

//Handle sent chat messages here
void CommandMgr::onChatEvent(ChatEvent& event) {
	std::string message = event.GetMessage();

	if(message[0] == '!') {
		//This is a command

		std::string noPrefix = message.substr(1);
		if(noPrefix.size() > 0) {
			this->parseAndInterpret(noPrefix);
		}

		event.SetCancelled(true);
	}
};