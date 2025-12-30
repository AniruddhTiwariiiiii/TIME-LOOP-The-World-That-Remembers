#pragma once
#include "System.h"

class World;

class RenderSystem : public System
{
public:
    explicit RenderSystem(World &world);

    void update(float deltaTime) override;

private:
    World &world;
};
