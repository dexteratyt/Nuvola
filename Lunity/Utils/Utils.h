#ifndef LUNITY_UTILS_UTILS
#define LUNITY_UTILS_UTILS
#include <Windows.h>
#include <fstream>
#include <string>
#include "../Client/Bridge/ClientInstance.h"

class Utils {
	static inline ClientInstance* clientInstance;
public:
    static void DebugF(const char*);
    static void DebugF(std::string);
	static void SetClientInstance(uintptr_t address);
	static auto GetClientInstance() -> ClientInstance*;
};


#endif /* LUNITY_UTILS_UTILS */
