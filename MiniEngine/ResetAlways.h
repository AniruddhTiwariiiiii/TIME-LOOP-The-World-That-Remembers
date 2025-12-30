#pragma once
#include "ResetPolicy.h"

class ResetAlways : public ResetPolicy
{
public:
    void reset(World &world, Entity &entity) override;
};
