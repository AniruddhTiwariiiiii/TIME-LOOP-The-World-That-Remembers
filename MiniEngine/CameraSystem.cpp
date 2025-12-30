#include "CameraSystem.h"
#include "World.h"
#include "Transform.h"
#include "Camera.h"
#include "Entity.h"
#include "PlayerTag.h"

CameraSystem::CameraSystem(World &world)
    : world(world) {}

void CameraSystem::update(float)
{
    for (Entity &entity : world.getEntities())
    {
        if (!world.getPlayer(entity))
            continue;

        Transform *t = world.getTransform(entity);
        Camera *c = world.getCamera(entity);
        if (!t || !c)
            continue;

        // Camera follows player (centered)
        c->x = t->x - 400.f; // half window width
        c->y = t->y - 300.f; // half window height
    }
}
