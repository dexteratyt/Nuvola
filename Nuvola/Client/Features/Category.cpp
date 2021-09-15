#include "Category.h"

Category::Category(const std::string& name) : Manager<Module>(name) {
    //LogFile::log("Created category " + name + "!");
}