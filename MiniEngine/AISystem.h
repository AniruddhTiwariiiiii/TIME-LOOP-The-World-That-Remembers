#pragma once
#include "System.h"

class World;

class AISystem : public System
{
public:
    explicit AISystem(World &world);
    void update(float deltaTime) override;

private:
    World &world;
    float direction; // +1 or -1
};
