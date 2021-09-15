#ifndef LUNITY_UTILS_IANIMWRAPPER
#define LUNITY_UTILS_IANIMWRAPPER

#include <chrono>

class IAnimWrapper {
	static inline std::chrono::system_clock::time_point lastTime;
	static inline float deltaTime;
public:
	static void NewFrame();
	static auto GetDeltaTime() -> float;
};

#endif /* LUNITY_UTILS_IANIMWRAPPER */
