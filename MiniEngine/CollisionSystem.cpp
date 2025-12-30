#include "CollisionSystem.h"
#include "World.h"
#include "Transform.h"
#include "Collider.h"
#include "Entity.h"
#include "EnemyTag.h"
#include "EventBus.h"
#include "DeathEvent.h"

#include <cstddef> // for size_t

CollisionSystem::CollisionSystem(World &world, EventBus &eventBus)
    : world(world), eventBus(eventBus) {}

static bool intersects(Transform *aT, Collider *aC,
                       Transform *bT, Collider *bC)
{
    return !(aT->x + aC->w < bT->x ||
             aT->x > bT->x + bC->w ||
             aT->y + aC->h < bT->y ||
             aT->y > bT->y + bC->h);
}

void CollisionSystem::update(float)
{
    auto &entities = world.getEntities();

    // If only one entity exists, nothing to collide with
    if (entities.size() < 2)
        return;

    for (size_t i = 0; i < entities.size(); ++i)
    {
        for (size_t j = i + 1; j < entities.size(); ++j)
        {
            Transform *t1 = world.getTransform(entities[i]);
            Transform *t2 = world.getTransform(entities[j]);
            Collider *c1 = world.getCollider(entities[i]);
            Collider *c2 = world.getCollider(entities[j]);

            if (!t1 || !t2 || !c1 || !c2)
                continue;

            if (intersects(t1, c1, t2, c2))
            {
                bool aEnemy = world.getEnemy(entities[i]) != nullptr;
                bool bEnemy = world.getEnemy(entities[j]) != nullptr;

                if (aEnemy ^ bEnemy)
                {
                    eventBus.emit(DeathEvent{});
                }
            }
        }
    }
}
