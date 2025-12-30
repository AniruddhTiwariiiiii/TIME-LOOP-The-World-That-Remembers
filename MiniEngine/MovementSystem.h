#pragma once
#include "System.h"

class World;
class EventBus;
struct MoveEvent;

class MovementSystem : public System
{
public:
    MovementSystem(World &world, EventBus &eventBus);

    void update(float deltaTime) override;

private:
    World &world;
    float vx;
    float vy;
};
