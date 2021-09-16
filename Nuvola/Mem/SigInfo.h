#ifndef NUVOLA_MEM_SIGINFO
#define NUVOLA_MEM_SIGINFO
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

#endif /* NUVOLA_MEM_SIGINFO */
