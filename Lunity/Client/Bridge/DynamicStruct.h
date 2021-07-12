#ifndef LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
#define LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT
#include <vector>
#include <string>

// Dynamic struct is a neat way to support multiple versions
// and maintain structures over time.
// This will help with updating classes and structures.
struct DynamicStruct;

// Basic dynamic object. 
struct DynamicObject {
	// Dynamic objects should be named by type
	// Dynamic fields & methods should be named by their respective names
    std::string name;
	// Address is the location of the resource (the pointer)
    uintptr_t address;
	// Offset is the offset of a resource from its relative parent
	// for example, a vtable offset or field offset
    uintptr_t offset;

	// Construct a DynamicObject
    DynamicObject(std::string name, uintptr_t offset) {
        this->name = name;
        this->offset = offset;
    };
	// Retrieve the name
    auto getName() -> std::string {
        return this->name;
    };
	// Retrieve the resource as a void*
    auto asVoid() -> void* {
        return (void*)this->getAddress();
    }
	// Change the wrapper's read location
    auto setAddress(uintptr_t address) -> void {
        this->address = address;
    }
	// Get the wrapper's read location
    auto getAddress() -> uintptr_t {
        return this->address;
    }
	// Set the offset of the resource
	// (Still relative to a parent)
    auto setOffset(uintptr_t offset) -> void {
        this->offset = offset;
    }
	// Retrieve the offset
    auto getOffset() -> uintptr_t {
        return this->offset;
    }
};

// A field for a dynamic struct
struct DynamicField : DynamicObject {
	// The constructor
    DynamicField(std::string fieldName, uintptr_t offset) : DynamicObject(fieldName, offset) {
    };
	// If the field was a struct, this can be used to get it.
    auto asStruct() -> DynamicStruct* {
        return (DynamicStruct*)this;
    };
};

// A method object
struct DynamicMethod : DynamicObject {
	// Le constructor
    DynamicMethod(std::string methodName, uintptr_t offset) : DynamicObject(methodName, offset) {
    }
	//Generate a call wrapper using PLH::FnCast
	//TODO: Make it work properly :)
	template<typename T>
	auto Cast(T pFunc) -> T {
		return PLH::FnCast(this->asVoid(), pFunc);
	}
};

// The big boy struct.
struct DynamicStruct : DynamicObject {
	// Vectors for all attributes of the struct
    std::vector<DynamicField*>* fields;
    std::vector<DynamicMethod*>* virtualFunctions; //VTable funcs
    std::vector<DynamicMethod*>* functions; //All other funcs
    DynamicStruct(std::string structName, uintptr_t offset) : DynamicObject(structName, offset) {
        fields = new std::vector<DynamicField*>();
        virtualFunctions = new std::vector<DynamicMethod*>();
        functions = new std::vector<DynamicMethod*>();
    };

	//Add a field to the struct
    auto addField(DynamicField* theField) -> void {
        theField->setAddress(this->getAddress()+offset);
        this->fields->push_back(theField);
    };
	//Add a virtual function/vtable function to the struct
    auto addVirtual(DynamicMethod* theMethod) -> void {
        uintptr_t newAddr = (*((uintptr_t*)this->getAddress()))+(8*offset);
        theMethod->setAddress(newAddr);
        this->virtualFunctions->push_back(theMethod);
    };
	//Add a non-virtual function to the struct
	//These are the functions typically found with signatures
    auto addFunction(DynamicMethod* theMethod) -> void {
        theMethod->setAddress(address);
        this->functions->push_back(theMethod);
    };

	//Retrieve the DynamicObject by name
    auto get(std::string name) -> DynamicObject* {
		//Search fields
        for(auto field : *fields) {
			//If name matches
            if(field->getName()==name) {
				//Adjust the address properly & return
                field->setAddress(this->getAddress()+field->getOffset());
                return field;
            }
        }
		//Search added virtual functions
        for(auto function : *virtualFunctions) {
			//If name matches
            if(function->getName()==name) {
				//Get cool address & return
                uintptr_t newAddr = (*((uintptr_t*)this->getAddress()))+(8*function->getOffset());
                function->setAddress(newAddr);
                return function;
            }
        }
		//Search non-virtual functions
        for(auto function : *functions) {
			//Match name
            if(function->getName()==name) {
				//Return, no address math needs to be added. The address is static.
                return function;
            }
        }
		//Everything failed? return null
		//PLEASE CHECK THIS IN CODE!!
        return nullptr;
    };
};


#endif /* LUNITY_CLIENT_BRIDGE_DYNAMICSTRUCT */
