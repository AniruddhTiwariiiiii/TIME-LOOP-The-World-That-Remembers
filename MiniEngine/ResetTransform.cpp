#include "ResetTransform.h"
#include "World.h"
#include "Transform.h"

void ResetTransform::reset(World &world, Entity &entity)
{
    if (auto *t = world.getTransform(entity))
    {
        t->x = 400.f;
        t->y = 300.f;
    }
}
