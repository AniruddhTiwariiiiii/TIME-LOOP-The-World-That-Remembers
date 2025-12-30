#pragma once
#include "System.h"

class World;

class CameraSystem : public System
{
public:
    explicit CameraSystem(World &world);
    void update(float deltaTime) override;

private:
    World &world;
};
