#ifndef NUVOLA_UTILS_UTILS
#define NUVOLA_UTILS_UTILS
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include "../Client/Bridge/ClientInstance.h"
#include <gsl/gsl>
#include <sstream>

#define LOG_FILE
//#define LOG_CONSOLE
#define LOG_GAME

namespace lun {
	struct ostream;
}

class Utils {
	static inline ClientInstance* clientInstance;
	static inline class MaterialPtr* materialPtr;

	//Minecraft Output (mcout), how creative
	static lun::ostream* omcout;
public:
    static void DebugF(const char*);
    static void DebugF(std::string);
	static auto mcout() -> lun::ostream&;
	static void SetClientInstance(uintptr_t address);
	static auto GetClientInstance() -> ClientInstance*;
	static auto GetUIMaterialPtr() -> class MaterialPtr*;
};

namespace lun {
	//Custom stream out object for std::cout like behavior within mc chat and other output methods
	struct ostream {
		std::stringstream stream;
	public:
		template<typename T>
		ostream& operator<<(T&& value) {
			stream << value;
			return *this;
		}

		ostream& operator<<(std::ostream& (*os)(std::ostream&)) {
			stream << os;
			
			return *this;
		}

		//Flush the output stream to DebugF
		ostream& flush() {
			std::string result = stream.str();
			Utils::DebugF(result);

			stream.flush();
			stream.clear();

			return *this;
		}
	};
}

#endif /* NUVOLA_UTILS_UTILS */
