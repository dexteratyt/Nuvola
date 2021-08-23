#ifndef LUNITY_UTILS_UTILS
#define LUNITY_UTILS_UTILS
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include "../Client/Bridge/ClientInstance.h"
#include <gsl/gsl>

class Utils {
	static inline ClientInstance* clientInstance;
	static inline class MaterialPtr* materialPtr;
public:
    static void DebugF(const char*);
    static void DebugF(std::string);
	static void SetClientInstance(uintptr_t address);
	static auto GetClientInstance() -> ClientInstance*;
	static auto GetUIMaterialPtr() -> class MaterialPtr*;
};


#endif /* LUNITY_UTILS_UTILS */
