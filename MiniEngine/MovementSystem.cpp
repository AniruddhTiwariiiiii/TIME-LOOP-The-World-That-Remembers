#include "MovementSystem.h"
#include "World.h"
#include "Transform.h"
#include "Entity.h"
#include "EventBus.h"
#include "MoveEvent.h"
#include "PlayerTag.h"

MovementSystem::MovementSystem(World &world, EventBus &eventBus)
    : world(world), vx(0.f), vy(0.f)
{
    eventBus.subscribe<MoveEvent>([this](const MoveEvent &e)
                                  {
        vx = e.dx;
        vy = e.dy; });
}

void MovementSystem::update(float deltaTime)
{
    const float speed = 200.f;

    for (Entity &entity : world.getEntities())
    {
        if (!world.getPlayer(entity))
            continue; // ✅ ONLY PLAYER MOVES VIA INPUT

        Transform *t = world.getTransform(entity);
        if (!t)
            continue;

        t->x += vx * speed * deltaTime;
        t->y += vy * speed * deltaTime;

        if (t->x < 0.f)
            t->x = 0.f;
        if (t->y < 0.f)
            t->y = 0.f;
        if (t->x > 780.f)
            t->x = 780.f;
        if (t->y > 580.f)
            t->y = 580.f;
    }
}
