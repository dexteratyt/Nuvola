#ifndef NUVOLA_CLIENT_FEATURES_COMMAND
#define NUVOLA_CLIENT_FEATURES_COMMAND

#include "ManagedItem.h"
#include <vector>
#include <string>
#include <ostream>

#include "../Bridge/GuiData.h"

class Command : public ManagedItem {
	auto GetGuiData() -> GuiData*;
public:
	Command(std::string name);

	virtual auto Execute(std::vector<std::string> params) -> bool;
	virtual auto GetDescription() -> std::string;
	void DisplayMessage(std::string message);
	auto GetOut() -> lun::ostream&;
};

#endif /* NUVOLA_CLIENT_FEATURES_COMMAND */
