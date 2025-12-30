#include "World.h"
#include "System.h"
#include "ResetPolicy.h"

// NOTE: Do NOT include Collider.h here unless needed by implementation

World::World() : nextEntityId(0) {}
World::~World() = default;

// -------------------- Entity --------------------

Entity &World::createEntity()
{
    entities.emplace_back(nextEntityId++);
    return entities.back();
}

std::vector<Entity> &World::getEntities()
{
    return entities;
}

// -------------------- Transform --------------------

Transform &World::addTransform(Entity &entity)
{
    transforms[entity.getId()] = {0.0f, 0.0f};
    return transforms[entity.getId()];
}

Transform *World::getTransform(Entity &entity)
{
    auto it = transforms.find(entity.getId());
    if (it != transforms.end())
        return &it->second;

    return nullptr;
}

// -------------------- Enemy ----------------------
EnemyTag &World::addEnemy(Entity &entity)
{
    enemies[entity.getId()] = {};
    return enemies[entity.getId()];
}

EnemyTag *World::getEnemy(Entity &entity)
{
    auto it = enemies.find(entity.getId());
    if (it != enemies.end())
        return &it->second;
    return nullptr;
}

// -------------------- Collider --------------------

Collider &World::addCollider(Entity &entity, float w, float h)
{
    colliders[entity.getId()] = {w, h};
    return colliders[entity.getId()];
}

Collider *World::getCollider(Entity &entity)
{
    auto it = colliders.find(entity.getId());
    if (it != colliders.end())
        return &it->second;

    return nullptr;
}

// -------------------- Memory (Time Loop) --------------------

Memory &World::addMemory(Entity &entity, std::unique_ptr<ResetPolicy> policy)
{
    memories[entity.getId()] = {std::move(policy)};
    return memories[entity.getId()];
}

Memory *World::getMemory(Entity &entity)
{
    auto it = memories.find(entity.getId());
    if (it != memories.end())
        return &it->second;

    return nullptr;
}

// --------------------Player tag ------------------------------
PlayerTag &World::addPlayer(Entity &entity)
{
    players[entity.getId()] = {};
    return players[entity.getId()];
}

PlayerTag *World::getPlayer(Entity &entity)
{
    auto it = players.find(entity.getId());
    if (it != players.end())
        return &it->second;
    return nullptr;
}

// ------------------Camera-------------------------------------
Camera &World::addCamera(Entity &entity)
{
    cameras[entity.getId()] = {0.f, 0.f};
    return cameras[entity.getId()];
}

Camera *World::getCamera(Entity &entity)
{
    auto it = cameras.find(entity.getId());
    if (it != cameras.end())
        return &it->second;
    return nullptr;
}

void World::resetWorld()
{
    for (Entity &entity : entities)
    {
        Memory *memory = getMemory(entity);
        if (memory && memory->resetPolicy)
        {
            memory->resetPolicy->reset(*this, entity);
        }
    }
}

// -------------------- Systems --------------------

void World::addSystem(std::unique_ptr<System> system)
{
    systems.push_back(std::move(system));
}

void World::update(float deltaTime)
{
    for (auto &system : systems)
    {
        system->update(deltaTime);
    }
}
