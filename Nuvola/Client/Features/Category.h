#ifndef LUNITY_CLIENT_FEATURES_CATEGORY
#define LUNITY_CLIENT_FEATURES_CATEGORY
#include <string>
#include <vector>
#include "Manager.h"
#include "Module.h"


class Category : public Manager<Module>{
public:
    explicit Category(const std::string& name);
};

#endif /* LUNITY_CLIENT_FEATURES_CATEGORY */
