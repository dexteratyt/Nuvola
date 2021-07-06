#ifndef LUNITY_MEM_SIGINFO
#define LUNITY_MEM_SIGINFO
#include <string>
struct SigInfo {
    std::string* signature;
    int offset;

    SigInfo(std::string* signature, int offset) {
        this->signature = signature;
        this->offset = offset;
    };
    ~SigInfo() {
        delete signature;
    }
};

#endif /* LUNITY_MEM_SIGINFO */
