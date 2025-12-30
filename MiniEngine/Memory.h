#pragma once
#include <memory>

class ResetPolicy;

struct Memory
{
    std::unique_ptr<ResetPolicy> resetPolicy;
};
