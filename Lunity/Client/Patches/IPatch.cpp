#include "IPatch.h"

IPatch::IPatch(std::string name)
{
    this->name = name;
}
auto IPatch::GetName() -> std::string
{
    return this->name;
}
auto IPatch::GetDis() -> PLH::CapstoneDisassembler&
{
    return *dis;
}
auto IPatch::Apply() -> bool
{
    return false;
}