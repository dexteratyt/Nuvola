#ifndef NUVOLA_CLIENT_FEATURES_CATEGORY
#define NUVOLA_CLIENT_FEATURES_CATEGORY
#include <string>
#include <vector>
#include "Manager.h"
#include "Module.h"


class Category : public Manager<Module>{
public:
    explicit Category(const std::string& name);
};

#endif /* NUVOLA_CLIENT_FEATURES_CATEGORY */
