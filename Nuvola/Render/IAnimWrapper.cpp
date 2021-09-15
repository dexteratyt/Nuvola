#include "IAnimWrapper.h"

void IAnimWrapper::NewFrame() {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::chrono::duration<float> diff = now - lastTime;
	deltaTime = diff.count();
	lastTime = now;
}

auto IAnimWrapper::GetDeltaTime() -> float {
	return deltaTime;
}