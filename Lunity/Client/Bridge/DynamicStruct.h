#ifndef LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
#define LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
/*
A rewrite of my DynamicStruct code.
Hopefully this will be nicer to use & update
*/

#include <string>
#include <vector>

struct Metadata {
	std::string name;

	Metadata(std::string name) {
		this->name = name;
	};

	std::string GetName() {
		return this->name;
	};
};
struct Addressable {
	uintptr_t address;

	Addressable(uintptr_t address) {
		this->address = address;
	};

	void SetAddress(uintptr_t address) {
		this->address = address;
	}

	auto GetAddress() -> uintptr_t {
		return this->address;
	}

	auto IsNull() -> bool {
		return this->GetAddress() == 0;
	}
};

struct DynamicField : Metadata {

	int offset;

	DynamicField(std::string name, int offset) : Metadata(name) {
		this->offset = offset;
	};

	auto GetOffset() -> int {
		return this->offset;
	}
};

struct DynamicStruct : Metadata, Addressable {

	std::vector<DynamicField*>* fields;

	DynamicStruct(std::string name, uintptr_t address) : Metadata(name), Addressable(address) {
		fields = new std::vector<DynamicField*>();
	};

	void AddField(std::string name, int offset) {
		fields->push_back(new DynamicField(name, offset));
	}

	auto GetField(std::string name) -> uintptr_t {
		return (uintptr_t)this->GetFieldRaw(name);
	}
	auto GetFieldRaw(std::string name) -> void* {
		uintptr_t address = this->GetAddress();
		uintptr_t offset = 0;

		for(auto* field : *fields) {
			if(field->GetName() == name) {
				offset = field->GetOffset();
				break;
			}
		}

		if(offset == 0) {
			throw std::exception(std::string(std::string("Unknown field \"") + name + std::string("\" of struct \"") + this->GetName() + std::string("\"")).c_str());
		}

		void* pokedAddress = (void*)(address+offset);
		return pokedAddress;
	}
};

#endif /* LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT */
