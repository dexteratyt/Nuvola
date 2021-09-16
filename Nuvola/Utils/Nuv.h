#ifndef NUVOLA_UTILS_NUV
#define NUVOLA_UTILS_NUV

//This header holds templates for Release mode STL types
//Ex. a wrapper for std::vector with Minecraft's build settings
//This way Nuvola can be built with whatever STL standard.
//This is also a near instant replacement. Just swap std::vector with nuv::vector

#define PTR_SIZE sizeof(void*)
#define STR_FIRST_ALIGN 0xF

#include <string>

namespace nuv {
	class string {
		//textData union to help us a bit
		union textData
		{
			const char* contentPtr;
			char contentData[STR_FIRST_ALIGN+1];
		} text;
static_assert(sizeof(textData) == 16, "textData is misaligned!");
		size_t length;
		size_t lengthTillRealign;
	public:
		//nuv::string constructor
		string(std::string text) {
			this->lengthTillRealign = STR_FIRST_ALIGN;
			this->setString(text);
		}
		//setting the string content via std::string
		void setString(std::string text) {
			//Clear the contentData, make sure its all null
			memset(this->text.contentData, 0, STR_FIRST_ALIGN+1);

			//Check the text length, we may need to reallocate where the content is stored
			if(text.length() > this->lengthTillRealign) {
				//If we need to relocate, allocate new memory with the text length + 1
				char* alloc = (char*)malloc(text.length()+1);
				//Set the content of the allocated memory
				for(int i = 0; i < text.length(); i++) {
					alloc[i] = text[i];
				}
				//Set the content pointer to the allocated mem
				this->text.contentPtr = alloc;
				this->lengthTillRealign = text.length()*2;
			}
			//If we do not need to re allocate
			else {
				//Set the contents to the text with no memory allocation
				for(int i = 0; i < text.length(); i++) {
					this->text.contentData[i] = text[i];
				}
			}
			//Set the length
			this->length = text.length();
		}
		//Convert back to std::string
		std::string getString() {
			//create a new string
			std::string newStr = "";
			//Check if the length is greater than 15
			//This tells us if its a pointer or if we can just copy the bytes
			if(STR_FIRST_ALIGN != this->lengthTillRealign) {
				//Its a pointer, std::string can use a char* to form a new instance
				newStr = text.contentPtr;
			} else {
				//Its not a pointer, so we can append each character
				for(int i = 0; i < this->length; i++) {
					newStr += text.contentData[i];
				}
			}
			return newStr;
		}
	};
static_assert(sizeof(nuv::string) == 32, "nuv::string is misaligned!");

	//TODO: finish kthx
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
			size_t size = size();
			size_t b_size = size*PTR_SIZE;
			size_t newAllocSize = b_size*2;
			T* newFirst = malloc(newAllocSize);

			//Copy old objects
			for(int i = 0; i < size(); i++) {
				*((T*)(((size_t)newFirst)+(i*PTR_SIZE))) = this[i];
			}

			//set new vals
			firstAddr = newFirst;
			lastAddr = b_size+PTR_SIZE;
			nextRealign = ((size_t)newFirst)+newAllocSize;
		}
		void push_back(T val) {
			if((((size_t)lastAddr)+PTR_SIZE == nextRealign)) {
				realign();
			}
			*lastAddr = val;
			((size_t)lastAddr) += PTR_SIZE;
		}
		bool remove(size_t index) {
			size_t size = size();
			if(index >= size) {
				//Index is outside of the size like bruh
				return false;
			}

			size_t offset = index*PTR_SIZE;
			//Clear the pointer
			*((size_t*)firstAddr+offset) = nullptr;



			return true;
		}
	};
}

#endif /* NUVOLA_UTILS_NUV */
