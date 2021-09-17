#include "CommandMgr.h"

#include "../Events/EventHandler.h"

#include "Commands/HelpCommand.h"
#include "Commands/SwingCommand.h"
#include "Commands/VersionCommand.h"

CommandMgr::CommandMgr() : Manager<Command>("CommandManager") {
    //Set instance
    instance = this;
    //Initialize commands
	auto* helpCommand = new HelpCommand();
	auto* swingCommand = new SwingCommand();
	auto* versionCommand = new VersionCommand();

	//Register commands
	this->addItem(helpCommand);
	this->addItem(swingCommand);
	this->addItem(versionCommand);

	EventHandler::registerListener(this);
}

CommandMgr* CommandMgr::instance = nullptr;

CommandMgr* CommandMgr::getInstance() {
	if(instance == nullptr) {
		instance = new CommandMgr();
	}
    return instance;
}

auto CommandMgr::findCommand(std::string name) -> Command* {
	std::vector<Command*>* allCommands = this->getItems();
	for(auto cmd : *allCommands) {
		if(cmd->MatchName(name)) {
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
	words.push_back(newWord);

	std::string cmdStr = words[0];
	words.erase(words.begin());
	
	Command* cmd = this->findCommand(cmdStr);
	if(cmd != nullptr) {
		cmd->Execute(words);
	} else {
		//No command found
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