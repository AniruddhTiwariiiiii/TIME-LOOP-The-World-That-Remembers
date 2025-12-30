#pragma once

#include "System.h"

class World;
class EventBus;

class CollisionSystem : public System
{
public:
    CollisionSystem(World &world, EventBus &eventBus);

    void update(float deltaTime) override;

private:
    World &world;
    EventBus &eventBus;
};
