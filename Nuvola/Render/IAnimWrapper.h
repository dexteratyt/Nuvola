#ifndef NUVOLA_RENDER_IANIMWRAPPER
#define NUVOLA_RENDER_IANIMWRAPPER

#include <chrono>

class IAnimWrapper {
	static inline std::chrono::system_clock::time_point lastTime;
	static inline float deltaTime;
public:
	static void NewFrame();
	static auto GetDeltaTime() -> float;
};

#endif /* NUVOLA_RENDER_IANIMWRAPPER */
