#include "RenderSystem.h"
#include "World.h"
#include <iostream>

RenderSystem::RenderSystem(World &world)
    : world(world) {}

void RenderSystem::update(float)
{
    std::cout << "---- WORLD STATE ----\n";

    for (Entity &entity : world.getEntities())
    {
        Transform *t = world.getTransform(entity);
        if (t)
        {
            std::cout << "Entity " << entity.getId()
                      << " at (" << t->x << ", " << t->y << ")\n";
        }
    }

    std::cout << "---------------------\n\n";
}
