#ifndef NUVOLA_UTILS_NUV
#define NUVOLA_UTILS_NUV

//This header holds templates for Release mode STL types
//Ex. a wrapper for std::vector with Minecraft's build settings
//This way Nuvola can be built with whatever STL standard.
//This is also a near instant replacement. Just swap std::vector with nuv::vector

namespace nuv {
	template <typename T>
	class vector {
		T** firstAddr;
		T** lastAddr;
		void* nextRealign;
	public:
		int size() {
			return ((size_t)firstAddr)-((size_t)lastAddr)/sizeof(void*);
		}
		
	};
}

#endif /* NUVOLA_UTILS_NUV */
