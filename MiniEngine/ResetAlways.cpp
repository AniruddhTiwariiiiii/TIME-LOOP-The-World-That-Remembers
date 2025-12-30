#include "ResetAlways.h"
#include "World.h"
#include "Transform.h"

void ResetAlways::reset(World &world, Entity &entity)
{
    Transform *t = world.getTransform(entity);
    if (t)
    {
        t->x = 0.0f;
        t->y = 0.0f;
    }
}
