#pragma once
#include "ResetPolicy.h"

class ResetTransform : public ResetPolicy
{
public:
    void reset(World &world, Entity &entity) override;
};
