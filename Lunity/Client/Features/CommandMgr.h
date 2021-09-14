#ifndef LUNITY_CLIENT_FEATURES_COMMANDMGR
#define LUNITY_CLIENT_FEATURES_COMMANDMGR

#include "Manager.h"
#include "Command.h"
#include "../Events/Listener.h"

class CommandMgr : public Manager<Command>, public Listener {
    static CommandMgr * instance;
	
public:
    CommandMgr();
    static CommandMgr* getInstance();
    auto getAllCommands() -> std::vector<Command*>* {
		return this->getItems();
	}
	auto findCommand(std::string name) -> Command*;
private:
	void parseAndInterpret(std::string message);
	void onChatEvent(ChatEvent& event) override;
};

#endif /* LUNITY_CLIENT_FEATURES_COMMANDMGR */
