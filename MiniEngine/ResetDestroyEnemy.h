#pragma once
#include "ResetPolicy.h"

class ResetDestroyEnemy : public ResetPolicy
{
public:
    void reset(World &world, Entity &entity) override;
};
