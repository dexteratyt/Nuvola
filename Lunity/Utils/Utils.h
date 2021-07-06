#ifndef LUNITY_UTILS_UTILS
#define LUNITY_UTILS_UTILS
#include <Windows.h>
#include <fstream>
#include <string>

class Utils {
public:
    static void DebugF(const char*);
    static void DebugF(std::string);
};


#endif /* LUNITY_UTILS_UTILS */
