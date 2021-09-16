#ifndef NUVOLA_UTILS_NUV
#define NUVOLA_UTILS_NUV

//This header holds templates for Release mode STL types
//Ex. a wrapper for std::vector with Minecraft's build settings
//This way Nuvola can be built with whatever STL standard.
//This is also a near instant replacement. Just swap std::vector with nuv::vector

#define PTR_SIZE sizeof(void*)

namespace nuv {
	template <typename T>
	class vector {
		T* firstAddr;
		T* lastAddr;
		void* nextRealign;
	public:
		size_t size() {
			return ((size_t)firstAddr)-((size_t)lastAddr)/PTR_SIZE;
		}
		T* begin() {
			return firstAddr;
		}
		T* end() {
			return lastAddr;
		}
		T operator[](size_t pos) {
			size_t ptrOffset = pos*PTR_SIZE;
			size_t item = firstAddr+ptrOffset;
			return (T)item;
		}
		void realign() {
			//TODO: magically fix memory leak that is probably actually impossible for me to fix
			
			//Double the element count, and multiply that by the size of a pointer
			//Leaves double the room before needing to realloc
			int newAllocSize = (size()*2)*(PTR_SIZE);
			T* newFirst = malloc(newAllocSize);

			for(int i = 0; i < size(); i++) {
				((T*)(((size_t)newFirst)+(i*PTR_SIZE)) = this[i];
			}
		}
		void push_back(T val) {
			if((((size_t)lastAddr)+PTR_SIZE == nextRealign) {

			}
		}
	};
}

#endif /* NUVOLA_UTILS_NUV */
