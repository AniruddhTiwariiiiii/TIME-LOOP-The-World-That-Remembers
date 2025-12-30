#include "AISystem.h"
#include "World.h"
#include "Transform.h"
#include "Entity.h"
#include "EnemyTag.h"

AISystem::AISystem(World &world)
    : world(world), direction(1.f) {}

void AISystem::update(float deltaTime)
{
    const float speed = 100.f;

    for (Entity &entity : world.getEntities())
    {
        if (!world.getEnemy(entity))
            continue; // ONLY enemies

        Transform *t = world.getTransform(entity);
        if (!t)
            continue;

        t->x += direction * speed * deltaTime;

        // simple patrol bounds
        if (t->x < 100.f)
            direction = 1.f;
        else if (t->x > 700.f)
            direction = -1.f;
    }
}
