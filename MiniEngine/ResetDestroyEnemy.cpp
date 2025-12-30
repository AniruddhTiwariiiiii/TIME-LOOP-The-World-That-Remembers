#include "ResetDestroyEnemy.h"
#include "World.h"
#include "EnemyTag.h"
#include "Transform.h"

void ResetDestroyEnemy::reset(World &world, Entity &entity)
{
    // If this entity is an enemy, move it far away permanently
    if (world.getEnemy(entity))
    {
        if (auto *t = world.getTransform(entity))
        {
            t->x = -10000.f;
            t->y = -10000.f;
        }
    }
}
