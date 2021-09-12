#ifndef LUNITY_CLIENT_FEATURES_COMMAND
#define LUNITY_CLIENT_FEATURES_COMMAND

#include "ManagedItem.h"
#include <vector>
#include <string>

class Command : public ManagedItem {
public:
	Command(std::string name);

	auto Execute(std::vector<std::string> params) -> bool;
};

#endif /* LUNITY_CLIENT_FEATURES_COMMAND */
