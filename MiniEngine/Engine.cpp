#include "Engine.h"
#include <iostream>
#include <memory>
#include "MovementSystem.h"
#include "LifeSystem.h"
#include "CollisionSystem.h"
#include "SDLRenderSystem.h"
#include "InputSystem.h"
#include "DeathEvent.h"
#include "QuitEvent.h"
#include "EnemyTag.h"
#include "PlayerTag.h"
#include "AISystem.h"
#include "CameraSystem.h"
#include "ResetTransform.h"
#include "ResetDestroyEnemy.h"

using namespace std;

Engine::Engine() : running(true)
{
    // -------- Player entity --------
    Entity &e = world.createEntity();
    Transform &t = world.addTransform(e);
    t.x = 400.f;
    t.y = 300.f;

    world.addCollider(e, 20.f, 20.f);
    world.addPlayer(e); // THIS WAS MISSING
    world.addCamera(e);

    // -------- Enemy entity --------
    Entity &enemy = world.createEntity();
    Transform &et = world.addTransform(enemy);
    et.x = 500.f;
    et.y = 300.f;

    world.addCollider(enemy, 20.f, 20.f);
    world.addEnemy(enemy);

    // -------- System order matters --------
    world.addSystem(std::make_unique<InputSystem>(eventBus));
    world.addSystem(std::make_unique<MovementSystem>(world, eventBus));
    world.addSystem(std::make_unique<AISystem>(world));
    world.addSystem(std::make_unique<CollisionSystem>(world, eventBus));
    world.addSystem(std::make_unique<LifeSystem>(world, eventBus));
    world.addSystem(std::make_unique<CameraSystem>(world)); // NEW
    world.addSystem(std::make_unique<SDLRenderSystem>(world));
    world.addMemory(e, std::make_unique<ResetTransform>());
    world.addMemory(enemy, std::make_unique<ResetDestroyEnemy>());

    // -------- Events --------
    eventBus.subscribe<DeathEvent>([this](const DeathEvent &)
                                   {
        std::cout << "⏳ Time loop triggered!\n";
        world.resetWorld(); });

    eventBus.subscribe<QuitEvent>([this](const QuitEvent &)
                                  { running = false; });
}

void Engine::run()
{
    const float deltaTime = 0.016f; // ~60 FPS

    while (running)
    {
        world.update(deltaTime);
    }
}
