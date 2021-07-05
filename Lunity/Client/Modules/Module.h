#include <string>

class Module {
public:
    std::string name;

    bool isEnabled, wasEnabled;

    Module(std::string name){
        this->name = name;
    };

    void setState(bool, bool);
};