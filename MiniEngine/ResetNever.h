#pragma once
#include "ResetPolicy.h"

class ResetNever : public ResetPolicy
{
public:
    void reset(World &, Entity &) override
    {
        // Do nothing
    }
};
